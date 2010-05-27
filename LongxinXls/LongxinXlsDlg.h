// LongxinXlsDlg.h : header file
//

#if !defined(AFX_LONGXINXLSDLG_H__5EEF0583_5ABD_423E_9CC2_B963BDC6A6B4__INCLUDED_)
#define AFX_LONGXINXLSDLG_H__5EEF0583_5ABD_423E_9CC2_B963BDC6A6B4__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

/////////////////////////////////////////////////////////////////////////////
// CLongxinXlsDlg dialog

class _Worksheet;
class CLongxinXlsDlg : public CDialog
{
// Construction
public:
	CLongxinXlsDlg(CWnd* pParent = NULL);	// standard constructor

// Dialog Data
	//{{AFX_DATA(CLongxinXlsDlg)
	enum { IDD = IDD_LONGXINXLS_DIALOG };
	CString	m_strXlsFile;
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CLongxinXlsDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	//{{AFX_MSG(CLongxinXlsDlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	afx_msg void OnButtonSelFile();
	afx_msg void OnButtonStart();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
private:
	HRESULT SetRangeVal(_Worksheet& workSheet,CString _strLocation);
	HRESULT InitMinMax();//初始化最小和最大值
private:
	int m_nMin,m_nMax;
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_LONGXINXLSDLG_H__5EEF0583_5ABD_423E_9CC2_B963BDC6A6B4__INCLUDED_)
