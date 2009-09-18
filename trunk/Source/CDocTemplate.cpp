// CDocTemplate.cpp

#include "../Include/afxwin.h"

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

