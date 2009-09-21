// CObject.cpp

#include "../Include/afx.h"

///////////////////////////////////////////////////////////////////////////

BOOL CArchive::IsStoring() const
{
	return TRUE;
}

///////////////////////////////////////////////////////////////////////////

CRuntimeClass* CRuntimeClass::m_pFirstClass = NULL;

CRuntimeClass::CRuntimeClass(
	LPCTSTR lpszClassName,
	UINT nObjectSize,
	CRuntimeClass* pBaseClass,
	CObject* (*pfnCreateObject)())
	: m_lpszClassName(lpszClassName)
	, m_nObjectSize(nObjectSize)
	, m_pBaseClass(pBaseClass)
	, m_pfnCreateObject(pfnCreateObject)
	, m_pNextClass(m_pFirstClass)
{
	m_pFirstClass = this;
}

CObject* CRuntimeClass::CreateObject() const
{
	return (*m_pfnCreateObject)();
}

BOOL CRuntimeClass::IsDerivedFrom(const CRuntimeClass* pBaseClass) const
{
	for (const CRuntimeClass* p = this; p; p = p->m_pBaseClass)
	{
		if (p == pBaseClass) return TRUE;
	}
	return FALSE;
}

CRuntimeClass* FromName(LPCTSTR /*lpszClassName*/)
{
	return NULL;
}

///////////////////////////////////////////////////////////////////////////

CRuntimeClass CObject::runtimeCObject(
	_T("CObject"), sizeof(CObject), NULL, CObject::CreateObject);

const CRuntimeClass* CObject::GetRuntimeClass() const
{
	return &runtimeCObject;
}

CObject* CObject::CreateObject()
{
	return new CObject();
}

BOOL CObject::IsKindOf(const CRuntimeClass* pClass) const
{
	return (GetRuntimeClass() == pClass);
}

///////////////////////////////////////////////////////////////////////////

void CObject::AssertValid() const
{
}

void CObject::Dump(CDumpContext& /*dc*/) const
{
}

///////////////////////////////////////////////////////////////////////////

