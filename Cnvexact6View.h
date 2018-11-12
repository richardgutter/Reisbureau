#if !defined(AFX_CNVEXACT6VIEW_H__8DF55342_BE3B_11D4_BC1C_006097638FC1__INCLUDED_)
#define AFX_CNVEXACT6VIEW_H__8DF55342_BE3B_11D4_BC1C_006097638FC1__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// Cnvexact6View.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CCnvexact6View form view

#ifndef __AFXEXT_H__
#include <afxext.h>
#endif

class CCnvexact6View : public CFormView
{
protected:
	CCnvexact6View();           // protected constructor used by dynamic creation
	DECLARE_DYNCREATE(CCnvexact6View)

// Form Data
public:
	//{{AFX_DATA(CCnvexact6View)
	enum { IDD = IDD_CNVEXACT6_DIALOG };
	long	m_tm;
	long	m_van;
	//}}AFX_DATA

	FILE *uit;
	void Conversie(void);

// Attributes
public:

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CCnvexact6View)
	public:
	virtual void OnInitialUpdate();
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	virtual ~CCnvexact6View();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

	// Generated message map functions
	//{{AFX_MSG(CCnvexact6View)
	afx_msg void OnVanButton();
	afx_msg void OnTmButton();
	afx_msg void OnConversionButton();
	afx_msg void OnDestroy();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_CNVEXACT6VIEW_H__8DF55342_BE3B_11D4_BC1C_006097638FC1__INCLUDED_)
