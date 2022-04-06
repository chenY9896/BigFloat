#pragma once
#include <deque>
#include<string>
#include<iostream>
#define DLL_API __declspec(dllexport)
using namespace std;

#define MAX_VAL 1000000000 // ����
#define VAL_LEN 9

class DLL_API ZeroException {
public:
	void error() { cout << "��������Ϊ0!" << endl; }
	string errorText() { return "��������Ϊ0!"; }
};

class DLL_API IllegalStrException {
public:
	void error() { cout << "���벻�Ϸ�!" << endl; }
	string errorText() { return "���벻�Ϸ�!"; }
};

class DLL_API OverFlowException {
public:
	void error() { cout << "ָ�����!" << endl; }
	string errorText() { return "ָ�����!"; }
};

class DLL_API BigFloat
{
private:
	deque <int> integer;//������
	int exponent;//ָ��
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
	void setAccuracy(int);//���ó�������
	string toString();// �ַ�����ʽ�����
	BigFloat operator=(const BigFloat&);//��ֵ
	friend BigFloat DLL_API operator-(const BigFloat&);//�෴��
	
	//�������������
	friend  ostream&  operator<<(ostream&, BigFloat&);
	friend  istream&  operator >> (istream&, BigFloat&);
	// �Ƚ����������
	friend bool DLL_API operator==(const BigFloat&, const BigFloat&);
	friend bool DLL_API operator!=(const BigFloat&, const BigFloat&);
	friend bool DLL_API operator<(const BigFloat&, const BigFloat&);
	friend bool DLL_API operator<=(const BigFloat&, const BigFloat&);
	friend bool DLL_API operator>(const BigFloat&, const BigFloat&);
	friend bool DLL_API operator>=(const BigFloat&, const BigFloat&);
	// �������������
	friend BigFloat DLL_API operator+(const BigFloat&, const BigFloat&);
	friend BigFloat DLL_API operator-(const BigFloat&, const BigFloat&);
	friend BigFloat DLL_API operator*(const BigFloat&, const BigFloat&);
	friend BigFloat DLL_API operator/(const BigFloat&, const BigFloat&) throw(ZeroException);
	friend BigFloat DLL_API operator+=(BigFloat&, const BigFloat&);
	friend BigFloat DLL_API operator-=(BigFloat&, const BigFloat&);
	friend BigFloat DLL_API operator*=(BigFloat&, const BigFloat&);
	friend BigFloat DLL_API operator/=(BigFloat&, const BigFloat&) throw(ZeroException);
};

