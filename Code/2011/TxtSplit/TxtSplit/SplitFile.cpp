#include "StdAfx.h"
#include "SplitFile.h"
#include "DataHandler.h"


CSplitFile::CSplitFile(void)
{
}


CSplitFile::~CSplitFile(void)
{
}

HRESULT CSplitFile::SplitTxtFile(CString _strTxtFile)
{
	HRESULT hr = E_FAIL;
	CString strPath = _strTxtFile.Left(_strTxtFile.ReverseFind(_T('\\')) + 1);
	CStdioFile file(_strTxtFile,CFile::modeRead);
	CString strTxt;
	BOOL bIsOutput = FALSE;
	CStdioFile* pFileOut = NULL;
	while(file.ReadString(strTxt))
	{
		TRACE(strTxt);
		strTxt.Trim();
		if(strTxt.GetLength() == 9)
		{
			CStringArray arrStr;
			CDataHandler::SplitString(strTxt,_T('.'),arrStr);
			if(arrStr.GetCount() == 2)
			{
				//011009.01
				if(arrStr.GetAt(0).GetLength() == 6 && arrStr.GetAt(1).GetLength() == 2)
				{
					bIsOutput = TRUE;
					CString strOutFileName = strPath + strTxt;
					strOutFileName += _T(".txt");
					if(pFileOut != NULL)
					{
						//pFileOut->Flush();
						pFileOut->Close();
						delete pFileOut;
						pFileOut = NULL;
					}
					pFileOut = new CStdioFile(strOutFileName,CFile::modeCreate|CFile::typeText|CFile::modeWrite);
				}

			}
		}
		if(bIsOutput && pFileOut)
		{
			pFileOut->WriteString(strTxt);
			pFileOut->WriteString(_T("\n"));
		}
	}
	if(pFileOut != NULL && bIsOutput)
	{
		//	pFileOut->Flush();
		pFileOut->Close();
		delete pFileOut;
		pFileOut = NULL;
	}
	file.Close();
	return S_OK;
}