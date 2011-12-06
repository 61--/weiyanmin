
// TxtSplitDlg.cpp : implementation file
//

#include "stdafx.h"
#include "TxtSplit.h"
#include "TxtSplitDlg.h"
#include "afxdialogex.h"
#include "DataHandler.h"
#include "SplitFile.h"
#include "DirDialog.h"


#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CAboutDlg dialog used for App About

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

// Dialog Data
	enum { IDD = IDD_ABOUTBOX };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

// Implementation
protected:
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialogEx(CAboutDlg::IDD)
{
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialogEx)
END_MESSAGE_MAP()


// CTxtSplitDlg dialog




CTxtSplitDlg::CTxtSplitDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(CTxtSplitDlg::IDD, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CTxtSplitDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CTxtSplitDlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_BUTTON_SPLIT_TXT, &CTxtSplitDlg::OnBnClickedButtonSplitTxt)
	ON_BN_CLICKED(IDC_BUTTON_SPLIT_DIR_TXT, &CTxtSplitDlg::OnBnClickedButtonSplitDirTxt)
END_MESSAGE_MAP()


// CTxtSplitDlg message handlers

BOOL CTxtSplitDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// Add "About..." menu item to system menu.

	// IDM_ABOUTBOX must be in the system command range.
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != NULL)
	{
		BOOL bNameValid;
		CString strAboutMenu;
		bNameValid = strAboutMenu.LoadString(IDS_ABOUTBOX);
		ASSERT(bNameValid);
		if (!strAboutMenu.IsEmpty())
		{
			pSysMenu->AppendMenu(MF_SEPARATOR);
			pSysMenu->AppendMenu(MF_STRING, IDM_ABOUTBOX, strAboutMenu);
		}
	}

	// Set the icon for this dialog.  The framework does this automatically
	//  when the application's main window is not a dialog
	SetIcon(m_hIcon, TRUE);			// Set big icon
	SetIcon(m_hIcon, FALSE);		// Set small icon

	// TODO: Add extra initialization here

	return TRUE;  // return TRUE  unless you set the focus to a control
}

void CTxtSplitDlg::OnSysCommand(UINT nID, LPARAM lParam)
{
	if ((nID & 0xFFF0) == IDM_ABOUTBOX)
	{
		CAboutDlg dlgAbout;
		dlgAbout.DoModal();
	}
	else
	{
		CDialogEx::OnSysCommand(nID, lParam);
	}
}

// If you add a minimize button to your dialog, you will need the code below
//  to draw the icon.  For MFC applications using the document/view model,
//  this is automatically done for you by the framework.

void CTxtSplitDlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // device context for painting

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// Center icon in client rectangle
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// Draw the icon
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialogEx::OnPaint();
	}
}

// The system calls this function to obtain the cursor to display while the user drags
//  the minimized window.
HCURSOR CTxtSplitDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}



void CTxtSplitDlg::OnBnClickedButtonSplitTxt()
{
	// TODO: Add your control notification handler code here
	CFileDialog dlg(TRUE);
	if(dlg.DoModal() != IDOK)
	{
		return ;
	}
	CString strFileName = dlg.GetPathName();
	CSplitFile SplitFile;
	HRESULT hr = E_FAIL;
	hr = SplitFile.SplitTxtFile(strFileName);
	if(FAILED(hr))
	{
		CString strMsg;
		strMsg.Format(_T("分割文件%s出错!"),strFileName);
		AfxMessageBox(strMsg);
		return ;
	}
	AfxMessageBox(_T("文本文件分割成功！"));
}


void CTxtSplitDlg::OnBnClickedButtonSplitDirTxt()
{
	// TODO: Add your control notification handler code here
	CDirDialog dlg;
	if(dlg.DoModal(this) != IDOK)
	{
		return;
	
	}
	CFileFind find;
	CString logpath = dlg.GetPathname();
	std::list<CString> lstFileName;
	CString strExt = _T("Txt");
	ReuseGetFileName(logpath,strExt,lstFileName);
	HRESULT hr = E_FAIL;
	CSplitFile SplitFile;
	for(auto itr = lstFileName.begin();itr != lstFileName.end();++itr)
	{				
		hr = SplitFile.SplitTxtFile(*itr);
		if(FAILED(hr))
		{
			CString strMsg;
			strMsg.Format(_T("分割文件%s出错!"),*itr);
			AfxMessageBox(strMsg);
			return ;
		}
	}
	AfxMessageBox(_T("文件夹下文本文件分割成功！"));
}

void CTxtSplitDlg::ReuseGetFileName(CString _strPath,CString& _strExt,std::list<CString> &_lstFileName)
{
	CString strPath = _strPath;
	if(strPath.Right(1) != _T("\\"))
	{
		strPath += _T("\\");
	}
	strPath += _T("*.*");
	BOOL bChangeDir = FALSE;
	CFileFind finder;
	BOOL bWorking = finder.FindFile(strPath);
	while (bWorking)
	{
		bWorking = finder.FindNextFile();
		if (finder.IsDots())
			continue;
		else if (finder.IsDirectory())
		{
			CString sTemp = finder.GetFilePath();
			ReuseGetFileName(sTemp,_strExt,_lstFileName);
		}
		else
		{
			CString sTemp = finder.GetFilePath();
			int nPos = sTemp.ReverseFind(_T('.'));
			if(nPos != -1 )
			{
				CString strExt = sTemp.Right(sTemp.GetLength()-nPos-1);
				if(strExt.Compare(strExt) == 0)
				{
					_lstFileName.push_back(sTemp);
				}
			}
			
		}
	}

	finder.Close();
}