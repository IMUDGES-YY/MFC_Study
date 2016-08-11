
// myapp_1Dlg.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "myapp_1.h"
#include "myapp_1Dlg.h"
#include "afxdialogex.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// Cmyapp_1Dlg �Ի���




Cmyapp_1Dlg::Cmyapp_1Dlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(Cmyapp_1Dlg::IDD, pParent)
	, time_sum(0)
	, tv_time_left(_T(""))
	, et_zkz(_T(""))
	, et_sfz(_T(""))
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void Cmyapp_1Dlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_BEGIN_TEXT, btn_begin_test);
	DDX_Text(pDX, IDC_TIME_LEFT, tv_time_left);
	DDX_Text(pDX, IDC_EDIT1, et_zkz);
	DDV_MaxChars(pDX, et_zkz, 11);
	DDX_Text(pDX, IDC_EDIT2, et_sfz);
	DDV_MaxChars(pDX, et_sfz, 18);
}

BEGIN_MESSAGE_MAP(Cmyapp_1Dlg, CDialogEx)
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_EN_CHANGE(IDC_EDIT1, &Cmyapp_1Dlg::OnEnChangeEdit1)
	ON_BN_CLICKED(IDC_BEGIN_TEXT, &Cmyapp_1Dlg::OnBnClickedBeginText)
//	ON_WM_TCARD()
ON_WM_TIMER()
END_MESSAGE_MAP()


// Cmyapp_1Dlg ��Ϣ�������

BOOL Cmyapp_1Dlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// ���ô˶Ի����ͼ�ꡣ��Ӧ�ó��������ڲ��ǶԻ���ʱ����ܽ��Զ�
	//  ִ�д˲���
	SetIcon(m_hIcon, TRUE);			// ���ô�ͼ��
	SetIcon(m_hIcon, FALSE);		// ����Сͼ��

	// TODO: �ڴ���Ӷ���ĳ�ʼ������

	return TRUE;  // ���ǽ��������õ��ؼ������򷵻� TRUE
}

// �����Ի��������С����ť������Ҫ����Ĵ���
//  �����Ƹ�ͼ�ꡣ����ʹ���ĵ�/��ͼģ�͵� MFC Ӧ�ó���
//  �⽫�ɿ���Զ���ɡ�

void Cmyapp_1Dlg::OnPaint()
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
HCURSOR Cmyapp_1Dlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}



void Cmyapp_1Dlg::OnEnChangeEdit1()
{
	// TODO:  ����ÿؼ��� RICHEDIT �ؼ���������
	// ���ʹ�֪ͨ��������д CDialogEx::OnInitDialog()
	// ���������� CRichEditCtrl().SetEventMask()��
	// ͬʱ�� ENM_CHANGE ��־�������㵽�����С�

	// TODO:  �ڴ���ӿؼ�֪ͨ����������
}


void Cmyapp_1Dlg::OnBnClickedBeginText()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	//������Ҫ�ж��û������׼��֤��Ϣ�����֤��Ϣ�Ƿ�Ϸ�����ʱ��ʡ��
	//�ж�׼��֤��
	UpdateData(TRUE);
	int zkz_result = check_zkz(et_zkz);
    if (zkz_result == 1)
    {
        MessageBox(_T("׼��֤Ϊ11λ����"));
        return;
    }

	int sfz_result = check_sfz(et_sfz);
	if(sfz_result==1)
	{
		 MessageBox(_T("���֤��Ϊ18λ���֣����һλ������x��֧�ִ�Сд��"));
        return;
    }
    if (sfz_result == 2)
    {
        MessageBox(_T("�Բ����������䲻�ںϷ���ְ�����䷶Χ"));
        return;
    }
    if (sfz_result == 3)
    {
        MessageBox(_T("���֤�������"));
        return;
    }
    btn_begin_test.EnableWindow(FALSE);//�ð�ť�޷����
    SetTimer(1,1000,NULL);//����һ����ʱ������������������,��һ����������ʱ��id���ڶ���������ʱ��������������������Ҫ�����ĺ�������ֵΪNULL����ϵͳ����
}


//void Cmyapp_1Dlg::OnTCard(UINT /*idAction*/, DWORD /*dwActionData*/)
//{
//	// TODO: �ڴ˴������Ϣ����������
//}


void Cmyapp_1Dlg::OnTimer(UINT_PTR nIDEvent)
{
	// TODO: �ڴ������Ϣ�����������/�����Ĭ��ֵ
	tv_time_left = getFormatTime(++time_sum);
    UpdateData(FALSE);
    CDialogEx::OnTimer(nIDEvent);
}



CString Cmyapp_1Dlg::getFormatTime(int time_left)
{
	int sum = 15*60 - time_left;
    int second = sum % 60;
    int minute = sum / 60;
    CString t;
    t.Format(L"%d��%d��",minute,second);
    return t;
}



int Cmyapp_1Dlg::check_zkz(CString zkz)
{
	int length = zkz.GetLength();
	if(length==11)
		return 0;
	return 1;
}


int Cmyapp_1Dlg::check_sfz(CString sfz)
{
	int length=sfz.GetLength();
	if(length==18)
	{
		return 0;
	}
	return 1;
}
