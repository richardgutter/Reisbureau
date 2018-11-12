#if !defined(AFX_AGENTSVIEW_H__EB8EA68F_F699_11D3_BC1B_006097638FC1__INCLUDED_)
#define AFX_AGENTSVIEW_H__EB8EA68F_F699_11D3_BC1B_006097638FC1__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// AgentsView.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CAgentsView form view

#ifndef __AFXEXT_H__
#include <afxext.h>
#endif

#include "agents.h"

class CAgentsView : public CFormView
{
protected:
	CAgentsView();           // protected constructor used by dynamic creation
	DECLARE_DYNCREATE(CAgentsView)

// Form Data
public:
	//{{AFX_DATA(CAgentsView)
	enum { IDD = IDD_AGENTS_DIALOG };
	CComboBox	m_language_cntrl;
	CEdit	m_zipcode_cntrl;
	CEdit	m_vat_cntrl;
	CEdit	m_tel_cntrl;
	CEdit	m_remark_cntrl;
	CButton	m_pricecat1_cntrl;
	CEdit	m_number_cntrl;
	CEdit	m_naam_cntrl;
	CEdit	m_fax_cntrl;
	CEdit	m_email_cntrl;
	CEdit	m_department_cntrl;
	CEdit	m_country_cntrl;
	CEdit	m_code_cntrl;
	CEdit	m_city_cntrl;
	CEdit	m_address2_cntrl;
	CEdit	m_address1_cntrl;
	CString	m_address1;
	CString	m_address2;
	CString	m_code;
	CString	m_department;
	CString	m_fax;
	CString	m_naam;
	CString	m_tel;
	CString	m_vat;
	int		m_pricecat1;
	CString	m_remark;
	CString	m_city;
	CString	m_country;
	CString	m_email;
	CString	m_zipcode;
	CString	m_number;
	CString	m_language;
	//}}AFX_DATA

// Attributes
public:

	CAgents m_setagents;
	BOOL m_toegang_tonen;
	BOOL m_toegang_toevoegen;
	BOOL m_toegang_wijzigen;
	BOOL m_toegang_verwijderen;
	BOOL m_tonen;
	BOOL m_nieuw;
	BOOL m_wijzigen;
	BOOL m_verwijderen;

	BOOL aanwezig(void);
	void veldenediten(BOOL);
	void recordweergeven(void);
	void veldenleegmaken(void);
	void inhoudopslaan(void);
	BOOL OpslaanCheck(void);

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CAgentsView)
	public:
	virtual void OnInitialUpdate();
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	virtual ~CAgentsView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

	// Generated message map functions
	//{{AFX_MSG(CAgentsView)
	afx_msg void OnClose();
	afx_msg void OnVerwijderenButton();
	afx_msg void OnVolgendeButton();
	afx_msg void OnVorigeButton();
	afx_msg void OnWijzigenButton();
	afx_msg void OnOpslaanButton();
	afx_msg void OnNieuwButton();
	afx_msg void OnNietopslaanButton();
	afx_msg void OnCodeButton();
	afx_msg void OnKillfocusCodeEdit();
	afx_msg void OnUpdateVolgendeButton(CCmdUI* pCmdUI);
	afx_msg void OnUpdateVorigeButton(CCmdUI* pCmdUI);
	afx_msg void OnUpdateOpslaanButton(CCmdUI* pCmdUI);
	afx_msg void OnUpdateNietopslaanButton(CCmdUI* pCmdUI);
	afx_msg void OnTonenButton();
	afx_msg void OnUpdateVerwijderenButton(CCmdUI* pCmdUI);
	afx_msg void OnDestroy();
	afx_msg void OnUpdateWijzigenButton(CCmdUI* pCmdUI);
	afx_msg void OnUpdateTonenButton(CCmdUI* pCmdUI);
	afx_msg void OnUpdateNieuwButton(CCmdUI* pCmdUI);
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_AGENTSVIEW_H__EB8EA68F_F699_11D3_BC1B_006097638FC1__INCLUDED_)
