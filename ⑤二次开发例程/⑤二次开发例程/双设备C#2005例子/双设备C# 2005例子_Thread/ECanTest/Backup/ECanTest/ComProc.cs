using System;
using System.Collections.Generic;
using System.Text;
using ECAN;
using System.Threading;

namespace ECanTest
{
    class ComProc
    {


        // Fields
        public bool EnableProc;

        public const int REC_MSG_BUF_MAX = 0x2710;

        public CAN_OBJ[] gRecMsgBuf;
        public uint gRecMsgBufHead;
        public uint gRecMsgBufTail;

        public CAN_OBJ[] gRecMsgBuf2;
        public uint gRecMsgBufHead2;
        public uint gRecMsgBufTail2;

        public const int SEND_MSG_BUF_MAX = 0x2710;

        public CAN_OBJ[] gSendMsgBuf;
        public uint gSendMsgBufHead;
        public uint gSendMsgBufTail;

        public CAN_OBJ[] gSendMsgBuf2;
        public uint gSendMsgBufHead2;
        public uint gSendMsgBufTail2;



        private Timer _RecTimer;
        private Timer _SendTimer;

        private AutoResetEvent RecEvent;
        private TimerCallback RecTimerDelegate;
        private AutoResetEvent SendEvent;
        private TimerCallback SendTimerDelegate;


      
        public ComProc()
        {
            this.gSendMsgBuf = new CAN_OBJ[SEND_MSG_BUF_MAX];
            this.gSendMsgBufHead = 0;
            this.gSendMsgBufTail = 0;

            this.gSendMsgBuf2 = new CAN_OBJ[SEND_MSG_BUF_MAX];
            this.gSendMsgBufHead2 = 0;
            this.gSendMsgBufTail2 = 0;

            this.gRecMsgBuf = new CAN_OBJ[REC_MSG_BUF_MAX];
            this.gRecMsgBufHead = 0;
            this.gRecMsgBufTail = 0;

            this.gRecMsgBuf2 = new CAN_OBJ[REC_MSG_BUF_MAX];
            this.gRecMsgBufHead2 = 0;
            this.gRecMsgBufTail2 = 0;


            this.EnableProc = false;
            this.RecEvent = new AutoResetEvent(false);
            this.RecTimerDelegate = new TimerCallback(this.RecTimer_Tick);
            this._RecTimer = new Timer(this.RecTimerDelegate, this.RecEvent, 0, 20);
            this.SendEvent = new AutoResetEvent(false);
            this.SendTimerDelegate = new TimerCallback(this.SendTimer_Tick);
            this._SendTimer = new Timer(this.SendTimerDelegate, this.SendEvent, 0, 20);

        }


 

        private void ReadMessages()
        {
            CAN_OBJ mMsg = new CAN_OBJ();

            int sCount = 0;
            do
            {
                uint mLen = 1;
                if (!((ECANDLL.Receive(1, 0, 0, out mMsg, mLen, 1) == ECANStatus.STATUS_OK) & (mLen > 0)))
                {
                    break;
                }

                this.gRecMsgBuf[this.gRecMsgBufHead].ID = mMsg.ID;
                this.gRecMsgBuf[this.gRecMsgBufHead].DataLen = mMsg.DataLen;
                this.gRecMsgBuf[this.gRecMsgBufHead].data = mMsg.data;
                this.gRecMsgBuf[this.gRecMsgBufHead].ExternFlag = mMsg.ExternFlag;
                this.gRecMsgBuf[this.gRecMsgBufHead].RemoteFlag = mMsg.RemoteFlag;
                this.gRecMsgBufHead += 1;
                if (this.gRecMsgBufHead >= REC_MSG_BUF_MAX)
                {
                    this.gRecMsgBufHead = 0;
                }
                sCount++;
            }
            while (sCount < 500);
        }



        private void ReadMessages2()
        {
            CAN_OBJ mMsg = new CAN_OBJ();

            int sCount = 0;
            do
            {
                uint mLen = 1;
                if (!((ECANDLL.Receive(1, 0, 1, out mMsg, mLen, 1) == ECANStatus.STATUS_OK) & (mLen > 0)))
                {
                    break;
                }

                this.gRecMsgBuf2[this.gRecMsgBufHead2].ID = mMsg.ID;
                this.gRecMsgBuf2[this.gRecMsgBufHead2].DataLen = mMsg.DataLen;
                this.gRecMsgBuf2[this.gRecMsgBufHead2].data = mMsg.data;
                this.gRecMsgBuf2[this.gRecMsgBufHead2].ExternFlag = mMsg.ExternFlag;
                this.gRecMsgBuf2[this.gRecMsgBufHead2].RemoteFlag = mMsg.RemoteFlag;
                this.gRecMsgBufHead2 += 1;
                if (this.gRecMsgBufHead2 >= REC_MSG_BUF_MAX)
                {
                    this.gRecMsgBufHead2 = 0;
                }
                sCount++;
            }
            while (sCount < 500);
        }


        private void SendMessages()
        {
            int sCount = 0;
            do
            {
                if (this.gSendMsgBufHead == this.gSendMsgBufTail)
                {
                    break;
                }
                CAN_OBJ mMsg = this.gSendMsgBuf[this.gSendMsgBufTail];
                this.gSendMsgBufTail += 1;
                if (this.gSendMsgBufTail >= SEND_MSG_BUF_MAX)
                {
                    this.gSendMsgBufTail = 0;
                }
                uint mLen = 1;
                if (ECANDLL.Transmit(1, 0, 0, ref mMsg, (ushort)mLen) != ECANStatus.STATUS_OK)
                {
                }
                sCount++;
            }
            while (sCount < 200);
        }

        private void SendMessages2()
        {
            int sCount = 0;
            do
            {
                if (this.gSendMsgBufHead2 == this.gSendMsgBufTail2)
                {
                    break;
                }
                CAN_OBJ mMsg = this.gSendMsgBuf2[this.gSendMsgBufTail2];
                this.gSendMsgBufTail2 += 1;
                if (this.gSendMsgBufTail2 >= SEND_MSG_BUF_MAX)
                {
                    this.gSendMsgBufTail2 = 0;
                }
                uint mLen = 1;
                if (ECANDLL.Transmit(1, 0, 1, ref mMsg, (ushort)mLen) != ECANStatus.STATUS_OK)
                {
                }
                sCount++;
            }
            while (sCount < 200);
        }


        public void RecTime()
        {
            if (this.EnableProc)
            {
                this.ReadMessages();
                this.ReadMessages2();
            }
        }

        private void RecTimer_Tick(object mObject)
        {
            this.RecTime();
        }

        private void SendTimer_Tick(object mObject)
        {
            this.SendTime();
        }


        public void SendTime()
        {
            if (this.EnableProc)
            {
                this.SendMessages();
                this.SendMessages2();
            }
        }




        public void Close()
        {
        }

 
    }
}
