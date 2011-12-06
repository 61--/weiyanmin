////////////////////////////////////////////////////////////////////////
// DirDialog.h: interface for the CDirDialog class.
//////////////////////////////////////////////////////////////////////
#pragma once


class    CDirDialog
{
public:

    CDirDialog();
    virtual ~CDirDialog();

    BOOL DoModal(CWnd *pwndParent = NULL);

	void SetWindowTitle(CString title){m_strWindowTitle = title;}
	void SetTitle(CString title){m_strTitle = title;}
	void SetSelDir(CString Dir){m_strSelDir = Dir;}
	void SetRootDir(CString Dir){m_strInitDir = Dir;}

	CString GetWindowText(){return m_strWindowTitle;}
	CString GetTitle(){return m_strTitle;}
	CString GetPathname(){return m_strPath;}

	static void GetFoldDocCount(const CString& path,int& nCount);
protected:
    CString m_strWindowTitle;
    CString m_strPath;
    CString m_strInitDir;
    CString m_strSelDir;
    CString m_strTitle;
    int  m_iImageIndex;
    BOOL m_bStatus;

private:

    virtual BOOL SelChanged(LPCTSTR lpcsSelection, CString& csStatusText) { return TRUE; };
    static int __stdcall CDirDialog::BrowseCtrlCallback(HWND hwnd, UINT uMsg, LPARAM lParam, LPARAM lpData);
};
