#include <iostream>
using namespace std;

bool isPrime(unsigned long long power)
{
	for (unsigned long long i = 2; i <= (int)(sqrt(power)); i++)
	{
		if (power % i == 0)
		{
			return false;
		}
	}
	return true;
}

void findnum(unsigned long long MAX, unsigned long long power = 2)
{
	cout << "1到" << pow(2, MAX) * (pow(2, MAX + 1) - 1) << "完全数为：" << endl;  //完全数的数论性质

	for (int i = 0; i < MAX; i++)
	{
		unsigned long long power2 = 2 * power - 1;
		unsigned long long x = power * power2;

		if (isPrime(power2))
		{
			cout << x << "是完全数" << endl;
		}

		power *= 2;
	}
}


int main()
{
	unsigned long long MAX = 0;
	cout << "请输入一个数：" << endl;
	cin >> MAX;

	findnum(MAX);

	system("pause");
	return 0;
}