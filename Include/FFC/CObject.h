// CObject.h
#ifndef __COBJECT_H__
#define __COBJECT_H__
///////////////////////////////////////////////////////////////////////////

class CArchive
{
public:
	BOOL IsStoring() const;
};

class CDumpContext
{
};

///////////////////////////////////////////////////////////////////////////

class CObject;

struct CRuntimeClass
{
	LPCTSTR        m_lpszClassName;
	UINT           m_nObjectSize;
	CRuntimeClass* m_pBaseClass;

	CObject* (*m_pfnCreateObject)();

	CObject* CreateObject() const;
	BOOL IsDerivedFrom(const CRuntimeClass* pBaseClass) const;
	static CRuntimeClass* FromName(LPCTSTR lpszClassName);
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
	CRuntimeClass className::runtime##className; \
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
#endif//__COBJECT_H__

