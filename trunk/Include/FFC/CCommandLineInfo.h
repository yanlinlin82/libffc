// CCommandLineInfo.h
#ifndef __FFC_CCOMMANDLINEINFO_H__
#define __FFC_CCOMMANDLINEINFO_H__
///////////////////////////////////////////////////////////////////////////

#include "CObject.h"

///////////////////////////////////////////////////////////////////////////

enum
{
	FileNew,
	FileOpen,
	FilePrint,
	FilePrintTo,
	FileDDE,
};

///////////////////////////////////////////////////////////////////////////

class CCommandLineInfo : public CObject
{
public:
	CCommandLineInfo()
		: m_bRunAutomated(FALSE)
		, m_bRunEmbeded(FALSE)
		, m_bShowSplash(TRUE)
		, m_nShellCommand(FileNew)
	{ }

public:
	virtual void ParseParam(const char* /*pszParam*/, BOOL /*bFlag*/, BOOL /*bLast*/) { }
	virtual void ParseParam(const WCHAR* /*pszParam*/, BOOL /*bFlag*/, BOOL /*bLast*/) { }

public:
	BOOL    m_bRunAutomated;  // Indicates the command-line /Automation option was found.
	BOOL    m_bRunEmbeded;    // Indicates the command-line /Embedding option was found.
	BOOL    m_bShowSplash;    // Indicates if a splash screen should be shown.
	UINT    m_nShellCommand;  // Indicates the shell command to be processed.
	CString m_strDriverName;  // Indicates the driver name if the shell command is Print To; otherwise empty.
	CString m_strFileName;    // Indicates the filename to be opened or printed; empty if the shell command is New or DDE.
	CString m_strPortName;    // Indicates the port name if the shell command is Print To; otherwise empty.
	CString m_strPrinterName; // Indicates the printer name if the shell command is Print To; otherwise empty.
};

///////////////////////////////////////////////////////////////////////////
#endif//__FFC_CCOMMANDLINEINFO_H__

