#pragma once


// CDialog_PROESS 对话框

class CDialog_PROESS : public CDialogEx
{
	DECLARE_DYNAMIC(CDialog_PROESS)

public:
	CDialog_PROESS(CWnd* pParent = NULL);   // 标准构造函数
	virtual ~CDialog_PROESS();

// 对话框数据
	enum { IDD = IDD_DIALOG_PROCESS };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedButton1();
	afx_msg void OnBnClickedButton2();
	afx_msg void OnBnClickedButton3();
	afx_msg void OnBnClickedButton4();
	afx_msg void OnBnClickedButton5();
	afx_msg void OnBnClickedButton6();
	afx_msg void OnBnClickedButton7();
};
