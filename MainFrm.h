// MainFrm.h : interface of the CMainFrame class
//
/////////////////////////////////////////////////////////////////////////////

#if !defined(AFX_MAINFRM_H__EB8EA668_F699_11D3_BC1B_006097638FC1__INCLUDED_)
#define AFX_MAINFRM_H__EB8EA668_F699_11D3_BC1B_006097638FC1__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

class CMainFrame : public CMDIFrameWnd
{
	DECLARE_DYNAMIC(CMainFrame)
public:
	CMainFrame();

// Attributes
public:
	BOOL m_agents;
	BOOL m_allotment;
	BOOL m_cnvexact6;
	BOOL m_coaches;
	BOOL m_configuration;
	BOOL m_fit;
	BOOL m_fitinv;
	BOOL m_groups;
	BOOL m_guides;
	BOOL m_hotels;
	BOOL m_invoices;
	BOOL m_printseries;
	BOOL m_proforma;
	BOOL m_restaurants;
	BOOL m_toegang;
	BOOL m_users;
	BOOL m_vat;
	BOOL m_vouchers;

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CMainFrame)
	public:
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
	//}}AFX_VIRTUAL

// Implementation
public:
	virtual ~CMainFrame();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:  // control bar embedded members
	CToolBar    m_wndToolBar;

// Generated message map functions
protected:
	//{{AFX_MSG(CMainFrame)
	afx_msg int OnCreate(LPCREATESTRUCT lpCreateStruct);
	afx_msg void OnUsers();
	afx_msg void OnVat();
	afx_msg void OnVouchers();
	afx_msg void OnRestaurants();
	afx_msg void OnHotels();
	afx_msg void OnGuides();
	afx_msg void OnGrpovz();
	afx_msg void OnGroups();
	afx_msg void OnFitovz();
	afx_msg void OnFitinv();
	afx_msg void OnCoaches();
	afx_msg void OnCnvexact6();
	afx_msg void OnBookings();
	afx_msg void OnAllotments();
	afx_msg void OnAgents();
	afx_msg void OnInvoices();
	afx_msg void OnProforma();
	afx_msg void OnBeheerConfiguration();
	afx_msg void OnUpdateInvoices(CCmdUI* pCmdUI);
	afx_msg void OnUpdateFitinv(CCmdUI* pCmdUI);
	afx_msg void OnInvoicesPrintseries();
	afx_msg void OnUpdateInvoicesPrintseries(CCmdUI* pCmdUI);
	afx_msg void OnUpdateAgents(CCmdUI* pCmdUI);
	afx_msg void OnUpdateAllotments(CCmdUI* pCmdUI);
	afx_msg void OnUpdateBeheerConfiguration(CCmdUI* pCmdUI);
	afx_msg void OnUpdateBookings(CCmdUI* pCmdUI);
	afx_msg void OnUpdateCnvexact6(CCmdUI* pCmdUI);
	afx_msg void OnUpdateCoaches(CCmdUI* pCmdUI);
	afx_msg void OnUpdateFitovz(CCmdUI* pCmdUI);
	afx_msg void OnUpdateGroups(CCmdUI* pCmdUI);
	afx_msg void OnUpdateGrpovz(CCmdUI* pCmdUI);
	afx_msg void OnUpdateGuides(CCmdUI* pCmdUI);
	afx_msg void OnUpdateHotels(CCmdUI* pCmdUI);
	afx_msg void OnUpdateProforma(CCmdUI* pCmdUI);
	afx_msg void OnUpdateRestaurants(CCmdUI* pCmdUI);
	afx_msg void OnUpdateUsers(CCmdUI* pCmdUI);
	afx_msg void OnUpdateVat(CCmdUI* pCmdUI);
	afx_msg void OnUpdateVouchers(CCmdUI* pCmdUI);
	afx_msg void OnToegang();
	afx_msg void OnUpdateToegang(CCmdUI* pCmdUI);
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_MAINFRM_H__EB8EA668_F699_11D3_BC1B_006097638FC1__INCLUDED_)
