// CRect.h
#ifndef __FFC_CRECT_H__
#define __FFC_CRECT_H__
///////////////////////////////////////////////////////////////////////////

#include <windows.h>

///////////////////////////////////////////////////////////////////////////

class CRect : public RECT
{
public:
	CRect() throw()
	{
		SetRect(0, 0, 0, 0);
	}

	CRect(int l, int t, int r, int b) throw()
	{
		SetRect(l, t, r, b);
	}

public:
	int Width() const { return right - left; }
	int Height() const { return bottom - top; }

public:
	void SetRect(int x1, int y1, int x2, int y2) throw()
	{
		left   = x1;
		top    = y1;
		right  = x2;
		bottom = y2;
	}

public:
	operator LPCRECT() const { return this; }

	operator LPRECT() { return this; }
};

///////////////////////////////////////////////////////////////////////////
#endif//__FFC_CRECT_H__

