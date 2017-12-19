
// 037_MFCDlg.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "037_MFC.h"
#include "037_MFCDlg.h"
#include "afxdialogex.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif



// ����Ӧ�ó��򡰹��ڡ��˵���� CAboutDlg �Ի���

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

// �Ի�������
	enum { IDD = IDD_ABOUTBOX };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

// ʵ��
protected:
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialogEx(CAboutDlg::IDD)
{
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialogEx)
END_MESSAGE_MAP()


// CMy037_MFCDlg �Ի���



CMy037_MFCDlg::CMy037_MFCDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(CMy037_MFCDlg::IDD, pParent)
	, EDIT_CS(_T(""))
	, m_nPlanNum(0)
	, m_nowNum(0)
	, m_nPreOperator(ONull)
	, LastPressIsOperater(false)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CMy037_MFCDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_EDIT1, EDIT);
	DDX_Text(pDX, IDC_EDIT1, EDIT_CS);
}

BEGIN_MESSAGE_MAP(CMy037_MFCDlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()


ON_BN_CLICKED(IDC_BUTTON_BS, &CMy037_MFCDlg::OnBnClickedButtonBs)
ON_BN_CLICKED(IDC_BUTTON_CE, &CMy037_MFCDlg::OnBnClickedButtonCe)
ON_BN_CLICKED(IDC_BUTTON_C, &CMy037_MFCDlg::OnBnClickedButtonC)
ON_EN_CHANGE(IDC_EDIT1, &CMy037_MFCDlg::OnEnChangeEdit1)
ON_BN_CLICKED(IDC_BUTTON_0, &CMy037_MFCDlg::OnBnClickedButton0)
ON_BN_CLICKED(IDC_BUTTON_1, &CMy037_MFCDlg::OnBnClickedButton1)
ON_BN_CLICKED(IDC_BUTTON_2, &CMy037_MFCDlg::OnBnClickedButton2)
ON_BN_CLICKED(IDC_BUTTON_3, &CMy037_MFCDlg::OnBnClickedButton3)
ON_BN_CLICKED(IDC_BUTTON_5, &CMy037_MFCDlg::OnBnClickedButton5)
ON_BN_CLICKED(IDC_BUTTON_6, &CMy037_MFCDlg::OnBnClickedButton6)
ON_BN_CLICKED(IDC_BUTTON_7, &CMy037_MFCDlg::OnBnClickedButton7)
ON_BN_CLICKED(IDC_BUTTON_8, &CMy037_MFCDlg::OnBnClickedButton8)
ON_BN_CLICKED(IDC_BUTTON_9, &CMy037_MFCDlg::OnBnClickedButton9)
ON_BN_CLICKED(IDC_BUTTON_4, &CMy037_MFCDlg::OnBnClickedButton4)
ON_BN_CLICKED(IDC_BUTTON_ZF, &CMy037_MFCDlg::OnBnClickedButtonZf)
ON_BN_CLICKED(IDC_BUTTON_DIAN, &CMy037_MFCDlg::OnBnClickedButtonDian)
ON_BN_CLICKED(IDC_BUTTON_CHU, &CMy037_MFCDlg::OnBnClickedButtonChu)
ON_BN_CLICKED(IDC_BUTTON_CHENG, &CMy037_MFCDlg::OnBnClickedButtonCheng)
ON_BN_CLICKED(IDC_BUTTON_JIAN, &CMy037_MFCDlg::OnBnClickedButtonJian)
ON_BN_CLICKED(IDC_BUTTON_JIA, &CMy037_MFCDlg::OnBnClickedButtonJia)
ON_BN_CLICKED(IDC_BUTTON_DENG, &CMy037_MFCDlg::OnBnClickedButtonDeng)
ON_BN_CLICKED(IDC_BUTTON_MC, &CMy037_MFCDlg::OnBnClickedButtonMc)
ON_BN_CLICKED(IDC_BUTTON_MR, &CMy037_MFCDlg::OnBnClickedButtonMr)
ON_BN_CLICKED(IDC_BUTTON_MS, &CMy037_MFCDlg::OnBnClickedButtonMs)
ON_BN_CLICKED(IDC_BUTTONMJIA, &CMy037_MFCDlg::OnBnClickedButtonmjia)
ON_BN_CLICKED(IDC_BUTTON_SQRT, &CMy037_MFCDlg::OnBnClickedButtonSqrt)
ON_BN_CLICKED(IDC_BUTTON_BAIFEN, &CMy037_MFCDlg::OnBnClickedButtonBaifen)
ON_BN_CLICKED(IDC_BUTTON_ONE_X, &CMy037_MFCDlg::OnBnClickedButtonOneX)
END_MESSAGE_MAP()


// CMy037_MFCDlg ��Ϣ��������
BOOL CMy037_MFCDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// ��������...���˵������ӵ�ϵͳ�˵��С�

	// IDM_ABOUTBOX ������ϵͳ���Χ�ڡ�
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != NULL)
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

	// ���ô˶Ի����ͼ�ꡣ  ��Ӧ�ó��������ڲ��ǶԻ���ʱ����ܽ��Զ�
	//  ִ�д˲���
	SetIcon(m_hIcon, TRUE);			// ���ô�ͼ��
	SetIcon(m_hIcon, FALSE);		// ����Сͼ��

	// TODO:  �ڴ����Ӷ���ĳ�ʼ������
	/*HWND h = ::GetDlgItem(m_hWnd, IDC_EDIT1);
	::SetWindowText(h, L"0.");*/
	EDIT.SetWindowText(L"");
	//this->GetDlgItem(IDC_EDIT1)->SetWindowText(L"0.");
	return TRUE;  // ���ǽ��������õ��ؼ������򷵻� TRUE
}

void CMy037_MFCDlg::OnSysCommand(UINT nID, LPARAM lParam)
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

// �����Ի���������С����ť������Ҫ����Ĵ���
//  �����Ƹ�ͼ�ꡣ  ����ʹ���ĵ�/��ͼģ�͵� MFC Ӧ�ó���
//  �⽫�ɿ���Զ���ɡ�

void CMy037_MFCDlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // ���ڻ��Ƶ��豸������

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// ʹͼ���ڹ����������о���
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// ����ͼ��
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialogEx::OnPaint();
	}
}

//���û��϶���С������ʱϵͳ���ô˺���ȡ�ù��
//��ʾ��
HCURSOR CMy037_MFCDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}

//��ʾEdit
void CMy037_MFCDlg::OnEnChangeEdit1()
{
	// TODO:  ����ÿؼ��� RICHEDIT �ؼ���������
	// ���ʹ�֪ͨ��������д CDialogEx::OnInitDialog()
	// ���������� CRichEditCtrl().SetEventMask()��
	// ͬʱ�� ENM_CHANGE ��־�������㵽�����С�
	// TODO:  �ڴ����ӿؼ�֪ͨ�����������
	UpdateData(true);
}

//����0
void CMy037_MFCDlg::OnBnClickedButton0()
{
	PressNum(0);
}

//����1
void CMy037_MFCDlg::OnBnClickedButton1()
{
	PressNum(1);
}

//����2
void CMy037_MFCDlg::OnBnClickedButton2()
{
	PressNum(2);
}

//����3
void CMy037_MFCDlg::OnBnClickedButton3()
{
	PressNum(3);
}

//����4
void CMy037_MFCDlg::OnBnClickedButton4()
{
	PressNum(4);
}

//����5
void CMy037_MFCDlg::OnBnClickedButton5()
{
	PressNum(5);
}

//����6
void CMy037_MFCDlg::OnBnClickedButton6()
{
	PressNum(6);
}

//����7
void CMy037_MFCDlg::OnBnClickedButton7()
{
	PressNum(7);
}

//����8
void CMy037_MFCDlg::OnBnClickedButton8()
{
	PressNum(8);
}

//����9
void CMy037_MFCDlg::OnBnClickedButton9()
{
	PressNum(9);
}

//�˸�
void CMy037_MFCDlg::OnBnClickedButtonBs()
{
	// TODO:  �ڴ����ӿؼ�֪ͨ�����������
	EDIT_CS.GetBuffer()[EDIT_CS.GetLength() - 1] = 0;
	EDIT_CS.ReleaseBuffer();
	UpdateData(false);
}

//CE
void CMy037_MFCDlg::OnBnClickedButtonCe()
{
	// TODO:  �ڴ����ӿؼ�֪ͨ�����������
	UpdateData(TRUE);
	EDIT_CS = _T("");
	UpdateData(false);
}

//C
void CMy037_MFCDlg::OnBnClickedButtonC()
{
	// TODO:  �ڴ����ӿؼ�֪ͨ�����������
	OnBnClickedButtonCe();
}

//����+-
void CMy037_MFCDlg::OnBnClickedButtonZf()
{
	// TODO:  �ڴ����ӿؼ�֪ͨ�����������
	UpdateData(TRUE);
	const TCHAR* ps = EDIT_CS.GetBuffer();
	if (ps[0] == '-'){
		ps++;
		EDIT_CS = ps;
	}
	else{
		CString s;
		s = _T("-");
		s += EDIT_CS;
		EDIT_CS = s;
	}
	EDIT_CS.ReleaseBuffer();
	UpdateData(false);
}

//��.
void CMy037_MFCDlg::OnBnClickedButtonDian()
{
	UpdateData(TRUE);
	// TODO:  �ڴ����ӿؼ�֪ͨ�����������
	if (-1 == EDIT_CS.Find(L'.'))
	{
		EDIT_CS += L".";
	}
	UpdateData(false);
}

//����
void CMy037_MFCDlg::OnBnClickedButtonChu()
{
	plan(ODiv);
}

//�˷�
void CMy037_MFCDlg::OnBnClickedButtonCheng()
{
	plan(OMul);
}

//����
void CMy037_MFCDlg::OnBnClickedButtonJian()
{
	plan(OSub);
}

//�ӷ�
void CMy037_MFCDlg::OnBnClickedButtonJia()
{
	plan(OAdd);
}

//MC
void CMy037_MFCDlg::OnBnClickedButtonMc()
{

}

//MR
void CMy037_MFCDlg::OnBnClickedButtonMr()
{

}

//MS
void CMy037_MFCDlg::OnBnClickedButtonMs()
{

}

//M+
void CMy037_MFCDlg::OnBnClickedButtonmjia()
{
	
}

//Sqrt
void CMy037_MFCDlg::OnBnClickedButtonSqrt()
{
	
}

//�ٷֱ�
void CMy037_MFCDlg::OnBnClickedButtonBaifen()
{
	
}

//1/x
void CMy037_MFCDlg::OnBnClickedButtonOneX()
{
	
}

//����
void CMy037_MFCDlg::OnBnClickedButtonDeng()
{
	plan(m_nPreOperator);
}

// ���ڼ�����������
int CMy037_MFCDlg::plan(OperatorNum nOperator)
{
	//����ϴΰ��µ��������,�����m_nPreOperator��ֵ,���˳��˺���
	if (LastPressIsOperater){
		m_nPreOperator = nOperator;
		/*EDIT_CS.Format(L"%d", nOperator);
		UpdateData(false);*/
		return 1;
	}
	m_nowNum = _wtoi(EDIT_CS);	//�ַ�ת����
	switch (m_nPreOperator){
	case ONull:	//������
		m_nPlanNum = m_nowNum;	//��ǰ�༭���ֵ
		break;
	case OAdd:	//+
		m_nPlanNum += m_nowNum;
		break;
	case OSub:	//-
		m_nPlanNum = m_nPlanNum - m_nowNum;
		break;
	case OMul:	//*
		m_nPlanNum = m_nPlanNum * m_nowNum;
		break;
	case ODiv:	//  /
		m_nPlanNum = m_nPlanNum / m_nowNum;
		break;
	}
	m_nPreOperator = nOperator;
	LastPressIsOperater = 1;
	EDIT_CS.Format(L"%d", m_nPlanNum);
	UpdateData(false);
	return 0;
}


// ��ʾ������0-9
int CMy037_MFCDlg::PressNum(int nNum)
{
	CString ts;
	ts.Format(L"%d", nNum);
	if (LastPressIsOperater){	//�ϴΰ��µ��������,���¸�ֵ
		EDIT_CS = ts;
	}
	else{
		EDIT_CS += ts;	//�ϴΰ��²��������
	}
	LastPressIsOperater = 0;
	UpdateData(false);
	return 0;
}