#if !defined(AFX_BOOKINGSVIEW_H__EB8EA691_F699_11D3_BC1B_006097638FC1__INCLUDED_)
#define AFX_BOOKINGSVIEW_H__EB8EA691_F699_11D3_BC1B_006097638FC1__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// BookingsView.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CBookingsView form view

#ifndef __AFXEXT_H__
#include <afxext.h>
#endif

#include "booking.h"
#include "allotmperioden.h"

class CBookingsView : public CFormView
{
protected:
	CBookingsView();           // protected constructor used by dynamic creation
	DECLARE_DYNCREATE(CBookingsView)

// Form Data
public:
	//{{AFX_DATA(CBookingsView)
	enum { IDD = IDD_BOOKINGS_DIALOG };
	CEdit	m_remarks_cntrl;
	CEdit	m_stretwinsingles_cntrl;
	CEdit	m_stretwins_cntrl;
	CEdit	m_stretriples_cntrl;
	CEdit	m_stresingles_cntrl;
	CEdit	m_strequads_cntrl;
	CEdit	m_stremultiples_cntrl;
	CEdit	m_stredoubles_cntrl;
	CEdit	m_strctwinsingles_cntrl;
	CEdit	m_strctwins_cntrl;
	CEdit	m_strctriples_cntrl;
	CEdit	m_strcsingles_cntrl;
	CEdit	m_strcquads_cntrl;
	CEdit	m_strcmultiples_cntrl;
	CEdit	m_strcdoubles_cntrl;
	CEdit	m_stratwinsingles_cntrl;
	CEdit	m_stratwins_cntrl;
	CEdit	m_stratriples_cntrl;
	CEdit	m_strasingles_cntrl;
	CEdit	m_straquads_cntrl;
	CEdit	m_stramultiples_cntrl;
	CEdit	m_stradoubels_cntrl;
	CEdit	m_tourref_cntrl;
	CButton	m_prvoucher_cntrl;
	CButton	m_prreconfirmation_cntrl;
	CEdit	m_prmhotel_cntrl;
	CEdit	m_prmagent_cntrl;
	CButton	m_prdocket_cntrl;
	CButton	m_prcancellation_cntrl;
	CEdit	m_algpax_cntrl;
	CEdit	m_algpassenger_cntrl;
	CEdit	m_alghotelcode_cntrl;
	CEdit	m_algdepartdate_cntrl;
	CEdit	m_algconfirmedby_cntrl;
	CEdit	m_algbookedby_cntrl;
	CEdit	m_algarrivaldate_cntrl;
	CEdit	m_agreference_cntrl;
	CEdit	m_agagentcode_cntrl;
	CTabCtrl	m_tab;
	CString	m_tourref;
	CString	m_alghotelcode;
	CString	m_algpassenger;
	int		m_algpax;
	CString	m_algbookedby;
	CString	m_algconfirmedby;
	CString	m_agreference;
	CString	m_agagentcode;
	CString	m_service;
	BOOL	m_voucher;
	CString	m_arrival;
	int		m_ronormal;
	int		m_robb;
	CString	m_prmagent;
	CString	m_prmhotel;
	BOOL	m_prcancellation;
	BOOL	m_prdocket;
	BOOL	m_prreconfirmation;
	BOOL	m_prvoucher;
	CString	m_algarrivaldate;
	CString	m_algdepartdate;
	CString	m_strcsingles;
	CString	m_stradoubles;
	CString	m_stramultiples;
	CString	m_straquads;
	CString	m_strasingles;
	CString	m_stratriples;
	CString	m_stratwins;
	CString	m_stratwinsingles;
	CString	m_strcdoubles;
	CString	m_strcmultiples;
	CString	m_strcquads;
	CString	m_strctriples;
	CString	m_strctwins;
	CString	m_strctwinsingles;
	CString	m_stredoubles;
	CString	m_stremultiples;
	CString	m_strequads;
	CString	m_stresingles;
	CString	m_stretriples;
	CString	m_stretwins;
	CString	m_stretwinsingles;
	CString	m_bookingdate;
	CString	m_user;
	CString	m_canceltext;
	CString	m_date_text;
	CString	m_alghotelnaam;
	CString	m_algnights;
	CString	m_algdepartday;
	CString	m_algarrivalday;
	CString	m_agagentname;
	CString	m_remarks;
	BOOL	m_remcarrental;
	BOOL	m_remexcursion;
	BOOL	m_remtransfer;
	BOOL	m_roperiode1;
	BOOL	m_roperiode2;
	BOOL	m_roperiode3;
	BOOL	m_roperiode4;
	BOOL	m_roperiode5;
	CString	m_robuttonnr;
	BOOL	m_roperiode6;
	BOOL	m_roperiode7;
	BOOL	m_roperiode8;
	BOOL	m_roperiode9;
	BOOL	m_roperiode10;
	//}}AFX_DATA

// Attributes
public:

	int m_nights;
	CString m_gebruiker;

	int m_periodes;
	BOOL m_nuldeperiode;
	BOOL m_buttoncheck;
	int m_periode;
	CString m_startdates[100];
	CString m_enddates[100];
	int m_allotment[100];
	int m_extra[100];
	int m_rocsingles[10];
	int m_roasingles[10];
	int m_roesingles[10];
	int m_roatwinsingles[10];
	int m_roetwinsingles[10];
	int m_roctwinsingles[10];
	int m_roatwins[10];
	int m_roetwins[10];
	int m_roctwins[10];
	int m_roadoubles[10];
	int m_roedoubles[10];
	int m_rocdoubles[10];
	int m_roatriples[10];
	int m_roetriples[10];
	int m_roctriples[10];
	int m_roaquads[10];
	int m_roequads[10];
	int m_rocquads[10];
	int m_roamultiples[10];
	int m_roemultiples[10];
	int m_rocmultiples[10];

	CString m_oldstartdates[10];
	CString m_oldenddates[10];
	int m_oldallotment[10];
	int m_oldextra[10];
	int m_oldcsingles[10];
	int m_oldasingles[10];
	int m_oldesingles[10];
	int m_oldatwinsingles[10];
	int m_oldetwinsingles[10];
	int m_oldctwinsingles[10];
	int m_oldatwins[10];
	int m_oldetwins[10];
	int m_oldctwins[10];
	int m_oldadoubles[10];
	int m_oldedoubles[10];
	int m_oldcdoubles[10];
	int m_oldatriples[10];
	int m_oldetriples[10];
	int m_oldctriples[10];
	int m_oldaquads[10];
	int m_oldequads[10];
	int m_oldcquads[10];
	int m_oldamultiples[10];
	int m_oldemultiples[10];
	int m_oldcmultiples[10];

	CString m_xstartdates[10];
	CString m_xenddates[10];
	int m_xallotment[10];
	int m_xextra[10];
	int m_xcsingles[10];
	int m_xasingles[10];
	int m_xesingles[10];
	int m_xatwinsingles[10];
	int m_xetwinsingles[10];
	int m_xctwinsingles[10];
	int m_xatwins[10];
	int m_xetwins[10];
	int m_xctwins[10];
	int m_xadoubles[10];
	int m_xedoubles[10];
	int m_xcdoubles[10];
	int m_xatriples[10];
	int m_xetriples[10];
	int m_xctriples[10];
	int m_xaquads[10];
	int m_xequads[10];
	int m_xcquads[10];
	int m_xamultiples[10];
	int m_xemultiples[10];
	int m_xcmultiples[10];

	CBooking m_setbooking;
	CAllotmperioden m_setperioden;
	BOOL m_toegang_tonen;
	BOOL m_toegang_toevoegen;
	BOOL m_toegang_wijzigen;
	BOOL m_toegang_verwijderen;
	BOOL m_toegang_cancellen;
	BOOL m_tonen;
	BOOL m_nieuw;
	BOOL m_wijzigen;
	BOOL m_verwijderen;
	BOOL m_cancel;
	BOOL m_privallotment;

	BOOL aanwezig(void);
	void veldenediten(BOOL);
	void recordweergeven(void);
	void veldenleegmaken(void);
	void inhoudopslaan(void);
	BOOL OpslaanCheck(void);

	void f_tab1(void);
	void f_tab2(void);
	void f_tab3(void);
	void f_tab4(void);
	int  m_tabkeuze;

	void bepaal_tourref(void);
	void VoegtoeAllotment(CString, COleDateTime);
	int  BerekenAantaldagen(COleDateTime);
	void BerekenAvailable(void);
	void ChangeAvailable(void);
	void BerekenMax();
	BOOL AllocateRooms(void);
	BOOL ChangeRooms(void);
	void DeleteRooms(void);

	CString m_jmmdd;
	int m_volgnr;

	long m_vouchernr;

	int m_lengte;
	int m_pages;
	BOOL m_printdirect;

	void prnt_fit(CDC*);
	void prnt_fitdocket(CDC*, int);
	void MakeVoucher(void);
	void prnt_voucher(CDC*, int);
	void prnt_confirmation(CDC*, int);
	void prnt_fitcancellation(CDC*, int);

	CString MaakStr(double);
	CString MaakStr(int);
	CString MaakStr2(int);

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CBookingsView)
	public:
	virtual void OnInitialUpdate();
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	virtual BOOL OnPreparePrinting(CPrintInfo* pInfo);
	virtual void OnBeginPrinting(CDC* pDC, CPrintInfo* pInfo);
	virtual void OnPrint(CDC* pDC, CPrintInfo* pInfo);
	virtual void OnEndPrinting(CDC* pDC, CPrintInfo* pInfo);
	virtual void OnDraw(CDC* pDC);
	//}}AFX_VIRTUAL

// Implementation
protected:
	virtual ~CBookingsView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

	// Generated message map functions
	//{{AFX_MSG(CBookingsView)
	afx_msg void OnClose();
	afx_msg void OnWijzigenButton();
	afx_msg void OnVorigeButton();
	afx_msg void OnVolgendeButton();
	afx_msg void OnVerwijderenButton();
	afx_msg void OnTourrefButton();
	afx_msg void OnTonenButton();
	afx_msg void OnPrivallotmentButton();
	afx_msg void OnOpslaanButton();
	afx_msg void OnNieuwButton();
	afx_msg void OnNietopslaanButton();
	afx_msg void OnCancelButton();
	afx_msg void OnAlghotelButton();
	afx_msg void OnAgagentButton();
	afx_msg void OnKillfocusAgagentcodeEdit();
	afx_msg void OnKillfocusAlghotelcodeEdit();
	afx_msg void OnKillfocusAlgarrivaldateEdit();
	afx_msg void OnKillfocusAlgdepartdateEdit();
	afx_msg void OnKillfocusTourrefEdit();
	afx_msg void OnSelchangeBookingTab(NMHDR* pNMHDR, LRESULT* pResult);
	afx_msg void OnUpdateFilePrint(CCmdUI* pCmdUI);
	afx_msg void OnUpdateFilePrintDirect(CCmdUI* pCmdUI);
	afx_msg void OnUpdateFilePrintPreview(CCmdUI* pCmdUI);
	afx_msg void OnUpdateVolgendeButton(CCmdUI* pCmdUI);
	afx_msg void OnUpdateVorigeButton(CCmdUI* pCmdUI);
	afx_msg void OnUpdateOpslaanButton(CCmdUI* pCmdUI);
	afx_msg void OnUpdateNietopslaanButton(CCmdUI* pCmdUI);
	afx_msg void OnUpdateVerwijderenButton(CCmdUI* pCmdUI);
	afx_msg void OnDestroy();
	afx_msg void OnAccel32806();
	afx_msg void OnRoperiode1Button();
	afx_msg void OnRoperiode2Button();
	afx_msg void OnRoperiode3Button();
	afx_msg void OnRoperiode4Button();
	afx_msg void OnRoperiode5Button();
	afx_msg void OnUpdateTonenButton(CCmdUI* pCmdUI);
	afx_msg void OnUpdateWijzigenButton(CCmdUI* pCmdUI);
	afx_msg void OnUpdateCancelButton(CCmdUI* pCmdUI);
	afx_msg void OnUpdateNieuwButton(CCmdUI* pCmdUI);
	afx_msg void OnRoperiode0Button();
	afx_msg void OnRoinputButton();
	afx_msg void OnRoperiode10Button();
	afx_msg void OnRoperiode6Button();
	afx_msg void OnRoperiode7Button();
	afx_msg void OnRoperiode8Button();
	afx_msg void OnRoperiode9Button();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_BOOKINGSVIEW_H__EB8EA691_F699_11D3_BC1B_006097638FC1__INCLUDED_)
