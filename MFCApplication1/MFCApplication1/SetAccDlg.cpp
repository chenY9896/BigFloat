// SetAccDlg.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "MFCApplication1.h"
#include "SetAccDlg.h"
#include "afxdialogex.h"
#include "BigFloat.h"


// SetAccDlg �Ի���

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


// SetAccDlg ��Ϣ�������


void SetAccDlg::OnBnClickedOk()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	UpdateData(true);
	BigFloat::setAccuracy(acc);
	CDialogEx::OnOK();
}
