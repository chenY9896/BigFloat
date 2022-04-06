#include "BigFloat.h"
#include <iostream>
#include <string>
using namespace std;

int main() {
	BigFloat a,b;
	cin >> a;
	cin >> b;
	
	cout << a << endl;
	cout << b << endl;

	if (a < b)
		cout << a << endl;
	else
		cout << b << endl;
	cout << "a+b=" << a + b << endl;
	cout << "a-b=" << a - b << endl;
	cout << "a*b=" << a * b << endl;
	try {
		cout << "a/b=" << a / b << endl;
	}
	catch (ZeroException e) {
		e.error();
	}
	
	system("pause");
	return 0;
}