// CException.h
#ifndef __FFC_CEXCEPTION_H__
#define __FFC_CEXCEPTION_H__
///////////////////////////////////////////////////////////////////////////

#include "CObject.h"

///////////////////////////////////////////////////////////////////////////

class CException : public CObject
{
};

///////////////////////////////////////////////////////////////////////////

class CArchiveException : public CException
{
};

class CDaoException : public CException
{
};

class CDBException : public CException
{
};

class CFileException : public CException
{
};

class CInternetException : public CException
{
};

class COleException : public CException
{
};

class COleDispatchException : public CException
{
};

///////////////////////////////////////////////////////////////////////////

class CSimpleException : public CException
{
};

class CMemoryException : public CSimpleException
{
};

class CNotSupportedException : public CSimpleException
{
};

class CResourceException : public CSimpleException
{
};

class CUserException : public CException
{
};

///////////////////////////////////////////////////////////////////////////
#endif//__FFC_CEXCEPTION_H__

