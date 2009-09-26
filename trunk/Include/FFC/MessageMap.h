// MessageMap.h
#ifndef __FFC_MESSAGEMAP_H__
#define __FFC_MESSAGEMAP_H__
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

///////////////////////////////////////////////////////////////////////////

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

#define ON_WM_CREATE() \
		if (msg == WM_CREATE) \
		{ \
			if (type == _Check) return TRUE; \
			if (type == _Message) return OnCreate(reinterpret_cast<LPCREATESTRUCT>(l)); \
		}

#define ON_WM_SIZE() \
		if (msg == WM_SIZE) \
		{ \
			if (type == _Check) return TRUE; \
			if (type == _Message) { OnSize(w, LOWORD(l), HIWORD(l)); return 0; } \
		}

#define ON_WM_SYSCOMMAND() \
		if (msg == WM_SYSCOMMAND) \
		{ \
			if (type == _Check) return TRUE; \
			if (type == _Message) { OnSysCommand(w, l); return 0; } \
		}

#define ON_WM_PAINT() \
		if (msg == WM_PAINT) \
		{ \
			if (type == _Check) return TRUE; \
			if (type == _Message) { OnPaint(); return 0; } \
		}

#define ON_WM_QUERYDRAGICON() \
		if (msg == WM_QUERYDRAGICON) \
		{ \
			if (type == _Check) return TRUE; \
			if (type == _Message) return reinterpret_cast<LRESULT>( \
				static_cast<HICON>(OnQueryDragIcon())); \
		}

#define ON_WM_NCDESTROY() \
		if (msg == WM_NCDESTROY) \
		{ \
			if (type == _Check) return TRUE; \
			if (type == _Message) { OnNcDestroy(); return 0; } \
		}

///////////////////////////////////////////////////////////////////////////
#endif//__FFC_MESSAGEMAP_H__

