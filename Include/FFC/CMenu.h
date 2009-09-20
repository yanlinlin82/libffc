// CMenu.h
#ifndef __FFC_CMENU_H__
#define __FFC_CMENU_H__
///////////////////////////////////////////////////////////////////////////

#include "CObject.h"
#include "CGdiObject.h"

///////////////////////////////////////////////////////////////////////////

class CMenu : public CObject
{
public:
	CMenu();

public:
	BOOL LoadMenu(LPCTSTR lpszResourceName);
	BOOL LoadMenu(UINT nIDResource);

public:
	BOOL AppendMenu(UINT nFlags, UINT_PTR nIDNewItem = 0, LPCTSTR lpszNewItem = NULL);
	BOOL AppendMenu(UINT nFlags, UINT_PTR nIDNewItem, const CBitmap* pBmp);

public:
	HMENU m_hMenu;
};

///////////////////////////////////////////////////////////////////////////
#endif//__FFC_CMENU_H__

