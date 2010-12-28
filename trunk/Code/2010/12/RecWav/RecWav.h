// RecWav.h : main header file for the RECWAV application
//

#if !defined(AFX_RECWAV_H__51BB2754_7531_433A_BCBF_539C918996D4__INCLUDED_)
#define AFX_RECWAV_H__51BB2754_7531_433A_BCBF_539C918996D4__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"		// main symbols

/////////////////////////////////////////////////////////////////////////////
// CRecWavApp:
// See RecWav.cpp for the implementation of this class
//

class CRecWavApp : public CWinApp
{
public:
	CRecWavApp();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CRecWavApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation

	//{{AFX_MSG(CRecWavApp)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_RECWAV_H__51BB2754_7531_433A_BCBF_539C918996D4__INCLUDED_)
