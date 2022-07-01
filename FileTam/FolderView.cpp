
// FolderView.cpp : implementation of the CFolderView class
//

#include "pch.h"
#include "framework.h"
#include "FileTam.h"

#include "FileTamDoc.h"
#include "FolderView.h"
#include "FileView.h"
#include "MainFrm.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CFolderView

IMPLEMENT_DYNCREATE(CFolderView, CTreeView)

BEGIN_MESSAGE_MAP(CFolderView, CTreeView)
END_MESSAGE_MAP()


// CFolderView construction/destruction

CFolderView::CFolderView()
{
	// TODO: add construction code here
}

CFolderView::~CFolderView()
{
}

BOOL CFolderView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: Modify the Window class or styles here by modifying the CREATESTRUCT cs

	return CTreeView::PreCreateWindow(cs);
}

void CFolderView::OnInitialUpdate()
{
	CTreeView::OnInitialUpdate();

	// TODO: You may populate your TreeView with items by directly accessing
	//  its tree control through a call to GetTreeCtrl().

	GetTreeCtrl().SetImageList(m_imgTree.GetImageList(), TVSIL_NORMAL);

	char pTmp[256];
	memset(pTmp, '\0', 256);
	// get logical drive info
	GetLogicalDriveStrings(256, pTmp);

	CString strDrive;

	for (int i = 0; i < 256; i++) {
		if (pTmp[i] == '\0' && pTmp[i + 1] == '\0')
			break;

		strDrive.Empty();
		while (pTmp[i] != '\0')
			strDrive += pTmp[i++];
		SetDriveInfo(strDrive);
	}

	// show each drive's subfolder
	HTREEITEM hItem;
	for (hItem == GetTreeCtrl().GetRootItem(); hItem; hItem = GetTreeCtrl().GetNextSiblingItem(hItem)) {
		if (GetTreeCtrl().ItemHasChildren(hItem))
			GetTreeCtrl().Expand(hItem, TVE_EXPAND);
	}
}


// CFolderView diagnostics

#ifdef _DEBUG
void CFolderView::AssertValid() const
{
	CTreeView::AssertValid();
}

void CFolderView::Dump(CDumpContext& dc) const
{
	CTreeView::Dump(dc);
}

CFileTamDoc* CFolderView::GetDocument() // non-debug version is inline
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CFileTamDoc)));
	return (CFileTamDoc*)m_pDocument;
}
#endif //_DEBUG


// CFolderView message handlers
