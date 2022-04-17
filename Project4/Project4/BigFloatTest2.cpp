#ifndef _DEBUG
#include "BigFloat.h"
#include <time.h>
#include <Windows.h> 

//随机生成数
string generateStr(const int len, const bool sign,const int e) {
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
		str += to_string(rand() % 9+1);
		for (int i = 1; i < len + e; i++) {
			str+=to_string(rand() % 10);
		}

	}
	else {
		str += to_string(rand() % 9 + 1);
		for (int i = 1; i < len; i++) {
			str += to_string(rand() % 10);
		}
		if (len > e) {
			str.insert(e, ".");
		}
	}
//	cout << str << endl;
	return str;
}

void TEST()
{
	
	BigFloat a, b;
	BigFloat::setAccuracy(10);
	double time = 0;
	LARGE_INTEGER t1, t2, tc;
	for (int i = 0; i < 100; i++) {
		a = generateStr(100, 1, 50);
		b = generateStr(100, 1, -50);
//		cout << a << endl << b << endl;
		QueryPerformanceFrequency(&tc);
		QueryPerformanceCounter(&t1);
		a /= b;
		QueryPerformanceCounter(&t2);
		cout << "用时:" << (float)(t2.QuadPart - t1.QuadPart)*1.0 / tc.QuadPart << "s" << endl;
//		cout << a << endl;
		time += (t2.QuadPart - t1.QuadPart)*1.0 / tc.QuadPart;
	}
	cout << "平均时长:" << (time / 100) << "s" << endl;
	
	//
	//cout<<BigFloat("7605238944.5970453086") + BigFloat("12846.402760423075135")<<endl;
	//cout<<BigFloat("31889126274868846012") + BigFloat("14766385524402442372")<<endl;
	//cout<<BigFloat("7605238944.5970453086") + BigFloat("12846.402760423075135")<<endl;
	//cout << BigFloat("-1771300020.2289702504") + BigFloat("-24371.700374213880894") << endl;
	//cout << BigFloat("0.00000892867576199747") + BigFloat("0.00000000112793671906") << endl;
	//cout << BigFloat("0.00000741543109356401") + BigFloat("47985892.828021333671") << endl;
	//cout << BigFloat("0.00073891398197675339") + BigFloat("-0.00085461831694011879") << endl;
	//cout << BigFloat("0.00023952437358729524") + BigFloat("0.00084037575198185663") << endl<<endl;

	//cout << BigFloat("7605238944.5970453086") - BigFloat("12846.402760423075135") << endl;
	//cout << BigFloat("31889126274868846012") - BigFloat("14766385524402442372") << endl;
	//cout << BigFloat("7605238944.5970453086") - BigFloat("12846.402760423075135") << endl;
	//cout << BigFloat("-1771300020.2289702504") - BigFloat("-24371.700374213880894") << endl;
	//cout << BigFloat("0.00000892867576199747") - BigFloat("0.00000000112793671906") << endl;
	//cout << BigFloat("0.00000741543109356401") - BigFloat("47985892.828021333671") << endl;
	//cout << BigFloat("0.00073891398197675339") - BigFloat("-0.00085461831694011879") << endl;
	//cout << BigFloat("0.00023952437358729524") - BigFloat("0.00084037575198185663") << endl << endl;

	//cout << BigFloat("7605238944.5970453086") * BigFloat("12846.402760423075135") << endl;
	//cout << BigFloat("31889126274868846012") * BigFloat("14766385524402442372") << endl;
	//cout << BigFloat("7605238944.5970453086") * BigFloat("12846.402760423075135") << endl;
	//cout << BigFloat("-1771300020.2289702504") * BigFloat("-24371.700374213880894") << endl;
	//cout << BigFloat("0.00000892867576199747") * BigFloat("0.00000000112793671906") << endl;
	//cout << BigFloat("0.00000741543109356401") * BigFloat("47985892.828021333671") << endl;
	//cout << BigFloat("0.00073891398197675339") * BigFloat("-0.00085461831694011879") << endl;
	//cout << BigFloat("0.00023952437358729524") * BigFloat("0.00084037575198185663") << endl << endl;

	//cout << BigFloat("7605238944.5970453086") / BigFloat("12846.402760423075135") << endl;
	//cout << BigFloat("31889126274868846012") / BigFloat("14766385524402442372") << endl;
	//cout << BigFloat("7605238944.5970453086") / BigFloat("12846.402760423075135") << endl;
	//cout << BigFloat("-1771300020.2289702504") / BigFloat("-24371.700374213880894") << endl;
	//cout << BigFloat("0.00000892867576199747") / BigFloat("0.00000000112793671906") << endl;
	//cout << BigFloat("0.00000741543109356401") / BigFloat("47985892.828021333671") << endl;
	//cout << BigFloat("0.00073891398197675339") / BigFloat("-0.00085461831694011879") << endl;
	//cout << BigFloat("0.00023952437358729524") / BigFloat("0.00084037575198185663") << endl << endl;
	//
	//try {
	//	cout << BigFloat("0.00023952437358729524") / BigFloat("0") << endl;
	//}catch(const BigFloatException& e){
	//	e.err();
	//}


	system("pause");
}



#endif