// ECanTestDlg.cpp : implementation file
//

#include "stdafx.h"
#include "ECanTest.h"
#include "ECanTestDlg.h"

#include "EcanVci.h"



#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif


#pragma comment(lib,"EcanVci")


/////////////////////////////////////////////////////////////////////////////
// CECanTestDlg dialog

CECanTestDlg::CECanTestDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CECanTestDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CECanTestDlg)
	m_EditSendData = _T("");
	m_EditSendFrmID = _T("");
	m_connect=0;
	m_devtype=USBCAN1;//USBCAN2;

	//}}AFX_DATA_INIT
	// Note that LoadIcon does not require a subsequent DestroyIcon in Win32
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CECanTestDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CECanTestDlg)
	DDX_Control(pDX, IDC_COMBO_SENDFRAMEFORMAT, m_ComboSendFrmFmt);
	DDX_Control(pDX, IDC_COMBO_SENDFRAMETYPE, m_ComboSendFrmType);
	DDX_Control(pDX, IDC_LIST_INFO, m_ListInfo);
	DDX_Control(pDX, IDC_COMBO_BAUD, m_ComboBaud);
	DDX_Text(pDX, IDC_EDIT_SENDDATA, m_EditSendData);
	DDX_Text(pDX, IDC_EDIT_SENDFRAMEID, m_EditSendFrmID);
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CECanTestDlg, CDialog)
	//{{AFX_MSG_MAP(CECanTestDlg)
	ON_BN_CLICKED(IDC_BUTTON_CONNECT, OnButtonConnect)
	ON_BN_CLICKED(IDC_BUTTON_STARTCAN, OnButtonStartcan)
	ON_BN_CLICKED(IDC_BUTTON_RESETCAN, OnButtonResetcan)
	ON_BN_CLICKED(IDC_BUTTON_SEND, OnButtonSend)
	ON_WM_CLOSE()
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CECanTestDlg message handlers

BOOL CECanTestDlg::OnInitDialog()
{
	CDialog::OnInitDialog();

	// Set the icon for this dialog.  The framework does this automatically
	//  when the application's main window is not a dialog
	SetIcon(m_hIcon, TRUE);			// Set big icon
	SetIcon(m_hIcon, FALSE);		// Set small icon
	
	CenterWindow(GetDesktopWindow());	// center to the hpc screen

	// TODO: Add extra initialization here
	m_ComboSendFrmType.SetCurSel(0);
	m_ComboSendFrmFmt.SetCurSel(0);
	m_ComboBaud.SetCurSel(0);
	
	m_EditSendFrmID="0000008A";
	m_EditSendData="01 02 03 04 05 06 07 08 ";
	
	UpdateData(false);
	
	return TRUE;  // return TRUE  unless you set the focus to a control
}



void CECanTestDlg::OnButtonConnect() 
{
	// TODO: Add your control notification handler code here
	
	if(m_connect==1)
	{
		m_connect=0;
		Sleep(500);
		GetDlgItem(IDC_BUTTON_CONNECT)->SetWindowText(_T("Connect"));
		CloseDevice(m_devtype,0);
		return;
	}

	INIT_CONFIG init_config;
	int baud;
	
	UpdateData(true);

	baud=m_ComboBaud.GetCurSel();

			init_config.AccCode = 0;
            init_config.AccMask =0xffffff;
            init_config.Filter = 0;

            switch (baud)
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


	if(OpenDevice(m_devtype,0,0)!=STATUS_OK)
	{
		MessageBox(_T("Open device fault!"),_T("Alarm"),MB_OK|MB_ICONQUESTION);
		return;
	}
	ShowInfo("Open device Success",0);

	if(InitCAN(m_devtype,0,0,&init_config)!=STATUS_OK)
	{
		MessageBox(_T("Init can fault!"),_T("Alarm"),MB_OK|MB_ICONQUESTION);
		CloseDevice(m_devtype,0);
		return;
	}

	ShowInfo("Init Success",0);
	
	m_connect=1;
	AfxBeginThread(ReceiveThread,this);

	
	GetDlgItem(IDC_BUTTON_CONNECT)->SetWindowText(_T("Disconnet"));


	//start


	if(m_connect==0)
	{
		MessageBox(_T("Not open device!"),_T("Alarm"),MB_OK|MB_ICONQUESTION);
		return;
	}
	if(StartCAN(m_devtype,0,0)==1)
	{
		ShowInfo("Start Success",0);		
	}
	else
	{
		CString str;
		str="Start Fault";
		ShowInfo(str,2);
	}	



}

void CECanTestDlg::OnButtonStartcan() 
{
	// TODO: Add your control notification handler code here
	if(m_connect==0)
	{
		MessageBox(_T("Not open device!"),_T("Alarm"),MB_OK|MB_ICONQUESTION);
		return;
	}
	if(StartCAN(m_devtype,0,0)==1)
	{
		ShowInfo("Open Success",0);		
	}
	else
	{
		CString str;
		str="Start Fault";
		ShowInfo(str,2);
	}	
}

void CECanTestDlg::OnButtonResetcan() 
{

}

void CECanTestDlg::OnButtonSend() 
{
	// TODO: Add your control notification handler code here
	
	
	/*
	if(m_connect==0)
	{
		MessageBox(_T("Not open device!"),_T("Alarm"),MB_OK|MB_ICONQUESTION);
		return;
	}
	CAN_OBJ frameinfo;
	char szFrameID[9];
	unsigned char FrameID[4]={0,0,0,0};
	memset(szFrameID,'0',9);
	CString sTmp;
	BYTE datalen=0;
	
	UpdateData(true);
	if(m_EditSendFrmID.GetLength()==0||
		(m_EditSendData.GetLength()==0&&m_ComboSendFrmType.GetCurSel()==0))
	{
		ShowInfo("Input data",1);
		return;
	}
	
	if(m_EditSendFrmID.GetLength()>8)
	{
		ShowInfo("ID rang over",1);
		return;
	}
	if(m_EditSendData.GetLength()>24)
	{
		ShowInfo("data over len,max 8 byte",1);
		return;
	}
	if(m_ComboSendFrmType.GetCurSel()==0)
	{
		if(m_EditSendData.GetLength()%3==1)
		{
			ShowInfo("data format fault,please input again",1);
			return;		
		}		
	}

	GetDlgItemText(IDC_EDIT_SENDFRAMEID,m_EditSendFrmID);

	GetDlgItemText(IDC_EDIT_SENDDATA,m_EditSendData);

	int i,k;
	k=0;
	CString cstmp="";
	datalen=(m_EditSendData.GetLength()+1)/3;

	for(i=0;i<m_EditSendData.GetLength();i++)
	{
			
		

		if(m_EditSendData.Mid(i+1,1)!=" ")
			cstmp=cstmp+m_EditSendData.Mid(i+1,1);
		else
		{
			if(cstmp!="")
			{
				frameinfo.Data[k]=(unsigned char)_tcstoul(cstmp,0,16);
				cstmp="";
				k=k+1;
			}
		}

				
	}



	UpdateData(false);
	
	frameinfo.DataLen=k;


	frameinfo.RemoteFlag=m_ComboSendFrmFmt.GetCurSel();
	frameinfo.ExternFlag=m_ComboSendFrmType.GetCurSel();
	if(frameinfo.ExternFlag==1)
	{
		frameinfo.ID=((DWORD)FrameID[0]<<24)+((DWORD)FrameID[1]<<16)+((DWORD)FrameID[2]<<8)+
			((DWORD)FrameID[3]);
	}
	else
	{
		frameinfo.ID=((DWORD)FrameID[2]<<8)+((DWORD)FrameID[3]);		
	}


	frameinfo.ID=_tcstoul(m_EditSendFrmID, 0, 16); 


	
	if(Transmit(m_devtype,0,0,&frameinfo,1)==1)
	{
		ShowInfo("Send success",0);		
	}
	else
	{
		ShowInfo("Send fault",2);		
	}
	
	  */

	if(m_connect==0)
		return;
	CAN_OBJ frameinfo;
	char szFrameID[9];
	unsigned char FrameID[4]={0,0,0,0};
	memset(szFrameID,'0',9);
	unsigned char Data[8];
	char szData[25];
	BYTE datalen=0;
	
	UpdateData(true);
	if(m_EditSendFrmID.GetLength()==0||
		(m_EditSendData.GetLength()==0&&m_ComboSendFrmType.GetCurSel()==0))
	{
		ShowInfo("请输入数据",1);
		return;
	}
	
	if(m_EditSendFrmID.GetLength()>8)
	{
		ShowInfo("ID值超过范围",1);
		return;
	}
	if(m_EditSendData.GetLength()>24)
	{
		ShowInfo("数据长度超过范围,最大为8个字节",1);
		return;
	}
	if(m_ComboSendFrmType.GetCurSel()==0)
	{
		if(m_EditSendData.GetLength()%3==1)
		{
			ShowInfo("数据格式不对,请重新输入",1);
			return;		
		}		
	}
	memcpy(&szFrameID[8-m_EditSendFrmID.GetLength()],(LPCTSTR)m_EditSendFrmID,m_EditSendFrmID.GetLength());
	strtodata((unsigned char*)szFrameID,FrameID,4,0);

	datalen=(m_EditSendData.GetLength()+1)/3;
	strcpy(szData,(LPCTSTR)m_EditSendData);
	strtodata((unsigned char*)szData,Data,datalen,1);


	UpdateData(false);
	
	frameinfo.SendType = 0;
	frameinfo.DataLen=datalen;
	memcpy(&frameinfo.Data,Data,datalen);

	frameinfo.RemoteFlag=m_ComboSendFrmFmt.GetCurSel();
	frameinfo.ExternFlag=m_ComboSendFrmType.GetCurSel();
	if(frameinfo.ExternFlag==1)
	{
		frameinfo.ID=((DWORD)FrameID[0]<<24)+((DWORD)FrameID[1]<<16)+((DWORD)FrameID[2]<<8)+
			((DWORD)FrameID[3]);
	}
	else
	{
		frameinfo.ID=((DWORD)FrameID[2]<<8)+((DWORD)FrameID[3]);		
	}
//	frameinfo.SendType=m_ComboSendType.GetCurSel();

	if(Transmit(m_devtype,0,0,&frameinfo,1)==1)
	{
		ShowInfo("写入成功",0);		
	}
	else
	{
		ShowInfo("写入失败",2);		
	}
}


UINT CECanTestDlg::ReceiveThread(void *param)
{
	CECanTestDlg *dlg=(CECanTestDlg*)param;
	CListBox *box=(CListBox *)dlg->GetDlgItem(IDC_LIST_INFO);
	CAN_OBJ frameinfo[50];

	int len=1;
	int i=0;
	CString str,tmpstr;
	while(1)
	{
		Sleep(1);
		if(dlg->m_connect==0)
			break;
		len=Receive(dlg->m_devtype,0,0,frameinfo,50,100);
		if(len>0)
		{
		
			for(i=0;i<len;i++)
			{
				str="Rec:  ";
				if(frameinfo[i].TimeFlag==0)
					tmpstr="Time:  ";
				else
					tmpstr.Format(_T("Time:%08x "),frameinfo[i].TimeStamp);
				str+=tmpstr;
				tmpstr.Format(_T("ID:%08x "),frameinfo[i].ID);
				str+=tmpstr;
				str+="Format:";
				if(frameinfo[i].RemoteFlag==0)
					tmpstr="Data ";
				else
					tmpstr="Romte ";
				str+=tmpstr;
				str+="Type:";
				if(frameinfo[i].ExternFlag==0)
					tmpstr="Stand ";
				else
					tmpstr="Exten ";
				str+=tmpstr;
				box->InsertString(box->GetCount(),str);
				if(frameinfo[i].RemoteFlag==0)
				{
					str="Data:";
					if(frameinfo[i].DataLen>8)
						frameinfo[i].DataLen=8;
					for(int j=0;j<frameinfo[i].DataLen;j++)
					{
						tmpstr.Format(_T("%02x "),frameinfo[i].Data[j]);
						str+=tmpstr;
					}

					
					box->InsertString(box->GetCount(),str);
					
				}				
			}
			box->SetCurSel(box->GetCount()-1);
		}
	}
	return 0;
}


//-----------------------------------------------------
//参数：
//str：要转换的字符串
//data：储存转换过来的数据串
//len:数据长度
//函数功能：字符串转换为数据串
//-----------------------------------------------------
int CECanTestDlg::strtodata(unsigned char *str, unsigned char *data,int len,int flag)
{
	unsigned char cTmp=0;
	int i=0;
	for(int j=0;j<len;j++)
	{
		if(chartoint(str[i++],&cTmp))
			return 1;
		data[j]=cTmp;
		if(chartoint(str[i++],&cTmp))
			return 1;
		data[j]=(data[j]<<4)+cTmp;
		if(flag==1)
			i++;
	}
	return 0;
}

//-----------------------------------------------------
//参数：
//chr：要转换的字符
//cint：储存转换过来的数据
//函数功能：字符转换为数据
//-----------------------------------------------------
int CECanTestDlg::chartoint(unsigned char chr, unsigned char *cint)
{
	unsigned char cTmp;
	cTmp=chr-48;
	if(cTmp>=0&&cTmp<=9)
	{
		*cint=cTmp;
		return 0;
	}
	cTmp=chr-65;
	if(cTmp>=0&&cTmp<=5)
	{
		*cint=(cTmp+10);
		return 0;
	}
	cTmp=chr-97;
	if(cTmp>=0&&cTmp<=5)
	{
		*cint=(cTmp+10);
		return 0;
	}
	return 1;
}


void CECanTestDlg::ShowInfo(CString str, int code)
{
	m_ListInfo.InsertString(m_ListInfo.GetCount(),str);
	m_ListInfo.SetCurSel(m_ListInfo.GetCount()-1);
}

void CECanTestDlg::OnClose() 
{
	// TODO: Add your message handler code here and/or call default
	CloseDevice(m_devtype,0);

	CDialog::OnClose();
}
