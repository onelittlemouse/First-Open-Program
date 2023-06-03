#include<iostream>
using namespace std;
#include<cmath>
#define BITNUM 10000000

class Simpson
{
public:
	virtual double fun(double x) = 0;

	Simpson(double ra = 0, double rb = 0)
	{
		this->a = ra;
		this->b = rb;
		this->Intevalue = 0;
	}

	void Integrate()
	{
		double dx = (b - a) / BITNUM;
		this->Intevalue = fun(this->a) + fun(this->b);
		for (int i = 0; i < BITNUM; i += 2)
		{
			this->Intevalue += 4 * fun(a + dx * i);
		}
		for (int i = 0; i < BITNUM; i += 2)
		{
			this->Intevalue += 2 * fun(a + dx * i);
		}
		this->Intevalue *= dx / 3;
	}

	void Print()
	{
		cout << "Result:" << this->Intevalue << endl;
	}

private:
	double Intevalue, a, b;
};

class A :public Simpson
{
public:
	A(double ra, double rb) :Simpson(ra, rb) {};

	double fun(double x)
	{
		return sin(x);
	}
};

class B :public Simpson
{
public:
	B(double ra, double rb) :Simpson(ra, rb) {};

	double fun(double x)
	{
		return exp(x);
	}
};

class C :public Simpson
{
public:
	C(double ra, double rb) :Simpson(ra, rb) {};

	double fun(double x)
	{
		return 1.0 / log(x);
	}
};



int main()
{
	A a1(0.0, 2.0 * atan(1));
	Simpson* s1 = &a1;
	s1->Integrate();
	B b1(0.0, 1.0);
	b1.Integrate();
	C c1(2.0, 3.0);
	Simpson* s2 = &c1;
	s2->Integrate();
	s1->Print();
	b1.Print();
	s2->Print();


	system("pause");

	return 0;
}