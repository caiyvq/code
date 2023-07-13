#ifndef HEAD
#define HEAD

#include<iostream>
#include<string>
#include<cassert>
#include<typeinfo>
#include<cmath>
using namespace std;
//fraction class
class fraction
{
private:
	int numerator;
	int denominator;
	string name="noname";
public:
	void setName(string s);
	void showData();
	void simplify();
	//default ctor
	fraction();
	//dtor
	~fraction();
	 //custom ctor
	fraction(int a, int b);
	//from string
	fraction(string s);
	//copy ctor
	fraction(const fraction& p);
	//operator=
	const fraction& operator=(const fraction& p);
	//operator+
	const fraction& operator+(const fraction& p)const;
	//operator-
	const fraction& operator-(const fraction& p)const;
	//operator*
	const fraction& operator*(const fraction& p)const;
	//operator/
	const fraction& operator/(const fraction& p)const;
	//operator==
	bool operator==(const fraction& p)const;
	//operator<
	bool operator< (const fraction& p)const;
	//operator<=
	bool operator<= (const fraction& p)const;
	//operator>
	bool operator> (const fraction& p)const;
	//operator>=
	bool operator>= (const fraction& p)const;
	//operator!=
	bool operator!=(const fraction& p)const;
	//operator>>
	friend istream& operator>>(istream& in, fraction& p);
	//operator<<
	friend ostream& operator<<(ostream& out, fraction& p);
	//to double
	operator double()const;
	//to string
	operator std::string()const;
};
int gcd(int a, int b);
istream& operator>>(istream& in, fraction& p);
ostream& operator<<(ostream& out, fraction& p);
#endif // !HEAD