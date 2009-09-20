// CDocument.h
#ifndef __FFC_CDOCUMENT_H__
#define __FFC_CDOCUMENT_H__
///////////////////////////////////////////////////////////////////////////

#include "CCmdTarget.h"

///////////////////////////////////////////////////////////////////////////

class CDocument : public CCmdTarget
{
public:
	virtual BOOL OnNewDocument();
	virtual BOOL OnOpenDocument(LPCTSTR lpszPathName);
	virtual BOOL OnSaveDocument(LPCTSTR lpszPathName);
	virtual void OnCloseDocument();

public:
	DECLARE_DYNCREATE(CDocument)
};

///////////////////////////////////////////////////////////////////////////
#endif//__FFC_CDOCUMENT_H__

