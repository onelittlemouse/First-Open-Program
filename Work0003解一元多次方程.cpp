#include <iostream>
using namespace std;

double func(double x, int n)
{
	double temp = 1.0;
	for (int i = 0; i < n; i++)
	{
		temp *= x;
	}
	return temp;
}

double func_1(double x, int n)
{
	double temp = 1.0;
	for (int i = 1; i < n; i++)
	{
		temp *= x;
	}
	return temp * n;
}

double func(double x, int m, double arr[])
{
	double y = 0;
	for (int i = 0; i <= m; i++)
	{
		y += arr[i] * func(x, i);
	}
	return y;
}

double func_1(double x, int m, double arr[])
{
	double y = 0;
	for (int i = 1; i <= m; i++)
	{
		y += arr[i] * func_1(x, i);
	}
	return y;
}

void test01()
{
	cout << "��ⷽ�̴�����" << endl;
	int m = 0;
	cin >> m;
	double* arr = new double[m + 1];

	cout << "�ⷽ�̣�";
	for (int i = 0; i <= m - 1; i++)
	{
		cout << "arr[" << m - i << "] * x^" << m - i << " + ";
	}
	cout << " arr[0] = 0" << endl;

	for (int i = 0; i <= m; i++)
	{
		cout << "����arr[" << i << "]��ֵ��" << endl;
		cin >> arr[i];
	}
	cout << "����һ������" << endl;
	double x = 0;
	cin >> x;

	while (func(x, m, arr) / func_1(x, m, arr) >= 0.0000001)
	{
		x -= func(x, m, arr) / func_1(x, m, arr);
	}

	cout << "x=" << x << endl;

	if (arr != NULL)
	{
		delete[]arr;
		arr = NULL;
	}
}

int main()
{	
	test01();

	system("pause");

	return 0;

}

//#include <iostream>
//using namespace std;
//
//int main()
//{	
//	//��ⷽ��
//	// x * x * x * x * x + 4 * x * x * x * x - 2 * x * x + 7 * x - 6 = 0;
//	
//	cout << "��ⷽ�̣�a5 * x^5 + a4 * x^4 + a3 * x^3 + a2 * x^2 + a1 * x + a0 = 0" << endl;
//
//	double a0;
//	double a1;
//	double a2;
//	double a3;
//	double a4;
//	double a5;
//	cout << "������a5��ֵ��" << endl;
//	cin >> a5;
//	cout << "������a4��ֵ��" << endl;
//	cin >> a4;
//	cout << "������a3��ֵ��" << endl;
//	cin >> a3;
//	cout << "������a2��ֵ��" << endl;
//	cin >> a2;
//	cout << "������a1��ֵ��" << endl;
//	cin >> a1;
//	cout << "������a0��ֵ��" << endl;
//	cin >> a0;
//
//	cout << "�����ķ���Ϊ��" << a5 << " * x^5 + " << a4 << " * x^4 + " << a3 << " * x^3 + " << a2 << " * x^2 + " << a1 << " * x + " << a0 << " = 0" << endl;
//
//	double x;
//	double y;
//	double z;
//	double min;
//	double max;
//	double step;
//
//	cout << "������һ��������½磺" << endl;
//	cin >> min;
//	cout << "������һ��������Ͻ磺" << endl;
//	cin >> max;
//	cout << "����Ϊ��" << endl;
//	cin >> step;
//
//	for (double i = min; i <= max; i += step)
//	{
//		cout << "x=" << i << "ʱ:\t����ֵΪ��" << a5 * i * i * i * i * i + a4 * i * i * i * i + a3 * i * i * i + a2 * i * i + a1 * i + a0 << endl;
//	}
//
//	double x0;
//
//	double times = 1;
//	cout << "��ѡ��Ҫ���м��γ��ԣ�" << endl;
//	cin >> times;
//
//	for (int t = 1; t <= times; t++)
//	{
//		cout << "������һ����ֵ��" << endl;
//		cin >> x0;
//		x = x0;
//
//		z = 5 * a5 * x * x * x * x + 4 * a4 * x * x * x + 3 * a3 * x * x + 2 * a2 * x + a1;
//		if (z == 0)
//		{
//			x = x + 0.01;
//		}
//
//		while (1)
//		{
//			y = a5 * x * x * x * x * x + a4 * x * x * x * x + a3 * x * x * x + a2 * x * x + a1 * x + a0;
//			z = 5 * a5 * x * x * x * x + 4 * a4 * x * x * x + 3 * a3 * x * x + 2 * a2 * x + a1;
//
//			x = x - y / z;
//
//			if (abs(y) < abs(x) * 0.000000001)
//			{
//				cout << "��" << x0 << "�����ķ��̵�һ����Ϊ��" << x << endl;
//				break;
//			}
//		}
//	}
//
//	/*
//	for (double i = -4; i <= 1; i += 0.1)
//	{
//		cout << i << "\t:" << i * i * i * i * i + 4 * i * i * i * i - 2 * i * i + 7 * i - 6 << endl;
//	}
//	*/
//
//	//�ݷ������������һ��������ʵ���⣬һ����-3.7~-3.6�䣬һ����-1.9~-1.8�䣬һ����0.7~0.8�䣬�������������
//
//	system("pause");
//
//	return 0;
//
//}