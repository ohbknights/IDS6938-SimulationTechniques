// Panel.cpp : implementation file
//

#include "stdafx.h"
#include "Behavior.h"
#include "Panel.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CPanel

IMPLEMENT_DYNCREATE(CPanel, CFormView)

CPanel::CPanel()
	: CFormView(CPanel::IDD)
{
	//{{AFX_DATA_INIT(CPanel)
	m_Number = 0;
	m_KAlign = 0.0;
	m_KArrival = 0.0;
	m_KAvoid = 0.0;
	m_KCohesion = 0.0;
	m_KDeparture = 0.0;
	m_KNeighborhood = 0.0;
	m_KNoise = 0.0;
	m_KV0 = 0.0;
	m_KP1 = 0.0;
	m_KV1 = 0.0;
	m_KSeparate = 0.0;
	m_KWander = 0.0;
	m_TAvoid = 0.0;
	m_Mass = 0.0;
	m_MaxForce = 0.0;
	m_MaxTorque = 0.0;
	m_MaxVel = 0.0;
	m_MaxW = 0.0;
	m_Inertia = 0.0;
	//}}AFX_DATA_INIT
	sim = NULL;
}

CPanel::~CPanel()
{
}

void CPanel::DoDataExchange(CDataExchange* pDX)
{
	CFormView::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CPanel)
	DDX_Text(pDX, IDC_NUMBER, m_Number);
	DDV_MinMaxUInt(pDX, m_Number, 1, 5000);
	DDX_Text(pDX, IDC_EDIT_KALIGN, m_KAlign);
	DDX_Text(pDX, IDC_EDIT_KARRIVAL, m_KArrival);
	DDX_Text(pDX, IDC_EDIT_KAVOID, m_KAvoid);
	DDX_Text(pDX, IDC_EDIT_KCOHESION, m_KCohesion);
	DDX_Text(pDX, IDC_EDIT_KDEPARTURE, m_KDeparture);
	DDX_Text(pDX, IDC_EDIT_KNEIGHBOR, m_KNeighborhood);
	DDX_Text(pDX, IDC_EDIT_KNOISE, m_KNoise);
	DDX_Text(pDX, IDC_EDIT_KV0, m_KV0);
	DDX_Text(pDX, IDC_EDIT_KP1, m_KP1);
	DDX_Text(pDX, IDC_EDIT_KV1, m_KV1);
	DDX_Text(pDX, IDC_EDIT_KSEPARATE, m_KSeparate);
	DDX_Text(pDX, IDC_EDIT_KWANDER, m_KWander);
	DDX_Text(pDX, IDC_EDIT_TAVOID, m_TAvoid);
	DDX_Text(pDX, IDC_EDIT_MASS, m_Mass);
	DDX_Text(pDX, IDC_EDIT_MAXFORCE, m_MaxForce);
	DDX_Text(pDX, IDC_EDIT_MAXTORQUE, m_MaxTorque);
	DDX_Text(pDX, IDC_EDIT_MAXVEL, m_MaxVel);
	DDX_Text(pDX, IDC_EDIT_MAXW, m_MaxW);
	DDX_Text(pDX, IDC_EDIT_INERTIA, m_Inertia);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CPanel, CFormView)
	//{{AFX_MSG_MAP(CPanel)
	ON_BN_CLICKED(IDC_BUTTON_NUM, OnButtonNum)
	ON_BN_CLICKED(IDC_RADIO_ARRIVAL, OnRadioArrival)
	ON_BN_CLICKED(IDC_RADIO_DEPARTURE, OnRadioDeparture)
	ON_BN_CLICKED(IDC_RADIO_FLEE, OnRadioFlee)
	ON_BN_CLICKED(IDC_RADIO_SEEK, OnRadioSeek)
	ON_BN_CLICKED(IDC_RADIO_WANDER, OnRadioWander)
	ON_BN_CLICKED(IDC_RADIO_OAVOID, OnRadioOavoid)
	ON_BN_CLICKED(IDC_RADIO_SEPARATION, OnRadioSeparation)
	ON_BN_CLICKED(IDC_RADIO_ALIGNMENT, OnRadioAlignment)
	ON_BN_CLICKED(IDC_RADIO_COHESION, OnRadioCohesion)
	ON_BN_CLICKED(IDC_RADIO_FLOCKING, OnRadioFlocking)
	ON_BN_CLICKED(IDC_RADIO_LEAD, OnRadioLead)
	ON_BN_CLICKED(IDC_BUTTON_UPDATE, OnButtonUpdate)
	ON_BN_CLICKED(IDC_CHECK_DEBUG, OnCheckDebug)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CPanel diagnostics

#ifdef _DEBUG
void CPanel::AssertValid() const
{
	CFormView::AssertValid();
}

void CPanel::Dump(CDumpContext& dc) const
{
	CFormView::Dump(dc);
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CPanel message handlers

void CPanel::GetSimulation(CSimulation *sim)
{
	this->sim = sim;
}

void CPanel::OnInitialUpdate() 
{
	CFormView::OnInitialUpdate();
	
	// TODO: Add your specialized code here and/or call the base class
	if (sim){
		m_Number = 1;
		sim->CreateAgents(m_Number);
		CheckRadioButton(IDC_RADIO_SEEK, IDC_RADIO_OAVOID, IDC_RADIO_ARRIVAL);
		sim->type = SEEK;
		m_Mass = SIMAgent::Mass;
		m_Inertia = SIMAgent::Inertia;
		m_MaxForce = SIMAgent::MaxForce;
		m_MaxTorque = SIMAgent::MaxTorque;
		m_MaxW = SIMAgent::MaxAngVel;
		m_MaxVel = SIMAgent::MaxVelocity;
		m_KAlign = SIMAgent::KAlign;
		m_KArrival = SIMAgent::KArrival;
		m_KAvoid = SIMAgent::KAvoid;
		m_KCohesion = SIMAgent::KCohesion;
		m_KDeparture = SIMAgent::KDeparture;
		m_KNeighborhood = SIMAgent::RNeighborhood;
		m_KNoise = SIMAgent::KNoise;
		m_KV0 = SIMAgent::Kv0;
		m_KP1 = SIMAgent::Kp1;
		m_KV1 = SIMAgent::Kv1;
		m_KSeparate = SIMAgent::KSeparate;
		m_KWander = SIMAgent::KWander;
		m_TAvoid = SIMAgent::TAvoid;
		UpdateData(FALSE);
	}
}

void CPanel::OnButtonNum() 
{
	// TODO: Add your control notification handler code here
	UpdateData(TRUE);
	sim->CreateAgents(m_Number);
}

void CPanel::OnRadioArrival() 
{
	// TODO: Add your control notification handler code here
	sim->type = ARRIVAL;
}

void CPanel::OnRadioDeparture() 
{
	// TODO: Add your control notification handler code here
	sim->type = DEPARTURE;
}

void CPanel::OnRadioFlee() 
{
	// TODO: Add your control notification handler code here
	sim->type = FLEE;
}

void CPanel::OnRadioSeek() 
{
	// TODO: Add your control notification handler code here
	sim->type = SEEK;
}

void CPanel::OnRadioWander() 
{
	// TODO: Add your control notification handler code here
	sim->type = WANDER;
	sim->SetV0();
}

void CPanel::OnRadioOavoid() 
{
	// TODO: Add your control notification handler code here
	sim->env.GenerateObstacles(4);
	sim->type = AVOID;
}

void CPanel::OnRadioSeparation() 
{
	// TODO: Add your control notification handler code here
	sim->type = SEPARATION;
}

void CPanel::OnRadioAlignment() 
{
	// TODO: Add your control notification handler code here
	sim->type = ALIGNMENT;
}

void CPanel::OnRadioCohesion() 
{
	// TODO: Add your control notification handler code here
	sim->type = COHESION;
}

void CPanel::OnRadioFlocking() 
{
	// TODO: Add your control notification handler code here
	sim->type = FLOCKING;
}

void CPanel::OnRadioLead() 
{
	// TODO: Add your control notification handler code here
	sim->type = LEADER;
}

void CPanel::OnButtonUpdate() 
{
	// TODO: Add your control notification handler code here
	UpdateData(TRUE);
	SIMAgent::Mass = m_Mass;
	SIMAgent::Inertia = m_Inertia;
	SIMAgent::MaxForce = m_MaxForce;
	SIMAgent::MaxTorque = m_MaxTorque;
	SIMAgent::MaxAngVel = m_MaxW;
	SIMAgent::MaxVelocity = m_MaxVel;
	SIMAgent::KAlign = m_KAlign;
	SIMAgent::KArrival = m_KArrival;
	SIMAgent::KAvoid = m_KAvoid;
	SIMAgent::KCohesion = m_KCohesion;
	SIMAgent::KDeparture = m_KDeparture;
	SIMAgent::RNeighborhood = m_KNeighborhood;
	SIMAgent::KNoise = m_KNoise;
	SIMAgent::Kv0 = m_KV0;
	SIMAgent::Kp1 = m_KP1;
	SIMAgent::Kv1 = m_KV1;
	SIMAgent::KSeparate = m_KSeparate;
	SIMAgent::KWander = m_KWander;
	SIMAgent::TAvoid = m_TAvoid;
}

void CPanel::OnCheckDebug() 
{
	// TODO: Add your control notification handler code here
	SIMAgent::debug = !SIMAgent::debug;
}
