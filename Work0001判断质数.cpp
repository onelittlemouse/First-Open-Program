#include <iostream>
using namespace std;


void findByPointer(int num)
{
	int* arr = new int[num + 1];

	int* p = arr;

	*p = 0;
	*(p + 1) = 0;

	for (int i = 2; i <= num; i++)
	{
		*(p + i) = 1;
	}

	int count = 0;

	for (int j = 1; j < num; j++)
	{
		p++;
		if (*p)
		{	
			count++;
			int* q = p + j;
			for (int k = 0;k < num / j - 1; k++)
			{
				*q = 0;
				q += j;
			}
		}
	}
	cout << num << "以内的质数个数为：" << count << "个" << endl;
}


int main()
{		
	int n = 0;
	cout << "计算1~n质数" << endl;
	cout << "n=" << endl;
	cin >> n;

	findByPointer(n);


	system("pause");
	return 0;
}

/*
方法一：
int a = 0;
cout << "请输入一个大于1的整数：" << endl;
cin >> a;
if (a == 2)
{
	cout << a << "是一个质数" << endl;
}
for (int i = 2; i < a/2+1; i++)
{
	if (a % i == 0)
	{
		cout << a << "不是一个质数" << endl;
		break;
	}
	else if (i == a/2)
	{
		cout << a << "是一个质数" << endl;
	}
}

double M = 0;
cout << "请输入一个数字M：" << endl;
cin >> M;
cout << "在1到" << M << "之间的质数为：" << endl;
double c = 0;
for (int i = 2; i <= M; i++)
{

	if (i == 2 )
	{
		cout << i << endl;
		c++;
	}
	for (int j = 2; j < sqrt(i)+1; j++)
	{
		if (i % j == 0)
		{
			break;
		}

		else if (j >=sqrt(i))
		{
			cout << i << endl;
			c++;
		}
	}
}

double d = (c / M)*100;
cout << "在1到" << M << "之间的质数共"<< c << "个" << endl;
cout << "在1到" << M << "之间质数出现概率：" << d << "%" << endl;
*/

/*
方法二
#define n 10000  //计算1~n质数

void findp()
{
	int times = 0;
	int* arr = new int[n + n];
	for (int i = 0; i < n + n; i++)
	{
		arr[i] = 0;
	}
	for (int i = 2; i <= n; i++)
	{
		if (arr[i] == 0)
		{
			times++;
			cout << i << endl;
			for (int j = 2; j <= n / i; j++)
			{
				arr[i * j] = -1;
			}
		}
	}
	cout << n <<"以内的质数个数为：" << times << endl;
	delete[] arr;
}
*/
