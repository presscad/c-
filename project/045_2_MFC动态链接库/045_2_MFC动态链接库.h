
// 045_2_MFC动态链接库.h : PROJECT_NAME 应用程序的主头文件
//

#pragma once

#ifndef __AFXWIN_H__
	#error "在包含此文件之前包含“stdafx.h”以生成 PCH 文件"
#endif

#include "resource.h"		// 主符号


// CMy045_2_MFC动态链接库App: 
// 有关此类的实现，请参阅 045_2_MFC动态链接库.cpp
//

class CMy045_2_MFC动态链接库App : public CWinApp
{
public:
	CMy045_2_MFC动态链接库App();

// 重写
public:
	virtual BOOL InitInstance();

// 实现

	DECLARE_MESSAGE_MAP()
};

extern CMy045_2_MFC动态链接库App theApp;