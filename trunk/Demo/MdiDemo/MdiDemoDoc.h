// MdiDemoDoc.h : interface of the CMdiDemoDoc class
//


#pragma once


class CMdiDemoDoc : public CDocument
{
protected: // create from serialization only
	CMdiDemoDoc();
	DECLARE_DYNCREATE(CMdiDemoDoc)

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
	virtual ~CMdiDemoDoc();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	DECLARE_MESSAGE_MAP()
};


