#pragma once


// SetAccDlg 对话框

class SetAccDlg : public CDialogEx
{
	DECLARE_DYNAMIC(SetAccDlg)

public:
	SetAccDlg(CWnd* pParent = NULL);   // 标准构造函数
	virtual ~SetAccDlg();

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DIALOG1 };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedOk();
	int acc;
};
