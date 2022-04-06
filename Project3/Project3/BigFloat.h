#pragma once
#include <vector>
#include <deque>
#include<iostream>
using namespace std;

class ZeroException {
public:
	void error() { cout << "��������Ϊ0!" << endl; }
	string errorText() { return "��������Ϊ0!"; }
};
class BigFloat
{
private:
	deque <char> integer;//������
	bool tag;//����
	int exponent;//����
	void trim();//��׼��
	static  int ACCURACY;//��������
public:
	BigFloat();//����
	BigFloat(string&);
	BigFloat(const BigFloat&);
	~BigFloat();
	string b_str();//BigFloatת��string
	void setAccuracy(int);//���ó�������
	static const BigFloat ZERO;
	static const BigFloat ONE;

	BigFloat operator=(const BigFloat& op);//��ֵ
	friend BigFloat operator-(const BigFloat&);//�෴��

	friend ostream& operator<<(ostream&, const BigFloat&);//���
	friend istream& operator >> (istream&, BigFloat&);//����

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

