// CDocTemplate.cpp

#include "../Include/afxwin.h"

///////////////////////////////////////////////////////////////////////////

CDocTemplate::CDocTemplate(
	UINT /*nIDResource*/,
	CRuntimeClass* pDocClass,
	CRuntimeClass* pFrameClass,
	CRuntimeClass* pViewClass)
{
	m_pDoc      = static_cast<CDocument*>(pDocClass  ->CreateObject());
	m_pFrameWnd = static_cast<CFrameWnd*>(pFrameClass->CreateObject());
	m_pView     = static_cast<CView*    >(pViewClass ->CreateObject());
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

///////////////////////////////////////////////////////////////////////////

CMultiDocTemplate::CMultiDocTemplate(
	UINT nIDResource,
	CRuntimeClass* pDocClass,
	CRuntimeClass* pFrameClass,
	CRuntimeClass* pViewClass)
	: CDocTemplate(nIDResource, pDocClass, pFrameClass, pViewClass)
{
}

///////////////////////////////////////////////////////////////////////////

