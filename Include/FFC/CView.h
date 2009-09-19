// CView.h
#ifndef __CVIEW_H__
#define __CVIEW_H__
///////////////////////////////////////////////////////////////////////////

#include "CWnd.h"
#include "CDocument.h"
#include "../afxext.h"

///////////////////////////////////////////////////////////////////////////

class CView : public CWnd
{
public:
	BOOL DoPreparePrinting(CPrintInfo* pInfo);
	CDocument* GetDocument( ) const;

public:
	virtual BOOL OnPreparePrinting(CPrintInfo* pInfo);

public:
	DECLARE_MESSAGE_MAP()

protected:
	afx_msg void OnFilePrint();
	afx_msg void OnFilePrintPreview();

public:
	DECLARE_DYNCREATE(CView)

public:
	CDocument* m_pDocument;
};

///////////////////////////////////////////////////////////////////////////

class CCtrlView : public CView
{
public:
	DECLARE_DYNCREATE(CCtrlView)
};

class CEditView : public CCtrlView
{
public:
	DECLARE_DYNCREATE(CEditView)
};

class CListView : public CCtrlView
{
public:
	DECLARE_DYNCREATE(CListView)
};

class CRichEditView : public CCtrlView
{
public:
	DECLARE_DYNCREATE(CRichEditView)
};

class CTreeView : public CCtrlView
{
public:
	DECLARE_DYNCREATE(CTreeView)
};

///////////////////////////////////////////////////////////////////////////

class CScrollView : public CView
{
public:
	DECLARE_DYNCREATE(CScrollView)
};

class CFormView : public CScrollView
{
public:
	DECLARE_DYNCREATE(CFormView)
};

///////////////////////////////////////////////////////////////////////////
#endif//__CVIEW_H__

