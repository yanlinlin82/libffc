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

CWinApp::~CWinApp()
{
	for (size_t i = 0; i < m_DocTemplateList.size(); i++)
	{
		delete m_DocTemplateList[i];
	}
	m_DocTemplateList.clear();
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

void CWinApp::AddDocTemplate(CDocTemplate* pTemplate)
{
	m_DocTemplateList.push_back(pTemplate);
}

void CWinApp::ParseCommandLine(CCommandLineInfo& /*rCmdInfo*/)
{
}

BOOL CWinApp::ProcessShellCommand(CCommandLineInfo& /*rCmdInfo*/)
{
	if (m_DocTemplateList.empty())
	{
		return FALSE;
	}

	CDocTemplate* pDocTemplate = m_DocTemplateList.front();
	
	TRACE("Create Doc: %p\n", pDocTemplate->m_pDocClass);
	CDocument* pDoc = pDocTemplate->CreateNewDocument();
	
	pDocTemplate->CreateNewFrame(pDoc, NULL);
	return TRUE;
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

