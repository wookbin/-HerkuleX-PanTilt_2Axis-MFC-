
// PanTilt_2AxisDlg.h: 헤더 파일
//

#pragma once
#include "HDLL.h" // Include HDLL Header file


// CPanTilt2AxisDlg 대화 상자
class CPanTilt2AxisDlg : public CDialogEx
{
// 생성입니다.
public:
	CPanTilt2AxisDlg(CWnd* pParent = nullptr);	// 표준 생성자입니다.

public:
	//Jog구조체
	CMD_SJog		_p_sjog[253];
	CMD_IJog		_p_ijog[253];

// 대화 상자 데이터입니다.
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_PANTILT_2AXIS_DIALOG };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV 지원입니다.


// 구현입니다.
protected:
	HICON m_hIcon;

	// 생성된 메시지 맵 함수
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedButton1();
	afx_msg void OnBnClickedButton2();
	afx_msg void OnTimer(UINT_PTR nIDEvent);
	afx_msg void OnBnClickedButton3();
	afx_msg void OnDestroy();
	CSliderCtrl m_Slider_PAN;
	afx_msg void OnNMCustomdrawSlider1(NMHDR* pNMHDR, LRESULT* pResult);
	CSliderCtrl m_Slider_TILT;
	afx_msg void OnNMCustomdrawSlider2(NMHDR* pNMHDR, LRESULT* pResult);
	afx_msg void OnHScroll(UINT nSBCode, UINT nPos, CScrollBar* pScrollBar);
	int m_iSlider_PAN_Data;
	afx_msg void OnEnChangeEdit1();
	int m_iSlider_TILT_Data;
	afx_msg void OnEnChangeEdit2();
	int m_iPlayTime_PAN;
	afx_msg void OnEnChangeEdit3();
	int m_iPlayTime_TILT;
	afx_msg void OnEnChangeEdit4();
	virtual BOOL PreTranslateMessage(MSG* pMsg);
};
