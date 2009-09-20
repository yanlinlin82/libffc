// CWinApp.h
#ifndef __FFC_CWINAPP_H__
#define __FFC_CWINAPP_H__
///////////////////////////////////////////////////////////////////////////

#include "CWinThread.h"
#include "CDocTemplate.h"
#include "CCommandLineInfo.h"
#include <vector>

///////////////////////////////////////////////////////////////////////////

#ifndef _AFX_MRU_COUNT
#define _AFX_MRU_COUNT 4
#endif

///////////////////////////////////////////////////////////////////////////

class CWinApp : public CWinThread
{
public:
	CWinApp();
	~CWinApp();

public:
	virtual BOOL InitInstance();
	virtual int Run();
	virtual void ExitInstance();

public:
	void SetRegistryKey(LPCTSTR lpszRegistryKey);
	void SetRegistryKey(UINT nIDRegistryKey);

	void LoadStdProfileSettings(UINT nMaxMRU = _AFX_MRU_COUNT);

	HICON LoadIcon(LPCTSTR lpszResourceName) const;
	HICON LoadIcon(UINT nIDResource) const;

	void AddDocTemplate(CDocTemplate* pTemplate);
	void ParseCommandLine(CCommandLineInfo& rCmdInfo);
	BOOL ProcessShellCommand(CCommandLineInfo& rCmdInfo);

public:
	DECLARE_MESSAGE_MAP()

protected:
	afx_msg void OnFileNew();
	afx_msg void OnFileOpen();
	afx_msg void OnFileSave();
	afx_msg void OnFileSaveAs();
	afx_msg void OnFilePrintSetup();
	afx_msg void OnFilePrint();
	afx_msg void OnHelp();

public:
	CWnd* m_pMainWnd;
	int   m_nCmdShow;
	std::vector<CDocTemplate*> m_DocTemplateList;
};

///////////////////////////////////////////////////////////////////////////

CWinApp* AFXAPI AfxGetApp();

///////////////////////////////////////////////////////////////////////////
#endif//__FFC_CWINAPP_H__

