// LongxinXls.h : main header file for the LONGXINXLS application
//

#if !defined(AFX_LONGXINXLS_H__F69D4FA5_9900_43A6_9C2D_2A13EEB8CB4B__INCLUDED_)
#define AFX_LONGXINXLS_H__F69D4FA5_9900_43A6_9C2D_2A13EEB8CB4B__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"		// main symbols
#include "LongxinXls_i.h"

/////////////////////////////////////////////////////////////////////////////
// CLongxinXlsApp:
// See LongxinXls.cpp for the implementation of this class
//

class CLongxinXlsApp : public CWinApp
{
public:
	CLongxinXlsApp();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CLongxinXlsApp)
	public:
	virtual BOOL InitInstance();
		virtual int ExitInstance();
	//}}AFX_VIRTUAL

// Implementation

	//{{AFX_MSG(CLongxinXlsApp)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
private:
	BOOL m_bATLInited;
private:
	BOOL InitATL();
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_LONGXINXLS_H__F69D4FA5_9900_43A6_9C2D_2A13EEB8CB4B__INCLUDED_)
