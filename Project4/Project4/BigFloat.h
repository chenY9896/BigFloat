#pragma once
#include <deque>
#include<string>
#include<iostream>

using namespace std;

#define MAX_VAL 1000000000 // ����
#define VAL_LEN 9

class ZeroException {
public:
	void error() { cout << "��������Ϊ0!" << endl; }
	string errorText() { return "��������Ϊ0!"; }
};

class IllegalStrException {
public:
	void error() { cout << "���벻�Ϸ�!" << endl; }
	string errorText() { return "���벻�Ϸ�!"; }
};

class OverFlowException {
public:
	void error() { cout << "ָ�����!" << endl; }
	string errorText() { return "ָ�����!"; }
};

class BigFloat
{
private:
	deque <int> integer;//������
	int exponent;//����
	bool tag;//����
	static int ACCURACY;//��������
	void trim();//��׼��
	bool checkStr(const string &);//���Ƿ��ַ�	  
	
public:
	BigFloat();//����
	BigFloat(const string&);
	BigFloat(const int&);
	BigFloat(const BigFloat&);
	~BigFloat();
	static void setAccuracy(int);//���ó�������
	string toString();// �ַ�����ʽ�����
	static const BigFloat ZERO;
	static const BigFloat ONE;
	static const BigFloat TEN;
	BigFloat operator=(const BigFloat&);//��ֵ
	friend BigFloat operator-(const BigFloat&);//�෴��
	
	//�������������
	friend ostream& operator<<(ostream&, BigFloat&);
	friend istream& operator >> (istream&, BigFloat&);
	// �Ƚ����������
	friend bool operator==(const BigFloat&, const BigFloat&);
	friend bool operator!=(const BigFloat&, const BigFloat&);
	friend bool operator<(const BigFloat&, const BigFloat&);
	friend bool operator<=(const BigFloat&, const BigFloat&);
	friend bool operator>(const BigFloat&, const BigFloat&);
	friend bool operator>=(const BigFloat&, const BigFloat&);
	// �������������
	friend BigFloat operator+(const BigFloat&, const BigFloat&);
	friend BigFloat operator-(const BigFloat&, const BigFloat&);
	friend BigFloat operator*(const BigFloat&, const BigFloat&);
	friend BigFloat operator/(const BigFloat&, const BigFloat&) throw(ZeroException);
	friend BigFloat operator+=(BigFloat&, const BigFloat&);
	friend BigFloat operator-=(BigFloat&, const BigFloat&);
	friend BigFloat operator*=(BigFloat&, const BigFloat&);
	friend BigFloat operator/=(BigFloat&, const BigFloat&) throw(ZeroException);
};

