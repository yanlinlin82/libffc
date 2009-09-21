// CDocTemplate.cpp

#include "../Include/afxwin.h"
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
	return CDocTemplate::CreateNewFrame(pDoc, pOther);
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

CFrameWnd* CMultiDocTemplate::CreateNewFrame(CDocument* pDoc, CFrameWnd* pOther)
{
	return CDocTemplate::CreateNewFrame(pDoc, pOther);
}

///////////////////////////////////////////////////////////////////////////

