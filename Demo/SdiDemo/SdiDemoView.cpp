// SdiDemoView.cpp : implementation of the CSdiDemoView class
//

#include "stdafx.h"
#include "SdiDemo.h"

#include "SdiDemoDoc.h"
#include "SdiDemoView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CSdiDemoView

IMPLEMENT_DYNCREATE(CSdiDemoView, CView)

BEGIN_MESSAGE_MAP(CSdiDemoView, CView)
	// Standard printing commands
	ON_COMMAND(ID_FILE_PRINT, CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, CView::OnFilePrintPreview)
END_MESSAGE_MAP()

// CSdiDemoView construction/destruction

CSdiDemoView::CSdiDemoView()
{
	// TODO: add construction code here

}

CSdiDemoView::~CSdiDemoView()
{
}

BOOL CSdiDemoView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: Modify the Window class or styles here by modifying
	//  the CREATESTRUCT cs

	return CView::PreCreateWindow(cs);
}

// CSdiDemoView drawing

void CSdiDemoView::OnDraw(CDC* /*pDC*/)
{
	CSdiDemoDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: add draw code for native data here
}


// CSdiDemoView printing

BOOL CSdiDemoView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// default preparation
	return DoPreparePrinting(pInfo);
}

void CSdiDemoView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add extra initialization before printing
}

void CSdiDemoView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add cleanup after printing
}


// CSdiDemoView diagnostics

#ifdef _DEBUG
void CSdiDemoView::AssertValid() const
{
	CView::AssertValid();
}

void CSdiDemoView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CSdiDemoDoc* CSdiDemoView::GetDocument() const // non-debug version is inline
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CSdiDemoDoc)));
	return (CSdiDemoDoc*)m_pDocument;
}
#endif //_DEBUG


// CSdiDemoView message handlers
