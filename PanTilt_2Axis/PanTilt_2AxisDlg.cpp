
// PanTilt_2AxisDlg.cpp: 구현 파일
//

#include "pch.h"
#include "framework.h"
#include "PanTilt_2Axis.h"
#include "PanTilt_2AxisDlg.h"
#include "afxdialogex.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif

// 사용할 모터 id 번호. ex)1 ~ 253까지의 ID table정의  JOG Mode사용시 활용
unsigned char szIDs[] = { 0x01,0x02,0x03,0x04,0x05,0x06,0x07,0x08,0x09,0x0a,0x0b,0x0c,0x0d,0x0e,0x0f,
										  0x10,0x11,0x12,0x13,0x14,0x15,0x16,0x17,0x18,0x19,0x1a,0x1b,0x1c,0x1d,0x1e,
										  0x1f,0x20,0x21,0x22,0x23,0x24,0x25,0x26,0x27,0x28,0x29,0x2a,0x2b,0x2c,0x2d,
										  0x2e,0x2f,0x30,0x31,0x32,0x33,0x34,0x35,0x36,0x37,0x38,0x39,0x3a,0x3b,0x3c,
										  0x3d,0x3e,0x3f,0x40,0x41,0x42,0x43,0x44,0x45,0x46,0x47,0x48,0x49,0x4a,0x4b,
										  0x4c,0x4d,0x4e,0x4f,0x50,0x51,0x52,0x53,0x54,0x55,0x56,0x57,0x58,0x59,0x5a,
										  0x5b,0x5c,0x5d,0x5e,0x5f,0x60,0x61,0x62,0x63,0x64,0x65,0x66,0x67,0x68,0x69,
										  0x6a,0x6b,0x6c,0x6d,0x6e,0x6f,0x70,0x71,0x72,0x73,0x74,0x75,0x76,0x77,0x78,
										  0x79,0x7a,0x7b,0x7c,0x7d,0x7e,0x7f,0x80,0x81,0x82,0x83,0x84,0x85,0x86,0x87,
										  0x88,0x89,0x8a,0x8b,0x8c,0x8d,0x8e,0x8f,0x90,0x91,0x92,0x93,0x94,0x95,0x96,
										  0x97,0x98,0x99,0x9a,0x9b,0x9c,0x9d,0x9e,0x9f,0xa0,0xa1,0xa2,0xa3,0xa4,0xa5,
										  0xa6,0xa7,0xa8,0xa9,0xaa,0xab,0xac,0xad,0xae,0xaf,0xb0,0xb1,0xb2,0xb3,0xb4,
										  0xb5,0xb6,0xb7,0xb8,0xb9,0xba,0xbb,0xbc,0xbd,0xbe,0xbf,0xc0,0xc1,0xc2,0xc3,
										  0xc4,0xc5,0xc6,0xc7,0xc8,0xc9,0xca,0xcb,0xcc,0xcd,0xce,0xcf,0xd0,0xd1,0xd2,
										  0xd3,0xd4,0xd5,0xd6,0xd7,0xd8,0xd9,0xda,0xdb,0xdc,0xdd,0xde,0xdf,0xe0,0xe1,
										  0xe2,0xe3,0xe4,0xe5,0xe6,0xe7,0xe8,0xe9,0xea,0xeb,0xec,0xed,0xee,0xef,0xf0,
										  0xf1,0xf2,0xf3,0xf4,0xf5,0xf6,0xf7,0xf8,0xf9,0xfa,0xfb,0xfc,0xfd,0xfe };

CString m_strPoseData[2] = {" ", };
int m_iPoseData[2] = { 0, 0 }; //Feedback Pose Data(Pan, Tilt)
int m_iKey_UpDown = 512; //0 deg
int m_iKey_LeftRight = 512; //0 deg
int m_iGain_PanTilt = 1;


// 응용 프로그램 정보에 사용되는 CAboutDlg 대화 상자입니다.
class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

// 대화 상자 데이터입니다.
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_ABOUTBOX };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 지원입니다.

// 구현입니다.
protected:
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialogEx(IDD_ABOUTBOX)
{
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialogEx)
END_MESSAGE_MAP()


// CPanTilt2AxisDlg 대화 상자



CPanTilt2AxisDlg::CPanTilt2AxisDlg(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_PANTILT_2AXIS_DIALOG, pParent)
	, m_iSlider_PAN_Data(512)
	, m_iSlider_TILT_Data(512)
	, m_iPlayTime_PAN(60)
	, m_iPlayTime_TILT(60)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CPanTilt2AxisDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_SLIDER1, m_Slider_PAN);
	DDX_Control(pDX, IDC_SLIDER2, m_Slider_TILT);
	DDX_Text(pDX, IDC_EDIT1, m_iSlider_PAN_Data);
	DDX_Text(pDX, IDC_EDIT2, m_iSlider_TILT_Data);
	DDX_Text(pDX, IDC_EDIT3, m_iPlayTime_PAN);
	DDX_Text(pDX, IDC_EDIT4, m_iPlayTime_TILT);
}

BEGIN_MESSAGE_MAP(CPanTilt2AxisDlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_BUTTON1, &CPanTilt2AxisDlg::OnBnClickedButton1)
	ON_BN_CLICKED(IDC_BUTTON2, &CPanTilt2AxisDlg::OnBnClickedButton2)
	ON_WM_TIMER()
	ON_BN_CLICKED(IDC_BUTTON3, &CPanTilt2AxisDlg::OnBnClickedButton3)
	ON_WM_DESTROY()
	ON_NOTIFY(NM_CUSTOMDRAW, IDC_SLIDER1, &CPanTilt2AxisDlg::OnNMCustomdrawSlider1)
	ON_NOTIFY(NM_CUSTOMDRAW, IDC_SLIDER2, &CPanTilt2AxisDlg::OnNMCustomdrawSlider2)
	ON_WM_HSCROLL()
	ON_EN_CHANGE(IDC_EDIT1, &CPanTilt2AxisDlg::OnEnChangeEdit1)
	ON_EN_CHANGE(IDC_EDIT2, &CPanTilt2AxisDlg::OnEnChangeEdit2)
	ON_EN_CHANGE(IDC_EDIT3, &CPanTilt2AxisDlg::OnEnChangeEdit3)
	ON_EN_CHANGE(IDC_EDIT4, &CPanTilt2AxisDlg::OnEnChangeEdit4)
//	ON_WM_KEYDOWN()
END_MESSAGE_MAP()


// CPanTilt2AxisDlg 메시지 처리기

BOOL CPanTilt2AxisDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// 시스템 메뉴에 "정보..." 메뉴 항목을 추가합니다.

	// IDM_ABOUTBOX는 시스템 명령 범위에 있어야 합니다.
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != nullptr)
	{
		BOOL bNameValid;
		CString strAboutMenu;
		bNameValid = strAboutMenu.LoadString(IDS_ABOUTBOX);
		ASSERT(bNameValid);
		if (!strAboutMenu.IsEmpty())
		{
			pSysMenu->AppendMenu(MF_SEPARATOR);
			pSysMenu->AppendMenu(MF_STRING, IDM_ABOUTBOX, strAboutMenu);
		}
	}

	// 이 대화 상자의 아이콘을 설정합니다.  응용 프로그램의 주 창이 대화 상자가 아닐 경우에는
	//  프레임워크가 이 작업을 자동으로 수행합니다.
	SetIcon(m_hIcon, TRUE);			// 큰 아이콘을 설정합니다.
	SetIcon(m_hIcon, FALSE);		// 작은 아이콘을 설정합니다.

	// TODO: 여기에 추가 초기화 작업을 추가합니다.

	//Jog구조체 초기화//
	memset(_p_sjog, 0, sizeof(_p_sjog));
	memset(_p_ijog, 0, sizeof(_p_ijog));

	//Slider Control Setting//
	// Pan Slider
	m_Slider_PAN.SetRange(21, 1002);
	m_Slider_PAN.SetLineSize(1);
	m_Slider_PAN.SetPageSize(100);
	m_Slider_PAN.SetPos(512); 
	// Tilt Slider
	m_Slider_TILT.SetRange(21, 1002);
	m_Slider_TILT.SetLineSize(1);
	m_Slider_TILT.SetPageSize(100);
	m_Slider_TILT.SetPos(512);



	return TRUE;  // 포커스를 컨트롤에 설정하지 않으면 TRUE를 반환합니다.
}

void CPanTilt2AxisDlg::OnSysCommand(UINT nID, LPARAM lParam)
{
	if ((nID & 0xFFF0) == IDM_ABOUTBOX)
	{
		CAboutDlg dlgAbout;
		dlgAbout.DoModal();
	}
	else
	{
		CDialogEx::OnSysCommand(nID, lParam);
	}
}

// 대화 상자에 최소화 단추를 추가할 경우 아이콘을 그리려면
//  아래 코드가 필요합니다.  문서/뷰 모델을 사용하는 MFC 애플리케이션의 경우에는
//  프레임워크에서 이 작업을 자동으로 수행합니다.

void CPanTilt2AxisDlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // 그리기를 위한 디바이스 컨텍스트입니다.

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// 클라이언트 사각형에서 아이콘을 가운데에 맞춥니다.
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// 아이콘을 그립니다.
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialogEx::OnPaint();
	}
}

// 사용자가 최소화된 창을 끄는 동안에 커서가 표시되도록 시스템에서
//  이 함수를 호출합니다.
HCURSOR CPanTilt2AxisDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}



void CPanTilt2AxisDlg::OnBnClickedButton1()
{
	// Serial Connect//
	Connect(3, 115200); //Serial Port: COM3, Baudrate: 115,200bps

	OnInitialize(1); //HerkuleX ID: 1 
	Sleep(10);
	OnInitialize(2); //HerkuleX ID: 2 
	Sleep(10);

	// Torque On HerkuleX ID_1
	Herkulex_Servo_Enable(1, 1);
	Sleep(10);
	// Torque On HerkuleX ID_2
	Herkulex_Servo_Enable(2, 1);
	Sleep(10);

	//Home Postion_S_JOG Used////////////////////////////////////////////
	OnBnClickedButton3();

	// 10ms Timer Loop Start
	SetTimer(1, 10, NULL);
}


void CPanTilt2AxisDlg::OnBnClickedButton2()
{
	//Timer Kill
	KillTimer(1);

	// Torque Off HerkuleX ID_1
	Herkulex_Servo_Enable(1, 0);
	Sleep(10);
	// Torque Off HerkuleX ID_2
	Herkulex_Servo_Enable(2, 0);

	// Serial Disconnect
	Disconnect();
}


void CPanTilt2AxisDlg::OnTimer(UINT_PTR nIDEvent)
{
	// 10ms Timer

	for (int i = 0; i < 2; i++)
	{
		SET_RAM_RegisterData_Read(i+1, RAM_CALIBRATED_POSITION, 1);
		Sleep(10);
		m_iPoseData[i] = GET_RAM_MAP_Read(i+1, RAM_CALIBRATED_POSITION);
		//EDIT Box Output
		m_strPoseData[i].Format("%d", m_iPoseData[i]);
		GetDlgItem(IDC_EDIT1+i)->SetWindowText(m_strPoseData[i]);
	}

	CDialogEx::OnTimer(nIDEvent);
}


void CPanTilt2AxisDlg::OnBnClickedButton3()
{
	//Home Postion_S_JOG Used////////////////////////////////////////////
	//HerkuleX ID 1 Setting
	_p_sjog[0].ID = szIDs[0];
	_p_sjog[0].LED = 1; //Green LED
	_p_sjog[0].NoAction = 0;
	_p_sjog[0].Stop = 0;
	_p_sjog[0].InfiniteTurn = 0x00; //Position Move
	_p_sjog[0].Profile = 0;
	_p_sjog[0].Value = 512; //0 deg
	//HerkuleX ID 2 Setting
	_p_sjog[1].ID = szIDs[1];
	_p_sjog[1].LED = 1; //Green LED
	_p_sjog[1].NoAction = 0;
	_p_sjog[1].Stop = 0;
	_p_sjog[1].InfiniteTurn = 0x00;//Position Move
	_p_sjog[1].Profile = 0;
	_p_sjog[1].Value = 512; //0 deg
	//S_JOG Move Call
	S_JOG_MOVE(60, 2, _p_sjog);
	//////////////////////////////////////////////////////////////////////////////////////////
}


void CPanTilt2AxisDlg::OnDestroy()
{
	CDialogEx::OnDestroy();


}


void CPanTilt2AxisDlg::OnNMCustomdrawSlider1(NMHDR* pNMHDR, LRESULT* pResult)
{
	LPNMCUSTOMDRAW pNMCD = reinterpret_cast<LPNMCUSTOMDRAW>(pNMHDR);
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	*pResult = 0;
}


void CPanTilt2AxisDlg::OnNMCustomdrawSlider2(NMHDR* pNMHDR, LRESULT* pResult)
{
	LPNMCUSTOMDRAW pNMCD = reinterpret_cast<LPNMCUSTOMDRAW>(pNMHDR);
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	*pResult = 0;
}


void CPanTilt2AxisDlg::OnHScroll(UINT nSBCode, UINT nPos, CScrollBar* pScrollBar)
{
	// TODO: 여기에 메시지 처리기 코드를 추가 및/또는 기본값을 호출합니다.

	if (nSBCode == SB_ENDSCROLL) //두번호출 방지
		return;


	if (pScrollBar == (CScrollBar*)&m_Slider_PAN)
	{
		UpdateData();
		m_iSlider_PAN_Data = m_Slider_PAN.GetPos();
		Position_Move(1, 1, m_iPlayTime_PAN, m_iSlider_PAN_Data, 0);
		// HerkuleX ID: 1
		// LED: 1(Green)
		// PlayTime: (m_iPlayTime_PAN * 11.2ms)
		// TargetPose: m_iSlider_PAN_Data
		// JogMode: 0 (S_JOG)
	}
	else if (pScrollBar == (CScrollBar*)&m_Slider_TILT)
	{
		UpdateData();
		m_iSlider_TILT_Data = m_Slider_TILT.GetPos();
		Position_Move(2, 2, m_iPlayTime_TILT, m_iSlider_TILT_Data, 0);
		// HerkuleX ID: 2
		// LED: 2(Blue)
		// PlayTime: (m_iPlayTime_TILT * 11.2ms)
		// TargetPose: m_iSlider_TILT_Data
		// JogMode: 0 (S_JOG)
	}


	CDialogEx::OnHScroll(nSBCode, nPos, pScrollBar);
}


void CPanTilt2AxisDlg::OnEnChangeEdit1()
{
	// TODO:  RICHEDIT 컨트롤인 경우, 이 컨트롤은
	// CDialogEx::OnInitDialog() 함수를 재지정 
	//하고 마스크에 OR 연산하여 설정된 ENM_CHANGE 플래그를 지정하여 CRichEditCtrl().SetEventMask()를 호출하지 않으면
	// 이 알림 메시지를 보내지 않습니다.

	// TODO:  여기에 컨트롤 알림 처리기 코드를 추가합니다.
}


void CPanTilt2AxisDlg::OnEnChangeEdit2()
{
	// TODO:  RICHEDIT 컨트롤인 경우, 이 컨트롤은
	// CDialogEx::OnInitDialog() 함수를 재지정 
	//하고 마스크에 OR 연산하여 설정된 ENM_CHANGE 플래그를 지정하여 CRichEditCtrl().SetEventMask()를 호출하지 않으면
	// 이 알림 메시지를 보내지 않습니다.

	// TODO:  여기에 컨트롤 알림 처리기 코드를 추가합니다.
}


void CPanTilt2AxisDlg::OnEnChangeEdit3()
{
	// TODO:  RICHEDIT 컨트롤인 경우, 이 컨트롤은
	// CDialogEx::OnInitDialog() 함수를 재지정 
	//하고 마스크에 OR 연산하여 설정된 ENM_CHANGE 플래그를 지정하여 CRichEditCtrl().SetEventMask()를 호출하지 않으면
	// 이 알림 메시지를 보내지 않습니다.

	// TODO:  여기에 컨트롤 알림 처리기 코드를 추가합니다.
}


void CPanTilt2AxisDlg::OnEnChangeEdit4()
{
	// TODO:  RICHEDIT 컨트롤인 경우, 이 컨트롤은
	// CDialogEx::OnInitDialog() 함수를 재지정 
	//하고 마스크에 OR 연산하여 설정된 ENM_CHANGE 플래그를 지정하여 CRichEditCtrl().SetEventMask()를 호출하지 않으면
	// 이 알림 메시지를 보내지 않습니다.

	// TODO:  여기에 컨트롤 알림 처리기 코드를 추가합니다.
}

BOOL CPanTilt2AxisDlg::PreTranslateMessage(MSG* pMsg)
{
	//키보드 메시지 처리 부분//
	if (pMsg->message == WM_KEYDOWN)
	{
		switch (pMsg->wParam)
		{
			case VK_PRIOR: //PanTilt Gain Up
				if (m_iGain_PanTilt >= 100)
					m_iGain_PanTilt = 100;
				else
					m_iGain_PanTilt++;
				break;
			case VK_NEXT: //PanTilt Gain Down
				if (m_iGain_PanTilt <= 1)
					m_iGain_PanTilt = 1;
				else
					m_iGain_PanTilt--;
				break;
			case VK_UP: //TILT UP
				if (m_iKey_UpDown <= 21)
					m_iKey_UpDown = 21;
				else
					m_iKey_UpDown = m_iKey_UpDown - m_iGain_PanTilt;
				break;
			case VK_DOWN: //TILT DOWN
				if (m_iKey_UpDown >= 1002)
					m_iKey_UpDown = 1002;
				else
					m_iKey_UpDown = m_iKey_UpDown + m_iGain_PanTilt;
				break;
			case VK_LEFT: //PAN LEFT
				if (m_iKey_LeftRight <= 21)
					m_iKey_LeftRight = 21;
				else
					m_iKey_LeftRight = m_iKey_LeftRight - m_iGain_PanTilt;
				break;
			case VK_RIGHT: //PAN RIGHT
				if (m_iKey_LeftRight >= 1002)
					m_iKey_LeftRight = 1002;
				else
					m_iKey_LeftRight = m_iKey_LeftRight + m_iGain_PanTilt;
				break;
			case VK_SPACE: //Home Position (0 Deg)
				m_iKey_LeftRight = 512;
				m_iKey_UpDown = 512;
				break;
		}

		//방향키 키동시 입력//
		if ((GetAsyncKeyState(VK_UP) & 0x8000) && (GetAsyncKeyState(VK_LEFT) & 0x8000)) //UP && LEFT
		{
			if (m_iKey_UpDown <= 21)
				m_iKey_UpDown = 21;
			else
				m_iKey_UpDown = m_iKey_UpDown - m_iGain_PanTilt;

			if (m_iKey_LeftRight <= 21)
				m_iKey_LeftRight = 21;
			else
				m_iKey_LeftRight = m_iKey_LeftRight - m_iGain_PanTilt;

		}
		else if ((GetAsyncKeyState(VK_UP) & 0x8000) && (GetAsyncKeyState(VK_RIGHT) & 0x8000)) //UP && RIGHT
		{
			if (m_iKey_UpDown <= 21)
				m_iKey_UpDown = 21;
			else
				m_iKey_UpDown = m_iKey_UpDown - m_iGain_PanTilt;

			if (m_iKey_LeftRight >= 1002)
				m_iKey_LeftRight = 1002;
			else
				m_iKey_LeftRight = m_iKey_LeftRight + m_iGain_PanTilt;

		}
		else if ((GetAsyncKeyState(VK_DOWN) & 0x8000) && (GetAsyncKeyState(VK_LEFT) & 0x8000)) //DOWN && LEFT
		{
			if (m_iKey_UpDown >= 1002)
				m_iKey_UpDown = 1002;
			else
				m_iKey_UpDown = m_iKey_UpDown + m_iGain_PanTilt;

			if (m_iKey_LeftRight <= 21)
				m_iKey_LeftRight = 21;
			else
				m_iKey_LeftRight = m_iKey_LeftRight - m_iGain_PanTilt;

		}
		else if ((GetAsyncKeyState(VK_DOWN) & 0x8000) && (GetAsyncKeyState(VK_RIGHT) & 0x8000)) //DOWN && RIGHT
		{
			if (m_iKey_UpDown >= 1002)
				m_iKey_UpDown = 1002;
			else
				m_iKey_UpDown = m_iKey_UpDown + m_iGain_PanTilt;

			if (m_iKey_LeftRight >= 1002)
				m_iKey_LeftRight = 1002;
			else
				m_iKey_LeftRight = m_iKey_LeftRight + m_iGain_PanTilt;

		}
			
		//S_JOG  Struct used///////////////////////////////////////////////////
		//HerkuleX ID 1 Setting
		_p_sjog[0].ID = szIDs[0];
		_p_sjog[0].LED = 7; //R, G, B  LED All On 
		_p_sjog[0].NoAction = 0;
		_p_sjog[0].Stop = 0;
		_p_sjog[0].InfiniteTurn = 0x00; //Position Move
		_p_sjog[0].Profile = 0;
		_p_sjog[0].Value = m_iKey_LeftRight;
		//HerkuleX ID 2 Setting
		_p_sjog[1].ID = szIDs[1];
		_p_sjog[1].LED = 7; //R, G, B  LED All On 
		_p_sjog[1].NoAction = 0;
		_p_sjog[1].Stop = 0;
		_p_sjog[1].InfiniteTurn = 0x00;//Position Move
		_p_sjog[1].Profile = 0;
		_p_sjog[1].Value = m_iKey_UpDown;

		//S_JOG Move Call
		S_JOG_MOVE(m_iPlayTime_PAN, 2, _p_sjog);
		// PlayTime: m_iPlayTime_PAN
		// Total Axis: 2 (HerkuleX ID 1, 2)
		//CMD_SJOG: _p_sjog
		
		return true;
	}

	return CDialogEx::PreTranslateMessage(pMsg);
}
