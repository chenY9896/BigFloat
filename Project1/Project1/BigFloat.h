#pragma once
#include <vector>
using namespace std;
class BigFloat
{
private:
	vector<int> m;
	bool s;
	int e;

public:
	BigFloat();
	BigFloat(int);
	BigFloat(string&);
	BigFloat(const BigFloat&);

	~BigFloat();

	friend bool operator==(const BigFloat&, const BigFloat&);
	friend bool operator!=(const BigFloat&, const BigFloat&);
	friend bool operator>(const BigFloat&, const BigFloat&);
	friend bool operator>=(const BigFloat&, const BigFloat&);
	friend bool operator<(const BigFloat&, const BigFloat&);
	friend bool operator<=(const BigFloat&, const BigFloat&);

	friend BigFloat operator+(BigFloat& ,BigFloat);
	friend BigFloat operator-(BigFloat&, BigFloat);
	friend BigFloat operator-(const BigFloat&);
	friend BigFloat operator*(const BigFloat&, const BigFloat&);
	friend BigFloat operator/(const BigFloat&, const BigFloat&);

	friend ostream& operator<<(ostream&, const BigFloat&);
	friend istream& operator>>(istream&, BigFloat&);

};

