// MdiDemoDoc.cpp : implementation of the CMdiDemoDoc class
//

#include "stdafx.h"
#include "MdiDemo.h"

#include "MdiDemoDoc.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CMdiDemoDoc

IMPLEMENT_DYNCREATE(CMdiDemoDoc, CDocument)

BEGIN_MESSAGE_MAP(CMdiDemoDoc, CDocument)
END_MESSAGE_MAP()


// CMdiDemoDoc construction/destruction

CMdiDemoDoc::CMdiDemoDoc()
{
	// TODO: add one-time construction code here

}

CMdiDemoDoc::~CMdiDemoDoc()
{
}

BOOL CMdiDemoDoc::OnNewDocument()
{
	if (!CDocument::OnNewDocument())
		return FALSE;

	// TODO: add reinitialization code here
	// (SDI documents will reuse this document)

	return TRUE;
}




// CMdiDemoDoc serialization

void CMdiDemoDoc::Serialize(CArchive& ar)
{
	if (ar.IsStoring())
	{
		// TODO: add storing code here
	}
	else
	{
		// TODO: add loading code here
	}
}


// CMdiDemoDoc diagnostics

#ifdef _DEBUG
void CMdiDemoDoc::AssertValid() const
{
	CDocument::AssertValid();
}

void CMdiDemoDoc::Dump(CDumpContext& dc) const
{
	CDocument::Dump(dc);
}
#endif //_DEBUG


// CMdiDemoDoc commands
