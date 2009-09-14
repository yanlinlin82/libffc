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
#include <cstring>

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
			int length = p - x;
			m_pData = new T[length + 1];
			memcpy(m_pData, x, (length + 1) * sizeof(T));
		}
	}

	CStringT(const CStringT& s)
		: m_pData(EmptyString())
	{
		if ( ! s.IsEmpty())
		{
			int length = s.GetLength();
			m_pData = new T[length + 1];
			memcpy(m_pData, s.m_pData, (length + 1) * sizeof(T));
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
	CStringT& operator = (const CStringT& s)
	{
		if (this != &s)
		{
			if (m_pData != EmptyString())
			{
				delete[] m_pData;
				m_pData = EmptyString();
			}
			if ( ! s.IsEmpty())
			{
				int length = s.GetLength();
				m_pData = new T[length + 1];
				memcpy(m_pData, s.m_pData, (length + 1) * sizeof(T));
			}
		}
		return *this;
	}

public:
	operator const T*() const { return m_pData; }
	BOOL IsEmpty() const { return m_pData == EmptyString(); }

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
