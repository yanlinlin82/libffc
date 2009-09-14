// SdiDemoView.h : interface of the CSdiDemoView class
//


#pragma once


class CSdiDemoView : public CView
{
protected: // create from serialization only
	CSdiDemoView();
	DECLARE_DYNCREATE(CSdiDemoView)

// Attributes
public:
	CSdiDemoDoc* GetDocument() const;

// Operations
public:

// Overrides
public:
	virtual void OnDraw(CDC* pDC);  // overridden to draw this view
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:
	virtual BOOL OnPreparePrinting(CPrintInfo* pInfo);
	virtual void OnBeginPrinting(CDC* pDC, CPrintInfo* pInfo);
	virtual void OnEndPrinting(CDC* pDC, CPrintInfo* pInfo);

// Implementation
public:
	virtual ~CSdiDemoView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	DECLARE_MESSAGE_MAP()
};

#ifndef _DEBUG  // debug version in SdiDemoView.cpp
inline CSdiDemoDoc* CSdiDemoView::GetDocument() const
   { return reinterpret_cast<CSdiDemoDoc*>(m_pDocument); }
#endif

