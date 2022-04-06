#include "BigFloat.h"
#include <iostream>
#include <string>
using namespace std;
void BigFloat::trim() {
	if (integer.size() != exponent) {
		deque<char>::iterator iter = integer.begin();
		while (!integer.empty() && (*iter) == 0) {
			integer.pop_front();
			iter = integer.begin();
		}
	}
	deque<char>::reverse_iterator r_iter = integer.rbegin();
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

BigFloat::BigFloat() {
	tag = true;
	integer.push_back(0);
	exponent = 0;
}
BigFloat::BigFloat(string& num) {
	bool type = false;
	tag = true;
	string str = ".";
	int e = 0;
	string::size_type idx;
	idx = num.find(str); //在num中查找是否有小数点
	if (idx == string::npos) //不存在。
		num = num + str;
	for (string::reverse_iterator iter = num.rbegin(); iter < num.rend(); iter++) {
		char ch = (*iter);
		if (ch == '+') {
			tag = true;
			break;
		}
		if (ch == '-') {
			tag = false;
			break;
		}
		if (ch == '.') {
			type = true;
			iter++;
		}
		if (type) {
			e++;
		}

		integer.push_back((char)((*iter) - '0'));
	}
	exponent = e;
	trim();
}

BigFloat::BigFloat(const BigFloat &num) {
	integer = num.integer;
	tag = num.tag;
	exponent = num.exponent;
}

BigFloat::~BigFloat()
{
}

string BigFloat::b_str()
{
	string str;
	int i = 0;
	if (exponent > 0) {
		if (!tag)
			str = "-";
		for (deque<char>::const_reverse_iterator iter = integer.rbegin(); iter != integer.rend(); iter++) {
			str += (char)((*iter) + '0');
			i++;
			if (exponent != integer.size() && exponent == i)
				str += ".";
		}
		return str;
	}
	else {
		if (!tag)
			str = "-";
		str += "0.";
		for (i = 0; i > exponent; i--)
			str += "0";
		for (deque<char>::const_reverse_iterator iter = integer.rbegin(); iter != integer.rend(); iter++) {
			str += (char)((*iter) + '0');
		}
		return str;
	}
}

void BigFloat::setAccuracy(int num)
{
	ACCURACY = num;
}

const BigFloat BigFloat::ZERO = BigFloat((string("0")));
const BigFloat BigFloat::ONE = BigFloat((string("1")));
int BigFloat::ACCURACY = 5;

BigFloat BigFloat::operator=(const BigFloat& num) {
	integer = num.integer;
	tag = num.tag;
	exponent = num.exponent;
	return (*this);
}
BigFloat operator-(const BigFloat& num) {
	BigFloat temp(num);
	temp.tag = !temp.tag;
	return temp;
}
ostream& operator<<(ostream& stream, const BigFloat& num) {
	int i = 0;
	if (num.exponent > 0) {
		if (!num.tag)
			stream << "-";
		for (deque<char>::const_reverse_iterator iter = num.integer.rbegin(); iter != num.integer.rend(); iter++) {
			stream << (char)((*iter) + '0');
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
			stream << "0";
		for (deque<char>::const_reverse_iterator iter = num.integer.rbegin(); iter != num.integer.rend(); iter++) {
			stream << (char)((*iter) + '0');
		}
		return stream;
	}

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
	deque<char>::const_iterator iter1, iter2;
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
			deque<char>::const_reverse_iterator iter1, iter2;
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
		deque<char>::iterator iter1;
		deque<char>::const_iterator iter2;
		int a = num1.integer.size() - num1.exponent;
		int b = num2.integer.size() - num2.exponent;
		char to_add = 0;     //进位
		if (a > b) {
			if (num1.exponent < a - b) {
				for (int i = a - b; i > 0; i--) {
					num1.integer.push_back(0);
					num1.exponent++;
				}
			}
			iter1 = num1.integer.begin();
			for (int i = a - b; i > 0; i--) {
				iter1++;
			}
			iter2 = num2.integer.begin();
			while (iter1 != num1.integer.end() && iter2 != num2.integer.end()) {
				(*iter1) = (*iter1) + (*iter2) + to_add;
				to_add = ((*iter1) > 9);    // 大于9进一位
				(*iter1) = (*iter1) % 10;
				iter1++;
				iter2++;
			}
			while (iter1 != num1.integer.end()) {
				(*iter1) = (*iter1) + to_add;
				to_add = ((*iter1) > 9);
				(*iter1) %= 10;
				iter1++;
			}
			while (iter2 != num2.integer.end()) {
				char val = (*iter2) + to_add;
				to_add = (val > 9);
				val %= 10;
				num1.integer.push_back(val);
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
			for (int i = b - a; i > 0; i--) {
				num1.integer.push_front(0);
			}
			iter1 = num1.integer.begin();
			iter2 = num2.integer.begin();
			while (iter1 != num1.integer.end() && iter2 != num2.integer.end()) {
				(*iter1) = (*iter1) + (*iter2) + to_add;
				to_add = ((*iter1) > 9);    // 大于9进一位
				(*iter1) = (*iter1) % 10;
				iter1++; iter2++;
			}
			while (iter1 != num1.integer.end()) {
				(*iter1) = (*iter1) + to_add;
				to_add = ((*iter1) > 9);
				(*iter1) %= 10;
				iter1++;
			}
			while (iter2 != num2.integer.end()) {
				char val = (*iter2) + to_add;
				to_add = (val > 9);
				val %= 10;
				num1.integer.push_back(val);
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
		deque<char>::iterator iter1;
		deque<char>::const_iterator iter2;
		int a = num1.integer.size() - num1.exponent;
		int b = num2.integer.size() - num2.exponent;
		char to_sub = 0;     //借位
		if (a > b) {
			iter1 = num1.integer.begin();
			for (int i = a - b; i > 0; i--) {
				iter1++;
			}
			iter2 = num2.integer.begin();
			while (iter1 != num1.integer.end() && iter2 != num2.integer.end()) {
				(*iter1) = (*iter1) - (*iter2) - to_sub;
				to_sub = 0;
				if ((*iter1) < 0) {
					to_sub = 1;
					(*iter1) += 10;
				}
				iter1++;
				iter2++;
			}
			while (iter1 != num1.integer.end()) {
				(*iter1) = (*iter1) - to_sub;
				to_sub = 0;
				if ((*iter1) < 0) {
					to_sub = 1;
					(*iter1) += 10;
				}
				else break;
				iter1++;
			}
			return num1;
		}
		else {
			for (int i = b - a; i > 0; i--) {
				num1.integer.push_front(0);
			}
			iter1 = num1.integer.begin();
			iter2 = num2.integer.begin();
			while (iter1 != num1.integer.end() && iter2 != num2.integer.end()) {
				(*iter1) = (*iter1) - (*iter2) - to_sub;
				to_sub = 0;
				if ((*iter1) < 0) {
					to_sub = 1;
					(*iter1) += 10;
				}
				iter1++;
				iter2++;
			}
			while (iter1 != num1.integer.end()) {
				(*iter1) = (*iter1) - to_sub;
				to_sub = 0;
				if ((*iter1) < 0) {
					to_sub = 1;
					(*iter1) += 10;
				}
				else break;
				iter1++;
			}
			num1.trim();
			return num1;
		}
	}
	else {
		if (num1 > BigFloat::ZERO)
			return num1 += (-num2);
		else
			return num1 = -(num2 + (-num1));
	}
}

BigFloat operator*=(BigFloat& num1, const BigFloat& num2) {//手工
	BigFloat result;
	if (num1 == BigFloat::ZERO || num2 == BigFloat::ZERO)
		result = BigFloat::ZERO;
	else {
		int i = 0;
		deque<char>::const_iterator iter2;
		deque<char>::iterator iter;
		iter2 = num2.integer.begin();
		result.tag = ((num1.tag && num2.tag) || (!num1.tag && !num2.tag));
		result.exponent = num1.exponent + num2.exponent;
		result.integer.resize(num1.integer.size() + num2.integer.size());//两个数相乘，结果的位数不会超过它们的位数之和。
		while (iter2 != num2.integer.end()) {
			char to_mul = 0, to_add = 0;  //记录乘法时的进位，加法时的进位
			iter = result.integer.begin();
			iter += i;
			for (deque<char>::const_iterator iter1 = num1.integer.begin(); iter1 != num1.integer.end(); iter1++) {
				char temp = (*iter1) * (*iter2) + to_mul;  //每位相乘的值
				to_mul = temp / 10;  //记录进位
				temp %= 10;  //进位后的值

				char temp2 = (*iter) + temp + to_add;
				(*iter) = temp2 % 10;  //设置相应位上的值和原本位上值相加后的值。
				to_add = temp2 / 10;  //记录进位
				iter++;
			}
			iter2++; i++;
			(*iter) = (*iter) + to_mul + to_add;
		}

	}
	num1 = result;
	num1.trim();
	return num1;

}

BigFloat operator/=(BigFloat& num1, const BigFloat& num2) {
	if (num2 == BigFloat::ZERO)
		throw ZeroException();
	if (num1 == BigFloat::ZERO)
		return num1;
	else {
		BigFloat result;
		result.tag = ((num1.tag && num2.tag) || (!num1.tag && !num2.tag));
		result.exponent = num1.exponent - num2.exponent + 2;
		BigFloat temp1, temp2;
		deque<char>::const_reverse_iterator iter2;
		deque<char>::reverse_iterator iter1;
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
		temp1.tag = true;
		temp1.exponent = temp1.integer.size();
		temp2.tag = true;
		temp2.exponent = temp2.integer.size();
		temp1.trim();
		bool flag = true;//提前结束循环
		for (int i = 0; (i <= BigFloat::ACCURACY) && flag; i++) {
			int k = 0;
			while ((temp1 < temp2) && (iter1 != num1.integer.rend())) {
				temp1.integer.push_front(*iter1);
				temp1.exponent = temp1.integer.size();
				temp1.trim();
				iter1++;
				if (k != 0) {
					result.integer.push_front(0);
				}
				if (i == 0)
					result.exponent--;

				k++;
			}
			while ((temp1 < temp2) && (iter1 == num1.integer.rend())) {
				temp1.integer.push_front(0);;
				temp1.exponent = temp1.integer.size();
				temp1.trim();
				if (temp1 == BigFloat::ZERO) {
					flag = false;
					break;
				}
				if (k != 0) {
					result.integer.push_front(0);
				}
				if (i == 0)
					result.exponent--;
				k++;
			}
			int j = 0;
			while (temp1 >= temp2) {
				temp1 -= temp2;
				j++;
			}
			if (i< BigFloat::ACCURACY)
				result.integer.push_front((char)(j));
			else {
				if (j > 4) {//四舍五入
					deque<char>::iterator iter = result.integer.begin();
					char to_add = 1;
					while (iter != result.integer.end()) {
						(*iter) = (*iter) + to_add;
						to_add = ((*iter) > 9);
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
