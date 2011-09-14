// Transfer.h : main header file for the TRANSFER application
//

#if !defined(AFX_TRANSFER_H__1A1F3A91_9466_4649_A1FB_AC2F22203A65__INCLUDED_)
#define AFX_TRANSFER_H__1A1F3A91_9466_4649_A1FB_AC2F22203A65__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"		// main symbols

/////////////////////////////////////////////////////////////////////////////
// CTransferApp:
// See Transfer.cpp for the implementation of this class
//

class CTransferApp : public CWinApp
{
public:
	CTransferApp();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CTransferApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation

	//{{AFX_MSG(CTransferApp)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_TRANSFER_H__1A1F3A91_9466_4649_A1FB_AC2F22203A65__INCLUDED_)
