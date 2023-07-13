#include"head.h"

int gcd(int a, int b)
{
	if (b == 0)
	{
		return a;
	}
	else
	{
		return gcd(b, a % b);
	}
};
void fraction::setName(string s)
{
	name = s;
}
void fraction::showData()
{
	cout << name << ": ";
	if (numerator == 0)
		cout << 0;
	else if (denominator != 1)
		cout << numerator << "/" << denominator;
	else
		cout << numerator;
	cout << endl;
}
void fraction::simplify()
{
	int divisor = gcd(numerator, denominator);
	divisor = divisor < 0 ? -divisor : divisor;
	denominator /= divisor;
	numerator /= divisor;
	if (denominator < 0)
	{
		denominator = -denominator;
		numerator = -numerator;
	}
}

fraction::fraction() :numerator(0), denominator(1)
{
	if (name != "noname")
		cout << name << ": default ctor" << endl;
	else
		cout << "default ctor" << endl;
};
fraction::~fraction()
{
	if (name != "noname")
		cout << name << ": dtor" << endl;
	else
		cout << "dtor" << endl;
}
fraction::fraction(int a, int b) :numerator(a), denominator(b)
{
	assert(denominator != 0);
	if (name != "noname")
		cout << name << ": custom ctor" << endl;
	else
		cout << "custom ctor" << endl;
	simplify();
};
fraction::fraction(string s)
{
	cout << "from string" << endl;
	double d = stod(s);
	double a = 1;
	int i = s.find('.');
	if (i == s.npos)//integer
	{
		numerator = d;
		denominator = 1;
	}
	else
	{
		double length = s.length() - (i + 1);
		denominator = pow(10,length);
		numerator = d*denominator;
		this->simplify();
	}
}
fraction::fraction(const fraction& p)
{
	numerator = p.numerator;
	denominator = p.denominator;
	if (name != "noname")
		cout << name << ": copy ctor" << endl;
	else
		cout << "copy ctor" << endl;
}

const fraction& fraction::operator= (const fraction& p)
{
	if (this != &p)
	{
		numerator = p.numerator;
		denominator = p.denominator;
	}
	cout <<name<< ": operator=" << endl;
	return *this;
}
const fraction& fraction::operator+(const fraction& p)const
{
	fraction temp;
	int den = this->denominator * p.denominator;
	int num = this->numerator * p.denominator + this->denominator * p.numerator;
	temp.denominator = den;
	temp.numerator = num;
	temp.simplify();
	cout <<name<< ": operator+" << endl;
	return temp;
}
const fraction& fraction::operator-(const fraction& p)const
{
	fraction temp;
	int den = this->denominator * p.denominator;
	int num = this->numerator * p.denominator - this->denominator * p.numerator;
	temp.denominator = den;
	temp.numerator = num;
	temp.simplify();
	cout << name << ": operator-" << endl;
	return temp;
}
const fraction& fraction::operator*(const fraction& p)const
{
	fraction temp;
	int den = this->denominator * p.denominator;
	int num = this->numerator * p.numerator;
	temp.denominator = den;
	temp.numerator = num;
	temp.simplify();
	cout << name << ": operator*" << endl;
	return temp;
}
const fraction& fraction::operator/(const fraction& p)const
{
	fraction temp;
	int den = this->denominator * p.numerator;
	int num = this->numerator * p.denominator;
	temp.denominator = den;
	temp.numerator = num;
	temp.simplify();
	cout << name << ": operator/" << endl;
	return temp;
}

bool fraction::operator==(const fraction& p)const
{
	cout << name << ": operator==" << endl;
	return (denominator == p.denominator) && (numerator == p.numerator);
}
bool fraction::operator<(const fraction& p)const
{
	cout << name << ": operator<" << endl;
	return numerator * p.denominator < denominator * p.numerator;
}
bool fraction::operator<=(const fraction& p)const
{
	cout << name << ": operator<=" << endl;
	return numerator * p.denominator <= denominator * p.numerator;
}
bool fraction::operator>(const fraction& p)const
{
	cout << name << ": operator>" << endl;
	return numerator * p.denominator > denominator * p.numerator;
}
bool fraction::operator>=(const fraction& p)const
{
	cout << name << ": operator>=" << endl;
	return numerator * p.denominator >= denominator * p.numerator;
}
bool fraction::operator!=(const fraction& p)const
{
	cout << name << ": operator!=" << endl;
	return (denominator != p.denominator) || (numerator != p.numerator);
}

istream& operator>>(istream& in, fraction& p)
{
	cout << p.name << ": operator>>" << endl;
	cout << p.name << ": " << "denominator: ";
	in >> p.denominator;
	cout << p.name << ": " << "numerator: ";
	in >> p.numerator;
	assert(p.denominator != 0);
	p.simplify();
	if (p.numerator == 0)
		p.denominator = 1;
	return in;
}
ostream& operator<<(ostream& out, fraction& p)
{
	cout << p.name << ": operator<<" << endl<<p.name<<": ";
	if (p.numerator == 0)
		out << 0;
	else if (p.denominator != 1)
		out << p.numerator << "/" << p.denominator;
	else
		out << p.numerator;
	return out;
}

fraction::operator double()const
{
	cout << name << ": to double" << endl;
	return double(this->numerator) / double(this->denominator);
}
fraction::operator std::string()const
{
	cout << name << ": to string" << endl;
	double d = double(this->numerator)/double(this->denominator);
	string s = to_string(d);
	return s;
}