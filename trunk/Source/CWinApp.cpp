// WinApp.cpp

#include "../Include/afxwin.h"

///////////////////////////////////////////////////////////////////////////

CWinApp* g_pApp = NULL;

///////////////////////////////////////////////////////////////////////////

CWinApp* AfxGetApp()
{
	return g_pApp;
}

///////////////////////////////////////////////////////////////////////////

CWinApp::CWinApp()
	: m_pMainWnd(NULL)
	, m_nCmdShow(SW_SHOW)
{
	g_pApp = this;
}

BOOL CWinApp::InitInstance()
{
	return TRUE;
}

int CWinApp::Run()
{
	if ( ! m_pMainWnd) return 1;

	MSG msg;
	while (::GetMessage(&msg, NULL, 0, 0))
	{
		::TranslateMessage(&msg);
		::DispatchMessage(&msg);
	}
	return msg.wParam;
}

void CWinApp::ExitInstance()
{
}

///////////////////////////////////////////////////////////////////////////

void CWinApp::SetRegistryKey(LPCTSTR /*lpszRegistryKey*/)
{
}

void CWinApp::SetRegistryKey(UINT /*nIDRegistryKey*/)
{
}

void CWinApp::LoadStdProfileSettings(UINT /*nMaxMRU*/)
{
}

HICON CWinApp::LoadIcon(LPCTSTR lpszResourceName) const
{
	return ::LoadIcon(AfxGetResourceHandle(), lpszResourceName);
}

HICON CWinApp::LoadIcon(UINT nIDResource) const
{
	return ::LoadIcon(AfxGetResourceHandle(), MAKEINTRESOURCE(nIDResource));
}

void CWinApp::AddDocTemplate(CDocTemplate* /*pTemplate*/)
{
}

void CWinApp::ParseCommandLine(CCommandLineInfo& /*rCmdInfo*/)
{
}

BOOL CWinApp::ProcessShellCommand(CCommandLineInfo& /*rCmdInfo*/)
{
	return FALSE;
}

///////////////////////////////////////////////////////////////////////////

BEGIN_MESSAGE_MAP(CWinApp, CCmdTarget)
	ON_COMMAND(ID_FILE_NEW, OnFileNew)
	ON_COMMAND(ID_FILE_OPEN, OnFileOpen)
	ON_COMMAND(ID_FILE_SAVE, OnFileSave)
	ON_COMMAND(ID_FILE_SAVE_AS, OnFileSaveAs)
	ON_COMMAND(ID_FILE_PRINT_SETUP, OnFilePrintSetup)
	ON_COMMAND(ID_FILE_PRINT, OnFilePrint)
	ON_COMMAND(ID_HELP, OnHelp)
END_MESSAGE_MAP()

void CWinApp::OnFileNew()
{
}

void CWinApp::OnFileOpen()
{
}

void CWinApp::OnFileSave()
{
}

void CWinApp::OnFileSaveAs()
{
}

void CWinApp::OnFilePrintSetup()
{
}

void CWinApp::OnFilePrint()
{
}

void CWinApp::OnHelp()
{
}

///////////////////////////////////////////////////////////////////////////

