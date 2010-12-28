// MCIControl.h: interface for the CMCIControl class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_MCICONTROL_H__F525E157_77D9_42C0_9575_7E73DC920CC1__INCLUDED_)
#define AFX_MCICONTROL_H__F525E157_77D9_42C0_9575_7E73DC920CC1__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

class CMCIControl  
{
public:
	CMCIControl();
	virtual ~CMCIControl();
public:
	HRESULT OpenFile(BSTR _bstrFile);
private:
	HWND m_hWndMCIWnd;
	HRESULT Close();
	HRESULT Init(CString _strFile);
};

#endif // !defined(AFX_MCICONTROL_H__F525E157_77D9_42C0_9575_7E73DC920CC1__INCLUDED_)
