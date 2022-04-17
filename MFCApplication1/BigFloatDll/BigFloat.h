#pragma once
#include <deque>
#include<string>
#include<iostream>
#define DLL_API __declspec(dllexport)
using namespace std;

#define MAX_VAL 1000000000 // ����
#define VAL_LEN 9
class DLL_API BigFloatException {
public:
	BigFloatException(string str = "", int i = 0) :errmsg(str), id(i) {
	}
	virtual void err()const = 0;//��ӡ������Ϣ
	virtual string err_msg()const = 0;//���س�����Ϣ
	virtual int err_id()const = 0;//���س������
protected:
	string errmsg;
	int id;
};

class DLL_API ZeroException :public BigFloatException {
public:
	ZeroException(string str = "��������Ϊ0��", int id = 1) :BigFloatException(str, id) {
	}
	virtual void err()const {
		cout << "������Ϣ��" << errmsg << endl;
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
	IllegalStrException(string str = "���벻�Ϸ�!", int id = 2) :BigFloatException(str, id) {
	}
	virtual void err()const {
		cout << "������Ϣ��" << errmsg << endl;
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
	ExponentOverFlowException(string str = "ָ�����!", int id = 3) :BigFloatException(str, id) {
	}
	virtual void err()const {
		cout << "������Ϣ��" << errmsg << endl;
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
	deque <int> integer;//������
	int exponent;//ָ��
	bool tag;//����
	static int ACCURACY;//��������
	void trim();//��׼��
	bool checkStr(const string &);//���Ƿ��ַ�	  
	
public:
	BigFloat();//����
	BigFloat(const string&) noexcept(false);
	BigFloat(const int&);
	BigFloat(const BigFloat&);
	~BigFloat();
	static void setAccuracy(int);//���ó�������
	static int getAccuracy();
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
	friend BigFloat DLL_API operator*(const BigFloat&, const BigFloat&) noexcept(false);
	friend BigFloat DLL_API operator/(const BigFloat&, const BigFloat&) noexcept(false);
	friend BigFloat DLL_API operator+=(BigFloat&, const BigFloat&);
	friend BigFloat DLL_API operator-=(BigFloat&, const BigFloat&);
	friend BigFloat DLL_API operator*=(BigFloat&, const BigFloat&) noexcept(false);
	friend BigFloat DLL_API operator/=(BigFloat&, const BigFloat&) noexcept(false);
};

