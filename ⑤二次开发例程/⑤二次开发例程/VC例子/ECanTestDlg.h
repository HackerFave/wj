// ECanTestDlg.h : header file
//

#if !defined(AFX_ECANTESTDLG_H__3DCE6D96_0B95_4875_A915_D7FF433C6E07__INCLUDED_)
#define AFX_ECANTESTDLG_H__3DCE6D96_0B95_4875_A915_D7FF433C6E07__INCLUDED_

#if _MSC_VER >= 1000
#pragma once
#endif // _MSC_VER >= 1000

/////////////////////////////////////////////////////////////////////////////
// CECanTestDlg dialog


/*
1000
800
666
500
400
250
200
125
100
80
50

*/

class CECanTestDlg : public CDialog
{
// Construction
public:
	CECanTestDlg(CWnd* pParent = NULL);	// standard constructor


	int m_devtype;
	static UINT ReceiveThread(void *param);
	int m_connect;

	void ShowInfo(CString str, int code);
	int strtodata(unsigned char *str, unsigned char *data,int len,int flag);
	int chartoint(unsigned char chr, unsigned char *cint);

// Dialog Data
	//{{AFX_DATA(CECanTestDlg)
	enum { IDD = IDD_ECANTEST_DIALOG };
	CComboBox	m_ComboSendFrmFmt;
	CComboBox	m_ComboSendFrmType;
	CListBox	m_ListInfo;
	CComboBox	m_ComboBaud;
	CString	m_EditSendData;
	CString	m_EditSendFrmID;
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CECanTestDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	//{{AFX_MSG(CECanTestDlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnButtonConnect();
	afx_msg void OnButtonStartcan();
	afx_msg void OnButtonResetcan();
	afx_msg void OnButtonSend();
	afx_msg void OnClose();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft eMbedded Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_ECANTESTDLG_H__3DCE6D96_0B95_4875_A915_D7FF433C6E07__INCLUDED_)
