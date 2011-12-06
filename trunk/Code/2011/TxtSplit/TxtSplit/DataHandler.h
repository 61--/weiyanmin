#pragma once


class  CDataHandler
{
public:
	CDataHandler(void);
	virtual ~CDataHandler(void);

	//variant to long transform
	static long VariantToLong(const CComVariant &var);
	static BOOL VariantToBool(const CComVariant &var);
	//variant to string transform
	static CString VariantToString(const CComVariant &var);
	//string to variant transform
	static BOOL StringToVariant(/*[in]*/const CString& str,/*[in]*/VARTYPE vt,/*[out]*/VARIANT* var);
	static int StringToInt(/*[in]*/const CString& str);
	static BOOL OleDateTimeToVariant(const COleDateTime& dt,VARIANT* _val);

	// BSTR比较
	static int BSTRCompare(BSTR strA, BSTR strB, BOOL bCaseSens = FALSE);

	//拆分字符串 split_char为分割字符
	static void SplitString(const CString& str,TCHAR split_char,CStringArray& arr);
	static void TrimString(CString& str);
	static void TrimStringAll(CString& str);

	//void ClearGlobalParam(GLOBALPARAM& the_prop);
	static BOOL ToValidXmlString(CString& cValue);// 转换xml 中的字符串的特殊符号.
	//static BOOL VarTypeToDBType(VARIANT* var,ADODB::DataTypeEnum& type,int& size);
	static CString LoadString(UINT nID);

	static CString    DectoHexstr(int iDec);
	static CString    FormatLength(CString strHexMaclength);
	static CString    FormatNO(CString strNO);
	static TCHAR	   ConvertHexData(TCHAR ch);
	static int		   String2Hex(CString str, char *SendOut);
	//将时间转换为字符形式
	//_iType = 0:日期时间都转换 _iType = 1:只转换日期　_iType＝2:只转换时间
	static CString   DateTimeToStr(COleDateTime dt,int _iType);
	static BOOL		 StringIsDigit(CString _str);//判断字符串是否为数值
};
