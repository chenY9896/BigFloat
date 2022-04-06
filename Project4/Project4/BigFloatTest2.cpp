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
		for (int i = 0; i < len - e; i++) {
			str+=to_string(rand() % 10);
		}

	}
	else {
		for (int i = 0; i < len; i++) {
			str += to_string(rand() % 10);
		}
		if (dec) {
			str.insert(e, ".");
		}

	}
	
	cout << str << endl;
	return str;
}

void TEST()
{
	BigFloat a, b;
	a = generate(100, 1, 1, -10);
	b = generate(100, 1, 1, 10);
	cout << a << endl << b << endl;
	LARGE_INTEGER t1, t2, tc;
	QueryPerformanceFrequency(&tc);
	QueryPerformanceCounter(&t1);
	a *= b;
	QueryPerformanceCounter(&t2);
	printf("Use Time:%f\n", (t2.QuadPart - t1.QuadPart)*1.0 / tc.QuadPart);
	cout << a << endl;
	system("pause");
}



#endif