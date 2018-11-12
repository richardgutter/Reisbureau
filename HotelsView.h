#if !defined(AFX_HOTELSVIEW_H__EB8EA6A1_F699_11D3_BC1B_006097638FC1__INCLUDED_)
#define AFX_HOTELSVIEW_H__EB8EA6A1_F699_11D3_BC1B_006097638FC1__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// HotelsView.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CHotelsView form view

#ifndef __AFXEXT_H__
#include <afxext.h>
#endif

#include "hotels.h"

class CHotelsView : public CFormView
{
protected:
	CHotelsView();           // protected constructor used by dynamic creation
	DECLARE_DYNCREATE(CHotelsView)

// Form Data
public:
	//{{AFX_DATA(CHotelsView)
	enum { IDD = IDD_HOTELS_DIALOG };
	CEdit	m_zipcode_cntrl;
	CEdit	m_strtwinsseason1_cntrl;
	CEdit	m_strtwinsseason2_cntrl;
	CEdit	m_strtwinsseason3_cntrl;
	CEdit	m_strtwinsseason4_cntrl;
	CEdit	m_strtwinsseason5_cntrl;
	CEdit	m_strtwinsseason6_cntrl;
	CEdit	m_strtsuseason1_cntrl;
	CEdit	m_strtsuseason2_cntrl;
	CEdit	m_strtsuseason3_cntrl;
	CEdit	m_strtsuseason4_cntrl;
	CEdit	m_strtsuseason5_cntrl;
	CEdit	m_strtsuseason6_cntrl;
	CEdit	m_strtriplesseason1_cntrl;
	CEdit	m_strtriplesseason2_cntrl;
	CEdit	m_strtriplesseason3_cntrl;
	CEdit	m_strtriplesseason4_cntrl;
	CEdit	m_strtriplesseason5_cntrl;
	CEdit	m_strtriplesseason6_cntrl;
	CEdit	m_tillseason1_cntrl;
	CEdit	m_tillseason2_cntrl;
	CEdit	m_tillseason3_cntrl;
	CEdit	m_tillseason4_cntrl;
	CEdit	m_tillseason5_cntrl;
	CEdit	m_tillseason6_cntrl;
	CEdit	m_telres_cntrl;
	CEdit	m_tel_cntrl;
	CEdit	m_strsinglesseason1_cntrl;
	CEdit	m_strsinglesseason2_cntrl;
	CEdit	m_strsinglesseason3_cntrl;
	CEdit	m_strsinglesseason4_cntrl;
	CEdit	m_strsinglesseason5_cntrl;
	CEdit	m_strsinglesseason6_cntrl;
	CEdit	m_strquadsseason1_cntrl;
	CEdit	m_strquadsseason2_cntrl;
	CEdit	m_strquadsseason3_cntrl;
	CEdit	m_strquadsseason4_cntrl;
	CEdit	m_strquadsseason5_cntrl;
	CEdit	m_strquadsseason6_cntrl;
	CEdit	m_naam_cntrl;
	CEdit	m_strmultiplesseason1_cntrl;
	CEdit	m_strmultiplesseason2_cntrl;
	CEdit	m_strmultiplesseason3_cntrl;
	CEdit	m_strmultiplesseason4_cntrl;
	CEdit	m_strmultiplesseason5_cntrl;
	CEdit	m_strmultiplesseason6_cntrl;
	CEdit	m_fromseason1_cntrl;
	CEdit	m_fromseason2_cntrl;
	CEdit	m_fromseason3_cntrl;
	CEdit	m_fromseason4_cntrl;
	CEdit	m_fromseason5_cntrl;
	CEdit	m_fromseason6_cntrl;
	CEdit	m_fax_cntrl;
	CEdit	m_email_cntrl;
	CEdit	m_strdoublesseason1_cntrl;
	CEdit	m_strdoublesseason2_cntrl;
	CEdit	m_strdoublesseason3_cntrl;
	CEdit	m_strdoublesseason4_cntrl;
	CEdit	m_strdoublesseason5_cntrl;
	CEdit	m_strdoublesseason6_cntrl;
	CEdit	m_country_cntrl;
	CEdit	m_code_cntrl;
	CEdit	m_city_cntrl;
	CEdit	m_address2_cntrl;
	CEdit	m_address1_cntrl;
	CTabCtrl	m_tab;
	CString	m_tel;
	CString	m_address1;
	CString	m_city;
	CString	m_code;
	CString	m_email;
	CString	m_fax;
	CString	m_naam;
	CString	m_address2;
	CString	m_telres;
	CString	m_country;
	CString	m_zipcode;
	CString	m_strdoublesseason1;
	CString	m_strdoublesseason2;
	CString	m_strdoublesseason3;
	CString	m_strdoublesseason4;
	CString	m_strdoublesseason5;
	CString	m_strdoublesseason6;
	CString	m_fromseason1;
	CString	m_fromseason2;
	CString	m_fromseason3;
	CString	m_fromseason4;
	CString	m_fromseason5;
	CString	m_fromseason6;
	CString	m_tillseason1;
	CString	m_tillseason2;
	CString	m_tillseason3;
	CString	m_tillseason4;
	CString	m_tillseason5;
	CString	m_tillseason6;
	CString	m_strmultiplesseason1;
	CString	m_strmultiplesseason2;
	CString	m_strmultiplesseason3;
	CString	m_strmultiplesseason4;
	CString	m_strmultiplesseason5;
	CString	m_strmultiplesseason6;
	CString	m_strquadsseason1;
	CString	m_strquadsseason2;
	CString	m_strquadsseason3;
	CString	m_strquadsseason4;
	CString	m_strquadsseason5;
	CString	m_strquadsseason6;
	CString	m_strsinglesseason1;
	CString	m_strsinglesseason2;
	CString	m_strsinglesseason3;
	CString	m_strsinglesseason4;
	CString	m_strsinglesseason5;
	CString	m_strsinglesseason6;
	CString	m_strtriplesseason1;
	CString	m_strtriplesseason2;
	CString	m_strtriplesseason3;
	CString	m_strtriplesseason4;
	CString	m_strtriplesseason5;
	CString	m_strtriplesseason6;
	CString	m_strtwinsseason1;
	CString	m_strtwinsseason2;
	CString	m_strtwinsseason3;
	CString	m_strtwinsseason4;
	CString	m_strtwinsseason5;
	CString	m_strtwinsseason6;
	CString	m_strtsuseason1;
	CString	m_strtsuseason2;
	CString	m_strtsuseason3;
	CString	m_strtsuseason4;
	CString	m_strtsuseason5;
	CString	m_strtsuseason6;
	//}}AFX_DATA

// Attributes
public:

	CHotels m_sethotels;
	BOOL m_toegang_tonen;
	BOOL m_toegang_toevoegen;
	BOOL m_toegang_wijzigen;
	BOOL m_toegang_verwijderen;
	BOOL m_tonen;
	BOOL m_nieuw;
	BOOL m_wijzigen;
	BOOL m_verwijderen;

	void f_tab1(void);
	void f_tab2(void);
	int  m_tabkeuze;

	BOOL aanwezig(void);
	void veldenediten(BOOL);
	void recordweergeven(void);
	void veldenleegmaken(void);
	void inhoudopslaan(void);
	BOOL OpslaanCheck(void);

	double m_doublesseason1;
	double m_doublesseason2;
	double m_doublesseason3;
	double m_doublesseason4;
	double m_doublesseason5;
	double m_doublesseason6;
	double m_multiplesseason1;
	double m_multiplesseason2;
	double m_multiplesseason3;
	double m_multiplesseason4;
	double m_multiplesseason5;
	double m_multiplesseason6;
	double m_quadsseason1;
	double m_quadsseason2;
	double m_quadsseason3;
	double m_quadsseason4;
	double m_quadsseason5;
	double m_quadsseason6;
	double m_singlesseason1;
	double m_singlesseason2;
	double m_singlesseason3;
	double m_singlesseason4;
	double m_singlesseason5;
	double m_singlesseason6;
	double m_triplesseason1;
	double m_triplesseason2;
	double m_triplesseason3;
	double m_triplesseason4;
	double m_triplesseason5;
	double m_triplesseason6;
	double m_twinsseason1;
	double m_twinsseason2;
	double m_twinsseason3;
	double m_twinsseason4;
	double m_twinsseason5;
	double m_twinsseason6;
	double m_tsuseason1;
	double m_tsuseason2;
	double m_tsuseason3;
	double m_tsuseason4;
	double m_tsuseason5;
	double m_tsuseason6;

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CHotelsView)
	public:
	virtual void OnInitialUpdate();
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	virtual ~CHotelsView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

	// Generated message map functions
	//{{AFX_MSG(CHotelsView)
	afx_msg void OnClose();
	afx_msg void OnWijzigenButton();
	afx_msg void OnVorigeButton();
	afx_msg void OnVolgendeButton();
	afx_msg void OnVerwijderenButton();
	afx_msg void OnTonenButton();
	afx_msg void OnOpslaanButton();
	afx_msg void OnNieuwButton();
	afx_msg void OnNietopslaanButton();
	afx_msg void OnKillfocusCodeEdit();
	afx_msg void OnCodeButton();
	afx_msg void OnUpdateVolgendeButton(CCmdUI* pCmdUI);
	afx_msg void OnUpdateVorigeButton(CCmdUI* pCmdUI);
	afx_msg void OnUpdateOpslaanButton(CCmdUI* pCmdUI);
	afx_msg void OnUpdateNietopslaanButton(CCmdUI* pCmdUI);
	afx_msg void OnUpdateVerwijderenButton(CCmdUI* pCmdUI);
	afx_msg void OnSelchangeHotelsTab(NMHDR* pNMHDR, LRESULT* pResult);
	afx_msg void OnDestroy();
	afx_msg void OnAccel32806();
	afx_msg void OnKillfocusFromseason1Edit();
	afx_msg void OnKillfocusFromseason2Edit();
	afx_msg void OnKillfocusFromseason3Edit();
	afx_msg void OnKillfocusFromseason4Edit();
	afx_msg void OnKillfocusFromseason5Edit();
	afx_msg void OnKillfocusFromseason6Edit();
	afx_msg void OnKillfocusTillseason1Edit();
	afx_msg void OnKillfocusTillseason2Edit();
	afx_msg void OnKillfocusTillseason3Edit();
	afx_msg void OnKillfocusTillseason4Edit();
	afx_msg void OnKillfocusTillseason5Edit();
	afx_msg void OnKillfocusTillseason6Edit();
	afx_msg void OnUpdateTonenButton(CCmdUI* pCmdUI);
	afx_msg void OnUpdateWijzigenButton(CCmdUI* pCmdUI);
	afx_msg void OnUpdateNieuwButton(CCmdUI* pCmdUI);
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_HOTELSVIEW_H__EB8EA6A1_F699_11D3_BC1B_006097638FC1__INCLUDED_)
