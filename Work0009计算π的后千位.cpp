#include<iostream>
using namespace std;
#include<cmath>

//���÷����м���ŷ���任������任���������Ӷ�����
void calculatepi()
{
	double s;
	int b, x, n, c, i, j, d, l;
	cout << "����piֵ��" << endl;
	cout << "�����뾫ȷλ����" << endl;
	cin >> x;

	//������Ҫ��ľ��ȣ�������Ҫѭ���������ù�ʽ��չ��ʽ����һ����������Դ˷����õ���n�����������ɴ˼��㾫�ȣ�
	for (s = 0, n = 1; n <= 500000000; n++)
	{
		s = s + log10((2 * n + 1) / n);
		if (s > x + 1)
		{
			break;
		}
	}
	cout << "n=" << n << endl;
	int* arr = new int[n + 100];

	//��ʼ��Ҫ�󾫶�����������С
	for (i = 0; i <= x + 5; i++)
	{
		arr[i] = 0; 
	}

	//����Ƕ�׵ĳ˷����㣨ŷ���任��
	//a[0]������������,a[i]������iλС��
	for (c = 1, j = n; j >= 1; j--)
	{
		//����1��2j+1�Ĳ����������ָ�λ���λ����
		d = 2 * j + 1;
		for (i = 0; i <= x + 4; i++)
		{
			arr[i] = c / d;
			c = (c % d) * 10 + arr[i + 1];
		}
		arr[x + 5] = c / d;
		//���г�j�Ĳ����������ֵ�λ���λ����
		for (b = 0, i = x + 5; i >= 0; i--)
		{
			arr[i] = arr[i] * j + b;  //*j
			b = arr[i] / 10;        //�����λ��
			arr[i] = arr[i] % 10;     //����һ��0~9������
		}
		//��a[0]�ӵ�1�����������������1���Լ�����(j-1)/(2j-1)��ˣ��������һ�������ڵ�����
		arr[0] = arr[0] + 1;
		c = arr[0];  //�˴���c���һֱΪ1
	}

	//��ʽ����Ϊpi/2��Ҫ�����2
	for (b = 0, i = x + 5; i >= 0; i--)
	{
		arr[i] = arr[i] * 2 + b;  //*2
		b = arr[i] / 10;        //�����λֵ
		arr[i] = arr[i] % 10;     //�õ����µ�ֵ������һ��Ϊ0~9������
	}

	//��ӡ���pi�ľ�ȷֵ
	cout << "pi=" << arr[0] << "." << endl;
	for (l = 0, i = 1; i <= x; i++)
	{
		cout << arr[i];
		l++;
		if (l % 10 == 0)
		{
			cout << "   ";
		}
		if (l % 100 == 0)
		{
			cout << endl;
		}
	}
	delete[] arr;
}


int main()
{	
	calculatepi();

	system("pause");
	return 0;
}