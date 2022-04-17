// SetAccDlg.cpp : 实现文件
//

#include "stdafx.h"
#include "MFCApplication1.h"
#include "SetAccDlg.h"
#include "afxdialogex.h"
#include "BigFloat.h"


// SetAccDlg 对话框

IMPLEMENT_DYNAMIC(SetAccDlg, CDialogEx)

SetAccDlg::SetAccDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(IDD_DIALOG1, pParent)
	, acc(0)
{
	acc = BigFloat::getAccuracy();
}

SetAccDlg::~SetAccDlg()
{
}

void SetAccDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT1, acc);
	
}


BEGIN_MESSAGE_MAP(SetAccDlg, CDialogEx)
	ON_BN_CLICKED(IDOK, &SetAccDlg::OnBnClickedOk)
END_MESSAGE_MAP()


// SetAccDlg 消息处理程序


void SetAccDlg::OnBnClickedOk()
{
	// TODO: 在此添加控件通知处理程序代码
	UpdateData(true);
	BigFloat::setAccuracy(acc);
	CDialogEx::OnOK();
}
