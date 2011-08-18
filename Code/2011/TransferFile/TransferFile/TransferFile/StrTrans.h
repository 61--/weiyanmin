#pragma once
class CStrTrans
{
public:
	CStrTrans(void);
	~CStrTrans(void);
public:
	CString TransToString(CString _str);
	CString TransToCode(CString _strCode);
};

