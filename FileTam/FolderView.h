
// FolderView.h : interface of the CFolderView class
//
#include "SystemImageList.h"
//#include "DlgFolder.h"

#pragma once

class CFileTamDoc;

class CFolderView : public CTreeView
{
protected: // create from serialization only
	CFolderView();
	DECLARE_DYNCREATE(CFolderView)

// Attributes
public:
	CFileTamDoc* GetDocument();

// Operations
public:

// Overrides
	public:
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
	protected:
	virtual void OnInitialUpdate(); // called first time after construct

// Implementation
public:
	virtual ~CFolderView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	DECLARE_MESSAGE_MAP()
};

#ifndef _DEBUG  // debug version in FolderView.cpp
inline CFileTamDoc* CFolderView::GetDocument()
   { return reinterpret_cast<CFileTamDoc*>(m_pDocument); }
#endif

