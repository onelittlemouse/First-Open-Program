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
	cout << num << "���ڵ���������Ϊ��" << count << "��" << endl;
}


int main()
{		
	int n = 0;
	cout << "����1~n����" << endl;
	cout << "n=" << endl;
	cin >> n;

	findByPointer(n);


	system("pause");
	return 0;
}

/*
����һ��
int a = 0;
cout << "������һ������1��������" << endl;
cin >> a;
if (a == 2)
{
	cout << a << "��һ������" << endl;
}
for (int i = 2; i < a/2+1; i++)
{
	if (a % i == 0)
	{
		cout << a << "����һ������" << endl;
		break;
	}
	else if (i == a/2)
	{
		cout << a << "��һ������" << endl;
	}
}

double M = 0;
cout << "������һ������M��" << endl;
cin >> M;
cout << "��1��" << M << "֮�������Ϊ��" << endl;
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
cout << "��1��" << M << "֮���������"<< c << "��" << endl;
cout << "��1��" << M << "֮���������ָ��ʣ�" << d << "%" << endl;
*/

/*
������
#define n 10000  //����1~n����

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
	cout << n <<"���ڵ���������Ϊ��" << times << endl;
	delete[] arr;
}
*/
