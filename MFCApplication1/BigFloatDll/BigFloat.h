#pragma once
#include <deque>
#include<string>
#include<iostream>
#define DLL_API __declspec(dllexport)
using namespace std;

#define MAX_VAL 1000000000 // 基数
#define VAL_LEN 9

class DLL_API ZeroException {
public:
	void error() { cout << "除数不能为0!" << endl; }
	string errorText() { return "除数不能为0!"; }
};

class DLL_API IllegalStrException {
public:
	void error() { cout << "输入不合法!" << endl; }
	string errorText() { return "输入不合法!"; }
};

class DLL_API OverFlowException {
public:
	void error() { cout << "指数溢出!" << endl; }
	string errorText() { return "指数溢出!"; }
};

class DLL_API BigFloat
{
private:
	deque <int> integer;//大整数
	int exponent;//指数
	bool tag;//符号
	static int ACCURACY;//除法精度
	void trim();//标准化
	bool checkStr(const string &);//检查非法字符	  
	
public:
	BigFloat();//构造
	BigFloat(const string&);
	BigFloat(const int&);
	BigFloat(const BigFloat&);
	~BigFloat();
	void setAccuracy(int);//设置除法精度
	string toString();// 字符串格式化输出
	BigFloat operator=(const BigFloat&);//赋值
	friend BigFloat DLL_API operator-(const BigFloat&);//相反数
	
	//输入输出流重载
	friend  ostream&  operator<<(ostream&, BigFloat&);
	friend  istream&  operator >> (istream&, BigFloat&);
	// 比较运算符重载
	friend bool DLL_API operator==(const BigFloat&, const BigFloat&);
	friend bool DLL_API operator!=(const BigFloat&, const BigFloat&);
	friend bool DLL_API operator<(const BigFloat&, const BigFloat&);
	friend bool DLL_API operator<=(const BigFloat&, const BigFloat&);
	friend bool DLL_API operator>(const BigFloat&, const BigFloat&);
	friend bool DLL_API operator>=(const BigFloat&, const BigFloat&);
	// 四则运算符重载
	friend BigFloat DLL_API operator+(const BigFloat&, const BigFloat&);
	friend BigFloat DLL_API operator-(const BigFloat&, const BigFloat&);
	friend BigFloat DLL_API operator*(const BigFloat&, const BigFloat&);
	friend BigFloat DLL_API operator/(const BigFloat&, const BigFloat&) throw(ZeroException);
	friend BigFloat DLL_API operator+=(BigFloat&, const BigFloat&);
	friend BigFloat DLL_API operator-=(BigFloat&, const BigFloat&);
	friend BigFloat DLL_API operator*=(BigFloat&, const BigFloat&);
	friend BigFloat DLL_API operator/=(BigFloat&, const BigFloat&) throw(ZeroException);
};

