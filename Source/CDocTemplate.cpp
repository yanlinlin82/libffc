// CDocTemplate.cpp

#include "../Include/afxwin.h"
#include "../Include/FFC/CWinApp.h"
#include "../Include/FFC/CFrameWnd.h"

///////////////////////////////////////////////////////////////////////////

CDocTemplate::CDocTemplate(
	UINT nIDResource,
	CRuntimeClass* pDocClass,
	CRuntimeClass* pFrameClass,
	CRuntimeClass* pViewClass)
	: m_nIDResource(nIDResource)
	, m_pDocClass(pDocClass)
	, m_pFrameClass(pFrameClass)
	, m_pViewClass(pViewClass)
{
}

CDocument* CDocTemplate::CreateNewDocument()
{
	ASSERT(m_pDocClass->IsDerivedFrom(RUNTIME_CLASS(CDocument)));

	return static_cast<CDocument*>(m_pDocClass->CreateObject());
}

CFrameWnd* CDocTemplate::CreateNewFrame(CDocument* pDoc, CFrameWnd* /*pOther*/)
{
	ASSERT(m_pFrameClass->IsDerivedFrom(RUNTIME_CLASS(CFrameWnd)));
	ASSERT(m_pViewClass->IsDerivedFrom(RUNTIME_CLASS(CView)));

	TRACE("Create Frame: %s\n", m_pFrameClass->m_lpszClassName);
	CFrameWnd* pFrameWnd = static_cast<CFrameWnd*>(m_pFrameClass->CreateObject());
	if ( ! pFrameWnd)
	{
		return NULL;
	}

	if ( ! pFrameWnd->LoadFrame(m_nIDResource))
	{
		delete pFrameWnd;
		return NULL;
	}

	CCreateContext cc;
	cc.m_pNewViewClass = m_pViewClass;
	cc.m_pCurrentDoc   = pDoc;
	pFrameWnd->CreateView(&cc);
	return pFrameWnd;
}

///////////////////////////////////////////////////////////////////////////

CSingleDocTemplate::CSingleDocTemplate(
	UINT nIDResource,
	CRuntimeClass* pDocClass,
	CRuntimeClass* pFrameClass,
	CRuntimeClass* pViewClass)
	: CDocTemplate(nIDResource, pDocClass, pFrameClass, pViewClass)
{
}

CDocument* CSingleDocTemplate::CreateNewDocument()
{
	return CDocTemplate::CreateNewDocument();
}

CFrameWnd* CSingleDocTemplate::CreateNewFrame(CDocument* pDoc, CFrameWnd* pOther)
{
	CWinApp* pApp = AfxGetApp();
	if ( ! pApp->m_pMainWnd)
	{
		pApp->m_pMainWnd = CDocTemplate::CreateNewFrame(pDoc, pOther);
	}
	return static_cast<CFrameWnd*>(pApp->m_pMainWnd);
}

///////////////////////////////////////////////////////////////////////////

CMultiDocTemplate::CMultiDocTemplate(
	UINT nIDResource,
	CRuntimeClass* pDocClass,
	CRuntimeClass* pFrameClass,
	CRuntimeClass* pViewClass)
	: CDocTemplate(nIDResource, pDocClass, pFrameClass, pViewClass)
{
}

CDocument* CMultiDocTemplate::CreateNewDocument()
{
	return CDocTemplate::CreateNewDocument();
}

CFrameWnd* CMultiDocTemplate::CreateNewFrame(CDocument* pDoc, CFrameWnd* /*pOther*/)
{
	CWnd* pMainWnd = AfxGetMainWnd();
	ASSERT(pMainWnd && pMainWnd->m_hWnd);
	if ( ! pMainWnd || ! pMainWnd->m_hWnd)
	{
		return NULL;
	}
	TRACE("MainWnd: %p, {%s}\n", pMainWnd, pMainWnd->GetRuntimeClass()->m_lpszClassName);
	ASSERT(pMainWnd->IsKindOf(RUNTIME_CLASS(CMDIFrameWnd)));

	CLIENTCREATESTRUCT ccs;
	ccs.hWindowMenu = NULL;
	ccs.idFirstChild = 1000;
	TRACE("Create MDI Client\n");
	CMDIFrameWnd* pMDIFrame = static_cast<CMDIFrameWnd*>(pMainWnd);
	pMDIFrame->m_MDIClient.CreateEx(0, _T("MDICLIENT"), NULL,
		WS_CHILD | WS_CLIPCHILDREN, 0, 0, 0, 0, pMDIFrame->m_hWnd, NULL, &ccs);
	TRACE("MDI Client hWnd = 0x%p, Err: %lu\n", pMDIFrame->m_MDIClient.m_hWnd, ::GetLastError());
	pMDIFrame->m_MDIClient.ShowWindow(SW_SHOW);

	TRACE("Create MDI Child\n");
	ASSERT(m_pFrameClass->IsDerivedFrom(RUNTIME_CLASS(CMDIChildWnd)));
	ASSERT(m_pViewClass->IsDerivedFrom(RUNTIME_CLASS(CView)));

	TRACE("Create Frame: %s\n", m_pFrameClass->m_lpszClassName);
	CFrameWnd* pChildFrameWnd = static_cast<CFrameWnd*>(m_pFrameClass->CreateObject());
	if ( ! pChildFrameWnd)
	{
		return NULL;
	}
	CRect rectChild(0, 0, 300, 200);
	pChildFrameWnd->Create(NULL, NULL, WS_CHILD, rectChild,
		&pMDIFrame->m_MDIClient, NULL, WS_EX_MDICHILD);
	TRACE("Child: %p\n", pChildFrameWnd->m_hWnd);
	pChildFrameWnd->ShowWindow(SW_SHOW);
	//return CDocTemplate::CreateNewFrame(pDoc, pOther);
	
	CCreateContext cc;
	cc.m_pNewViewClass = m_pViewClass;
	cc.m_pCurrentDoc   = pDoc;
	pChildFrameWnd->CreateView(&cc);
	return pChildFrameWnd;
}

///////////////////////////////////////////////////////////////////////////

