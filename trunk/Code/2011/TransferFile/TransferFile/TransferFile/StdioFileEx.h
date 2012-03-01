// StdioFileEx.h: interface for the CStdioFileEx class.
//
// Version 1.1 23 August 2003.	Incorporated fixes from Dennis Jeryd.
// Version 1.3 19 February 2005. Incorporated fixes from Howard J Oh and some of my own.
// Version 1.4 26 February 2005. Fixed stupid screw-up in code from 1.3.
// Version 1.5 18 November 2005. - Incorporated fixes from Andy Goodwin.
//											- Allows code page to be specified for reading/writing
//											- Properly calculates multibyte buffer size instead of
//												assuming lstrlen(s).
//											- Should handle UTF8 properly.
//
// Copyright David Pritchard 2003-2005. davidpritchard@ctv.es
//
// You can use this class freely, but please keep my ego happy 
// by leaving this comment in place.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_STDIOFILEEX_H__41AFE3CA_25E0_482F_8B00_C40775BCDB81__INCLUDED_)
#define AFX_STDIOFILEEX_H__41AFE3CA_25E0_482F_8B00_C40775BCDB81__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#define	nUNICODE_BOM						0xFEFF		// Unicode "byte order mark" which goes at start of file
#define	sNEWLINE								_T("\r\n")	// New line characters
#define	sDEFAULT_UNICODE_FILLER_CHAR	"#"			// Filler char used when no conversion from Unicode to local code page is possible

class  CStdioFileEx: public CStdioFile
{
public:
	CStdioFileEx();
	CStdioFileEx( LPCTSTR lpszFileName, UINT nOpenFlags );

	virtual BOOL	Open( LPCTSTR lpszFileName, UINT nOpenFlags, CFileException* pError = NULL );
	virtual BOOL	ReadString(CString& rString);
	virtual void	WriteString( LPCTSTR lpsz );
	bool				IsFileUnicodeText()	{ return m_bIsUnicodeText; }	
	unsigned long	GetCharCount();

	// Additional flag to allow Unicode text writing
	static const UINT modeWriteUnicode;

	void				SetCodePage(IN const UINT nCodePage);

	// static utility functions

	// --------------------------------------------------------------------------------------------
	//
	//	CStdioFileEx::GetUnicodeStringFromMultiByteString()
	//
	// --------------------------------------------------------------------------------------------
	// Returns:    int - num. of chars written (0 means error)
	// Parameters: char *		szMultiByteString		(IN)		Multi-byte input string
	//					wchar_t*		szUnicodeString		(OUT)		Unicode outputstring
	//					int			nUnicodeBufferSize	(IN)		Size of Unicode output buffer (chars) (IN)
	//					int			nCodePage				(IN)		Code page used to perform conversion
	//																			Default = -1 (Get local code page).
	//
	// Purpose:		Gets a Unicode string from a MultiByte string.
	// Notes:		None.
	// Exceptions:	None.
	//
	static int		GetUnicodeStringFromMultiByteString(IN LPCSTR szMultiByteString, OUT wchar_t* szUnicodeString, IN int nUnicodeBufferSize, IN int nCodePage=-1);

	// --------------------------------------------------------------------------------------------
	//
	//	CStdioFileEx::GetMultiByteStringFromUnicodeString()
	//
	// --------------------------------------------------------------------------------------------
	// Returns:    int - number of characters written. 0 means error
	// Parameters: wchar_t *	szUnicodeString			(IN)	Unicode input string
	//					char*			szMultiByteString			(OUT)	Multibyte output string
	//					int			nMultiByteBufferSize		(IN)	Multibyte buffer size
	//					int			nCodePage					(IN)	Code page used to perform conversion
	//																			Default = -1 (Get local code page).
	//
	// Purpose:		Gets a MultiByte string from a Unicode string.
	// Notes:		.
	// Exceptions:	None.
	//
	static int			GetMultiByteStringFromUnicodeString(wchar_t * szUnicodeString,char* szMultiByteString,
																			int nMultiByteBufferSize,int nCodePage=-1);

	//---------------------------------------------------------------------------------------------------
	//
	//	CStdioFileEx::GetRequiredMultiByteLengthForUnicodeString()
	//
	//---------------------------------------------------------------------------------------------------
	// Returns:    int
	// Parameters: wchar_t * szUnicodeString,int nCodePage=-1
	//
	// Purpose:		Obtains the multi-byte buffer size needed to accommodate a converted Unicode string.
	//	Notes:		We can't assume that the buffer length is simply equal to the number of characters
	//					because that wouldn't accommodate multibyte characters!
	//
	static int			GetRequiredMultiByteLengthForUnicodeString(wchar_t * szUnicodeString,int nCodePage=-1);


	// --------------------------------------------------------------------------------------------
	//
	//	CStdioFileEx::IsFileUnicode()
	//
	// --------------------------------------------------------------------------------------------
	// Returns:    bool
	// Parameters: const CString& sFilePath
	//
	// Purpose:		Determines whether a file is Unicode by reading the first character and detecting
	//					whether it's the Unicode byte marker.
	// Notes:		None.
	// Exceptions:	None.
	//
	static bool IsFileUnicode(const CString& sFilePath);

	static UINT	GetCurrentLocaleCodePage();

protected:
	UINT	ProcessFlags(const CString& sFilePath, UINT& nOpenFlags);

	bool		m_bIsUnicodeText;
	UINT		m_nFlags;
	int		m_nFileCodePage;
};

#endif // !defined(AFX_STDIOFILEEX_H__41AFE3CA_25E0_482F_8B00_C40775BCDB81__INCLUDED_)
