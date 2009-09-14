// CDocTemplate.h
#ifndef __CDOCTEMPLATE_H__
#define __CDOCTEMPLATE_H__
///////////////////////////////////////////////////////////////////////////

#include "CObject.h"
#include "CDocument.h"
#include "CFrameWnd.h"
#include "CView.h"

///////////////////////////////////////////////////////////////////////////

class CDocTemplate : public CObject
{
public:
	CDocTemplate(
		UINT nIDResource,
		CRuntimeClass* pDocClass,
		CRuntimeClass* pFrameClass,
		CRuntimeClass* pViewClass);

private:
	CDocument* m_pDoc;
	CFrameWnd* m_pFrameWnd;
	CView*     m_pView;
};

///////////////////////////////////////////////////////////////////////////

class CSingleDocTemplate : public CDocTemplate
{
public:
	CSingleDocTemplate(
		UINT nIDResource,
		CRuntimeClass* pDocClass,
		CRuntimeClass* pFrameClass,
		CRuntimeClass* pViewClass);
};

///////////////////////////////////////////////////////////////////////////

class CMultiDocTemplate : public CDocTemplate
{
public:
	CMultiDocTemplate(
		UINT nIDResource,
		CRuntimeClass* pDocClass,
		CRuntimeClass* pFrameClass,
		CRuntimeClass* pViewClass);
};

///////////////////////////////////////////////////////////////////////////
#endif//__CDOCTEMPLATE_H__

