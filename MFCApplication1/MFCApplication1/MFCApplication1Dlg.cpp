
// MFCApplication1Dlg.cpp : 实现文件
//

#include "BigFloat.h"
#include "stdafx.h"
#include "MFCApplication1.h"
#include "MFCApplication1Dlg.h"
#include "afxdialogex.h"
#include "SetAccDlg.h"
#include<CString>
#include<string>
#include<windows.h>
#include<iostream>



#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// 用于应用程序“关于”菜单项的 CAboutDlg 对话框

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_ABOUTBOX };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

// 实现
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


// CMFCApplication1Dlg 对话框



CMFCApplication1Dlg::CMFCApplication1Dlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(IDD_MFCAPPLICATION1_DIALOG, pParent)
	, Cstr(_T(""))
	, Cstr1(_T(""))
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CMFCApplication1Dlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT1, Cstr);
	DDX_Text(pDX, IDC_EDIT2, Cstr1);
	DDX_Control(pDX, IDC_EDIT1, m_edit);
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
	ON_EN_CHANGE(IDC_EDIT1, &CMFCApplication1Dlg::OnEnChangeEdit1)
	ON_COMMAND(ID_ACCURACY, &CMFCApplication1Dlg::OnAccuracy)
END_MESSAGE_MAP()


// CMFCApplication1Dlg 消息处理程序

BOOL CMFCApplication1Dlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// 将“关于...”菜单项添加到系统菜单中。

	// IDM_ABOUTBOX 必须在系统命令范围内。
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

	// 设置此对话框的图标。  当应用程序主窗口不是对话框时，框架将自动
	//  执行此操作
	SetIcon(m_hIcon, TRUE);			// 设置大图标
	SetIcon(m_hIcon, FALSE);		// 设置小图标

	// TODO: 在此添加额外的初始化代码
	m_menu.LoadMenuW(IDR_MENU1); 
	SetMenu(&m_menu); //将菜单加入到对话框。
	result = 0;
	num1 = 0;
	num2 = 0;
	str1 = "0";
	str = "0";
	tag = "";
	the_one = true;
	flag = false;
	putin = false;

	m_Font.CreatePointFont(180, _T("黑体"));
	m_edit.SetFont(&m_Font);
	return TRUE;  // 除非将焦点设置到控件，否则返回 TRUE
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

// 如果向对话框添加最小化按钮，则需要下面的代码
//  来绘制该图标。  对于使用文档/视图模型的 MFC 应用程序，
//  这将由框架自动完成。

void CMFCApplication1Dlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // 用于绘制的设备上下文

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// 使图标在工作区矩形中居中
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// 绘制图标
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialogEx::OnPaint();
	}
}

//当用户拖动最小化窗口时系统调用此函数取得光标
//显示。
HCURSOR CMFCApplication1Dlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}



void CMFCApplication1Dlg::OnBnClickedButton1()
{// TODO: 在此添加控件通知处理程序代码
	putin = true;
	if (flag) {
		the_one = true;
		flag = false;
		Cstr1 = "";
	}
	if (str == "0")
		str = "1";
	else
		str += "1";
	Cstr =str.c_str();
	UpdateData(false);
}

void CMFCApplication1Dlg::OnBnClickedButton2()
{
	// TODO: 在此添加控件通知处理程序代码
	putin = true;
	if (flag) {
		the_one = true;
		flag = false;
		Cstr1 = "";
	}
	if (str == "0")
		str = "2";
	else
		str += "2";
	Cstr = str.c_str();
	UpdateData(false);
}


void CMFCApplication1Dlg::OnBnClickedButton3()
{
	// TODO: 在此添加控件通知处理程序代码
	putin = true;
	if (flag) {
		the_one = true;
		flag = false;
		Cstr1 = "";
	}
	if (str == "0")
		str = "3";
	else
		str += "3";
	Cstr = str.c_str();
	UpdateData(false);
}


void CMFCApplication1Dlg::OnBnClickedButton4()
{
	// TODO: 在此添加控件通知处理程序代码
	putin = true;
	if (flag) {
		the_one = true;
		flag = false;
		Cstr1 = "";
	}
	if (str == "0")
		str = "4";
	else
		str += "4";
	Cstr = str.c_str();
	UpdateData(false);
}


void CMFCApplication1Dlg::OnBnClickedButton5()
{
	// TODO: 在此添加控件通知处理程序代码
	putin = true;
	if (flag) {
		the_one = true;
		flag = false;
		Cstr1 = "";
	}
	if (str == "0")
		str = "5";
	else
		str += "5";
	Cstr = str.c_str();
	UpdateData(false);
}


void CMFCApplication1Dlg::OnBnClickedButton6()
{
	// TODO: 在此添加控件通知处理程序代码
	putin = true;
	if (flag) {
		the_one = true;
		flag = false;
		Cstr1 = "";
	}
	if (str == "0")
		str = "6";
	else
		str += "6";
	Cstr = str.c_str();
	UpdateData(false);
}


void CMFCApplication1Dlg::OnBnClickedButton7()
{
	// TODO: 在此添加控件通知处理程序代码
	putin = true;
	if (flag) {
		the_one = true;
		flag = false;
		Cstr1 = "";
	}
	if (str == "0")
		str = "7";
	else
		str += "7";
	Cstr = str.c_str();
	UpdateData(false);
}



void CMFCApplication1Dlg::OnBnClickedButton8()
{
	// TODO: 在此添加控件通知处理程序代码
	putin = true;
	if (flag) {
		the_one = true;
		flag = false;
		Cstr1 = "";
	}
	if (str == "0")
		str = "8";
	else
		str += "8";
	Cstr = str.c_str();
	UpdateData(false);
}


void CMFCApplication1Dlg::OnBnClickedButton9()
{
	// TODO: 在此添加控件通知处理程序代码
	putin = true;
	if (flag) {
		the_one = true;
		flag = false;
		Cstr1 = "";
	}
	if (str == "0")
		str = "9";
	else
		str += "9";
	Cstr = str.c_str();
	UpdateData(false);
}


void CMFCApplication1Dlg::OnBnClickedButton0()
{
	// TODO: 在此添加控件通知处理程序代码
	putin = true;
	if (flag) {
		the_one = true;
		flag = false;
		Cstr1 = "";
	}
	if (str == "0")
		str = "0";
	else
		str += "0";
	Cstr = str.c_str();
	UpdateData(false);
}


void CMFCApplication1Dlg::OnBnClickedButton10()
{
	// TODO: 在此添加控件通知处理程序代码
	putin = true;
	if (flag) {
		the_one = true;
		flag = false;
		Cstr1 = "";
	}
	string::size_type idx = str.find(".");
	if (idx == string::npos)
		str += ".";
	Cstr = str.c_str();
	UpdateData(false);
}


void CMFCApplication1Dlg::OnBnClickedButton17()//CE
{
	// TODO: 在此添加控件通知处理程序代码
	putin = true;
	if (flag) {
		the_one = true;
		flag = false;
		Cstr1 = "";
	}
	str = "0";
	Cstr = str.c_str();
	UpdateData(false);
}


void CMFCApplication1Dlg::OnBnClickedButton18()//C
{
	// TODO: 在此添加控件通知处理程序代码
	putin = false;
	flag = false;
	str1 = "0";
	str = "0";
	tag = "";
	the_one = true;
	result = 0;
	Cstr = str.c_str();
	Cstr1 = "";
	UpdateData(false);
}


void CMFCApplication1Dlg::OnBnClickedButton19()//←
{
	// TODO: 在此添加控件通知处理程序代码
	putin = true;
	if (str.length() == 1)
		str = "0";
	else
		str.pop_back();
	if (flag) {
		the_one = true;
		flag = false;
		Cstr1 = "";
		str = result.toString();
	}
	Cstr = str.c_str();
	UpdateData(false);
}


void CMFCApplication1Dlg::OnBnClickedButton11()//+/-
{
	// TODO: 在此添加控件通知处理程序代码
		UpdateData(true);
		str = CW2A(Cstr.GetString());
		num2 = str;
		str = (-num2).toString();
		Cstr=str.c_str();
		UpdateData(false);
		
}


void CMFCApplication1Dlg::OnBnClickedButton12()//+
{
	// TODO: 在此添加控件通知处理程序代码
	if (the_one) {
		putin = false;
		UpdateData(true);
		str = CW2A(Cstr.GetString());
		the_one = false;
		tag = "+";
		try {
			result = str;
		}
		catch (BigFloatException& e) {
			Cstr = e.err_msg().c_str();
			AfxMessageBox(Cstr);
			OnBnClickedButton18();
			return;
		}
	}
	else {
		if (putin) {
			UpdateData(true);
			str = CW2A(Cstr.GetString());
			putin = false;
			try {
				if (tag == "+")
					result += str;
				else if (tag == "×")
					result *= str;
				else if (tag == "÷")
					result /= str;
				else if (tag == "-")
					result -= str;
			}
			catch (BigFloatException& e) {
				Cstr = e.err_msg().c_str();
				AfxMessageBox(Cstr);
				OnBnClickedButton18();
				return;
			}
			tag = "+";
		}
		else {
			tag = "+";
			
		}
	}	
	str = result.toString();
	str1 = result.toString() + "+";
	Cstr = str.c_str();
	Cstr1 = str1.c_str();
	UpdateData(false);
	str = "0";
	flag = false;
}


void CMFCApplication1Dlg::OnBnClickedButton13()
{
	// TODO: 在此添加控件通知处理程序代码
	if (the_one) {
		putin = false;
		UpdateData(true);
		str = CW2A(Cstr.GetString());
		the_one = false;
		tag = "-";
		try {
			result = str;
		}
		catch (BigFloatException& e) {
			Cstr = e.err_msg().c_str();
			AfxMessageBox(Cstr);
			OnBnClickedButton18();
			return;
		}
		
	}
	else {
		if (putin) {
			UpdateData(true);
			str = CW2A(Cstr.GetString());
			putin = false;
			try {
				if (tag == "+")
					result += str;
				else if (tag == "×")
					result *= str;
				else if (tag == "÷")
					result /= str;
				else if (tag == "-")
					result -= str;
			}
			catch (BigFloatException& e) {
				Cstr = e.err_msg().c_str();
				AfxMessageBox(Cstr);
				OnBnClickedButton18();
				return;
			}
			tag = "-";
		}
		else {
			tag = "-";
			
		}

	}
	str = result.toString();
	str1 = result.toString() + "-";
	Cstr = str.c_str();
	Cstr1 = str1.c_str();
	UpdateData(false);
	str = "0";
	flag = false;
}


void CMFCApplication1Dlg::OnBnClickedButton14()
{
	// TODO: 在此添加控件通知处理程序代码
	if (the_one) {
		putin = false;
		UpdateData(true);
		str = CW2A(Cstr.GetString());
		the_one = false;
		tag = "×";
		try {
			result = str;
		}
		catch (BigFloatException& e) {
			Cstr = e.err_msg().c_str();
			AfxMessageBox(Cstr);
			OnBnClickedButton18();
			return;
		}
	}
	else {
		if (putin) {
			UpdateData(true);
			str = CW2A(Cstr.GetString());
			putin = false;
			try {
				if (tag == "+")
					result += str;
				else if (tag == "×")
					result *= str;
				else if (tag == "÷")
					result /= str;
				else if (tag == "-")
					result -= str;
			}
			catch (BigFloatException& e) {
				Cstr = e.err_msg().c_str();
				AfxMessageBox(Cstr);
				OnBnClickedButton18();
				return;
			}
			tag = "×";
		}
		else {
			tag = "×";
		}

	}
	str = result.toString();
	str1 = result.toString() + "×";
	Cstr = str.c_str();
	Cstr1 = str1.c_str();
	UpdateData(false);
	str = "0";
	flag = false;
}


void CMFCApplication1Dlg::OnBnClickedButton15()
{
	// TODO: 在此添加控件通知处理程序代码
	if (the_one) {
		putin = false;
		UpdateData(true);
		str = CW2A(Cstr.GetString());
		the_one = false;
		tag = "÷";
		try {
			result = str;
		}
		catch (BigFloatException& e) {
			Cstr = e.err_msg().c_str();
			AfxMessageBox(Cstr);
			OnBnClickedButton18();
			return;
		}
	}
	else {
		if (putin) {
			UpdateData(true);
			str = CW2A(Cstr.GetString());
			putin = false;
			try {
				if (tag == "+")
					result += str;
				else if (tag == "×")
					result *= str;
				else if (tag == "÷")
					result /= str;
				else if (tag == "-")
					result -= str;
			}
			catch (BigFloatException& e) {
				Cstr = e.err_msg().c_str();
				AfxMessageBox(Cstr);
				OnBnClickedButton18();
				return;
			}
			tag = "÷";
		}
		else {
			tag = "÷";
		}

	}
	str = result.toString();
	str1 = result.toString() + "÷";
	Cstr = str.c_str();
	Cstr1 = str1.c_str();
	UpdateData(false);
	str = "0";
	flag = false;
}


void CMFCApplication1Dlg::OnBnClickedButton16()//=
{
	// TODO: 在此添加控件通知处理程序代码
	if (putin) {
		putin = false;
		UpdateData(true);
		str = CW2A(Cstr.GetString());
		str1 = str1 + str + "=";
		try {
			if (tag == "+")
			result += str;
		else if (tag == "×")
			result *= str;
		else if (tag == "÷") 			
				result /= str;
			else if (tag == "-")
			result -= str;
		}
		catch (BigFloatException& e) {
			Cstr = e.err_msg().c_str();
			AfxMessageBox(Cstr);
			OnBnClickedButton18();
			return;
		}
		str = result.toString();
		Cstr = str.c_str();
		Cstr1 = str1.c_str();
		UpdateData(false);
		str = "0";
		flag = true;
	}
	
}


BOOL CMFCApplication1Dlg::PreTranslateMessage(MSG* pMsg)
{
	// TODO: 在此添加专用代码和/或调用基类
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


void CMFCApplication1Dlg::OnEnChangeEdit1()
{
	// TODO:  如果该控件是 RICHEDIT 控件，它将不
	// 发送此通知，除非重写 CDialogEx::OnInitDialog()
	// 函数并调用 CRichEditCtrl().SetEventMask()，
	// 同时将 ENM_CHANGE 标志“或”运算到掩码中。

	// TODO:  在此添加控件通知处理程序代码
	putin = true;
	if (flag) {
		the_one = true;
		flag = false;
		Cstr1 = "";
	}
}


void CMFCApplication1Dlg::OnAccuracy()
{
	// TODO: 在此添加命令处理程序代码
	SetAccDlg dlg;
	dlg.DoModal();
}
