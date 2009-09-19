// CCmdTarget.h
#ifndef __CCMDTARGET_H__
#define __CCMDTARGET_H__
///////////////////////////////////////////////////////////////////////////

#include "CObject.h"

///////////////////////////////////////////////////////////////////////////

struct AFX_CMDHANDLERINFO
{
};

///////////////////////////////////////////////////////////////////////////

#define DECLARE_MESSAGE_MAP() \
public: \
	virtual LRESULT _ProcessMessage(CCmdTarget::_ProcessType type, HWND hWnd, UINT msg, WPARAM w, LPARAM l);

#define IMPLEMENT_MESSAGE_MAP(thisClass) \
	LRESULT thisClass::_ProcessMessage(CCmdTarget::_ProcessType, HWND, UINT, WPARAM, LPARAM) \
	{ \
		return FALSE; \
	}

#define BEGIN_MESSAGE_MAP(thisClass, baseClass) \
	LRESULT thisClass::_ProcessMessage(CCmdTarget::_ProcessType type, HWND hWnd, UINT msg, WPARAM w, LPARAM l) \
	{ \
		typedef baseClass _Base;

#define END_MESSAGE_MAP() \
		return _Base::_ProcessMessage(type, hWnd, msg, w, l); \
	}

#define ON_MESSAGE(message, proc) \
		if (msg == message) \
		{ \
			if (type == _Check) return TRUE; \
			if (type == _Message) return proc(w, l); \
		}

#define ON_COMMAND(id, proc) \
		if ((msg == WM_COMMAND) && (LOWORD(w) == id)) \
		{ \
			if (type == _Check) return TRUE; \
			if (type == _Command) { proc(); return 0; } \
		}

///////////////////////////////////////////////////////////////////////////

class CCmdTarget : public CObject
{
public:
	enum _ProcessType { _Check, _Message, _Command };

	DECLARE_MESSAGE_MAP()

	DECLARE_DYNCREATE(CCmdTarget)

public:
	virtual BOOL OnCmdMsg(UINT nID, int nCode, void* pExtra, AFX_CMDHANDLERINFO* pHandlerInfo);
};

///////////////////////////////////////////////////////////////////////////
#endif//__CCMDTARGET_H__

