#if !defined(AFX_ZKBOOKINGDLG_H__33497C6B_C1E2_11D3_BC18_006097638FC1__INCLUDED_)
#define AFX_ZKBOOKINGDLG_H__33497C6B_C1E2_11D3_BC18_006097638FC1__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// ZkbookingDlg.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CZkbookingDlg dialog

class CZkbookingDlg : public CDialog
{
// Construction
public:
	CZkbookingDlg(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(CZkbookingDlg)
	enum { IDD = IDD_ZKBOOKING_DIALOG };
	CListCtrl	m_lijst;
	//}}AFX_DATA

	CString m_tourref;
	BOOL    m_fit;
	int     m_item;

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CZkbookingDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CZkbookingDlg)
	virtual BOOL OnInitDialog();
	virtual void OnCancel();
	virtual void OnOK();
	afx_msg void OnDblclkLijstList(NMHDR* pNMHDR, LRESULT* pResult);
	afx_msg void OnColumnclickLijstList(NMHDR* pNMHDR, LRESULT* pResult);
	afx_msg void OnClickLijstList(NMHDR* pNMHDR, LRESULT* pResult);
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_ZKBOOKINGDLG_H__33497C6B_C1E2_11D3_BC18_006097638FC1__INCLUDED_)
