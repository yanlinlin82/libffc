// CDC.h
#ifndef __FFC_CDC_H__
#define __FFC_CDC_H__
///////////////////////////////////////////////////////////////////////////

#include "CObject.h"

class CWnd;

///////////////////////////////////////////////////////////////////////////

class CDC : public CObject
{
public:
	CDC();

public:
	virtual BOOL TextOut(int x, int y, LPCTSTR text, int count);
	BOOL TextOut(int x, int y, const CString& text);

	virtual int DrawText(
		LPCTSTR lpszString,
		int nCount,
		LPRECT lpRect,
		UINT nFormat);

	int DrawText(
		const CString& str,
		LPRECT lpRect,
		UINT nFormat);

	BOOL DrawIcon(int x, int y, HICON hIcon);
	BOOL DrawIcon(POINT point, HICON hIcon);

public:
	HDC GetSafeHdc() const { return m_hDC; }

public:
	HDC m_hDC;
};

///////////////////////////////////////////////////////////////////////////

class CClientDC : public CDC
{
};

///////////////////////////////////////////////////////////////////////////

class CMetaFileDC : public CDC
{
};

///////////////////////////////////////////////////////////////////////////

class CPaintDC : public CDC
{
public:
	explicit CPaintDC(CWnd* pWnd);
	~CPaintDC();

public:
	PAINTSTRUCT m_ps;
	HWND m_hWnd;
};

///////////////////////////////////////////////////////////////////////////

class CWindowDC : public CDC
{
};

///////////////////////////////////////////////////////////////////////////
#endif//__FFC_CDC_H__

