// CView.h
#ifndef __FFC_CVIEW_H__
#define __FFC_CVIEW_H__
///////////////////////////////////////////////////////////////////////////

#include "CWnd.h"
#include "CDocument.h"
#include "CPrintInfo.h"
#include "CDC.h"

///////////////////////////////////////////////////////////////////////////

class CView : public CWnd
{
protected:
	CView();

public:
	BOOL DoPreparePrinting(CPrintInfo* pInfo);
	CDocument* GetDocument() const;

protected:
	virtual BOOL OnPreparePrinting(CPrintInfo* pInfo);
	virtual void OnDraw(CDC* pDC) = 0;

public:
	DECLARE_MESSAGE_MAP()

protected:
	afx_msg void OnPaint();
	afx_msg void OnFilePrint();
	afx_msg void OnFilePrintPreview();

public:
	DECLARE_DYNAMIC(CView)

public:
	CDocument* m_pDocument;
};

///////////////////////////////////////////////////////////////////////////

class CCtrlView : public CView
{
public:
	DECLARE_DYNCREATE(CCtrlView)

protected:
	virtual void OnDraw(CDC*) { }
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

protected:
	virtual void OnDraw(CDC*) { }
};

class CFormView : public CScrollView
{
public:
	DECLARE_DYNCREATE(CFormView)
};

///////////////////////////////////////////////////////////////////////////
#endif//__FFC_CVIEW_H__

