// Cnvexact6View.cpp : implementation file
//

#include "stdafx.h"
#include "travel.h"
#include "Cnvexact6View.h"

#include <stdio.h>
#include <io.h>
#include <stdlib.h>
#include <process.h>
#include <conio.h> 
#include "zkinvoicedlg.h"
#include "invoices.h"
#include "datecnv.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CCnvexact6View

IMPLEMENT_DYNCREATE(CCnvexact6View, CFormView)

CCnvexact6View::CCnvexact6View()
	: CFormView(CCnvexact6View::IDD)
{
	//{{AFX_DATA_INIT(CCnvexact6View)
	m_tm = 0;
	m_van = 0;
	//}}AFX_DATA_INIT
}

CCnvexact6View::~CCnvexact6View()
{
}

void CCnvexact6View::DoDataExchange(CDataExchange* pDX)
{
	CFormView::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CCnvexact6View)
	DDX_Text(pDX, IDC_TM_EDIT, m_tm);
	DDX_Text(pDX, IDC_VAN_EDIT, m_van);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CCnvexact6View, CFormView)
	//{{AFX_MSG_MAP(CCnvexact6View)
	ON_BN_CLICKED(IDC_VAN_BUTTON, OnVanButton)
	ON_BN_CLICKED(IDC_TM_BUTTON, OnTmButton)
	ON_BN_CLICKED(IDC_CONVERSION_BUTTON, OnConversionButton)
	ON_WM_DESTROY()
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CCnvexact6View diagnostics

#ifdef _DEBUG
void CCnvexact6View::AssertValid() const
{
	CFormView::AssertValid();
}

void CCnvexact6View::Dump(CDumpContext& dc) const
{
	CFormView::Dump(dc);
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CCnvexact6View message handlers

extern CTravelApp theApp;

void CCnvexact6View::OnInitialUpdate() 
{
	CFormView::OnInitialUpdate();
	
	// TODO: Add your specialized code here and/or call the base class

	GetDocument()->SetTitle("Conversion EXACT 6");

	CFormView::OnInitialUpdate();
	
	// change our size to a nice size :)
	ResizeParentToFit(false);
}

void CCnvexact6View::OnDestroy() 
{
	CFormView::OnDestroy();
	
	// TODO: Add your message handler code here
	theApp.cnvexact6view = FALSE;
}

void CCnvexact6View::OnVanButton() 
{
	// TODO: Add your control notification handler code here
	CZkinvoiceDlg dlg;
	dlg.DoModal();
	if (dlg.m_number != 0)
	{
		m_van = dlg.m_number;
		UpdateData(FALSE);
	}
}

void CCnvexact6View::OnTmButton() 
{
	// TODO: Add your control notification handler code here
	CZkinvoiceDlg dlg;
	dlg.DoModal();
	if (dlg.m_number != 0)
	{
		m_tm = dlg.m_number;
		UpdateData(FALSE);
	}
}

void CCnvexact6View::OnConversionButton() 
{
	// TODO: Add your control notification handler code here
	static int i = 0;

	BeginWaitCursor();
	UpdateData(TRUE);

	if (m_van == 0 && m_tm != 0)
		m_van = 1;
	if (m_van != 0 && m_tm == 0)
		m_tm = m_van;

	if (m_van == 0 && m_tm == 0)
		;
	else if (i == 0)
	{
		i++;
		if ((uit = fopen("C:\\EXACT\\IMPORT\\FMUTA6.IMP", "wt")) != NULL)
		{
			Conversie();
			fclose(uit);
		}
		else
			MessageBox("The file FMUTA6.IMP couldn't be made !",
				"Conversion EXACT 6", MB_OK  + MB_ICONSTOP);
	}
	else
	{
		i++;
		if ((uit = fopen("C:\\EXACT\\IMPORT\\FMUTA6.IMP", "at")) != NULL)
		{
			Conversie();
			fclose(uit);
		}
		else
			MessageBox("The file FMUTA6.IMP couldn't be opened !",
				"Conversion EXACT 6", MB_OK  + MB_ICONSTOP);
	}
	EndWaitCursor();
}

void CCnvexact6View::Conversie() 
{
	// TODO: Add extra validation here
	CInvoices m_setinvoices;
	CDatecnv  m_datecnv;

	CString boeknr = "8000";
	CString boekjaar;
	CString periode;
	CString datum;
	long    rekeningnr;
	double  bedrag;
	CString omschrijving;
	CString debiteurnr;
	CString m_zoekwaarde;
	CString m_beginwaarde;
	CString m_eindwaarde;

	m_beginwaarde.Format("%d", m_van);
	m_eindwaarde.Format("%d", m_tm);
	m_zoekwaarde = "invoicenr >= " + m_beginwaarde
		+ "and invoicenr <= " + m_eindwaarde;
	m_setinvoices.m_strFilter = m_zoekwaarde;
	m_setinvoices.Open();

//	if (!m_setinvoices.IsEOF())
//	{
//		while (m_setinvoices.m_invoicenr <= m_tm
//				&& !m_setinvoices.IsEOF())
		while (!m_setinvoices.IsEOF())
		{
			datum  = m_setinvoices.m_date[6];
			datum += m_setinvoices.m_date[7];
			datum += m_setinvoices.m_date[4];
			datum += m_setinvoices.m_date[5];
			datum += m_setinvoices.m_date[0];
			datum += m_setinvoices.m_date[1];
			datum += m_setinvoices.m_date[2];
			datum += m_setinvoices.m_date[3];

			periode = " ";
			if (datum.GetAt(4) != '0')
				periode += datum[2];
			else
				periode += " ";
			periode += datum[3];

			boekjaar  = datum[4];
			boekjaar += datum[5];
			boekjaar += datum[6];
			boekjaar += datum[7];

			rekeningnr   = m_setinvoices.m_invoicenr;
			bedrag       = m_setinvoices.m_total;
			omschrijving = m_setinvoices.m_reference;
			debiteurnr   = m_setinvoices.m_clientnr;

		    fprintf(uit, "\"   0\",\"V\",\" 2\",");
			fprintf(uit, "\"%s\",", periode);
			fprintf(uit, "\"%s\",", boekjaar);
			fprintf(uit, "\"%d\",", rekeningnr);
			fprintf(uit, "\"%s\",", omschrijving);
			fprintf(uit, "\"%s\",", datum);
			fprintf(uit, "\"\",");
			fprintf(uit, "\"%s\",", debiteurnr);
			fprintf(uit, "\"\",\"\",");
			fprintf(uit, "%.2f", bedrag);
			fprintf(uit, "\"J\",\"HFL\",     1.000000,\"\",        0.00,");
			fprintf(uit, "\"%s\",", datum);
			fprintf(uit, "\"\",\"\",       0.00,\"\",\"\",\"\",        0.00,");
			fprintf(uit, "\"\",\"\",       0.00,\"\",\"\",\"N\",\"\",       0.00,");
			fprintf(uit, "       0.00,       0.00,       0.00,\"\",\"\",\"\"\n");
	
		    fprintf(uit, "\"   1\",\"V\",\" 2\",");
			fprintf(uit, "\"%s\",", periode);
			fprintf(uit, "\"%s\",", boekjaar);
			fprintf(uit, "\"%d\",", rekeningnr);
			fprintf(uit, "\"%s\",", omschrijving);
			fprintf(uit, "\"%s\",", datum);
			fprintf(uit, "\"%s\",", boeknr);
			fprintf(uit, "\"\",\"\",\"\",");
			fprintf(uit, "%.2f,", bedrag);
			fprintf(uit, "\"\",\"HFL\",     1.000000,\"\",        0.00,");
			fprintf(uit, "\"\",\"\",\"0  \",        0.00,\"\",\"\",\"\",");
			fprintf(uit, "       0.00,\"\",\"\",        0.00,\"0\",\"\",\"N\",");
			fprintf(uit, "\"\",        0.00,        0.00,      0.00,      0.00,");
			fprintf(uit, "\"\",\"\",\"\"\n");

			m_setinvoices.MoveNext();
		}

		m_setinvoices.Close();
//	}
}
