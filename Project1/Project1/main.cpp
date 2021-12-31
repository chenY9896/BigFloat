#include "BigFloat.h"
#include <iostream>
#include<string>
using namespace std;

int main() {
	
	BigFloat A, B;
	while (cin >> A >> B) {
		cout << "A:" << A << endl;
		cout << "B:" << B << endl;	
		break;
	}
	if (A == B) {
		cout << "A = B " << endl;
	}
	else if (A > B) {
		cout << "A > B " << endl;
	}
	else cout << "A < B " << endl;

	cout << "A + B = " << A + B << endl;


	/*
	float a;
	cin >> a;
	cout << a << endl;
	*/

	system("pause");
	return 0;
}