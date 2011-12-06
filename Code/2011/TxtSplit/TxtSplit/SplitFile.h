#pragma once
class CSplitFile
{
public:
	CSplitFile(void);
	~CSplitFile(void);
public:
	HRESULT SplitTxtFile(CString _strTxtFile);
};

