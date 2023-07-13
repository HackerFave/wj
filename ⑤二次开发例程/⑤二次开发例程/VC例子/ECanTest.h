// ECanTest.h : main header file for the ECANTEST application
//

#if !defined(AFX_ECANTEST_H__81513902_37A3_4D18_8DC2_196012723BCD__INCLUDED_)
#define AFX_ECANTEST_H__81513902_37A3_4D18_8DC2_196012723BCD__INCLUDED_

#if _MSC_VER >= 1000
#pragma once
#endif // _MSC_VER >= 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"		// main symbols

/////////////////////////////////////////////////////////////////////////////
// CECanTestApp:
// See ECanTest.cpp for the implementation of this class
//

class CECanTestApp : public CWinApp
{
public:
	CECanTestApp();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CECanTestApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation

	//{{AFX_MSG(CECanTestApp)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft eMbedded Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_ECANTEST_H__81513902_37A3_4D18_8DC2_196012723BCD__INCLUDED_)
