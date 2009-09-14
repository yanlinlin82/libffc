// ConsoleDemo.cpp : Defines the entry point for the console application.
//

#include "StdAfx.h"
#include "ConsoleDemo.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif

// The one and only application object

CWinApp theApp;

using namespace std;

int _tmain(int /*argc*/, TCHAR* /*argv*/[], TCHAR* /*envp*/[])
{
	int nRetCode = 0;

	// initialize MFC and print and error on failure
	if (!AfxWinInit(::GetModuleHandle(NULL), NULL, ::GetCommandLine(), 0))
	{
		_tprintf(_T("Fatal Error: FFC initialization failed\n"));
		nRetCode = 1;
	}
	else
	{
		CString text;
		text.LoadString(IDS_APP_TITLE);
		_tprintf(_T("%s\n"), (LPCTSTR)text);
	}

	return nRetCode;
}

