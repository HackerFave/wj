/**
 * @file jt808.hpp
 * @author 谭创
 * @brief 
 * @version 0.1
 * @date 2023-02-22
 * 
 * @copyright Copyright () 2019
 * 
 */
#ifndef _JT808_H
#define _JT808_H

#include <atomic>
#include <cstdint>
#include <cstring>
#include <QDebug>
typedef struct
{
    uint16_t msgId;
    uint16_t serialNum; //encodeMsg不需要填充，主要用于解析cloud数据.
    uint16_t bodyLen;
    uint8_t body[1024];
} Jt808MsgST;

#define JT808_REVERSE_BYTE1 0X0D
#define JT808_REVERSE_BYTE2 0X0A

#define JT808_CLOUD_REVERSE_BYTE1 0X3e
#define JT808_CLOUD_REVERSE_BYTE2 0X3d

#define JT808_CLOUD_REVERSE_BYTE3 0X1A
#define JT808_CLOUD_REVERSE_BYTE4 0X19

#define BODYLEN_VAILD_BIT (0x3FF)
#define JT808_HEAD_LEN (10)
class JT808
{
public:
    static std::atomic<uint16_t> serialNum;

    enum msgType
    {
        clouldMsg = 0,
        defaultMsg
    };

private:
    static int enCodeHead(Jt808MsgST &msg, uint8_t *outResult)
    {
        std::memmove(outResult, &msg.msgId, 2);
        msg.bodyLen &= BODYLEN_VAILD_BIT;
        std::memmove(outResult + 2, &msg.bodyLen, 2);
        uint16_t num = serialNum.fetch_add(1);
        std::memmove(outResult + 4, &num, 2);
        uint16_t totalPkg = 1;
        std::memmove(outResult + 6, &totalPkg, 2);
        uint16_t indexPkg = 1;
        std::memmove(outResult + 8, &indexPkg, 2);
        return 10;
    }
    static uint8_t checkSum(uint8_t *data, int dataLen)
    {
        uint8_t sum = 0;
        for (int i = 0; i < dataLen; i++)
        {
            sum ^= data[i];
        }
        return sum;
    }
    static int reverseEncode(enum msgType type, uint8_t *data, int dataLen, uint8_t *outResult)
    {
        int outResultLen = 0;
        for (int i = 0; i < dataLen; i++)
        {
            switch (data[i])
            {
            case JT808_REVERSE_BYTE1:
            {
                outResult[outResultLen++] = JT808_REVERSE_BYTE1;
                outResult[outResultLen++] = 0x01;
                break;
            }
            case JT808_REVERSE_BYTE2:
            {
                outResult[outResultLen++] = JT808_REVERSE_BYTE1;
                outResult[outResultLen++] = 0x02;
                break;
            }
            case JT808_CLOUD_REVERSE_BYTE1:
            case JT808_CLOUD_REVERSE_BYTE3:
            {
                if (type == clouldMsg)
                {
                    outResult[outResultLen++] = data[i] - 1;
                    outResult[outResultLen++] = 0x02;
                    break;
                }
                [[fallthrough]];
            }
            case JT808_CLOUD_REVERSE_BYTE2:
            case JT808_CLOUD_REVERSE_BYTE4:
            {
                if (type == clouldMsg)
                {
                    outResult[outResultLen++] = data[i];
                    outResult[outResultLen++] = 0x01;
                    break;
                }
                [[fallthrough]];
            }
            default:
                outResult[outResultLen++] = data[i];
                break;
            }
        }
        outResult[outResultLen++] = 0x0D;
        outResult[outResultLen++] = 0x0A;
        return outResultLen;
    }

    static int reverseDecode(enum msgType type, uint8_t *data, int dataLen, uint8_t *outResult)
    {
        int outResultLen = 0;
        for (int i = 0; i < dataLen - 2; i++)
        {
            switch (data[i])
            {
            case JT808_REVERSE_BYTE1:
            {
                if (data[++i] == 0x02)
                {
                    outResult[outResultLen++] = 0x0A;
                }
                else
                {
                    outResult[outResultLen++] = 0x0D;
                }
                break;
            }
            case JT808_CLOUD_REVERSE_BYTE2:
            case JT808_CLOUD_REVERSE_BYTE4:
            {
                if (type != clouldMsg)
                {
                    outResult[outResultLen++] = data[i];
                    break;
                }
                if (data[++i] == 0x01)
                {
                    outResult[outResultLen++] = data[i - 1];
                }
                else
                {
                    outResult[outResultLen++] = data[i - 1] + 1;
                }
                break;
            }
            default:
                outResult[outResultLen++] = data[i];
                break;
            }
        }
        return outResultLen;
    }

public:
    static int enCodeMsg(enum msgType type, Jt808MsgST &msg, uint8_t *outResult)
    {
        int resultLen = 0;
        int newLen = msg.bodyLen * 2 + JT808_HEAD_LEN + 4;
        uint8_t *tempResult = new uint8_t[newLen];
        resultLen = enCodeHead(msg, tempResult);
        std::memmove(tempResult + resultLen, msg.body, msg.bodyLen);
        resultLen += msg.bodyLen;
        tempResult[resultLen] = checkSum(tempResult, resultLen);
        resultLen += 1;
        resultLen = reverseEncode(type, tempResult, resultLen, outResult);
        delete[] tempResult;
        return resultLen;
    }

    static int deCodeMsg(enum msgType type, uint8_t *data, int dataLen, Jt808MsgST &outResult)
    {
        uint8_t *temp = new uint8_t[dataLen];
        int len = reverseDecode(type, data, dataLen, temp);
        uint8_t sum = checkSum(temp, len - 1);
        if (temp[len - 1] != sum)
        {
            qWarning() << "JT808 decodeMsg checkSum Failed:dataSum" << static_cast<int>(temp[len - 1])
                       << "--" << static_cast<int>(sum);
            delete[] temp;
            return -1;
        }
        std::memmove(&outResult.msgId, temp, sizeof(outResult.msgId));
        std::memmove(&outResult.bodyLen, temp + 2, sizeof(outResult.bodyLen));
        outResult.bodyLen &= BODYLEN_VAILD_BIT;
        std::memmove(&outResult.serialNum, temp + 4, sizeof(outResult.serialNum));

        if (len != (outResult.bodyLen + 1 + JT808_HEAD_LEN))
        {
            qWarning() << "JT808 decodeMsg Len Failed:data-bodyLen[" << outResult.bodyLen
                       << "],calcbodyLen[" << len - JT808_HEAD_LEN - 1 << "]";
            delete[] temp;
            return -1;
        }
        std::memmove(outResult.body, temp + JT808_HEAD_LEN, outResult.bodyLen);
        delete[] temp;
        return outResult.bodyLen;
    }
};

#endif
