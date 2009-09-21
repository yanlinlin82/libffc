// CDocTemplate.h
#ifndef __FFC_CDOCTEMPLATE_H__
#define __FFC_CDOCTEMPLATE_H__
///////////////////////////////////////////////////////////////////////////

#include "CCmdTarget.h"

///////////////////////////////////////////////////////////////////////////

class CDocument;
class CFrameWnd;

///////////////////////////////////////////////////////////////////////////

class CDocTemplate : public CCmdTarget
{
public:
	CDocTemplate(
		UINT nIDResource,
		CRuntimeClass* pDocClass,
		CRuntimeClass* pFrameClass,
		CRuntimeClass* pViewClass);

public:
	virtual CDocument* CreateNewDocument();
	virtual CFrameWnd* CreateNewFrame(CDocument* pDoc, CFrameWnd* pOther);

public:
	UINT m_nIDResource;
	CRuntimeClass* m_pDocClass;
	CRuntimeClass* m_pFrameClass;
	CRuntimeClass* m_pViewClass;
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
public:
	virtual CDocument* CreateNewDocument();
	virtual CFrameWnd* CreateNewFrame(CDocument* pDoc, CFrameWnd* pOther);
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
public:
	virtual CDocument* CreateNewDocument();
	virtual CFrameWnd* CreateNewFrame(CDocument* pDoc, CFrameWnd* pOther);
};

///////////////////////////////////////////////////////////////////////////
#endif//__FFC_CDOCTEMPLATE_H__

