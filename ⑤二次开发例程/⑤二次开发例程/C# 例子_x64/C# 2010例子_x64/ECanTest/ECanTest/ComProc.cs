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


        public const int SEND_MSG_BUF_MAX = 0x2710;

        public CAN_OBJ[] gSendMsgBuf;
        public uint gSendMsgBufHead;
        public uint gSendMsgBufTail;



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


            this.gRecMsgBuf = new CAN_OBJ[REC_MSG_BUF_MAX];
            this.gRecMsgBufHead = 0;
            this.gRecMsgBufTail = 0;



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
                if (!(ECANDLL.Receive(1, 0, 0, out mMsg, mLen, 1) == ECANStatus.STATUS_OK))
                {
                    break;
                }
                if (mLen == 0) break;

                this.gRecMsgBuf[this.gRecMsgBufHead].ID = mMsg.ID;
                this.gRecMsgBuf[this.gRecMsgBufHead].DataLen = mMsg.DataLen;
                this.gRecMsgBuf[this.gRecMsgBufHead].data = mMsg.data;
                this.gRecMsgBuf[this.gRecMsgBufHead].ExternFlag = mMsg.ExternFlag;
                this.gRecMsgBuf[this.gRecMsgBufHead].RemoteFlag = mMsg.RemoteFlag;
				this.gRecMsgBuf[this.gRecMsgBufHead].TimeStamp = mMsg.TimeStamp;
                this.gRecMsgBuf[this.gRecMsgBufHead].Reserved = mMsg.Reserved;
                this.gRecMsgBuf[this.gRecMsgBufHead].TimeFlag = mMsg.TimeFlag;
                this.gRecMsgBufHead += 1;
                if (this.gRecMsgBufHead >= REC_MSG_BUF_MAX)
                {
                    this.gRecMsgBufHead = 0;
                }
                sCount++;
            }
            while (sCount < 500);
        }



 
        private void SendMessages()
        {
            CAN_OBJ[] mMsg = new CAN_OBJ[2];
            int aa=0;

            int sCount = 0;
            do
            {
                if (this.gSendMsgBufHead == this.gSendMsgBufTail)
                {
                    break;
                }
                mMsg[0] = this.gSendMsgBuf[this.gSendMsgBufTail];
                mMsg[1] = this.gSendMsgBuf[this.gSendMsgBufTail];
                //mMsg[0].data[0] = 0;
                //mMsg[0].data[1] = 0;
                //mMsg[0].data[2] = 0;
                this.gSendMsgBufTail+=1;
                if (this.gSendMsgBufTail >= SEND_MSG_BUF_MAX)
                {
                    this.gSendMsgBufTail = 0;
                }
                uint mLen = 1;
                aa=System.Runtime.InteropServices.Marshal.SizeOf(mMsg[1]);
                if (ECANDLL.Transmit(1, 0, 0, mMsg, (ushort)mLen) != ECANStatus.STATUS_OK)
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
            }
        }




        public void Close()
        {
        }

 
    }
}
