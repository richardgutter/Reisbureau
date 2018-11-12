#if !defined(AFX_FITOVZVIEW_H__EB8EA697_F699_11D3_BC1B_006097638FC1__INCLUDED_)
#define AFX_FITOVZVIEW_H__EB8EA697_F699_11D3_BC1B_006097638FC1__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// FitovzView.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CFitovzView form view

#ifndef __AFXEXT_H__
#include <afxext.h>
#endif

class CFitovzView : public CFormView
{
protected:
	CFitovzView();           // protected constructor used by dynamic creation
	DECLARE_DYNCREATE(CFitovzView)

// Form Data
public:
	//{{AFX_DATA(CFitovzView)
	enum { IDD = IDD_FITOVZ_DIALOG };
	CListBox m_keuzelijst;
	CString	m_clnameto;
	CString	m_naam;
	CString	m_clnamefrom;
	CString	m_codefrom;
	long	m_numberfrom;
	long	m_numberto;
	CString	m_datefrom;
	CString	m_dateto;
	BOOL	m_cancelled;
	CString	m_omschrijving;
	int		m_maand;
	int		m_jaar;
	//}}AFX_DATA

// Attributes
public:

	COleDateTime m_begin;
	COleDateTime m_einde;
/*
	BOOL m_ovz;
	BOOL m_fithotel;
	BOOL m_fitagent;
	BOOL m_fithotelall;
	BOOL m_fitagentall;
	BOOL m_fitcancel;
	BOOL m_fitnamelist;
	BOOL m_fitbookingdate;
	BOOL m_fitvouchernr;
	BOOL m_fitvouchername;
*/

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CFitovzView)
	public:
	virtual void OnInitialUpdate();
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	virtual ~CFitovzView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

	// Generated message map functions
	//{{AFX_MSG(CFitovzView)
	afx_msg void OnSelchangeKeuzeList();
	afx_msg void OnOverviewButton();
	afx_msg void OnZoekButton();
	afx_msg void OnKillfocusCodefromEdit();
	afx_msg void OnDestroy();
	afx_msg void OnDblclkKeuzeList();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_FITOVZVIEW_H__EB8EA697_F699_11D3_BC1B_006097638FC1__INCLUDED_)
