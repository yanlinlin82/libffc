// CObject.h
#ifndef __FFC_COBJECT_H__
#define __FFC_COBJECT_H__
///////////////////////////////////////////////////////////////////////////

#include <windows.h>
#include <tchar.h>

///////////////////////////////////////////////////////////////////////////

class CArchive
{
public:
	BOOL IsStoring() const;
};

///////////////////////////////////////////////////////////////////////////

class CDumpContext
{
};

///////////////////////////////////////////////////////////////////////////

class CObject;

class CRuntimeClass
{
public:
	CRuntimeClass(
		LPCTSTR lpszClassName,
		UINT nObjectSize,
		CRuntimeClass* pBaseClass,
		CObject* (*pfnCreateObject)());

public:
	CObject* CreateObject() const;
	BOOL IsDerivedFrom(const CRuntimeClass* pBaseClass) const;
	static CRuntimeClass* FromName(LPCTSTR lpszClassName);

public:
	LPCTSTR        m_lpszClassName;
	UINT           m_nObjectSize;
	CRuntimeClass* m_pBaseClass;

	CObject* (*m_pfnCreateObject)();

	CRuntimeClass* m_pNextClass;
	static CRuntimeClass* m_pFirstClass;
};

///////////////////////////////////////////////////////////////////////////

#define RUNTIME_CLASS(className) \
	(&className::runtime##className)

#define DECLARE_DYNAMIC(className) \
public: \
	static CRuntimeClass runtime##className; \
	virtual const CRuntimeClass* GetRuntimeClass() const;

#define DECLARE_DYNCREATE(className) \
	DECLARE_DYNAMIC(className) \
	static CObject* CreateObject();

#define IMPLEMENT_DYNAMIC(className, baseClassName) \
	CRuntimeClass className::runtime##className( \
		_T(#className), \
		sizeof(className), \
		RUNTIME_CLASS(baseClassName), \
		className::CreateObject); \
	const CRuntimeClass* className::GetRuntimeClass() const \
	{ \
		return &runtime##className; \
	}

#define IMPLEMENT_DYNCREATE(className, baseClassName) \
	IMPLEMENT_DYNAMIC(className, baseClassName) \
	CObject* className::CreateObject() \
	{ \
		return new className(); \
	}

///////////////////////////////////////////////////////////////////////////

class CObject
{
public:
	virtual ~CObject() { }

public:
	BOOL IsKindOf(const CRuntimeClass* pClass) const;

public:
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;

public:
	DECLARE_DYNCREATE(CObject)
};

///////////////////////////////////////////////////////////////////////////
#endif//__FFC_COBJECT_H__

