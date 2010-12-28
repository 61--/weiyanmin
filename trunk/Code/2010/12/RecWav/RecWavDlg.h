// RecWavDlg.h : header file
//

#if !defined(AFX_RECWAVDLG_H__3A975674_72EC_4CA8_AE5B_6B620673B054__INCLUDED_)
#define AFX_RECWAVDLG_H__3A975674_72EC_4CA8_AE5B_6B620673B054__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

/////////////////////////////////////////////////////////////////////////////
// CRecWavDlg dialog

class CRecWavDlg : public CDialog
{
// Construction
public:
	CRecWavDlg(CWnd* pParent = NULL);	// standard constructor

// Dialog Data
	//{{AFX_DATA(CRecWavDlg)
	enum { IDD = IDD_RECWAV_DIALOG };
		// NOTE: the ClassWizard will add data members here
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CRecWavDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	//{{AFX_MSG(CRecWavDlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	afx_msg void OnButtonInit();
	afx_msg void OnButtonRec();
	afx_msg void OnButtonStop();
	afx_msg void OnButtonPlay();
	afx_msg void OnButtonSave();
	afx_msg void OnButtonOpen();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
private:
	HWND m_hWndMCIWnd;
	long m_Int;
	CString m_strFile;
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_RECWAVDLG_H__3A975674_72EC_4CA8_AE5B_6B620673B054__INCLUDED_)
