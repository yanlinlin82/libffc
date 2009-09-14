// CView.h
#ifndef __CVIEW_H__
#define __CVIEW_H__
///////////////////////////////////////////////////////////////////////////

#include "CWnd.h"
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
	CDocument* m_pDocument;
};

///////////////////////////////////////////////////////////////////////////

class CCtrlView : public CView
{
};

class CEditView : public CCtrlView
{
};

class CListView : public CCtrlView
{
};

class CRichEditView : public CCtrlView
{
};

class CTreeView : public CCtrlView
{
};

///////////////////////////////////////////////////////////////////////////

class CScrollView : public CView
{
};

class CFormView : public CScrollView
{
};

///////////////////////////////////////////////////////////////////////////
#endif//__CVIEW_H__

