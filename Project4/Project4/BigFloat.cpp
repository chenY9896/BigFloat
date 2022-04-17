#include "BigFloat.h"
#include <iostream>
#include <string>
#include<limits.h>
using namespace std;

int BigFloat::ACCURACY = 5;

void BigFloat::setAccuracy(int num)
{
	ACCURACY = num;
}
int BigFloat::getAccuracy()
{
	return ACCURACY;
}
//字符串合法性检查，只允许出现字符 0~9、负号和小数点
bool BigFloat::checkStr(const string & str)
{
	for (string::const_iterator iter = str.begin(); iter != str.end(); ++iter)
	{
		if (!(((*iter) >= '0' && (*iter) <= '9')|| ((*iter) == '.'&&iter != str.begin()) || ((*iter) == '-')&&iter==str.begin()&&*(iter+1)!='.')) return false;
	}
	return true;
}

void BigFloat::trim() {
	if (integer.size() != exponent) {
		deque<int>::iterator iter = integer.begin();
		while (!integer.empty() && (*iter) == 0) {
			integer.pop_front();
			iter = integer.begin();
		}
	}
	deque<int>::reverse_iterator r_iter = integer.rbegin();
	while (!integer.empty() && (*r_iter) == 0) {
		integer.pop_back();
		exponent--;
		r_iter = integer.rbegin();
	}
	if (integer.size() == 0) {
		tag = true;
		integer.push_back(0);
		exponent = 1;
	}

}

BigFloat::BigFloat()
{
	tag = true;
	integer.push_back(0);
	exponent = 1;
}
// 字符串构造
// str：十进制字符串
BigFloat::BigFloat(const string & str1)
{
	string str = str1;
	tag = true;
	if (checkStr(str)) {
		string::size_type idx = str.find("-"); //在str中查找是否有负号
		if (idx != string::npos) //存在负号
		{
			tag = false;
			string::const_iterator iter = str.begin();
			str.erase(iter);
		}
		idx = str.find(".");//在str中查找是否有小数点
		if (idx == string::npos) //不存在
		{
			int len = str.length();
			// 按长度9截取子串
			while (len >= VAL_LEN)
			{
				string s = str.substr(len - VAL_LEN, VAL_LEN);
				integer.push_back(stoi(s));
				len -= VAL_LEN;
			}
			// 残留子串
			if (len > 0)
			{
				string s = str.substr(0, len);
				integer.push_back(stoi(s));
			}
			exponent = integer.size();
		}
		else {
			bool type = true;
			string str_int, str_dec;//将数分为整数部分和小数部分分开存储
			for (string::iterator iter = str.begin(); iter < str.end(); iter++)
			{
				char ch = (*iter);
				if (ch == '.') {
					type = false;
					iter++;
				}
				if (type)str_int.push_back(*iter);
				else str_dec.push_back(*iter);
			}
			for (int i = str_dec.length() % VAL_LEN; i < VAL_LEN; i++) {
				str_dec.push_back('0');
			}
			int  len = str_dec.length();
			while (len >= VAL_LEN)
			{
				string s = str_dec.substr(len - VAL_LEN, VAL_LEN);
				integer.push_back(stoi(s));
				len -= VAL_LEN;
			}
			len = str_int.length();
			exponent = 0;
			// 按长度9截取子串
			while (len >= VAL_LEN)
			{
				string s = str_int.substr(len - VAL_LEN, VAL_LEN);
				integer.push_back(stoi(s));
				len -= VAL_LEN;
				exponent++;
			}
			// 残留子串
			if (len > 0)
			{
				string s = str_int.substr(0, len);
				integer.push_back(stoi(s));
				exponent++;
			}

		}
		trim();
	}
	else
		throw IllegalStrException();
	
}

BigFloat::BigFloat(const int & num1)
{
	int num = num1;
	int e = 0;
	if (num >= 0)
		tag = true;
	else {
		tag = false;
		num *= (-1);
	}
	if (num >= MAX_VAL) {
		while (num >= MAX_VAL) {
			integer.push_back(num%MAX_VAL);
			e++;
			num /= MAX_VAL;
		}
	}
		integer.push_back(num);
		e++;
	
	exponent = e;
	
}

BigFloat::BigFloat(const BigFloat & num)
{
	integer = num.integer;
	tag = num.tag;
	exponent = num.exponent;
}

BigFloat::~BigFloat()
{
}

BigFloat BigFloat::operator=(const BigFloat& num) {
	integer = num.integer;
	tag = num.tag;
	exponent = num.exponent;
	return (*this);
}

string BigFloat::toString()
{
	int i = 0;
	string str = "";
	if (exponent > 0) {
		if (!tag)
			str += "-";
		for (deque<int>::const_reverse_iterator iter = integer.rbegin(); iter !=integer.rend(); iter++) {
			if ((*iter) < 100000000 && iter != integer.rbegin()) {
				int count = 0;
				int temp = (*iter);
				while (temp = temp / 10)count++;
				for (int i = 0; i < 9 - count - 1; i++)
					str+= "0";
			}
			str += to_string(*iter);
			i++;
			if (exponent != integer.size() && exponent == i)
				str+=".";
		}
		string::size_type idx = str.find(".");
		int j = 0; bool tag = false;
		if (idx != string::npos) {
			for (string::reverse_iterator iter = str.rbegin(); iter != str.rend(); iter++) {
				if ((*iter) == '0' && iter == str.rbegin())
					tag = true;
				if (tag && (*iter) == '0')
					j++;
				if ((*iter) != '0')
					break;
			}
		}
		for(int i=0;i<j;i++)
			str.pop_back();
		return str;
	}
	else {
		if (!tag)
			str+=  "-";
		str+=  "0.";
		for (i = 0; i > exponent; i--)
			str+=  "000000000";
		for (deque<int>::const_reverse_iterator iter = integer.rbegin(); iter != integer.rend(); iter++) {
			if ((*iter) < 100000000) {
				int count = 0;
				int temp = (*iter);
				while (temp = temp / 10)count++;
				for (int i = 0; i < 9 - count - 1; i++)
					str+= "0";
			}
			str+= to_string(*iter);
		}
		string::size_type idx = str.find(".");//小数部分去零
		int j = 0; bool tag = false;
		if (idx != string::npos) {
			for (string::reverse_iterator iter = str.rbegin(); iter != str.rend(); iter++) {
				if ((*iter) == '0' && iter == str.rbegin())
					tag = true;
				if (tag && (*iter) == '0')
					j++;
				if ((*iter) != '0')
					break;
			}
		}
		for (int i = 0; i<j; i++)
			str.pop_back();
		return str;
	}
}

BigFloat operator-(const BigFloat& num) {
	BigFloat temp(num);
	temp.tag = !temp.tag;
	return temp;
}
/*
ostream& operator<<(ostream& stream, const BigFloat& num) {
	int i = 0;
	if (num.exponent > 0) {
		if (!num.tag)
			stream << "-";
		for (deque<int>::const_reverse_iterator iter = num.integer.rbegin(); iter != num.integer.rend(); iter++) {
			if ((*iter) < 100000000 && iter!= num.integer.rbegin()) {
				int count = 0;
				int temp = (*iter);
				while (temp = temp / 10)count++;
				for (int i = 0; i < 9-count-1; i++)
					stream << "0";
			}	
			stream <<(*iter);
			i++;
			if (num.exponent != num.integer.size() && num.exponent == i)
				stream << ".";
		}
		return stream;
	}
	else {
		if (!num.tag)
			stream << "-";
		stream << "0.";
		for (i = 0; i > num.exponent; i--)
			stream << "000000000";
		for (deque<int>::const_reverse_iterator iter = num.integer.rbegin(); iter != num.integer.rend(); iter++) {
			if ((*iter) < 100000000) {
				int count = 0;
				int temp = (*iter);
				while (temp = temp / 10)count++;
				for (int i = 0; i < 9 - count - 1; i++)
					stream << "0";
			}
			stream << (*iter);
		}
		return stream;
	}

}
*/

ostream& operator<<(ostream& stream, BigFloat& num) {
	string str = num.toString();
	stream << str;
	return stream;
}
istream& operator >> (istream& stream, BigFloat& num) {
	string str;
	stream >> str;
	num = BigFloat(str);
	return stream;
}

bool operator==(const BigFloat& num1, const BigFloat& num2) {
	if (num1.tag == (!num2.tag)) {
		return false;
	}
	if (num1.integer.size() != num2.integer.size()) {
		return false;
	}
	if (num1.exponent != num2.exponent) {
		return false;
	}
	deque<int>::const_iterator iter1, iter2;
	iter1 = num1.integer.begin();
	iter2 = num2.integer.begin();
	while (iter1 != num1.integer.end()) {
		if (*iter1 != *iter2)  return false;
		iter1++;
		iter2++;
	}
	return true;
}


bool operator!=(const BigFloat& num1, const BigFloat& num2) {
	bool tag = !(num1 == num2);
	return tag;
}

bool operator<(const BigFloat& num1, const BigFloat& num2) {
	if (num1.tag != num2.tag) {
		return !num1.tag;
	}
	else {
		if (num1.exponent != num2.exponent) {
			return num1.exponent < num2.exponent;
		}
		else {
			deque<int>::const_reverse_iterator iter1, iter2;
			iter1 = num1.integer.rbegin();
			iter2 = num2.integer.rbegin();
			while (iter1 != num1.integer.rend() && iter2 != num2.integer.rend()) {
				if (num1.tag &&  *iter1 < *iter2) return true;
				if (num1.tag &&  *iter1 > *iter2) return false;
				if (!num1.tag &&  *iter1 > *iter2) return true;
				if (!num1.tag &&  *iter1 < *iter2) return false;
				iter1++;
				iter2++;
			}
			if (iter1 == num1.integer.rend() && iter2 != num2.integer.rend())
				return true;
			else return false;
		}
	}
}



bool operator>(const BigFloat& num1, const BigFloat& num2) {
	bool tag = !(num1 <= num2);
	return tag;
}

bool operator>=(const BigFloat& num1, const BigFloat& num2) {
	bool tag = (num1 > num2) || (num1 == num2);
	return tag;
}

bool operator<=(const BigFloat& num1, const BigFloat& num2) {
	bool tag = (num1 < num2) || (num1 == num2);
	return tag;
}

BigFloat operator+=(BigFloat& num1, const BigFloat& num2) {
	if (num1.tag == num2.tag) {
		deque<int>::iterator iter1;
		deque<int>::const_iterator iter2;
		int to_add = 0;     //进位
		int a = num1.integer.size() - num1.exponent;
		int b = num2.integer.size() - num2.exponent;
		if (a > b) {//被加数小数位长度大于加数
			if (num1.exponent < a - b) {
				for (int i = a - b; i > 0; i--) {
					num1.integer.push_back(0);
					num1.exponent++;
				}
			}
			iter1 = num1.integer.begin();
			for (int i = a - b; i > 0; i--) {
				iter1++;//移位
			}
			iter2 = num2.integer.begin();
		}
		else {
			for (int i = b - a; i > 0; i--) {
				num1.integer.push_front(0);//补0
			}
			iter1 = num1.integer.begin();
			iter2 = num2.integer.begin();
		}
		int temp;
		while (iter1 != num1.integer.end() && iter2 != num2.integer.end()) {
			temp = (*iter1) + (*iter2) + to_add;
			to_add = (temp > MAX_VAL - 1);    // 进位
			(*iter1) = temp % MAX_VAL;
			iter1++;
			iter2++;
		}
		while (iter1 != num1.integer.end()) {
			temp = (*iter1) + to_add;
			to_add = (temp > MAX_VAL - 1);
			(*iter1) = temp % MAX_VAL;
			iter1++;
		}
		while (iter2 != num2.integer.end()) {
			temp = (*iter2) + to_add;
			to_add = (temp > MAX_VAL - 1);
			temp %= 10;
			num1.integer.push_back(temp);
			num1.exponent++;
			iter2++;
		}
		if (to_add != 0) {
			num1.integer.push_back(to_add);
			num1.exponent++;
		}
		num1.trim();
		return num1;
	}
	else {
		if (num1.tag)
			return num1 -= (-num2);
		else
			return num1 = num2 - (-num1);
	}
}


BigFloat operator-=(BigFloat& num1, const BigFloat& num2) {
	if (num1.tag == num2.tag) {
		if (num1 < num2) {  // 2 - 3
			BigFloat num(num2 - num1);
			num1 = -num;
			return num1;
		}
		else if (!num1.tag) {
			if (-num1 > -num2)  // (-3)-(-2) = -(3 - 2)
				return num1 = -((-num1) - (-num2));
			else             // (-2)-(-3) = 3 - 2 
				return num1 = (-num2) - (-num1);
		}
		deque<int>::iterator iter1;
		deque<int>::const_iterator iter2;
		int a = num1.integer.size() - num1.exponent;
		int b = num2.integer.size() - num2.exponent;
		int to_sub = 0;     //借位
		if (a > b) {
			iter1 = num1.integer.begin();
			for (int i = a - b; i > 0; i--) {
				iter1++;
			}
			iter2 = num2.integer.begin();
			
		}
		else {
			for (int i = b - a; i > 0; i--) {
				num1.integer.push_front(0);
			}
			iter1 = num1.integer.begin();
			iter2 = num2.integer.begin();
		}
		while (iter1 != num1.integer.end() && iter2 != num2.integer.end()) {
			(*iter1) = (*iter1) - (*iter2) - to_sub;
			to_sub = 0;
			if ((*iter1) < 0) {
				to_sub = 1;
				(*iter1) += MAX_VAL;
			}
			iter1++;
			iter2++;
		}
		while (iter1 != num1.integer.end()) {
			(*iter1) = (*iter1) - to_sub;
			to_sub = 0;
			if ((*iter1) < 0) {
				to_sub = 1;
				(*iter1) += MAX_VAL;
			}
			else break;
			iter1++;
		}
		num1.trim();
		return num1;
	}
	else {
		if (num1.tag)
			return num1 += (-num2);
		else
			return num1 = -(num2 + (-num1));
	}
}


BigFloat operator*=(BigFloat& num1, const BigFloat& num2) {//手工
	BigFloat result;
	if (num1 == 0 || num2 == 0)
		result = 0;
	else {
		int i = 0;	
		deque<int>::iterator iter;
		long long temp;
		result.tag = ((num1.tag && num2.tag) || (!num1.tag && !num2.tag));
		if (num1.exponent > 0 && num2.exponent > 0 && num1.exponent > INT_MAX - num2.exponent)
			throw ExponentOverFlowException();
		else if (num1.exponent < 0 && num2.exponent < 0 && num1.exponent < INT_MIN - num2.exponent)
			throw ExponentOverFlowException();
		result.exponent = num1.exponent + num2.exponent;
		result.integer.resize(num1.integer.size() + num2.integer.size());//两个数相乘，结果的位数不会超过它们的位数之和。
		for (deque<int>::const_iterator iter2 = num2.integer.begin(); iter2 != num2.integer.end(); iter2++) {
			int to_mul = 0, to_add = 0;  //记录乘法时的进位，加法时的进位
			iter = result.integer.begin();
			iter += i;
			for (deque<int>::const_iterator iter1 = num1.integer.begin(); iter1 != num1.integer.end(); iter1++) {
				temp = (long long)(*iter1) * (long long)(*iter2) + to_mul;  //每位相乘的值
				to_mul = temp / MAX_VAL;  //记录乘法进位
				temp %= MAX_VAL;  //进位后的值

				temp = (*iter) + temp + to_add;
				(*iter) = temp % MAX_VAL;  //设置相应位上的值和原本位上值相加后的值。
				to_add = temp / MAX_VAL;  //记录加法进位
				iter++;
			}
			 i++;
			(*iter) = (*iter) + to_mul + to_add;
		}

	}
	num1 = result;
	num1.trim();
	return num1;

}


BigFloat operator/=(BigFloat& num1, const BigFloat& num2) {
	if (num2 == 0)
		throw ZeroException();
	if (num1 == 0)
		return num1;
	else {
		BigFloat result;
		result.tag = ((num1.tag && num2.tag) || (!num1.tag && !num2.tag));
		if (num1.exponent > 0 && num2.exponent < 0 && num1.exponent > INT_MAX + num2.exponent)
			throw ExponentOverFlowException();
		else if (num1.exponent < 0 && num2.exponent > 0 && num1.exponent < INT_MIN + num2.exponent)
			throw ExponentOverFlowException();
		result.exponent = num1.exponent - num2.exponent;
		result.integer.pop_back();
		BigFloat temp1, temp2;//余数、取整除数
		deque<int>::const_reverse_iterator iter2;
		deque<int>::reverse_iterator iter1;
		iter1 = num1.integer.rbegin();
		iter2 = num2.integer.rbegin();
		temp2.integer = num2.integer;
		if (num1.integer.size() > num2.integer.size()) {
			while (iter2 != num2.integer.rend()) {
				temp1.integer.push_front(*iter1);
				iter1++;
				iter2++;
			}
		}
		else {
			temp1.integer = num1.integer;
			iter1 = num1.integer.rend();
			while (num2.integer.size() > temp1.integer.size())
				temp1.integer.push_front(0);//补0
		}

		if ( num1 > num2 && (num1.tag&&num2.tag) && (num1.exponent==num2.exponent)) {
			result.exponent++;
		}
		temp1.tag = true;
		temp1.exponent = temp1.integer.size();
		temp2.tag = true;
		temp2.exponent = temp2.integer.size();
		temp1.trim();
		bool flag = true;//提前结束循环
		int j = 0;//商
		int m = BigFloat::ACCURACY;
		if (result.exponent < 0)
			m = BigFloat::ACCURACY + result.exponent-1;
		for (int i = 0; (i <= m) && flag; i++) {
			while ((temp1 < temp2) && (iter1 != num1.integer.rend())) {
				temp1.integer.push_front(*iter1);
				temp1.exponent = temp1.integer.size();
				temp1.trim();
				iter1++;
			}
			while ((temp1 < temp2) && (iter1 == num1.integer.rend())) {
				temp1.integer.push_front(0);
				temp1.exponent = temp1.integer.size();
				temp1.trim();
				if (temp1 == 0) {
					flag = false;
					break;
				}
			}
			j = 0;
			while (temp1 >= temp2) {
				BigFloat temp = temp2;
				int k = 1;
				while (temp1 >= (temp * 10)) {
					temp = temp * 10;
					k *= 10;//扩大倍数
				}
				while (temp1 >= temp) {
					temp1 -= temp;
					j += k;
				}
				
			}
			if (!flag) break;
			else if (i< BigFloat::ACCURACY)
				result.integer.push_front(j);
			else {
				if (j > (MAX_VAL/2-1)) {//四舍五入
					deque<int>::iterator iter = result.integer.begin();
					int to_add = 1;
					while (iter != result.integer.end()) {
						(*iter) = (*iter) + to_add;
						to_add = ((*iter) > MAX_VAL-1);
						if (to_add == 0) break;
						(*iter) %= 10;
						iter++;
					}
				}

			}
		}
		result.trim();
		num1 = result;
		return num1;
	}
}


BigFloat operator+(const BigFloat& num1, const BigFloat& num2) {
	BigFloat temp(num1);
	temp += num2;
	return temp;
}
BigFloat operator-(const BigFloat& num1, const BigFloat& num2) {
	BigFloat temp(num1);
	temp -= num2;
	return temp;
}

BigFloat operator*(const BigFloat& num1, const BigFloat& num2) {
	BigFloat temp(num1);
	temp *= num2;
	return temp;
}

BigFloat operator/(const BigFloat& num1, const BigFloat& num2) {
	BigFloat temp(num1);
	temp /= num2;
	return temp;
}
