
// myapp_1.h : PROJECT_NAME Ӧ�ó������ͷ�ļ�
//

#pragma once

#ifndef __AFXWIN_H__
	#error "�ڰ������ļ�֮ǰ������stdafx.h�������� PCH �ļ�"
#endif

#include "resource.h"		// ������


// Cmyapp_1App:
// �йش����ʵ�֣������ myapp_1.cpp
//

class Cmyapp_1App : public CWinApp
{
public:
	Cmyapp_1App();

// ��д
public:
	virtual BOOL InitInstance();

// ʵ��

	DECLARE_MESSAGE_MAP()
};

extern Cmyapp_1App theApp;