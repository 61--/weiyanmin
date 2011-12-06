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

	// BSTR�Ƚ�
	static int BSTRCompare(BSTR strA, BSTR strB, BOOL bCaseSens = FALSE);

	//����ַ��� split_charΪ�ָ��ַ�
	static void SplitString(const CString& str,TCHAR split_char,CStringArray& arr);
	static void TrimString(CString& str);
	static void TrimStringAll(CString& str);

	//void ClearGlobalParam(GLOBALPARAM& the_prop);
	static BOOL ToValidXmlString(CString& cValue);// ת��xml �е��ַ������������.
	//static BOOL VarTypeToDBType(VARIANT* var,ADODB::DataTypeEnum& type,int& size);
	static CString LoadString(UINT nID);

	static CString    DectoHexstr(int iDec);
	static CString    FormatLength(CString strHexMaclength);
	static CString    FormatNO(CString strNO);
	static TCHAR	   ConvertHexData(TCHAR ch);
	static int		   String2Hex(CString str, char *SendOut);
	//��ʱ��ת��Ϊ�ַ���ʽ
	//_iType = 0:����ʱ�䶼ת�� _iType = 1:ֻת�����ڡ�_iType��2:ֻת��ʱ��
	static CString   DateTimeToStr(COleDateTime dt,int _iType);
	static BOOL		 StringIsDigit(CString _str);//�ж��ַ����Ƿ�Ϊ��ֵ
};
