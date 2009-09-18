// CDocument.cpp

#include "../Include/afxwin.h"

///////////////////////////////////////////////////////////////////////////

IMPLEMENT_DYNCREATE(CDocument, CCmdTarget)

BOOL CDocument::OnNewDocument()
{
	return FALSE;
}

BOOL CDocument::OnOpenDocument(LPCTSTR /*lpszPathName*/)
{
	return FALSE;
}

BOOL CDocument::OnSaveDocument(LPCTSTR /*lpszPathName*/)
{
	return FALSE;
}

void CDocument::OnCloseDocument()
{
}

///////////////////////////////////////////////////////////////////////////

