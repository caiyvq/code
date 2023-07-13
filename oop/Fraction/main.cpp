#include"head.h"
int main(int argc, char* argv[])
{
	//ctor, dtor, operator=,>>,<<********************************
	cout << "\033[36m" << "Test for ctor, dtor, ==, <<, >> :" << "\033[m" << endl;
	system("pause");
	cout << "a0: ";
	fraction a0;//default ctor
	a0.setName("a0");
	cout << a0 << endl;//ostream

	cout << "a1: ";
	fraction a1(5, 9);//custom ctor, auto
	a1.setName("a1");
	cout << a1 << endl;//ostream
	
	cout << "a2: ";
	fraction a2 = fraction(12, 7);//custom ctor, manual
	a2.setName("a2");
	cout << a2 << endl;//ostream

	cout << "a3: ";
	fraction* a3=new fraction;//default ctor
	a3->setName("a3");
	cin >> *a3;//istream
	cout << *a3 << endl;//ostream
	delete a3;//dtor

	cout << "a4: ";
	fraction* a4 = new fraction(1, 2);//custom ctor
	a4->setName("a4");
	cout << *a4 << endl;//ostream
	delete a4;//dtor

	cout << "a5: ";
	fraction a5 = a1;//copy ctor
	a5.setName("a5");
	cout << a5 << endl;

	cout << "a6: ";
	fraction a6;//default ctor
	a6.setName("a6");
	a6 = a1;//operator=
	cout << a6 << endl;
	//*******************************************
	system("pause");
	system("cls");
	//arithmetical operator*********************
	cout <<"\033[36m" << "Test for +, -, *, / :" << "\033[m" << endl;
	system("pause");
	{
		cout << "b0: ";
		fraction b0 = a1 + a2;//operator+
		b0.setName("b0");
		cout << "b0=a1+a2: " << endl;
		cout << b0 << endl;

		b0 = a1.operator-(a2);//operator-
		cout << "b0=a1-a2: " << endl;
		cout << b0 << endl;

		b0 = a1 * a2;//operator*
		cout << "b0=a1*a2: " << endl;
		cout << b0 << endl;

		b0 = a1.operator/(a2);//operator/
		cout << "b0=a1/a2: " << endl;
		cout << b0 << endl;
	}
	//*******************************************
	system("pause");
	system("cls");
	//relational operator*************************
	cout <<"\033[36m" << "Test for ==, !=, <, <=, >, >= :" << "\033[m" << endl;
	system("pause");
	{
		bool c0 = (a1 == a2);//operator==
		cout << "a1==a2: " << c0 << endl;
		c0 = (a1 == a1);
		cout << "a1==a1: " << c0 << endl;
		c0 = (a1 != a2);//operator!=
		cout << "a1!=a2: " << c0 << endl;
		c0 = (a1 != a1);
		cout << "a1!=a1: " << c0 << endl;

		bool c1 = (a1 < a2);//operator<
		cout << "a1<a2: " << c1 << endl;
		c1 = (a2 < a1);
		cout << "a2<a1: " << c1 << endl;
		c1 = (a1 < a1);
		cout << "a1<a1: " << c1 << endl;

		bool c2 = (a1 > a2);//operator>
		cout << "a1>a2: " << c2 << endl;
		c2 = (a2 > a1);
		cout << "a2>a1: " << c2 << endl;
		c2 = (a1 > a1);
		cout << "a1>a1: " << c2 << endl;

		bool c3 = (a1 <= a2);//operator<=
		cout << "a1<=a2: " << c3 << endl;
		c3 = (a2 <= a1);
		cout << "a2<=a1: " << c3 << endl;
		c3 = (a1 <= a1);
		cout << "a1<=a1: " << c3 << endl;

		bool c4 = (a1 >= a2);//operator>=
		cout << "a1>=a2: " << c4 << endl;
		c4 = (a2 >= a1);
		cout << "a2>=a1: " << c4 << endl;
		c4 = (a1 >= a1);
		cout << "a1>=a1: " << c4 << endl;
	}
	//***************************************
	system("pause");
	system("cls");
	//conversion*******************************
	{
		cout << "\033[36m" << "Test for type conversion :" << "\033[m" << endl;
		system("pause");
		double d0 = a1;//to double
		cout << "d0: " << d0 << endl << "d0: " << typeid(d0).name() << endl;
		string d1 = a1;//to string
		cout << "d1: " << d1 << endl << "d1: " << typeid(d1).name() << endl;
		cout << "d2: ";
		string d3 = "0.375";
		fraction d2 = d3;//from string
		d2.setName("d2");
		cout << d2 << endl;
	}
	//******************************************
	system("pause");
	system("cls");
	cout <<  "\33[36m" << "exit the program, call dtor" << "\33[m" << endl;
	system("pause");
	return 0;
}