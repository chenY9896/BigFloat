#ifndef _DEBUG
#include "BigFloat.h"
#include <time.h>
#include <Windows.h> 

//随机生成数
string generate(const int len, const bool sign, const bool dec,const int e) {
	LARGE_INTEGER time;
	QueryPerformanceCounter(&time);   
	srand((unsigned int)time.QuadPart);
	string str = "";
	if (!sign)
		str += "-";
	if (e <= 0) {
		str += "0.";
		for (int i = e; i < 0; i++) {
			str += "0"; 
		}
		str += to_string(rand() % 10+1);
		for (int i = 1; i < len + e; i++) {
			str+=to_string(rand() % 10);
		}

	}
	else {
		str += to_string(rand() % 10 + 1);
		for (int i = 1; i < len; i++) {
			str += to_string(rand() % 10);
		}
		if (dec) {
			str.insert(e, ".");
		}
	}
//	cout << str << endl;
	return str;
}

void TEST()
{
	/*
	BigFloat a, b;
	BigFloat::setAccuracy(10);
	double time = 0;
	LARGE_INTEGER t1, t2, tc;
	for (int i = 0; i < 10; i++) {
		a = generate(1000, 1, 1, 500);
		b = generate(1000, 1, 1, 500);
	//	cout << a << endl << b << endl;
		QueryPerformanceFrequency(&tc);
		QueryPerformanceCounter(&t1);
		a /= b;
		QueryPerformanceCounter(&t2);
		cout << "Use Time:" << (float)(t2.QuadPart - t1.QuadPart)*1.0 / tc.QuadPart << "s" << endl;
	//	cout << a << endl;
		time += (t2.QuadPart - t1.QuadPart)*1.0 / tc.QuadPart;
	}
	cout << "Average Time:" << (time / 10) << "s" << endl;
	*/
	cout << BigFloat("123412341234123412341234123412341289430984095.8328452930854923984721374109578034") / BigFloat("120934789347523984502394852389459832.348983043051234") << endl;
	system("pause");
}



#endif