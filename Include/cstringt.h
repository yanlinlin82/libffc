// cstringt.h
//
// This is part of FFC (Free Foundation Classes).
//
// Anthor: Linlin Yan (yanlinlin82[at]gmail.com).
//
// Any sugguestion is welcome.

#ifndef __CSTRINGT_H__
#define __CSTRINGT_H__
///////////////////////////////////////////////////////////////////////////

#include <windows.h>
#include <tchar.h>

///////////////////////////////////////////////////////////////////////////

template <typename T>
class CStringT
{
public:
	CStringT(const T* x = NULL)
		: m_pData(EmptyString())
	{
		if (x)
		{
			const T* p = x;
			while (*p) p++;
			m_pData = new T[p - x + 1];
			lstrcpy(m_pData, x);
		}
	}

	virtual ~CStringT()
	{
		if (m_pData != EmptyString())
		{
			delete[] m_pData;
			m_pData = EmptyString();
		}
	}

public:
	operator const T*() const { return m_pData; }

public:
	BOOL LoadString(UINT id)
	{
		T buffer[1024] = { 0 };
		if ( ! ::LoadString(::GetModuleHandle(NULL), id, buffer, 1024))
		{
			return FALSE;
		}
		m_pData = new T[lstrlen(buffer)];
		::lstrcpy(m_pData, buffer);
		return TRUE;
	}

private:
	T* m_pData;

private:
	static T* EmptyString()
	{
		static T c = 0;
		return &c;
	}
};

typedef CStringT<CHAR>  CStringA;
typedef CStringT<WCHAR> CStringW;
typedef CStringT<TCHAR> CString;

///////////////////////////////////////////////////////////////////////////
#endif//__CSTRINGT_H__

