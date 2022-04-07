#include "BigFloat.h"
#include <iostream>
#include <string>
using namespace std;
BigFloat::BigFloat()
{
	s = true;
	e = 0;
	m.push_back(0);

}
BigFloat::BigFloat(const BigFloat &num)
{
	m = num.m;
	e = num.e;
	s = num.s;
}
/*需重写
BigFloat::BigFloat(int num){
	if (num >= 0)
		s = true;
	else{
		s = false;
		num *= (-1);
	}
	do {
		m.push_back((int)(num % 10));
		num /= 10;
		
	} while (num != 0);
	e = 0;
}
*/
BigFloat::BigFloat(string& num) {
	e = 1; 
	s = true;
	bool headtag = false,tailtag = false;

	string::iterator iter = num.begin(); 
	while(iter != num.end())  //使用正向迭代器去除字符串前边的0.
	{
		char ch = (*iter);
		if (ch == '-') {
			s = false;
			num.erase(iter);
		}
		else if (ch == '0' && (*(iter+1) == '.')) {
			break;
		}
		else if (ch == '0') {
			num.erase(iter);
		}
		else if (ch != '0') {
			break;
		}
	}
	
	string::reverse_iterator r_iter = num.rbegin(); //使用反向迭代器去除字符串后边的0.
	while(r_iter != num.rend()) 
	{
		char ch = (*r_iter);
		if (ch == '0') {
			r_iter = string::reverse_iterator(num.erase((++r_iter).base()));
		}
		else if (ch != '0') {
			break;
		}
	}

	for (string::iterator iter = num.begin(); iter != num.end(); ++iter)	
	{
		char ch = (*iter);
		if (ch == '.') {
			e = distance(iter , num.end());
			continue;
		}
		else {
			m.push_back((int)((*iter) - '0'));
		}
	}
}
BigFloat::~BigFloat()
{
}
istream& operator >> (istream& stream, BigFloat& num) {    
	string str;
	stream >> str;
	num = BigFloat(str);
	return stream;
}
ostream& operator << (ostream& stream,const BigFloat& num) {
	if (!num.s)
		stream << "-";
	for (vector<int>::const_iterator iter = num.m.begin(); iter != num.m.end(); iter++) {
		if (num.e == distance(iter , num.m.end() )+1)
			stream << ".";
		stream << *iter;
	}
	return stream;
}
bool operator==(const BigFloat& num1, const BigFloat& num2) 
{
	if (num1.s == (!num2.s)) {
		return false;
	}
	if (num1.m.size() != num2.m.size()) {
		return false;
	}
	if (num1.e != num2.e) {
		return false;
	}
	vector<int>::const_iterator iter1, iter2;
	iter1 = num1.m.begin();
	iter2 = num2.m.begin();
	while (iter1 != num1.m.end()) {
		if (*iter1 != *iter2)  
			return false;
		iter1++;
		iter2++;
	}
	return true;
}
bool operator!=(const BigFloat& num1, const BigFloat& num2) {
	return !(num1 == num2);
}
bool operator<(const BigFloat& num1, const BigFloat& num2) {
	bool sign;
	if (num1.s != num2.s) {
		sign = !num1.s;
		return sign;
	}
	else if (num1.e != num2.e) {
		if (num1.e > num2.e) {
			BigFloat temp = num2;
			temp.e = num1.e;
			for (int i = 0; i < num1.e - num2.e; i++)
				temp.m.push_back(0);

			cout << temp << endl;

			if (num1.m.size() != temp.m.size()) {
				if (num1.s) {
					sign = num1.m.size()<temp.m.size();
					return sign;
				}
				else {
					sign = num1.m.size()>temp.m.size();
					return sign;
				}
			}
			vector<int>::const_iterator iter1, iter2;
			iter1 = num1.m.begin();
			iter2 = temp.m.begin();
			while (iter1 != num1.m.end()) {
				if (num1.s &&  *iter1 < *iter2) return true;
				if (num1.s &&  *iter1 > *iter2) return false;
				if (!num1.s &&  *iter1 > *iter2) return true;
				if (!num1.s &&  *iter1 < *iter2) return false;
				iter1++;
				iter2++;
			}
			return (num1.s && iter2 != temp.m.end()) || (!num1.s && iter1 != num1.m.end());
		}
		else {
			BigFloat temp = num1;
			temp.e = num2.e;
			for (int i = 0; i < num2.e - num1.e; i++)
				temp.m.push_back(0);
			if (num2.m.size() != temp.m.size()) {
				if (num2.s) {
					sign = num1.m.size()<temp.m.size();
					return sign;
				}
				else {
					sign = num2.m.size()>temp.m.size();
					return sign;
				}
			}
			vector<int>::const_iterator iter1, iter2;
			iter1 = num2.m.begin();
			iter2 = temp.m.begin();
			while (iter1 != num1.m.end()) {
				if (num2.s &&  *iter1 < *iter2) return true;
				if (num2.s &&  *iter1 > *iter2) return false;
				if (!num2.s &&  *iter1 > *iter2) return true;
				if (!num2.s &&  *iter1 < *iter2) return false;
				iter1++;
				iter2++;
			}
			return (num2.s && iter2 != temp.m.end()) || (!num2.s && iter1 != num2.m.end());
		}

	}
	else {
		if (num1.m.size() != num2.m.size()) {
			if (num1.s) {
				sign = num1.m.size()<num2.m.size();
				return sign;
			}
			else {
				sign = num1.m.size()>num2.m.size();
				return sign;
			}
		}
		vector<int>::const_iterator iter1, iter2;
		iter1 = num1.m.begin();
		iter2 = num2.m.begin();
		while (iter1 != num1.m.end()) {
			if (num1.s &&  *iter1 < *iter2) return true;
			if (num1.s &&  *iter1 > *iter2) return false;
			if (!num1.s &&  *iter1 > *iter2) return true;
			if (!num1.s &&  *iter1 < *iter2) return false;
			iter1++;
			iter2++;
		}
		return (num1.s && iter2 != num2.m.end()) || (!num1.s && iter1 != num1.m.end());
	}
}
bool operator>(const BigFloat& num1, const BigFloat& num2) {
	bool tag = !(num1 <= num2);
	return tag;
}
bool operator>=(const BigFloat& num1, const BigFloat& num2) {
	bool tag = (num1>num2) || (num1 == num2);
	return tag;
}
bool operator<=(const BigFloat& num1, const BigFloat& num2) {
	bool tag = (num1<num2) || (num1 == num2);
	return tag;
}

BigFloat operator-(const BigFloat & num)
{
	BigFloat temp(num);
	temp.s = !temp.s;
	return temp;
}

BigFloat operator+(BigFloat& num1, BigFloat num2)
{
	if (num1.s == num2.s) {     //同号
		if (num1.e != num2.e) {
			if (num1.e > num2.e) {
				for (int i = 0; i < num1.e - num2.e; i++)	//添0对齐
					num2.m.push_back(0);
				num2.e = num1.e;
			}
			else {
				for (int i = 0; i < num2.e - num1.e; i++)	//添0对齐
					num1.m.push_back(0);
				num1.e = num2.e;
			}
		}
		vector<int>::reverse_iterator iter1, iter2, iter;
		int a = num1.m.size();
		int b = num2.m.size();
		int to_add = 0;     //进位
		iter1 = num1.m.rbegin();
		iter2 = num2.m.rbegin();
		while (iter1 != num1.m.rend() && iter2 != num2.m.rend()) {
			(*iter1) = (*iter1) + (*iter2) + to_add;
			to_add = ((*iter1) > 9);    
			(*iter1) = (*iter1) % 10;
			iter1++;
			iter2++;
		}
		while (iter1 != num1.m.rend()) {
			(*iter1) = (*iter1) + to_add;
			to_add = ((*iter1) > 9);
			(*iter1) %= 10;
			iter1++;
		}
		while (iter2 != num2.m.rend()) {
			int val = (*iter2) + to_add;
			to_add = (val > 9);
			val %= 10;
			num1.m.insert(num1.m.begin(), val);
			iter2++;
		}
		if (to_add != 0)
			num1.m.insert(num1.m.begin(), to_add);
		return num1;
	}
	else {
		if (num1.s)
			return num1 - (-num2);
		else
			return num1 = num2 - (-num1);
	}
}
BigFloat operator-(BigFloat& num1, BigFloat num2) {
	if (num1.s == num2.s) { 
		if (num1.s) {
			if (num1 < num2){
				BigFloat num(num2 - num1);
				num1 = -num2;
				return num1;
			}
		}
		else {
			if (-num1 > -num2)
				return num1 = -((-num1) - (-num2));
			else
				return num1 = (-num2) - (-num1);
		}

		int to_sub = 0;
		if (num1.e != num2.e) {
			if (num1.e > num2.e) {
				for (int i = 0; i < num1.e - num2.e; i++)	//添0对齐
					num2.m.push_back(0);
				num2.e = num1.e;
			}
			else {
				for (int i = 0; i < num2.e - num1.e; i++)	//添0对齐
					num1.m.push_back(0);
				num1.e = num2.e;
			}
		}
	vector<int>::reverse_iterator iter1,iter2;
	iter1 = num1.m.rbegin();
	iter2 = num2.m.rbegin();
	while (iter1 != num1.m.rend() && iter2 != num2.m.rend()) {
		(*iter1) = (*iter1) - (*iter2) - to_sub;
		to_sub = 0;
		if ((*iter1) < 0) {
			to_sub = 1;
			(*iter1) += 10;
		}
		iter1++;
		iter2++;
	}
	while (iter1 != num1.m.rend()) {
		(*iter1) = (*iter1) - to_sub;
		to_sub = 0;
		if ((*iter1) < 0) {
			to_sub = 1;
			(*iter1) += 10;
		}
		else break;
		iter1++;
	}
	vector<int>::iterator iter = num1.m.begin();
	while (!num1.m.empty() && (*iter) == 0) {
		num1.m.erase(iter);
		iter = num1.m.begin();
	}
	if (num1.m.size() == 0) {
		num1.s = true;
		num1.m.insert(num1.m.begin(), 0);
	}
	
	return num1;
}
	else {
		string zero = "0";
		if (num1 > BigFloat(zero))
			return num1 =num1+ (-num2);
		else
			return num1 = -(num2 + (-num1));
}
	return num1;
}
