#if !defined(AFX_FITBOOKINGDATEVIEW_H__082B9D66_F829_11D3_BC1B_006097638FC1__INCLUDED_)
#define AFX_FITBOOKINGDATEVIEW_H__082B9D66_F829_11D3_BC1B_006097638FC1__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// FitbookingdateView.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CFitbookingdateView view

#include "booking.h"

class CFitbookingdateView : public CScrollView
{
protected:
	CFitbookingdateView();           // protected constructor used by dynamic creation
	DECLARE_DYNCREATE(CFitbookingdateView)

// Attributes
public:
	CBooking m_setbooking;
	int m_breedte;
	long m_pages;

	long m_aantal_regels;
	long m_aantal_regels_kop;

	long m_p_start_regel;
	long m_p_aantal_regels ;
	long m_begin;

	void ovz_fitbookingdate(CDC*, double);
	void prnt_fitbookingdate(CDC*, double);

	CString MaakStr(double);
	CString MaakStr(int);

	CString m_selstartcode;
	CString m_selstartdate;
	CString m_selenddate;
	CString m_selname;
	long    m_selnumberfrom;
	long    m_selnumberto;
	CString m_selclnamefrom;
	CString m_selclnameto;
	BOOL    m_selcancelled;


// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CFitbookingdateView)
	public:
	virtual BOOL OnScroll(UINT nScrollCode, UINT nPos, BOOL bDoScroll = TRUE);
	protected:
	virtual void OnDraw(CDC* pDC);      // overridden to draw this view
	virtual void OnInitialUpdate();     // first time after construct
	virtual void OnPrint(CDC* pDC, CPrintInfo* pInfo);
	virtual void OnBeginPrinting(CDC* pDC, CPrintInfo* pInfo);
	virtual BOOL OnPreparePrinting(CPrintInfo* pInfo);
	virtual void OnEndPrinting(CDC* pDC, CPrintInfo* pInfo);
	virtual BOOL OnScrollBy(CSize sizeScroll, BOOL bDoScroll = TRUE);
	//}}AFX_VIRTUAL

// Implementation
protected:
	virtual ~CFitbookingdateView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

	// Generated message map functions
	//{{AFX_MSG(CFitbookingdateView)
		// NOTE - the ClassWizard will add and remove member functions here.
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_FITBOOKINGDATEVIEW_H__082B9D66_F829_11D3_BC1B_006097638FC1__INCLUDED_)
