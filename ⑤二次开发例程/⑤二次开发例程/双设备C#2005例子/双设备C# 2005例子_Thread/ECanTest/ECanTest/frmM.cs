using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Text;
using System.Windows.Forms;
using ECAN;

namespace ECanTest
{
    public partial class frmM : Form
    {
        byte m_Baudrate;
        byte m_Baudrate2;

        byte m_connect = 0;
        ComProc mCan=new ComProc();

        byte m_connect1 = 0;

        private void IncludeTextMessage(string strMsg)
        {
            lbxInfo.Items.Add(strMsg);
            lbxInfo.SelectedIndex = lbxInfo.Items.Count - 1;
        }

        public frmM()
        {
            InitializeComponent();
        }

        private void frmM_FormClosing(object sender, FormClosingEventArgs e)
        {
            this.m_connect = 0;
            this.mCan.EnableProc = false;

            ECANDLL.CloseDevice(1, 0);
        }

 
        private void btnInit_Click(object sender, EventArgs e)
        {
            if (m_connect == 1)
            {
                m_connect = 0;
                this.mCan.EnableProc = false;


                ECANDLL.CloseDevice(1, 0);
                btnInit.Text = "打开设备";

                btnReset.Enabled = false;
                btnWrite.Enabled = false;

                return;
            }

            INIT_CONFIG init_config=new INIT_CONFIG();

            init_config.AccCode = 0;
            init_config.AccMask =0xffffff;
            init_config.Filter = 0;

            switch (m_Baudrate)
            {
                case 0: //1000

                    init_config.Timing0 = 0;
                    init_config.Timing1 =0x14;
                    break;
                case 1: //800

                    init_config.Timing0 = 0;
                    init_config.Timing1 = 0x16;
                    break;
                case 2: //666

                    init_config.Timing0 = 0x80;
                    init_config.Timing1 = 0xb6;
                    break;
                case 3: //500

                    init_config.Timing0 = 0;
                    init_config.Timing1 = 0x1c;
                    break;
                case 4://400

                    init_config.Timing0 = 0x80;
                    init_config.Timing1 = 0xfa;
                    break;
                case 5://250

                    init_config.Timing0 = 0x01;
                    init_config.Timing1 = 0x1c;
                    break;
                case 6://200

                    init_config.Timing0 = 0x81;
                    init_config.Timing1 = 0xfa;
                    break;
                case 7://125

                    init_config.Timing0 = 0x03;
                    init_config.Timing1 = 0x1c;
                    break;
                case 8://100

                    init_config.Timing0 = 0x04;
                    init_config.Timing1 = 0x1c;
                    break;
                case 9://80

                    init_config.Timing0 = 0x83;
                    init_config.Timing1 = 0xff;
                    break;
                case 10://50

                    init_config.Timing0 = 0x09;
                    init_config.Timing1 = 0x1c;
                    break;
                
            }

            init_config.Mode = 0;

            if (ECANDLL.OpenDevice(1, 0, 0) != ECAN.ECANStatus.STATUS_OK)
            {

                MessageBox.Show("Open device fault!", "Error!", MessageBoxButtons.OK, MessageBoxIcon.Error);

                return;
            }
            //Set can1 baud
            if (ECANDLL.InitCAN(1, 0, 0, ref init_config) != ECAN.ECANStatus.STATUS_OK)
            {

                MessageBox.Show("Init can fault!", "Error!", MessageBoxButtons.OK, MessageBoxIcon.Error);

                ECANDLL.CloseDevice(1, 0);
                return;
            }

            //set can2 baud

            switch (m_Baudrate2)
             {
                 case 0: //1000

                     init_config.Timing0 = 0;
                     init_config.Timing1 = 0x14;
                     break;
                 case 1: //800

                     init_config.Timing0 = 0;
                     init_config.Timing1 = 0x16;
                     break;
                 case 2: //666

                     init_config.Timing0 = 0x80;
                     init_config.Timing1 = 0xb6;
                     break;
                 case 3: //500

                     init_config.Timing0 = 0;
                     init_config.Timing1 = 0x1c;
                     break;
                 case 4://400

                     init_config.Timing0 = 0x80;
                     init_config.Timing1 = 0xfa;
                     break;
                 case 5://250

                     init_config.Timing0 = 0x01;
                     init_config.Timing1 = 0x1c;
                     break;
                 case 6://200

                     init_config.Timing0 = 0x81;
                     init_config.Timing1 = 0xfa;
                     break;
                 case 7://125

                     init_config.Timing0 = 0x03;
                     init_config.Timing1 = 0x1c;
                     break;
                 case 8://100

                     init_config.Timing0 = 0x04;
                     init_config.Timing1 = 0x1c;
                     break;
                 case 9://80

                     init_config.Timing0 = 0x83;
                     init_config.Timing1 = 0xff;
                     break;
                 case 10://50

                     init_config.Timing0 = 0x09;
                     init_config.Timing1 = 0x1c;
                     break;

             }

             init_config.Mode = 0;





            if (ECANDLL.InitCAN(1, 0,1, ref init_config) != ECAN.ECANStatus.STATUS_OK)
            {

                MessageBox.Show("Init can fault!", "Error!", MessageBoxButtons.OK, MessageBoxIcon.Error);

                ECANDLL.CloseDevice(1, 0);
                return;
            }


            m_connect = 1;
            this.mCan.EnableProc =true;

            btnInit.Text = "关闭设备";
            btnReset.Enabled = true;
            btnWrite.Enabled = true;
            IncludeTextMessage("Open 0 Success");

            btnWrite2.Enabled = true;

            if (m_connect == 0)
            {
                MessageBox.Show("Not open device!", "Error!", MessageBoxButtons.OK, MessageBoxIcon.Error);

                return;
            }

            //Start Can1

            if (ECANDLL.StartCAN(1, 0, 0) == ECAN.ECANStatus.STATUS_OK)
            {
                IncludeTextMessage("Start CAN1 Success");
                tmrRead.Enabled = true;

            }
            else
            {
                IncludeTextMessage("Start Fault");
            }
            //start CAN2
            if (ECANDLL.StartCAN(1, 0, 1) == ECAN.ECANStatus.STATUS_OK)
            {
                IncludeTextMessage("Start CAN2 Success");
                tmrRead.Enabled = true;

            }
            else
            {
                IncludeTextMessage("Start Fault");
            }	


        }


        private void cbbBaudrates_SelectedIndexChanged(object sender, EventArgs e)
        {
            m_Baudrate =(byte)cbbBaudrates.SelectedIndex;
        }

      

        private void btnReset_Click(object sender, EventArgs e)
        {
            if (m_connect == 0)
            {
                MessageBox.Show("Not open device!", "Error!", MessageBoxButtons.OK, MessageBoxIcon.Error);

                return;
            }
            if (ECANDLL.ResetCAN(1, 0, 0) == ECANStatus.STATUS_OK)
            {
               IncludeTextMessage("Reset Success");
            }
            else
            {
                IncludeTextMessage("Reset Fault");
            }

        }

        private void btnWrite_Click(object sender, EventArgs e)
        {

                 if (this.m_connect == 0)
                {
                    MessageBox.Show("Not open device!", "Error!", MessageBoxButtons.OK, MessageBoxIcon.Hand);
                }
                else
                {
                    CAN_OBJ frameinfo;



                    TextBox txtbCurrentTextBox;


                    // We create a TPCANMsg message structure 
                    //
                    frameinfo = new CAN_OBJ();
                    frameinfo.SendType = 0;

                    frameinfo.data = new byte[8];
                    frameinfo.Reserved = new byte[2];

                    // We configurate the Message.  The ID (max 0x1FF),
                    // Length of the Data, Message Type (Standard in 
                    // this example) and die data
                    //
                    frameinfo.ID = Convert.ToUInt32(txtID.Text, 16);
                    frameinfo.DataLen = Convert.ToByte(nudLength.Value);


                    if (this.chbExtended.Checked)
                    {
                        frameinfo.ExternFlag = 1;
                    }
                    else
                    {
                        frameinfo.ExternFlag = 0;
                    }
                    if (this.chbRemote.Checked)
                    {
                        frameinfo.RemoteFlag = 1;
                    }
                    else
                    {
                        frameinfo.RemoteFlag = 0;
                        txtbCurrentTextBox = txtData0;

                        int tlen = frameinfo.DataLen - 1;
                        for (int i = 0; i <= tlen; i++)
                        {
                            frameinfo.data[i] = Convert.ToByte(txtbCurrentTextBox.Text, 0x10);
                            if (i < 7)
                            {
                                txtbCurrentTextBox = (TextBox) this.GetNextControl(txtbCurrentTextBox, true);
                            }
                        }
                    }
                    this.mCan.gSendMsgBuf[this.mCan.gSendMsgBufHead].ID = frameinfo.ID;
                    this.mCan.gSendMsgBuf[this.mCan.gSendMsgBufHead].DataLen = frameinfo.DataLen;
                    this.mCan.gSendMsgBuf[this.mCan.gSendMsgBufHead].data = frameinfo.data;
                    this.mCan.gSendMsgBuf[this.mCan.gSendMsgBufHead].ExternFlag = frameinfo.ExternFlag;
                    this.mCan.gSendMsgBuf[this.mCan.gSendMsgBufHead].RemoteFlag = frameinfo.RemoteFlag;
                    this.mCan.gSendMsgBufHead += 1;
                    if (this.mCan.gSendMsgBufHead >= ComProc.SEND_MSG_BUF_MAX)
                    {
                        this.mCan.gSendMsgBufHead = 0;
                    }
                }

           

        }

        private void btnInfoClear_Click(object sender, EventArgs e)
        {
            lbxInfo.Items.Clear();
        }

        private void tmrRead_Tick(object sender, EventArgs e)
        {
            ReadMessages();
            ReadMessages2();
            ReadError1();
            ReadError2();

        }

        private void ReadError1()
        {

            CAN_ERR_INFO mErrInfo = new CAN_ERR_INFO();

            if (ECANDLL.ReadErrInfo(1, 0, 0, out mErrInfo) == ECANStatus.STATUS_OK)
            {
                labErrInfo1.Text = string.Format("{0:X4}h", mErrInfo.ErrCode);
                labRx.Text = string.Format("{0:X4}h", mErrInfo.Passive_ErrData[1]);
                labTx.Text = string.Format("{0:X4}h", mErrInfo.Passive_ErrData[2]);

            }
            else
            {

                labErrInfo1.Text = "Read Error Fault";
            }



        }
        private void ReadError2()
        {

            CAN_ERR_INFO mErrInfo = new CAN_ERR_INFO();

            if (ECANDLL.ReadErrInfo(1, 0, 1, out mErrInfo) == ECANStatus.STATUS_OK)
            {
                labErrInfo2.Text = string.Format("{0:X4}h", mErrInfo.ErrCode);

            }
            else
            {

                labErrInfo2.Text = "Read Error Fault";
            }



        }

        private void ReadMessages()
        {

                CAN_OBJ frameinfo = new CAN_OBJ();
                int mCount = 0;
                while (this.mCan.gRecMsgBufHead != this.mCan.gRecMsgBufTail)
                {
                    string tmpstr;
                    frameinfo = this.mCan.gRecMsgBuf[this.mCan.gRecMsgBufTail];
                    this.mCan.gRecMsgBufTail += 1;
                    if (this.mCan.gRecMsgBufTail >= ComProc.REC_MSG_BUF_MAX)
                    {
                        this.mCan.gRecMsgBufTail = 0;
                    }
                    string str = "Rec: ";
                    if (frameinfo.TimeFlag == 0)
                    {
                        tmpstr = "Time:  ";
                    }
                    else
                    {
                        tmpstr = "Time:" + string.Format("{0:X8}h", frameinfo.TimeStamp);
                    }
                    str = str + tmpstr;
                    tmpstr = "  ID:" + string.Format("{0:X8}h", frameinfo.ID);
                    str = str + tmpstr + " Format:";
                    if (frameinfo.RemoteFlag == 0)
                    {
                        tmpstr = "Data ";
                    }
                    else
                    {
                        tmpstr = "Romte ";
                    }
                    str = str + tmpstr + " Type:";
                    if (frameinfo.ExternFlag == 0)
                    {
                        tmpstr = "Stand ";
                    }
                    else
                    {
                        tmpstr = "Exten ";
                    }
                    str = str + tmpstr;
                    if (frameinfo.RemoteFlag == 0)
                    {
                        str = str + " Data:";
                        if (frameinfo.DataLen > 8)
                        {
                            frameinfo.DataLen = 8;
                        }
                        int mlen = frameinfo.DataLen - 1;
                        for (int j = 0; j <= mlen; j++)
                        {
                            tmpstr = string.Format("{0:X2}h", frameinfo.data[j]);
                            str = str + tmpstr;
                        }
                    }
                    this.lbxRec.Items.Add(str);
                    if (this.lbxRec.Items.Count > 500)
                    {
                        this.lbxRec.Items.Clear();
                    }
                    mCount++;
                    if (mCount >= 50)
                    {
                        break;
                    }
                    Application.DoEvents();
                }



        }

        private void ReadMessages2()
        {

            CAN_OBJ frameinfo = new CAN_OBJ();
            int mCount = 0;
            while (this.mCan.gRecMsgBufHead2 != this.mCan.gRecMsgBufTail2)
            {
                string tmpstr;
                frameinfo = this.mCan.gRecMsgBuf2[this.mCan.gRecMsgBufTail2];
                this.mCan.gRecMsgBufTail2 += 1;
                if (this.mCan.gRecMsgBufTail2 >= ComProc.REC_MSG_BUF_MAX)
                {
                    this.mCan.gRecMsgBufTail2 = 0;
                }
                string str = "Rec: ";
                if (frameinfo.TimeFlag == 0)
                {
                    tmpstr = "Time:  ";
                }
                else
                {
                    tmpstr = "Time:" + string.Format("{0:X8}h", frameinfo.TimeStamp);
                }
                str = str + tmpstr;
                tmpstr = "  ID:" + string.Format("{0:X8}h", frameinfo.ID);
                str = str + tmpstr + " Format:";
                if (frameinfo.RemoteFlag == 0)
                {
                    tmpstr = "Data ";
                }
                else
                {
                    tmpstr = "Romte ";
                }
                str = str + tmpstr + " Type:";
                if (frameinfo.ExternFlag == 0)
                {
                    tmpstr = "Stand ";
                }
                else
                {
                    tmpstr = "Exten ";
                }
                str = str + tmpstr;
                if (frameinfo.RemoteFlag == 0)
                {
                    str = str + " Data:";
                    if (frameinfo.DataLen > 8)
                    {
                        frameinfo.DataLen = 8;
                    }
                    int mlen = frameinfo.DataLen - 1;
                    for (int j = 0; j <= mlen; j++)
                    {
                        tmpstr = string.Format("{0:X2}h", frameinfo.data[j]);
                        str = str + tmpstr;
                    }
                }
                this.lbxRec2.Items.Add(str);
                if (this.lbxRec2.Items.Count > 500)
                {
                    this.lbxRec2.Items.Clear();
                }
                mCount++;
                if (mCount >= 50)
                {
                    break;
                }
                Application.DoEvents();
            }



        }

        private void btnMsgClear_Click(object sender, EventArgs e)
        {
            lbxRec.Items.Clear();
        }

        private void Form1_Load(object sender, EventArgs e)
        {
            cbbBaudrates.SelectedIndex =3;
            cbbBaudrates2.SelectedIndex =5;
        }

        private void btnMsgClear2_Click(object sender, EventArgs e)
        {
            lbxRec2.Items.Clear();

        }

        private void btnInfoClear2_Click(object sender, EventArgs e)
        {
            lbxInfo2.Items.Clear();
        }

        private void cbbBaudrates2_SelectedIndexChanged(object sender, EventArgs e)
        {
            m_Baudrate2 = (byte)cbbBaudrates2.SelectedIndex;

        }

        private void btnWrite2_Click(object sender, EventArgs e)
        {
            if (this.m_connect == 0)
            {
                MessageBox.Show("Not open device!", "Error!", MessageBoxButtons.OK, MessageBoxIcon.Hand);
            }
            else
            {
                CAN_OBJ frameinfo;



                TextBox txtbCurrentTextBox;


                // We create a TPCANMsg message structure 
                //
                frameinfo = new CAN_OBJ();

                frameinfo.data = new byte[8];
                frameinfo.Reserved = new byte[2];

                // We configurate the Message.  The ID (max 0x1FF),
                // Length of the Data, Message Type (Standard in 
                // this example) and die data
                //
                frameinfo.ID = Convert.ToUInt32(txtID2.Text, 16);
                frameinfo.DataLen = Convert.ToByte(nudLength2.Value);


                if (this.chbExtended2.Checked)
                {
                    frameinfo.ExternFlag = 1;
                }
                else
                {
                    frameinfo.ExternFlag = 0;
                }
                if (this.chbRemote2.Checked)
                {
                    frameinfo.RemoteFlag = 1;
                }
                else
                {
                    frameinfo.RemoteFlag = 0;
                    txtbCurrentTextBox = txtData20;

                    int tlen = frameinfo.DataLen - 1;
                    for (int i = 0; i <= tlen; i++)
                    {
                        frameinfo.data[i] = Convert.ToByte(txtbCurrentTextBox.Text, 0x10);
                        if (i < 7)
                        {
                            txtbCurrentTextBox = (TextBox)this.GetNextControl(txtbCurrentTextBox, true);
                        }
                    }
                }
                this.mCan.gSendMsgBuf2[this.mCan.gSendMsgBufHead2].ID = frameinfo.ID;
                this.mCan.gSendMsgBuf2[this.mCan.gSendMsgBufHead2].DataLen = frameinfo.DataLen;
                this.mCan.gSendMsgBuf2[this.mCan.gSendMsgBufHead2].data = frameinfo.data;
                this.mCan.gSendMsgBuf2[this.mCan.gSendMsgBufHead2].ExternFlag = frameinfo.ExternFlag;
                this.mCan.gSendMsgBuf2[this.mCan.gSendMsgBufHead2].RemoteFlag = frameinfo.RemoteFlag;
                this.mCan.gSendMsgBufHead2 += 1;
                if (this.mCan.gSendMsgBufHead2 >=ComProc.SEND_MSG_BUF_MAX)
                {
                    this.mCan.gSendMsgBufHead2 = 0;
                }
            }
        }

        private void button1_Click(object sender, EventArgs e)
        {

            int i;
            BOARD_INFO mReadBoardInfo = new BOARD_INFO();

            if (ECANDLL.ReadBoardInfo(1, 0, out mReadBoardInfo) == ECANStatus.STATUS_OK)
            {
                labInfo.Text = "";
                for(i=0;i<10;i++)

                    labInfo.Text =labInfo.Text +(char)(mReadBoardInfo.str_Serial_Num[i]);

            }
            else
            {

                labInfo.Text = "Read info Fault";
            }
        }

        private void chbExtended_CheckedChanged(object sender, EventArgs e)
        {
            if (chbExtended.Checked)
            {
                txtID.MaxLength = 8;
            }
            else
            {

                txtID.MaxLength = 3;
            }

        }

        private void button2_Click(object sender, EventArgs e)
        {
            if (ECANDLL.OpenDevice(1, 0, 0) != ECAN.ECANStatus.STATUS_OK)
            {

                MessageBox.Show("Open device fault!", "Error!", MessageBoxButtons.OK, MessageBoxIcon.Error);

                return;
            }
           timer1.Enabled = true;

        }

        private void timer1_Tick(object sender, EventArgs e)
        {
            ReadError1();
        }

        private void tmrDisplay_Tick(object sender, EventArgs e)
        {

        }

       

        private void timer2_Tick(object sender, EventArgs e)
        {
            
            CAN_ERR_INFO mErrInfo4 = new CAN_ERR_INFO();

            if (ECANDLL.ReadErrInfo(1, 1,0, out mErrInfo4) == ECANStatus.STATUS_OK)
            {
                labErrInfo2.Text = string.Format("{0:X4}h", mErrInfo4.ErrCode);

            }
            else
            {

                labErrInfo2.Text = "Read Error Fault";
            }

          
        }

        private void button4_Click(object sender, EventArgs e)
        {
            CAN_ERR_INFO mErrInfo1 = new CAN_ERR_INFO();

            if (ECANDLL.ReadErrInfo(1,0, 0, out mErrInfo1) == ECANStatus.STATUS_OK)
            {
                this.lbxRec2.Items.Add(string.Format("{0:X4}h", mErrInfo1.ErrCode));
            }

            if (ECANDLL.ReadErrInfo(1,1, 0, out mErrInfo1) == ECANStatus.STATUS_OK)
            {
                this.lbxRec2.Items.Add(string.Format("{0:X4}h", mErrInfo1.ErrCode));
            }


            if (ECANDLL.ReadErrInfo(1, 2, 0, out mErrInfo1) == ECANStatus.STATUS_OK)
            {
                this.lbxRec2.Items.Add(string.Format("{0:X4}h", mErrInfo1.ErrCode));
            }


            if (ECANDLL.ReadErrInfo(1, 3, 0, out mErrInfo1) == ECANStatus.STATUS_OK)
            {
                this.lbxRec2.Items.Add(string.Format("{0:X4}h", mErrInfo1.ErrCode));
            }


        }

        private void btnOpen1_Click(object sender, EventArgs e)
        {

            if (m_connect1 == 1)
            {
                m_connect1 = 0;
               //this.mCan.EnableProc = false;


                ECANDLL.CloseDevice(1, 0);
                btnOpen1.Text = "打开设备";

               // btnReset.Enabled = false;
               // btnWrite.Enabled = false;

                return;
            }

            INIT_CONFIG init_config = new INIT_CONFIG();

            init_config.AccCode = 0;
            init_config.AccMask = 0xffffff;
            init_config.Filter = 0;

            switch (m_Baudrate)
            {
                case 0: //1000

                    init_config.Timing0 = 0;
                    init_config.Timing1 = 0x14;
                    break;
                case 1: //800

                    init_config.Timing0 = 0;
                    init_config.Timing1 = 0x16;
                    break;
                case 2: //666

                    init_config.Timing0 = 0x80;
                    init_config.Timing1 = 0xb6;
                    break;
                case 3: //500

                    init_config.Timing0 = 0;
                    init_config.Timing1 = 0x1c;
                    break;
                case 4://400

                    init_config.Timing0 = 0x80;
                    init_config.Timing1 = 0xfa;
                    break;
                case 5://250

                    init_config.Timing0 = 0x01;
                    init_config.Timing1 = 0x1c;
                    break;
                case 6://200

                    init_config.Timing0 = 0x81;
                    init_config.Timing1 = 0xfa;
                    break;
                case 7://125

                    init_config.Timing0 = 0x03;
                    init_config.Timing1 = 0x1c;
                    break;
                case 8://100

                    init_config.Timing0 = 0x04;
                    init_config.Timing1 = 0x1c;
                    break;
                case 9://80

                    init_config.Timing0 = 0x83;
                    init_config.Timing1 = 0xff;
                    break;
                case 10://50

                    init_config.Timing0 = 0x09;
                    init_config.Timing1 = 0x1c;
                    break;

            }

            init_config.Mode = 0;

            if (ECANDLL.OpenDevice(1,1, 0) != ECAN.ECANStatus.STATUS_OK)
            {

                MessageBox.Show("Open device 1 fault!", "Error!", MessageBoxButtons.OK, MessageBoxIcon.Error);

                return;
            }
            //Set can1 baud
            if (ECANDLL.InitCAN(1, 1, 0, ref init_config) != ECAN.ECANStatus.STATUS_OK)
            {

                MessageBox.Show("Init can fault!", "Error!", MessageBoxButtons.OK, MessageBoxIcon.Error);

                ECANDLL.CloseDevice(1, 1);
                return;
            }

            //set can2 baud

            switch (m_Baudrate2)
            {
                case 0: //1000

                    init_config.Timing0 = 0;
                    init_config.Timing1 = 0x14;
                    break;
                case 1: //800

                    init_config.Timing0 = 0;
                    init_config.Timing1 = 0x16;
                    break;
                case 2: //666

                    init_config.Timing0 = 0x80;
                    init_config.Timing1 = 0xb6;
                    break;
                case 3: //500

                    init_config.Timing0 = 0;
                    init_config.Timing1 = 0x1c;
                    break;
                case 4://400

                    init_config.Timing0 = 0x80;
                    init_config.Timing1 = 0xfa;
                    break;
                case 5://250

                    init_config.Timing0 = 0x01;
                    init_config.Timing1 = 0x1c;
                    break;
                case 6://200

                    init_config.Timing0 = 0x81;
                    init_config.Timing1 = 0xfa;
                    break;
                case 7://125

                    init_config.Timing0 = 0x03;
                    init_config.Timing1 = 0x1c;
                    break;
                case 8://100

                    init_config.Timing0 = 0x04;
                    init_config.Timing1 = 0x1c;
                    break;
                case 9://80

                    init_config.Timing0 = 0x83;
                    init_config.Timing1 = 0xff;
                    break;
                case 10://50

                    init_config.Timing0 = 0x09;
                    init_config.Timing1 = 0x1c;
                    break;

            }

            init_config.Mode = 0;





            if (ECANDLL.InitCAN(1, 1, 1, ref init_config) != ECAN.ECANStatus.STATUS_OK)
            {

                MessageBox.Show("Init can fault!", "Error!", MessageBoxButtons.OK, MessageBoxIcon.Error);

                ECANDLL.CloseDevice(1,1);
                return;
            }


            m_connect = 1;
            this.mCan.EnableProc = true;

            btnInit.Text = "关闭设备";
            btnReset.Enabled = true;
            btnWrite.Enabled = true;
            IncludeTextMessage("Open 1 Success");

            btnWrite2.Enabled = true;

            if (m_connect == 0)
            {
                MessageBox.Show("Not open device!", "Error!", MessageBoxButtons.OK, MessageBoxIcon.Error);

                return;
            }

            //Start Can1

            if (ECANDLL.StartCAN(1, 1, 0) == ECAN.ECANStatus.STATUS_OK)
            {
                IncludeTextMessage("Start CAN1 Success");
                tmrRead.Enabled = true;

            }
            else
            {
                IncludeTextMessage("Start Fault");
            }
            //start CAN2
            if (ECANDLL.StartCAN(1, 1, 1) == ECAN.ECANStatus.STATUS_OK)
            {
                IncludeTextMessage("Start CAN2 Success");
                tmrRead.Enabled = true;

            }
            else
            {
                IncludeTextMessage("Start Fault");
            }	

            timer2.Enabled = true;
        }


       
   
    }


}