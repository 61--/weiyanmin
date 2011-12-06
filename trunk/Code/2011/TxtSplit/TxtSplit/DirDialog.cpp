///////////////////////////////////////////////////////////////////////////
// DirDialog.cpp: implementation of the CDirDialog class.
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "DirDialog.h"
#include "shlobj.h"

#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif

// Callback function called by SHBrowseForFolder's browse control
// after initialization and when selection changes
int __stdcall CDirDialog::BrowseCtrlCallback(HWND hwnd, UINT uMsg, LPARAM lParam, LPARAM lpData)
{
    CDirDialog* pDirDialogObj = (CDirDialog*)lpData;
    if (uMsg == BFFM_INITIALIZED )
    {
        if( ! pDirDialogObj->m_strSelDir.IsEmpty() )
            ::SendMessage(hwnd, BFFM_SETSELECTION, TRUE, (LPARAM)(LPCTSTR)(pDirDialogObj->m_strSelDir));
        if( ! pDirDialogObj->m_strWindowTitle.IsEmpty() )
            ::SetWindowText(hwnd, (LPCTSTR) pDirDialogObj->m_strWindowTitle);
    }
    else if( uMsg == BFFM_SELCHANGED )
    {
        LPITEMIDLIST pidl = (LPITEMIDLIST) lParam;
        TCHAR selection[MAX_PATH];
        if( ! ::SHGetPathFromIDList(pidl, selection) )
            selection[0] = '\0';

        CString csStatusText;
        BOOL bOk = pDirDialogObj->SelChanged(selection, csStatusText);

        if( pDirDialogObj->m_bStatus )
            ::SendMessage(hwnd, BFFM_SETSTATUSTEXT , 0, (LPARAM)(LPCTSTR)csStatusText);

        ::SendMessage(hwnd, BFFM_ENABLEOK, 0, bOk);
    }
  return 0;
}

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

CDirDialog::CDirDialog()
{
	m_bStatus = FALSE;
	m_strWindowTitle.Empty();
    m_strPath.Empty();
    m_strInitDir.Empty();
    m_strSelDir.Empty();
    m_strTitle.Empty();
    m_iImageIndex = 0;
}

CDirDialog::~CDirDialog()
{
}

BOOL CDirDialog::DoModal(CWnd *pwndParent)
{

    if( ! m_strSelDir.IsEmpty() )
    {
        m_strSelDir.TrimRight();
        if( m_strSelDir.Right(1) == _T("\\") || m_strSelDir.Right(1) == _T("/") )
            m_strSelDir = m_strSelDir.Left(m_strSelDir.GetLength() - 1);
    }

    LPMALLOC pMalloc;
    if (SHGetMalloc (&pMalloc)!= NOERROR)
        return FALSE;

    BROWSEINFO bInfo;
    LPITEMIDLIST pidl;
    ZeroMemory ( (PVOID) &bInfo,sizeof (BROWSEINFO));

    if (!m_strInitDir.IsEmpty ())
    {
        ULONG         chEaten;
        ULONG         dwAttributes;
        HRESULT       hr;
        LPSHELLFOLDER pDesktopFolder;
        //
        // Get a pointer to the Desktop's IShellFolder interface.
        //
        if (SUCCEEDED(SHGetDesktopFolder(&pDesktopFolder)))
        {
            //
            // IShellFolder::ParseDisplayName requires the file name be in Unicode.
            //
#ifdef UNICODE
			hr = pDesktopFolder->ParseDisplayName(NULL,
				NULL,
				m_strInitDir.GetBuffer(MAX_PATH),
				&chEaten,
				&pidl,
				&dwAttributes);
			m_strInitDir.ReleaseBuffer(-1);
#else
			OLECHAR       olePath[MAX_PATH];
            MultiByteToWideChar(CP_ACP, MB_PRECOMPOSED, m_strInitDir.GetBuffer(MAX_PATH), -1,
                                olePath, MAX_PATH);

            m_strInitDir.ReleaseBuffer (-1);
            //
            // Convert the path to an ITEMIDLIST.
            //
            hr = pDesktopFolder->ParseDisplayName(NULL,
                                                NULL,
                                                olePath,
                                                &chEaten,
                                                &pidl,
                                                &dwAttributes);
#endif
            if (FAILED(hr))
            {
                pMalloc ->Free (pidl);
                pMalloc ->Release ();
                return FALSE;
            }
            bInfo.pidlRoot = pidl;

        }
    }
    bInfo.hwndOwner = pwndParent == NULL ? NULL : pwndParent->GetSafeHwnd();
    bInfo.pszDisplayName = m_strPath.GetBuffer (MAX_PATH);
    bInfo.lpszTitle = m_strTitle;
    bInfo.ulFlags = BIF_RETURNFSANCESTORS
                    | BIF_RETURNONLYFSDIRS
                    | (m_bStatus ? BIF_STATUSTEXT : 0);

    bInfo.lpfn = BrowseCtrlCallback;  // address of callback function
    bInfo.lParam = (LPARAM)this;      // pass address of object to callback function

    if ((pidl = ::SHBrowseForFolder(&bInfo)) == NULL)
    {
        return FALSE;
    }
    m_strPath.ReleaseBuffer();
    m_iImageIndex = bInfo.iImage;

    if (::SHGetPathFromIDList(pidl, m_strPath.GetBuffer(MAX_PATH)) == FALSE)
    {
        pMalloc ->Free(pidl);
        pMalloc ->Release();
        return FALSE;
    }

    m_strPath.ReleaseBuffer();

    pMalloc ->Free(pidl);
    pMalloc ->Release();

    return TRUE;
}

void CDirDialog::GetFoldDocCount(const CString& path,int& nCount)
{
	CString strWildcard(path);
	strWildcard += _T("\\*.*");

	CFileFind finder;
	BOOL bWorking = finder.FindFile(strWildcard);
	while (bWorking)
	{
		bWorking = finder.FindNextFile();
		if (finder.IsDots())
			continue;
		if (finder.IsDirectory())  // if it's a directory, recursively search it
		{
			nCount++;
			CString str = finder.GetFilePath();
			GetFoldDocCount(str,nCount);	
		}
		else  //it's a file
		{
			nCount++;
		}
	}
	finder.Close();	
}