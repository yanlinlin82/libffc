// Menu.cpp

#include "../Include/afxwin.h"

///////////////////////////////////////////////////////////////////////////

CMenu::CMenu()
	: m_hMenu(NULL)
{
}

///////////////////////////////////////////////////////////////////////////

BOOL CMenu::LoadMenu(LPCTSTR lpszResourceName)
{
	m_hMenu = ::LoadMenu(AfxGetResourceHandle(), lpszResourceName);
	return (m_hMenu != NULL);
}

BOOL CMenu::LoadMenu(UINT nIDResource)
{
	return LoadMenu(MAKEINTRESOURCE(nIDResource));
}

///////////////////////////////////////////////////////////////////////////

BOOL CMenu::AppendMenu(UINT nFlags, UINT_PTR nIDNewItem, LPCTSTR lpszNewItem)
{
	ASSERT(m_hMenu != NULL);
	return ::AppendMenu(m_hMenu, nFlags, nIDNewItem, lpszNewItem);
}

BOOL CMenu::AppendMenu(UINT /*nFlags*/, UINT_PTR /*nIDNewItem*/, const CBitmap* /*pBmp*/)
{
	return FALSE;
}

///////////////////////////////////////////////////////////////////////////

