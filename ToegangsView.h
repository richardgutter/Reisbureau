#if !defined(AFX_TOEGANGSVIEW_H__7FCEFA04_B729_11D4_BC1C_006097638FC1__INCLUDED_)
#define AFX_TOEGANGSVIEW_H__7FCEFA04_B729_11D4_BC1C_006097638FC1__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// ToegangsView.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CToegangsView form view

#ifndef __AFXEXT_H__
#include <afxext.h>
#endif

#include "toegang.h"

class CToegangsView : public CFormView
{
protected:
	CToegangsView();           // protected constructor used by dynamic creation
	DECLARE_DYNCREATE(CToegangsView)

// Form Data
public:
	//{{AFX_DATA(CToegangsView)
	enum { IDD = IDD_TOEGANG_DIALOG };
	BOOL	m_add0;
	BOOL	m_add1;
	BOOL	m_add2;
	BOOL	m_add3;
	BOOL	m_add4;
	BOOL	m_add5;
	BOOL	m_cancel0;
	BOOL	m_cancel1;
	BOOL	m_cancel2;
	BOOL	m_cancel3;
	BOOL	m_cancel4;
	BOOL	m_cancel5;
	BOOL	m_change0;
	BOOL	m_change1;
	BOOL	m_change2;
	BOOL	m_change3;
	BOOL	m_change4;
	BOOL	m_change5;
	BOOL	m_delete0;
	BOOL	m_delete1;
	BOOL	m_delete2;
	BOOL	m_delete3;
	BOOL	m_delete4;
	BOOL	m_delete5;
	BOOL	m_show0;
	BOOL	m_show1;
	BOOL	m_show2;
	BOOL	m_show3;
	BOOL	m_show4;
	BOOL	m_show5;
	CString	m_show;
	CString	m_functie;
	//}}AFX_DATA

// Attributes
public:

	CToegang m_settoegang;
	BOOL m_toegang_tonen;
	BOOL m_toegang_wijzigen;
	BOOL m_tonen;

	void veldenediten(BOOL);
	void recordweergeven(void);

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CToegangsView)
	public:
	virtual void OnInitialUpdate();
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	virtual ~CToegangsView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

	// Generated message map functions
	//{{AFX_MSG(CToegangsView)
	afx_msg void OnDestroy();
	afx_msg void OnTonenButton();
	afx_msg void OnUpdateTonenButton(CCmdUI* pCmdUI);
	afx_msg void OnWijzigenButton();
	afx_msg void OnUpdateWijzigenButton(CCmdUI* pCmdUI);
	afx_msg void OnNietopslaanButton();
	afx_msg void OnUpdateNietopslaanButton(CCmdUI* pCmdUI);
	afx_msg void OnOpslaanButton();
	afx_msg void OnUpdateOpslaanButton(CCmdUI* pCmdUI);
	afx_msg void OnVolgendeButton();
	afx_msg void OnVorigeButton();
	afx_msg void OnAdd0Check();
	afx_msg void OnAdd1Check();
	afx_msg void OnAdd2Check();
	afx_msg void OnAdd3Check();
	afx_msg void OnAdd4Check();
	afx_msg void OnAdd5Check();
	afx_msg void OnCancel0Check();
	afx_msg void OnCancel1Check();
	afx_msg void OnCancel2Check();
	afx_msg void OnCancel3Check();
	afx_msg void OnCancel4Check();
	afx_msg void OnCancel5Check();
	afx_msg void OnChange0Check();
	afx_msg void OnChange1Check();
	afx_msg void OnChange2Check();
	afx_msg void OnChange3Check();
	afx_msg void OnChange4Check();
	afx_msg void OnChange5Check();
	afx_msg void OnDelete0Check();
	afx_msg void OnDelete1Check();
	afx_msg void OnDelete2Check();
	afx_msg void OnDelete3Check();
	afx_msg void OnDelete4Check();
	afx_msg void OnDelete5Check();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_TOEGANGSVIEW_H__7FCEFA04_B729_11D4_BC1C_006097638FC1__INCLUDED_)
