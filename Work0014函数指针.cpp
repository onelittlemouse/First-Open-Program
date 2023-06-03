#include <iostream>
using namespace std;
#include<cmath>
#define pi 3.1415926535

double s_t(double t)
{
	return t * t + 2 * t - 1;
}

double g_t(double t)
{
	return sin(t) + exp(-t * t);  //e的指数
}

double s_t_1(double t)
{
	return (s_t(t + 0.000000001) - s_t(t)) / 0.000000001;
}

double g_t_1(double t)
{
	return (g_t(t + 0.000000001) - g_t(t)) / 0.000000001;
}

double getRoot(double f(double), double f_(double), double startval)
{
	while (1)
	{
		if (f(startval) == 0)
		{
			startval += 0.001;
		}
		startval = startval - f(startval) / f_(startval);
		if (f(startval) / f_(startval) < 0.00000001)
		{
			return startval;
			break;
		}
	}
}

double calintegral(double f(double), double left, double right, double step)
{
	double result = 0;
	for (double i = left; i <= right; i += step)
	{
		result += (f(i) + f(i + step)) * step / 2;
	}
	return result;
}

double getMax(double arr[], int len)
{
	for (int i = 0; i < len - 1; i++)
	{
		if (arr[i] > arr[i + 1])
		{
			double temp = arr[i];
			arr[i] = arr[i + 1];
			arr[i + 1] = temp;
		}
	}
	return arr[len - 1];
}

double getMin(double arr[], int len)
{
	for (int i = 0; i < len - 1; i++)
	{
		if (arr[i] < arr[i + 1])
		{
			double temp = arr[i];
			arr[i] = arr[i + 1];
			arr[i + 1] = temp;
		}
	}
	return arr[len - 1];
}

double getSum(double arr[], int len)
{
	double sum = 0;
	for (int i = 0; i < len; i++)
	{
		sum += arr[i];
	}
	return sum;
}

double getAverage(double arr[], int len)
{
	return getSum(arr, len) / len;
}

double getStdDev(double arr[], int len)
{
	double average = getAverage(arr, len);
	double sumSquare = 0;
	for (int i = 0; i < len; i++)
	{
		sumSquare += (arr[i] - average) * (arr[i] - average);
	}
	return sqrt(sumSquare / len);
}

double Stat(double arr[], int len, double sFunc(double[], int))
{
	return sFunc(arr, len);
}


int main()
{
	cout << "s(1)=" << s_t(1) << endl;
	cout << "g(1)=" << g_t(1) << endl;
	cout << "s'(1)=" << s_t_1(1) << endl;
	cout << "g'(1)=" << g_t_1(1) << endl;

	cout << "请输入试根次数：" << endl;
	int num = 1;
	cin >> num;
	for (int i = 0; i < num; i++)
	{
		cout << "请输入一个数值：" << endl;
		double t = 0;
		cin >> t;
		cout << t << "附近的一个根为：" << getRoot(g_t, g_t_1, t) << endl;

	}

	cout << calintegral(g_t, 0, pi, 0.00001) << endl;

	double arr[] = { 0.9,1.2,1.1,0.8,0.7 };
	int len = sizeof(arr) / sizeof(arr[0]);
	cout << Stat(arr, len, getMax) << endl;
	cout << Stat(arr, len, getMin) << endl;
	cout << Stat(arr, len, getSum) << endl;
	cout << Stat(arr, len, getAverage) << endl;
	cout << Stat(arr, len, getStdDev) << endl;


	system("pause");

	return 0;
}