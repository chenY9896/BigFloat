#pragma once
#include <vector>
#include <deque>
#include<iostream>
using namespace std;

class ZeroException {
public:
	void error() { cout << "除数不能为0!" << endl; }
	string errorText() { return "除数不能为0!"; }
};
class BigFloat
{
private:
	deque <char> integer;//大整数
	bool tag;//符号
	int exponent;//阶码
	void trim();//标准化
	static  int ACCURACY;//除法精度
public:
	BigFloat();//构造
	BigFloat(string&);
	BigFloat(const BigFloat&);
	~BigFloat();
	string b_str();//BigFloat转换string
	void setAccuracy(int);//设置除法精度
	static const BigFloat ZERO;
	static const BigFloat ONE;

	BigFloat operator=(const BigFloat& op);//赋值
	friend BigFloat operator-(const BigFloat&);//相反数

	friend ostream& operator<<(ostream&, const BigFloat&);//输出
	friend istream& operator >> (istream&, BigFloat&);//输入

	friend bool operator==(const BigFloat&, const BigFloat&);
	friend bool operator<(const BigFloat&, const BigFloat&);
	friend bool operator<=(const BigFloat&, const BigFloat&);
	friend bool operator>(const BigFloat&, const BigFloat&);
	friend bool operator>=(const BigFloat&, const BigFloat&);

	friend BigFloat operator+(const BigFloat&, const BigFloat&);
	friend BigFloat operator-(const BigFloat&, const BigFloat&);
	friend BigFloat operator*(const BigFloat&, const BigFloat&);
	friend BigFloat operator/(const BigFloat&, const BigFloat&) throw(ZeroException);

	friend BigFloat operator+=(BigFloat&, const BigFloat&);
	friend BigFloat operator-=(BigFloat&, const BigFloat&);
	friend BigFloat operator*=(BigFloat&, const BigFloat&);
	friend BigFloat operator/=(BigFloat&, const BigFloat&) throw(ZeroException);
};

