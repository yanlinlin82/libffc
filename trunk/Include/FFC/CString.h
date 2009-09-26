// CString.h
#ifndef __FFC_CSTRING_H__
#define __FFC_CSTRING_H__
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

	int GetLength() const { return lstrlen(m_pData); }

public:
	BOOL LoadString(UINT id)
	{
		T buffer[1024] = { 0 };
		if ( ! ::LoadString(::GetModuleHandle(NULL), id, buffer, 1024))
		{
			return FALSE;
		}
		m_pData = new T[lstrlen(buffer) + 1];
		::lstrcpy(m_pData, buffer);
		return TRUE;
	}

public:
	void Format(LPCTSTR lpszFormat, ...)
	{
		va_list argList;
		va_start(argList, lpszFormat);
		FormatV(lpszFormat, argList);
	}

	void Format(UINT nFormatID, ...)
	{
		CStringT<T> format;
		format.LoadString(nFormatID);
		va_list argList;
		va_start(argList, nFormatID);
		FormatV(format, argList);
	}

	void FormatV(LPCTSTR lpszFormat, va_list argList)
	{
		T buffer[1024] = { 0 };
		wvsprintf(buffer, lpszFormat, argList);
		m_pData = new T[lstrlen(buffer) + 1];
		::lstrcpy(m_pData, buffer);
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
#endif//__FFC_CSTRING_H__

