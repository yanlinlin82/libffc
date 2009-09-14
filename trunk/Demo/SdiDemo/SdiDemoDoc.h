// SdiDemoDoc.h : interface of the CSdiDemoDoc class
//


#pragma once


class CSdiDemoDoc : public CDocument
{
protected: // create from serialization only
	CSdiDemoDoc();
	DECLARE_DYNCREATE(CSdiDemoDoc)

// Attributes
public:

// Operations
public:

// Overrides
public:
	virtual BOOL OnNewDocument();
	virtual void Serialize(CArchive& ar);

// Implementation
public:
	virtual ~CSdiDemoDoc();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	DECLARE_MESSAGE_MAP()
};


