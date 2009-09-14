// atltypes.h
//
// This is part of FFC (Free Foundation Classes).
//
// Anthor: Linlin Yan (yanlinlin82[at]gmail.com).
//
// Any sugguestion is welcome.

#ifndef __ATLTYPES_H__
#define __ATLTYPES_H__
///////////////////////////////////////////////////////////////////////////

#include <windows.h>

///////////////////////////////////////////////////////////////////////////

class CRect : public tagRECT
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
#endif//__ATLTYPES_H__

