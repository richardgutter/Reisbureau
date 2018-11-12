// Booking.cpp : implementation file
//

#include "stdafx.h"
#include "travel.h"
#include "Booking.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CBooking

IMPLEMENT_DYNAMIC(CBooking, CRecordset)

CBooking::CBooking(CDatabase* pdb)
	: CRecordset(pdb)
{
	//{{AFX_FIELD_INIT(CBooking)
	m_bo_tourref = _T("");
	m_bo_periode = _T("");
	m_bo_volgnr = 0;
	m_bo_date = _T("");
	m_bo_passn = _T("");
	m_bo_pax = 0;
	m_ho_code = _T("");
	m_ho_name = _T("");
	m_ag_code = _T("");
	m_ag_name = _T("");
	m_bo_agentrf = _T("");
	m_bo_arrdate = _T("");
	m_bo_depdate = _T("");
	m_bo_nights = 0;
	m_bo_asngls = 0;
	m_bo_atwnsngls = 0;
	m_bo_atwns = 0;
	m_bo_adbls = 0;
	m_bo_atrpls = 0;
	m_bo_aqds = 0;
	m_bo_amltpls = 0;
	m_bo_rsngls = 0;
	m_bo_rtwnsngls = 0;
	m_bo_rtwns = 0;
	m_bo_rdbls = 0;
	m_bo_rtrpls = 0;
	m_bo_rqds = 0;
	m_bo_rmltpls = 0;
	m_bo_esngls = 0;
	m_bo_etwns = 0;
	m_bo_etwnsngls = 0;
	m_bo_edbls = 0;
	m_bo_etrpls = 0;
	m_bo_eqds = 0;
	m_bo_emltpls = 0;
	m_us_naam = _T("");
	m_bo_bkdby = _T("");
	m_bo_cnfmdby = _T("");
	m_bo_service = _T("");
	m_bo_arrival = _T("");
	m_bo_mhotel = _T("");
	m_bo_magent = _T("");
	m_bo_prdocket = FALSE;
	m_bo_prconfirm = FALSE;
	m_bo_prvoucher = FALSE;
	m_bo_prcancel = FALSE;
	m_bo_remark1 = _T("");
	m_bo_remark2 = _T("");
	m_bo_remark3 = _T("");
	m_bo_cancel = _T("");
	m_bo_invoice = FALSE;
	m_bo_privall = FALSE;
	m_bo_transfer = FALSE;
	m_bo_excursion = FALSE;
	m_bo_carrental = FALSE;
	m_nFields = 55;
	//}}AFX_FIELD_INIT
	m_nDefaultType = dynaset;
}


CString CBooking::GetDefaultConnect()
{
	return _T("ODBC;DSN=travel");
}

CString CBooking::GetDefaultSQL()
{
	return _T("[BOOKING]");
}

void CBooking::DoFieldExchange(CFieldExchange* pFX)
{
	//{{AFX_FIELD_MAP(CBooking)
	pFX->SetFieldType(CFieldExchange::outputColumn);
	RFX_Text(pFX, _T("[bo_tourref]"), m_bo_tourref);
	RFX_Text(pFX, _T("[bo_periode]"), m_bo_periode);
	RFX_Int(pFX, _T("[bo_volgnr]"), m_bo_volgnr);
	RFX_Text(pFX, _T("[bo_date]"), m_bo_date);
	RFX_Text(pFX, _T("[bo_passn]"), m_bo_passn);
	RFX_Int(pFX, _T("[bo_pax]"), m_bo_pax);
	RFX_Text(pFX, _T("[ho_code]"), m_ho_code);
	RFX_Text(pFX, _T("[ho_name]"), m_ho_name);
	RFX_Text(pFX, _T("[ag_code]"), m_ag_code);
	RFX_Text(pFX, _T("[ag_name]"), m_ag_name);
	RFX_Text(pFX, _T("[bo_agentrf]"), m_bo_agentrf);
	RFX_Text(pFX, _T("[bo_arrdate]"), m_bo_arrdate);
	RFX_Text(pFX, _T("[bo_depdate]"), m_bo_depdate);
	RFX_Long(pFX, _T("[bo_nights]"), m_bo_nights);
	RFX_Int(pFX, _T("[bo_asngls]"), m_bo_asngls);
	RFX_Int(pFX, _T("[bo_atwnsngls]"), m_bo_atwnsngls);
	RFX_Int(pFX, _T("[bo_atwns]"), m_bo_atwns);
	RFX_Int(pFX, _T("[bo_adbls]"), m_bo_adbls);
	RFX_Int(pFX, _T("[bo_atrpls]"), m_bo_atrpls);
	RFX_Int(pFX, _T("[bo_aqds]"), m_bo_aqds);
	RFX_Int(pFX, _T("[bo_amltpls]"), m_bo_amltpls);
	RFX_Int(pFX, _T("[bo_rsngls]"), m_bo_rsngls);
	RFX_Int(pFX, _T("[bo_rtwnsngls]"), m_bo_rtwnsngls);
	RFX_Int(pFX, _T("[bo_rtwns]"), m_bo_rtwns);
	RFX_Int(pFX, _T("[bo_rdbls]"), m_bo_rdbls);
	RFX_Int(pFX, _T("[bo_rtrpls]"), m_bo_rtrpls);
	RFX_Int(pFX, _T("[bo_rqds]"), m_bo_rqds);
	RFX_Int(pFX, _T("[bo_rmltpls]"), m_bo_rmltpls);
	RFX_Int(pFX, _T("[bo_esngls]"), m_bo_esngls);
	RFX_Int(pFX, _T("[bo_etwns]"), m_bo_etwns);
	RFX_Int(pFX, _T("[bo_etwnsngls]"), m_bo_etwnsngls);
	RFX_Int(pFX, _T("[bo_edbls]"), m_bo_edbls);
	RFX_Int(pFX, _T("[bo_etrpls]"), m_bo_etrpls);
	RFX_Int(pFX, _T("[bo_eqds]"), m_bo_eqds);
	RFX_Int(pFX, _T("[bo_emltpls]"), m_bo_emltpls);
	RFX_Text(pFX, _T("[us_naam]"), m_us_naam);
	RFX_Text(pFX, _T("[bo_bkdby]"), m_bo_bkdby);
	RFX_Text(pFX, _T("[bo_cnfmdby]"), m_bo_cnfmdby);
	RFX_Text(pFX, _T("[bo_service]"), m_bo_service);
	RFX_Text(pFX, _T("[bo_arrival]"), m_bo_arrival);
	RFX_Text(pFX, _T("[bo_mhotel]"), m_bo_mhotel);
	RFX_Text(pFX, _T("[bo_magent]"), m_bo_magent);
	RFX_Bool(pFX, _T("[bo_prdocket]"), m_bo_prdocket);
	RFX_Bool(pFX, _T("[bo_prconfirm]"), m_bo_prconfirm);
	RFX_Bool(pFX, _T("[bo_prvoucher]"), m_bo_prvoucher);
	RFX_Bool(pFX, _T("[bo_prcancel]"), m_bo_prcancel);
	RFX_Text(pFX, _T("[bo_remark1]"), m_bo_remark1);
	RFX_Text(pFX, _T("[bo_remark2]"), m_bo_remark2);
	RFX_Text(pFX, _T("[bo_remark3]"), m_bo_remark3);
	RFX_Text(pFX, _T("[bo_cancel]"), m_bo_cancel);
	RFX_Bool(pFX, _T("[bo_invoice]"), m_bo_invoice);
	RFX_Bool(pFX, _T("[bo_privall]"), m_bo_privall);
	RFX_Bool(pFX, _T("[bo_transfer]"), m_bo_transfer);
	RFX_Bool(pFX, _T("[bo_excursion]"), m_bo_excursion);
	RFX_Bool(pFX, _T("[bo_carrental]"), m_bo_carrental);
	//}}AFX_FIELD_MAP
}

/////////////////////////////////////////////////////////////////////////////
// CBooking diagnostics

#ifdef _DEBUG
void CBooking::AssertValid() const
{
	CRecordset::AssertValid();
}

void CBooking::Dump(CDumpContext& dc) const
{
	CRecordset::Dump(dc);
}
#endif //_DEBUG
