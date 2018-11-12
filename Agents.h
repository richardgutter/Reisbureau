#if !defined(AFX_AGENTS_H__5FFDEC64_FEC7_11D3_BC1B_006097638FC1__INCLUDED_)
#define AFX_AGENTS_H__5FFDEC64_FEC7_11D3_BC1B_006097638FC1__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// Agents.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CAgents recordset

class CAgents : public CRecordset
{
public:
	CAgents(CDatabase* pDatabase = NULL);
	DECLARE_DYNAMIC(CAgents)

// Field/Param Data
	//{{AFX_FIELD(CAgents, CRecordset)
	CString	m_ag_code;
	CString	m_ag_name;
	CString	m_ag_addr1;
	CString	m_ag_addr2;
	CString	m_ag_zipcode;
	CString	m_ag_city;
	CString	m_ag_country;
	CString	m_ag_departm;
	CString	m_ag_tel;
	CString	m_ag_fax;
	CString	m_ag_email;
	CString	m_ag_lang;
	CString	m_ag_number;
	CString	m_ag_vatnr;
	CString	m_ag_price;
	CString	m_ag_remark;
	//}}AFX_FIELD


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CAgents)
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

#endif // !defined(AFX_AGENTS_H__5FFDEC64_FEC7_11D3_BC1B_006097638FC1__INCLUDED_)
