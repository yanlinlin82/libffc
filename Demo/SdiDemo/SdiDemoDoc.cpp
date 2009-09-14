// SdiDemoDoc.cpp : implementation of the CSdiDemoDoc class
//

#include "stdafx.h"
#include "SdiDemo.h"

#include "SdiDemoDoc.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CSdiDemoDoc

IMPLEMENT_DYNCREATE(CSdiDemoDoc, CDocument)

BEGIN_MESSAGE_MAP(CSdiDemoDoc, CDocument)
END_MESSAGE_MAP()


// CSdiDemoDoc construction/destruction

CSdiDemoDoc::CSdiDemoDoc()
{
	// TODO: add one-time construction code here

}

CSdiDemoDoc::~CSdiDemoDoc()
{
}

BOOL CSdiDemoDoc::OnNewDocument()
{
	if (!CDocument::OnNewDocument())
		return FALSE;

	// TODO: add reinitialization code here
	// (SDI documents will reuse this document)

	return TRUE;
}




// CSdiDemoDoc serialization

void CSdiDemoDoc::Serialize(CArchive& ar)
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


// CSdiDemoDoc diagnostics

#ifdef _DEBUG
void CSdiDemoDoc::AssertValid() const
{
	CDocument::AssertValid();
}

void CSdiDemoDoc::Dump(CDumpContext& dc) const
{
	CDocument::Dump(dc);
}
#endif //_DEBUG


// CSdiDemoDoc commands
