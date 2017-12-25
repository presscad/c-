// Dialog_PROESS.cpp : 实现文件
//

#include "stdafx.h"
#include "037_MFC.h"
#include "Dialog_PROESS.h"
#include "afxdialogex.h"


// CDialog_PROESS 对话框

IMPLEMENT_DYNAMIC(CDialog_PROESS, CDialogEx)

CDialog_PROESS::CDialog_PROESS(CWnd* pParent /*=NULL*/)
	: CDialogEx(CDialog_PROESS::IDD, pParent)
{

}

CDialog_PROESS::~CDialog_PROESS()
{
}

void CDialog_PROESS::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(CDialog_PROESS, CDialogEx)
	ON_BN_CLICKED(IDC_BUTTON1, &CDialog_PROESS::OnBnClickedButton1)
	ON_BN_CLICKED(IDC_BUTTON2, &CDialog_PROESS::OnBnClickedButton2)
	ON_BN_CLICKED(IDC_BUTTON3, &CDialog_PROESS::OnBnClickedButton3)
	ON_BN_CLICKED(IDC_BUTTON4, &CDialog_PROESS::OnBnClickedButton4)
	ON_BN_CLICKED(IDC_BUTTON5, &CDialog_PROESS::OnBnClickedButton5)
	ON_BN_CLICKED(IDC_BUTTON6, &CDialog_PROESS::OnBnClickedButton6)
	ON_BN_CLICKED(IDC_BUTTON7, &CDialog_PROESS::OnBnClickedButton7)
END_MESSAGE_MAP()


// CDialog_PROESS 消息处理程序

PROCESS_INFORMATION pi;

void CDialog_PROESS::OnBnClickedButton1()
{
	// TODO:  在此添加控件通知处理程序代码
	//STAR
	// TODO: 在此添加控件通知处理程序代码
	STARTUPINFOA si = { sizeof(si) };
	TCHAR ws[256] = L"notepad.exe d:\\1.txt";
	CreateProcessA(NULL, "notepad.exe d:\\1.txt", NULL, NULL, false, NORMAL_PRIORITY_CLASS, NULL, NULL, &si, &pi);
	//CreateProcess(NULL,L"notepad.exe d:\\1.txt",NULL,NULL,false,NORMAL_PRIORITY_CLASS,NULL,NULL,&si,&pi);
}

//正常结束
void CDialog_PROESS::OnBnClickedButton2()
{
	// TODO: 在此添加控件通知处理程序代码

	TerminateProcess(pi.hProcess,1);
	TerminateThread(pi.hThread,1);
}

//强制结束(任务管理器的结束方式 提示报错)
void CDialog_PROESS::OnBnClickedButton3()
{
	// TODO: 在此添加控件通知处理程序代码
	//强制退出 清理的工作还没完成
	ExitProcess(1222);
}

DWORD WINAPI ThreadProc1(
	LPVOID lpParameter   // thread data
	)
{
	static int i = 0;
	while (1)
	{
		Sleep(1000);
		TRACE("thread  i=%d    \n", i++);
	}

	return 1;
}

HANDLE th;
void CDialog_PROESS::OnBnClickedButton4()
{
	// TODO:  在此添加控件通知处理程序代码
	DWORD tid;
	//创建新线程
	th = CreateThread(NULL, 0, ThreadProc1, 0, CREATE_SUSPENDED, &tid);
}


void CDialog_PROESS::OnBnClickedButton5()
{
	// TODO:  在此添加控件通知处理程序代码
	ResumeThread(th); //恢复线程
}


void CDialog_PROESS::OnBnClickedButton6()
{
	// TODO:  在此添加控件通知处理程序代码
	SuspendThread(th);//挂起线程
}


void CDialog_PROESS::OnBnClickedButton7()
{
	// TODO:  在此添加控件通知处理程序代码
	TerminateThread(th, 11);
}
