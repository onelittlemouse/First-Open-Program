#include <iostream>
using namespace std;
#include<fstream>
#include<string>

int caldigit(int num)
{
	for (int i = 1; i < 100; i++)
	{
		num = num / 10;
		if (num == 0)
		{
			return i;
		}
	}
}

bool isCorrect(int num,int digit)
{
	int NUM = num;
	int pow1 = 1;
	for (int i = 0; i < digit; i++)
	{
		pow1 *= (num % 10);
	}		
	int add = pow1;
	for (int i = 0; i < digit - 1; i++)
	{
		int pow2 = 1;
		for (int j = 0; j < digit; j++)
		{
			pow2 *= (num / 10 % 10);
		}
		add += pow2;
		num = num / 10;
	}

	if (NUM == add)
	{
		return true;
	}
	return false;
}

int main()
{	
	ofstream ofs;
	ofs.open("ˮ�ɻ���������.txt", ios::out);
	
	int times = 0;
	int max = 0;
	cout << "��������Ҫ���ҵ���λ����" << endl;
	cin >> max;
	cout << "ˮ�ɻ�����" << endl;
	int MAX = 1;
	for (int i = 0; i < max; i++)
	{
		MAX *= 10;
	}

	for (int i = 100; i < MAX; i++)
	{
		int j = caldigit(i);
		if (isCorrect(i, j) == true)
		{
			times++;
			ofs << i << endl;
		}
	}
	ofs << max << "λ���ڵ�ˮ�ɻ�������" << times << "��" << endl;
	ofs.close();

	ifstream ifs;
	ifs.open("ˮ�ɻ���������.txt", ios::in);
	if (!ifs.is_open())
	{
		cout << "�ļ���ʧ��" << endl;
	}
	string buf;
	while (getline(ifs, buf))
	{
		cout << buf << endl;
	}
	ifs.close();

	system("pause");
	return 0;
}
/*
for (int x = 100; x < 1000; x++)
{
	int a = x / 100;
	int b = x / 10 - 10 * a;

	if (abs(a - b) % 2 == 0)
	{
		int c = x % 10;
		if ( 100 * a + 10 * b + c == a * a * a + b * b * b + c * c * c)
		{
			cout << x << "��ˮ�ɻ���" << endl;
		}
	}
}
*/