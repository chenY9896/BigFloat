
// MFCApplication1Dlg.cpp : ʵ���ļ�
//

#include "BigFloat.h"
#include "stdafx.h"
#include "MFCApplication1.h"
#include "MFCApplication1Dlg.h"
#include "afxdialogex.h"
#include<CString>
#include<string>
#include<windows.h>
#include<iostream>



#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// ����Ӧ�ó��򡰹��ڡ��˵���� CAboutDlg �Ի���

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

// �Ի�������
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_ABOUTBOX };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

// ʵ��
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


// CMFCApplication1Dlg �Ի���



CMFCApplication1Dlg::CMFCApplication1Dlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(IDD_MFCAPPLICATION1_DIALOG, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CMFCApplication1Dlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CMFCApplication1Dlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_BUTTON1, &CMFCApplication1Dlg::OnBnClickedButton1)
	ON_BN_CLICKED(IDC_BUTTON2, &CMFCApplication1Dlg::OnBnClickedButton2)
	ON_BN_CLICKED(IDC_BUTTON3, &CMFCApplication1Dlg::OnBnClickedButton3)
	ON_BN_CLICKED(IDC_BUTTON4, &CMFCApplication1Dlg::OnBnClickedButton4)
	ON_BN_CLICKED(IDC_BUTTON5, &CMFCApplication1Dlg::OnBnClickedButton5)
	ON_BN_CLICKED(IDC_BUTTON6, &CMFCApplication1Dlg::OnBnClickedButton6)
	ON_BN_CLICKED(IDC_BUTTON7, &CMFCApplication1Dlg::OnBnClickedButton7)
	ON_BN_CLICKED(IDC_BUTTON8, &CMFCApplication1Dlg::OnBnClickedButton8)
	ON_BN_CLICKED(IDC_BUTTON9, &CMFCApplication1Dlg::OnBnClickedButton9)
	ON_BN_CLICKED(IDC_BUTTON0, &CMFCApplication1Dlg::OnBnClickedButton0)
	ON_BN_CLICKED(IDC_BUTTON10, &CMFCApplication1Dlg::OnBnClickedButton10)
	ON_BN_CLICKED(IDC_BUTTON17, &CMFCApplication1Dlg::OnBnClickedButton17)
	ON_BN_CLICKED(IDC_BUTTON18, &CMFCApplication1Dlg::OnBnClickedButton18)
	ON_BN_CLICKED(IDC_BUTTON19, &CMFCApplication1Dlg::OnBnClickedButton19)
	ON_BN_CLICKED(IDC_BUTTON11, &CMFCApplication1Dlg::OnBnClickedButton11)
	ON_BN_CLICKED(IDC_BUTTON12, &CMFCApplication1Dlg::OnBnClickedButton12)
	ON_BN_CLICKED(IDC_BUTTON13, &CMFCApplication1Dlg::OnBnClickedButton13)
	ON_BN_CLICKED(IDC_BUTTON14, &CMFCApplication1Dlg::OnBnClickedButton14)
	ON_BN_CLICKED(IDC_BUTTON15, &CMFCApplication1Dlg::OnBnClickedButton15)
	ON_BN_CLICKED(IDC_BUTTON16, &CMFCApplication1Dlg::OnBnClickedButton16)
END_MESSAGE_MAP()


// CMFCApplication1Dlg ��Ϣ�������

BOOL CMFCApplication1Dlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// ��������...���˵�����ӵ�ϵͳ�˵��С�

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

	// TODO: �ڴ���Ӷ���ĳ�ʼ������
	result = 0;
	num1 = 0;
	num2 = 0;
	str1 = "0";
	str2 = "0";
	str = "0";

	tag = true;
	flag = true;
	return TRUE;  // ���ǽ��������õ��ؼ������򷵻� TRUE
}

void CMFCApplication1Dlg::OnSysCommand(UINT nID, LPARAM lParam)
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

// �����Ի��������С����ť������Ҫ����Ĵ���
//  �����Ƹ�ͼ�ꡣ  ����ʹ���ĵ�/��ͼģ�͵� MFC Ӧ�ó���
//  �⽫�ɿ���Զ���ɡ�

void CMFCApplication1Dlg::OnPaint()
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
HCURSOR CMFCApplication1Dlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}



void CMFCApplication1Dlg::OnBnClickedButton1()
{// TODO: �ڴ���ӿؼ�֪ͨ����������
	flag = true;
	if (str2 == "0")
		str2 = "1";
	else
		str2 += "1";
	CString cstr ( str2.c_str());
	GetDlgItem(IDC_EDIT1)->SetWindowText(cstr);
}

void CMFCApplication1Dlg::OnBnClickedButton2()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	flag = true;
	if (str2 == "0")
		str2 = "2";
	else
		str2 += "2";
	CString cstr(str2.c_str());
	GetDlgItem(IDC_EDIT1)->SetWindowText(cstr);
}


void CMFCApplication1Dlg::OnBnClickedButton3()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	flag = true;
	if (str2 == "0")
		str2 = "3";
	else
		str2 += "3";
	CString cstr(str2.c_str());
	GetDlgItem(IDC_EDIT1)->SetWindowText(cstr);
}


void CMFCApplication1Dlg::OnBnClickedButton4()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	flag = true;
	if (str2 == "0")
		str2 = "4";
	else
		str2 += "4";
	CString cstr(str2.c_str());
	GetDlgItem(IDC_EDIT1)->SetWindowText(cstr);
}


void CMFCApplication1Dlg::OnBnClickedButton5()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	flag = true;
	if (str2 == "0")
		str2 = "5";
	else
		str2 += "5";
	CString cstr(str2.c_str());
	GetDlgItem(IDC_EDIT1)->SetWindowText(cstr);
}


void CMFCApplication1Dlg::OnBnClickedButton6()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	flag = true;
	if (str2 == "0")
		str2 = "6";
	else
		str2 += "6";
	CString cstr(str2.c_str());
	GetDlgItem(IDC_EDIT1)->SetWindowText(cstr);
}


void CMFCApplication1Dlg::OnBnClickedButton7()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	flag = true;
	if (str2 == "0")
		str2 = "7";
	else
		str2 += "7";
	CString cstr(str2.c_str());
	GetDlgItem(IDC_EDIT1)->SetWindowText(cstr);
}



void CMFCApplication1Dlg::OnBnClickedButton8()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	flag = true;
	if (str2 == "0")
		str2 = "8";
	else
		str2 += "8";
	CString cstr(str2.c_str());
	GetDlgItem(IDC_EDIT1)->SetWindowText(cstr);
}


void CMFCApplication1Dlg::OnBnClickedButton9()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	flag = true;
	if (str2 == "0")
		str2 = "9";
	else
		str2 += "9";
	CString cstr(str2.c_str());
	GetDlgItem(IDC_EDIT1)->SetWindowText(cstr);
}


void CMFCApplication1Dlg::OnBnClickedButton0()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	flag = true;
	if (str2 == "0")
		str2 = "0";
	else
		str2 += "0";
	CString cstr(str2.c_str());
	GetDlgItem(IDC_EDIT1)->SetWindowText(cstr);
}


void CMFCApplication1Dlg::OnBnClickedButton10()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	flag = true;
	string::size_type idx = str2.find(".");
	if (idx == string::npos)
		str2 += ".";
	CString cstr(str2.c_str());
	GetDlgItem(IDC_EDIT1)->SetWindowText(cstr);
}


void CMFCApplication1Dlg::OnBnClickedButton17()//CE
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	flag = true;
	str2 = "0";
	CString cstr(str2.c_str());
	GetDlgItem(IDC_EDIT1)->SetWindowText(cstr);
}


void CMFCApplication1Dlg::OnBnClickedButton18()//C
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	flag = true;
	str1 = "0";
	str2 = "0";
	str = "0";
	tag = true;
	result = 0;
	CString cstr(str2.c_str());
	GetDlgItem(IDC_EDIT1)->SetWindowText(cstr);
	GetDlgItem(IDC_EDIT2)->SetWindowText(_T(""));
}


void CMFCApplication1Dlg::OnBnClickedButton19()//��
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	flag = true;
	if (str2.length() == 1)
		str2 = "0";
	else
		str2.pop_back();
	CString cstr(str2.c_str());
	GetDlgItem(IDC_EDIT1)->SetWindowText(cstr);
}


void CMFCApplication1Dlg::OnBnClickedButton11()//+/-
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
		CString cstr;
		GetDlgItem(IDC_EDIT1)->GetWindowTextW(cstr);
		str2 = CW2A(cstr.GetString());
		num2 = str2;
		str2 = (-num2).toString();
		cstr=str2.c_str();
		GetDlgItem(IDC_EDIT1)->SetWindowText(cstr);
		
}


void CMFCApplication1Dlg::OnBnClickedButton12()//+
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	if (tag) {
		CString cstr;
		GetDlgItem(IDC_EDIT1)->GetWindowTextW(cstr);
		str2 = CW2A(cstr.GetString());
		tag = false;
		result = str2;
		str2 = "0";
		str = result.toString() + "+";
		CString cstr1(str2.c_str());
		GetDlgItem(IDC_EDIT1)->SetWindowText(cstr1);
	}
	else {
		CString cstr;
		GetDlgItem(IDC_EDIT1)->GetWindowTextW(cstr);
		str2 = CW2A(cstr.GetString());
		if (str.find("+") != string::npos)
			result += str2;
		else if (str.find("��") != string::npos)
			result *= str2;
		else if (str.find("��") != string::npos) {
			try {
				result /= str2;
			}
			catch (ZeroException e) {
				cstr = e.errorText().c_str();
				AfxMessageBox(cstr);
				flag = true;
				str1 = "0";
				str2 = "0";
				str = "0";
				tag = true;
				result = 0;
				CString cstr(str2.c_str());
				GetDlgItem(IDC_EDIT1)->SetWindowText(cstr);
				GetDlgItem(IDC_EDIT2)->SetWindowText(_T(""));
			}
		}
		else if (str.find("-") != string::npos)
			result -= str2;
		str2 = "0";
		str = result.toString() + "+";
		CString cstr1(result.toString().c_str());
		GetDlgItem(IDC_EDIT1)->SetWindowText(cstr1);
	}	
	CString cstr(str.c_str());
	GetDlgItem(IDC_EDIT2)->SetWindowText(cstr);

}


void CMFCApplication1Dlg::OnBnClickedButton13()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	if (tag) {
		CString cstr;
		GetDlgItem(IDC_EDIT1)->GetWindowTextW(cstr);
		str2 = CW2A(cstr.GetString());
		tag = false;
		result = str2;
		str2 = "0";
		str = result.toString() + "-";
		CString cstr1(str2.c_str());
		GetDlgItem(IDC_EDIT1)->SetWindowText(cstr1);
	}
	else {
		CString cstr;
		GetDlgItem(IDC_EDIT1)->GetWindowTextW(cstr);
		str2 = CW2A(cstr.GetString());
		if (str.find("+") != string::npos)
			result += str2;		
		else if (str.find("��") != string::npos)
			result *= str2;
		else if (str.find("��") != string::npos) {
			try {
				result /= str2;
			}
			catch (ZeroException e) {
				cstr = e.errorText().c_str();
				AfxMessageBox(cstr);
				flag = true;
				str1 = "0";
				str2 = "0";
				str = "0";
				tag = true;
				result = 0;
				CString cstr(str2.c_str());
				GetDlgItem(IDC_EDIT1)->SetWindowText(cstr);
				GetDlgItem(IDC_EDIT2)->SetWindowText(_T(""));
			}
		}
		else if (str.find("-") != string::npos)
			result -= str2;
		str2 = "0";
		str = result.toString() + "-";
		CString cstr1(result.toString().c_str());
		GetDlgItem(IDC_EDIT1)->SetWindowText(cstr1);
	}
	
	CString cstr(str.c_str());
	GetDlgItem(IDC_EDIT2)->SetWindowText(cstr);

}


void CMFCApplication1Dlg::OnBnClickedButton14()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	if (tag) {
		CString cstr;
		GetDlgItem(IDC_EDIT1)->GetWindowTextW(cstr);
		str2 = CW2A(cstr.GetString());
		tag = false;
		result = str2;
		str2 = "0";
		str = result.toString() + "��";
		CString cstr1(str2.c_str());
		GetDlgItem(IDC_EDIT1)->SetWindowText(cstr1);
	}
	else {
		CString cstr;
		GetDlgItem(IDC_EDIT1)->GetWindowTextW(cstr);
		str2 = CW2A(cstr.GetString());
		if (str.find("+") != string::npos)
			result += str2;
		else if (str.find("��") != string::npos)
			result *= str2;
		else if (str.find("��") != string::npos) {
			try {
				result /= str2;
			}
			catch (ZeroException e) {
				cstr = e.errorText().c_str();
				AfxMessageBox(cstr);
				flag = true;
				str1 = "0";
				str2 = "0";
				str = "0";
				tag = true;
				result = 0;
				CString cstr(str2.c_str());
				GetDlgItem(IDC_EDIT1)->SetWindowText(cstr);
				GetDlgItem(IDC_EDIT2)->SetWindowText(_T(""));
			}
		}
		else if (str.find("-") != string::npos)
			result -= str2;
		str2 = "0";
		str = result.toString() + "��";
		CString cstr1(result.toString().c_str());
		GetDlgItem(IDC_EDIT1)->SetWindowText(cstr1);
	}	
	CString cstr(str.c_str());
	GetDlgItem(IDC_EDIT2)->SetWindowText(cstr);

}


void CMFCApplication1Dlg::OnBnClickedButton15()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	if (tag) {
		CString cstr;
		GetDlgItem(IDC_EDIT1)->GetWindowTextW(cstr);
		str2 = CW2A(cstr.GetString());
		tag = false;
		result = str2;
		str2 = "0";
		str = result.toString() + "��";
		CString cstr1(str2.c_str());
		GetDlgItem(IDC_EDIT1)->SetWindowText(cstr1);
	}
	else {
		CString cstr;
		GetDlgItem(IDC_EDIT1)->GetWindowTextW(cstr);
		str2 = CW2A(cstr.GetString());
		if (str.find("+") != string::npos)
			result += str2;
		else if (str.find("��") != string::npos)
			result *= str2;
		else if (str.find("��") != string::npos) {
			try {
				result /= str2;
			}
			catch (ZeroException e) {
				cstr = e.errorText().c_str();
				AfxMessageBox(cstr);
				flag = true;
				str1 = "0";
				str2 = "0";
				str = "0";
				tag = true;
				result = 0;
				CString cstr(str2.c_str());
				GetDlgItem(IDC_EDIT1)->SetWindowText(cstr);
				GetDlgItem(IDC_EDIT2)->SetWindowText(_T(""));
			}
		}
		else if (str.find("-") != string::npos)
			result -= str2;
		str2 = "0";
		str = result.toString() + "��";
		CString cstr1(result.toString().c_str());
		GetDlgItem(IDC_EDIT1)->SetWindowText(cstr1);
	}

	CString cstr(str.c_str());
	GetDlgItem(IDC_EDIT2)->SetWindowText(cstr);

}


void CMFCApplication1Dlg::OnBnClickedButton16()//=
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	CString cstr;
	GetDlgItem(IDC_EDIT1)->GetWindowTextW(cstr);
	str2 = CW2A(cstr.GetString());
	str = str + str2 +"=";
	if (str.find("+") != string::npos)
		result += str2;	
	else if (str.find("��") != string::npos)
		result *= str2;
	else if (str.find("��") != string::npos) {
		try {
			result /= str2;
		}
		catch (ZeroException e) {
			cstr = e.errorText().c_str();
			AfxMessageBox(cstr);
			flag = true;
			str1 = "0";
			str2 = "0";
			str = "0";
			tag = true;
			result = 0;
			CString cstr(str2.c_str());
			GetDlgItem(IDC_EDIT1)->SetWindowText(cstr);
			GetDlgItem(IDC_EDIT2)->SetWindowText(_T(""));
		}
		
	}
		
	else if (str.find("-") != string::npos)
		result -= str2;
	str2 = "0";
	CString cstr1(result.toString().c_str());
	GetDlgItem(IDC_EDIT1)->SetWindowText(cstr1);
	CString cstr2(str.c_str());
	GetDlgItem(IDC_EDIT2)->SetWindowText(cstr2);
	str = result.toString();
	flag = false;
}


BOOL CMFCApplication1Dlg::PreTranslateMessage(MSG* pMsg)
{
	// TODO: �ڴ����ר�ô����/����û���
	if (pMsg->message == WM_KEYDOWN) {
		switch (pMsg->wParam){
		case VK_RETURN:
			OnBnClickedButton16();
			break;
		case VK_ADD:
			CMFCApplication1Dlg::OnBnClickedButton12();
			break;
		case VK_SUBTRACT:
			CMFCApplication1Dlg::OnBnClickedButton13();
			break;
		case VK_MULTIPLY:
			CMFCApplication1Dlg::OnBnClickedButton14();
			break;
		case VK_DIVIDE:
			CMFCApplication1Dlg::OnBnClickedButton15();
			break;
		case VK_NUMPAD0:
			CMFCApplication1Dlg::OnBnClickedButton0();
			break; 
		case VK_NUMPAD1:
			CMFCApplication1Dlg::OnBnClickedButton1();
			break;
		case VK_NUMPAD2:
			CMFCApplication1Dlg::OnBnClickedButton2();
			break;
		case VK_NUMPAD3:
			CMFCApplication1Dlg::OnBnClickedButton3();
			break;
		case VK_NUMPAD4:
			CMFCApplication1Dlg::OnBnClickedButton4();
			break;
		case VK_NUMPAD5:
			CMFCApplication1Dlg::OnBnClickedButton5();
			break;
		case VK_NUMPAD6:
			CMFCApplication1Dlg::OnBnClickedButton6();
			break;
		case VK_NUMPAD7:
			CMFCApplication1Dlg::OnBnClickedButton7();
			break;
		case VK_NUMPAD8:
			CMFCApplication1Dlg::OnBnClickedButton8();
			break;
		case VK_NUMPAD9:
			CMFCApplication1Dlg::OnBnClickedButton9();
			break;
		case VK_DECIMAL:
			CMFCApplication1Dlg::OnBnClickedButton10();
			break;
		case VK_BACK:
			CMFCApplication1Dlg::OnBnClickedButton19();
			break;
		default:
			break;
		}
	}
	return CDialogEx::PreTranslateMessage(pMsg);
}
