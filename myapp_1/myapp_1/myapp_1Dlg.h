
// myapp_1Dlg.h : ͷ�ļ�
//

#pragma once
#include "afxwin.h"


// Cmyapp_1Dlg �Ի���
class Cmyapp_1Dlg : public CDialogEx
{
// ����
public:
	Cmyapp_1Dlg(CWnd* pParent = NULL);	// ��׼���캯��

// �Ի�������
	enum { IDD = IDD_MYAPP_1_DIALOG };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV ֧��


// ʵ��
protected:
	HICON m_hIcon;

	// ���ɵ���Ϣӳ�亯��
	virtual BOOL OnInitDialog();
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnEnChangeEdit1();
	CButton btn_begin_test;
	afx_msg void OnBnClickedBeginText();
//	afx_msg void OnTCard(UINT /*idAction*/, DWORD /*dwActionData*/);
	afx_msg void OnTimer(UINT_PTR nIDEvent);
	int time_sum;
	CString getFormatTime(int time_left);
	CString tv_time_left;
	CString et_zkz;
	CString et_sfz;

	int check_zkz(CString zkz);
	int check_sfz(CString sfz);
};
