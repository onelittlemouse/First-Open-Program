#include<iostream>
using namespace std;
#include<cmath>
#define pi 4.0 * atan(1.0)

double sin_x(double x, double err)
{
	if (x <= err)
	{
		return x;
	}
	int sign = x > 0 ? 1 : -1;
	x = abs(x);
	while (x > pi / 2)
	{
		x -= pi;
		sign = -sign;
	}
	int i = 1;
	double d = x;
	double sum = x;
	while (abs(d) > err)
	{
		d *= (((-x * x) / (2.0 * i)) / (2.0 * i + 1.0));
		sum += d;
		++i;
	}

	return sum * sign;
}

void test_cosin()
{
	//对一个实数
	double x0;
	cout << "请输入一个实数x:" << endl;
	cin >> x0;

	double x = x0 * pi;
	double sign1 = -1;
	double sum = 1;

	for (int i = 2; i < 100; i += 2)
	{
		double factorial1 = 1;
		double power1 = 1;
		for (int j = 1; j <= i; j++)
		{
			factorial1 *= j;
			power1 *= x;
		}
		sum += (power1 * sign1) / factorial1;
		if (abs((power1 * sign1) / factorial1) < abs(x) * 0.0000001)
		{
			cout << "cos(" << x0 << "*pi)=" << sum << endl;
			break;
		}
		sign1 = -sign1;
	}


	//对一个虚数
	cout << "请输入一个虚数a+b*i:" << endl;
	double a = 0;
	double b = 0;
	cout << "输入a的值：" << endl;
	cin >> a;
	cout << "输入b的值：" << endl;
	cin >> b;

	//复数表达方式的变换
	double r = sqrt(a * a + b * b) * pi;
	double degree = atan2(b, a);
	double sign2 = -1;
	double sum1 = 1;
	double sum2 = 0;
	for (int i = 2; i < 100; i += 2)
	{
		double factorial2 = 1;
		double power2 = 1;
		for (int j = 1; j <= i; j++)
		{
			factorial2 *= j;
			power2 *= r;
		}
		double degrees = i * degree;
		sum1 += (power2 * sign2 * cos(degrees)) / factorial2;
		sum2 += (power2 * sign2 * sin(degrees)) / factorial2;
		if (abs((power2 * sign2) / factorial2) < abs(x) * 0.0000001)
		{
			cout << "cos((" << a << "+" << b << "*i)" << "*pi)=" << sum1 << "+" << sum2 << "*i" << endl;
			break;
		}
		sign2 = -sign2;
	}
}


int main()
{
	srand((unsigned int)time(NULL));
	cout.precision(16);
	double x = 30000;
	cout << x << "      " << std::sin(x) << "   " << sin_x(x, 0.0) << endl;
	

	system("pause");

	return 0;

}

/*
	double x = 0;
	cout << "请输入x的值" << endl;
	cin >> x;
	double a = 0;
	double factoriali = 1;
	double y = 1;
	int sign = 1;
	for (int i = 1; i < 30; i += 2)
	{
		factoriali = 1;
		y = 1;
		for (int j = 1; j <= i; j++)
		{
			factoriali *= j;
			y *= x;
		}
		a += sign * y / factoriali;
		sign = -sign;
	}
	cout << "sin(x)=" << a << endl;
*/