#include"head.h"


int main(int argc, char* argv[])
{
	Vector<int> v0;
	cout << v0.size() << endl;
	cout << boolalpha << v0.empty() << endl;
	v0.push_back(1);
	v0.push_back(2);
	v0.push_back(3);
	v0.push_back(4);
	cout << v0.size() << endl;
	cout << v0.at(0) << endl;
	cout << v0.at(1) << endl;
	cout << v0[2] << endl;
	cout << v0[3] << endl;
	//cout << v0.at(4) << endl;
	cout << v0[4] << endl;
	cout << boolalpha <<v0.empty() << endl;

	Vector<double>v1(10);
	cout << v1.size() << endl;
	cout << v1.at(3) << endl;
	v1.clear();
	cout << v1.size() << endl;

	Vector<int>v2 = v0;
	cout << v2.size() << endl;
	cout << boolalpha << v2.empty() << endl;
	cout << v2.size() << endl;
	cout << v2.at(0) << endl;
	cout << v2.at(1) << endl;
	cout << v2[2] << endl;
	cout << v2[3] << endl;
	return 0;
}