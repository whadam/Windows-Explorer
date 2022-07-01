
// FileView.h : interface of the CFileView class
//

#pragma once


class CFileView : public CListView
{
protected: // create from serialization only
	CFileView() noexcept;
	DECLARE_DYNCREATE(CFileView)

// Attributes
public:
	CFileTamDoc* GetDocument() const;

// Operations
public:

// Overrides
public:
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:
	virtual void OnInitialUpdate(); // called first time after construct

// Implementation
public:
	virtual ~CFileView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	afx_msg void OnStyleChanged(int nStyleType, LPSTYLESTRUCT lpStyleStruct);
	DECLARE_MESSAGE_MAP()
};

#ifndef _DEBUG  // debug version in FileView.cpp
inline CFileTamDoc* CFileView::GetDocument() const
   { return reinterpret_cast<CFileTamDoc*>(m_pDocument); }
#endif

