#pragma once
#include <deque>
#include<string>
#include<iostream>
#define DLL_API __declspec(dllexport)
using namespace std;

#define MAX_VAL 1000000000 // 基数
#define VAL_LEN 9
class DLL_API BigFloatException {
public:
	BigFloatException(string str = "", int i = 0) :errmsg(str), id(i) {
	}
	virtual void err()const = 0;//打印出错信息
	virtual string err_msg()const = 0;//返回出错信息
	virtual int err_id()const = 0;//返回出错代码
protected:
	string errmsg;
	int id;
};

class DLL_API ZeroException :public BigFloatException {
public:
	ZeroException(string str = "除数不能为0！", int id = 1) :BigFloatException(str, id) {
	}
	virtual void err()const {
		cout << "错误信息：" << errmsg << endl;
	}
	virtual string err_msg()const {
		return errmsg;
	}
	virtual int err_id()const {
		return id;
	}
};

class DLL_API IllegalStrException :public BigFloatException {
public:
	IllegalStrException(string str = "输入不合法!", int id = 2) :BigFloatException(str, id) {
	}
	virtual void err()const {
		cout << "错误信息：" << errmsg << endl;
	}
	virtual string err_msg()const {
		return errmsg;
	}
	virtual int err_id()const {
		return id;
	}
};
class DLL_API ExponentOverFlowException :public BigFloatException {
public:
	ExponentOverFlowException(string str = "指数溢出!", int id = 3) :BigFloatException(str, id) {
	}
	virtual void err()const {
		cout << "错误信息：" << errmsg << endl;
	}
	virtual string err_msg()const {
		return errmsg;
	}
	virtual int err_id()const {
		return id;
	}
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
	BigFloat(const string&) noexcept(false);
	BigFloat(const int&);
	BigFloat(const BigFloat&);
	~BigFloat();
	static void setAccuracy(int);//设置除法精度
	static int getAccuracy();
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
	friend BigFloat DLL_API operator*(const BigFloat&, const BigFloat&) noexcept(false);
	friend BigFloat DLL_API operator/(const BigFloat&, const BigFloat&) noexcept(false);
	friend BigFloat DLL_API operator+=(BigFloat&, const BigFloat&);
	friend BigFloat DLL_API operator-=(BigFloat&, const BigFloat&);
	friend BigFloat DLL_API operator*=(BigFloat&, const BigFloat&) noexcept(false);
	friend BigFloat DLL_API operator/=(BigFloat&, const BigFloat&) noexcept(false);
};

