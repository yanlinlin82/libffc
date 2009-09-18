// CCmdTarget.h
#ifndef __CCMDTARGET_H__
#define __CCMDTARGET_H__
///////////////////////////////////////////////////////////////////////////

#include "CObject.h"

///////////////////////////////////////////////////////////////////////////

class CCmdTarget : public CObject
{
public:
	virtual BOOL _ProcessMessage(HWND hWnd, UINT msg, WPARAM w, LPARAM l, LRESULT& r);

public:
	DECLARE_DYNCREATE(CCmdTarget)
};

///////////////////////////////////////////////////////////////////////////

#define DECLARE_MESSAGE_MAP() \
	virtual BOOL _ProcessMessage(HWND hWnd, UINT msg, WPARAM w, LPARAM l, LRESULT& r);

#define BEGIN_MESSAGE_MAP(thisClass, baseClass) \
	BOOL thisClass::_ProcessMessage(HWND hWnd, UINT msg, WPARAM w, LPARAM l, LRESULT& r) \
	{ \
		typedef baseClass _base;

#define END_MESSAGE_MAP() \
		return _base::_ProcessMessage(hWnd, msg, w, l, r); \
	}

#define ON_MESSAGE(message, proc) \
		if (msg == message) \
		{ \
			r = proc(w, l); \
			return TRUE; \
		}

#define ON_COMMAND(id, proc) \
		if ((msg == WM_COMMAND) && (LOWORD(w) == id)) \
		{ \
			proc(); \
			return TRUE; \
		}

///////////////////////////////////////////////////////////////////////////
#endif//__CCMDTARGET_H__

