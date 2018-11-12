#if !defined(AFX_BOOKING_H__23A8AF00_FC8E_11D4_BC1D_006097638FC1__INCLUDED_)
#define AFX_BOOKING_H__23A8AF00_FC8E_11D4_BC1D_006097638FC1__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// Booking.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CBooking recordset

class CBooking : public CRecordset
{
public:
	CBooking(CDatabase* pDatabase = NULL);
	DECLARE_DYNAMIC(CBooking)

// Field/Param Data
	//{{AFX_FIELD(CBooking, CRecordset)
	CString	m_bo_tourref;
	CString	m_bo_periode;
	int		m_bo_volgnr;
	CString	m_bo_date;
	CString	m_bo_passn;
	int		m_bo_pax;
	CString	m_ho_code;
	CString	m_ho_name;
	CString	m_ag_code;
	CString	m_ag_name;
	CString	m_bo_agentrf;
	CString	m_bo_arrdate;
	CString	m_bo_depdate;
	long	m_bo_nights;
	int		m_bo_asngls;
	int		m_bo_atwnsngls;
	int		m_bo_atwns;
	int		m_bo_adbls;
	int		m_bo_atrpls;
	int		m_bo_aqds;
	int		m_bo_amltpls;
	int		m_bo_rsngls;
	int		m_bo_rtwnsngls;
	int		m_bo_rtwns;
	int		m_bo_rdbls;
	int		m_bo_rtrpls;
	int		m_bo_rqds;
	int		m_bo_rmltpls;
	int		m_bo_esngls;
	int		m_bo_etwns;
	int		m_bo_etwnsngls;
	int		m_bo_edbls;
	int		m_bo_etrpls;
	int		m_bo_eqds;
	int		m_bo_emltpls;
	CString	m_us_naam;
	CString	m_bo_bkdby;
	CString	m_bo_cnfmdby;
	CString	m_bo_service;
	CString	m_bo_arrival;
	CString	m_bo_mhotel;
	CString	m_bo_magent;
	BOOL	m_bo_prdocket;
	BOOL	m_bo_prconfirm;
	BOOL	m_bo_prvoucher;
	BOOL	m_bo_prcancel;
	CString	m_bo_remark1;
	CString	m_bo_remark2;
	CString	m_bo_remark3;
	CString	m_bo_cancel;
	BOOL	m_bo_invoice;
	BOOL	m_bo_privall;
	BOOL	m_bo_transfer;
	BOOL	m_bo_excursion;
	BOOL	m_bo_carrental;
	//}}AFX_FIELD


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CBooking)
	public:
	virtual CString GetDefaultConnect();    // Default connection string
	virtual CString GetDefaultSQL();    // Default SQL for Recordset
	virtual void DoFieldExchange(CFieldExchange* pFX);  // RFX support
	//}}AFX_VIRTUAL

// Implementation
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_BOOKING_H__23A8AF00_FC8E_11D4_BC1D_006097638FC1__INCLUDED_)
