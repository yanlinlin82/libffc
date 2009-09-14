// MdiDemoView.h : interface of the CMdiDemoView class
//


#pragma once


class CMdiDemoView : public CView
{
protected: // create from serialization only
	CMdiDemoView();
	DECLARE_DYNCREATE(CMdiDemoView)

// Attributes
public:
	CMdiDemoDoc* GetDocument() const;

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
	virtual ~CMdiDemoView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	DECLARE_MESSAGE_MAP()
};

#ifndef _DEBUG  // debug version in MdiDemoView.cpp
inline CMdiDemoDoc* CMdiDemoView::GetDocument() const
   { return reinterpret_cast<CMdiDemoDoc*>(m_pDocument); }
#endif

