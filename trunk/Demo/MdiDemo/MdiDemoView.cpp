// MdiDemoView.cpp : implementation of the CMdiDemoView class
//

#include "stdafx.h"
#include "MdiDemo.h"

#include "MdiDemoDoc.h"
#include "MdiDemoView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CMdiDemoView

IMPLEMENT_DYNCREATE(CMdiDemoView, CView)

BEGIN_MESSAGE_MAP(CMdiDemoView, CView)
	// Standard printing commands
	ON_COMMAND(ID_FILE_PRINT, CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, CView::OnFilePrintPreview)
END_MESSAGE_MAP()

// CMdiDemoView construction/destruction

CMdiDemoView::CMdiDemoView()
{
	// TODO: add construction code here

}

CMdiDemoView::~CMdiDemoView()
{
}

BOOL CMdiDemoView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: Modify the Window class or styles here by modifying
	//  the CREATESTRUCT cs

	return CView::PreCreateWindow(cs);
}

// CMdiDemoView drawing

void CMdiDemoView::OnDraw(CDC* pDC)
{
	CMdiDemoDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;
	
	// TODO: add draw code for native data here
	pDC->TextOut(10, 10, _T("Hello, MDI!"));
}


// CMdiDemoView printing

BOOL CMdiDemoView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// default preparation
	return DoPreparePrinting(pInfo);
}

void CMdiDemoView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add extra initialization before printing
}

void CMdiDemoView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add cleanup after printing
}


// CMdiDemoView diagnostics

#ifdef _DEBUG
void CMdiDemoView::AssertValid() const
{
	CView::AssertValid();
}

void CMdiDemoView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CMdiDemoDoc* CMdiDemoView::GetDocument() const // non-debug version is inline
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CMdiDemoDoc)));
	return (CMdiDemoDoc*)m_pDocument;
}
#endif //_DEBUG


// CMdiDemoView message handlers
