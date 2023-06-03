#include<iostream>
using namespace std;

//方法一  递归算法
int check(int arr[], int n, int k, int N)
{
	if (n == 1)
	{
		arr[k % N] = 1;
		k % N == 0 ? cout << "第1个出列的是第" << N << "个人" << endl : cout << "第1个出列的是第" << k % N << "个人" << endl;
		return k % N;
	}

	int ret = check(arr, n - 1, k, N);
	int judge = 0;
	for (int i = 1;; i++)
	{ 
		if (arr[(ret + i) % N] == 0)
		{
			judge++;
			if (judge == k)
			{
				arr[(ret + i) % N] = 1;
				if ((ret + i) % N != 0)
				{
					n == N ? cout << "最后剩下的是第" << (ret + i) % N << "个人" << endl : cout << "第" << n << "个出列的是第" << (ret + i) % N << "个人" << endl;
				}
				else
				{
					n == N ? cout << "最后剩下的是第" << N << "个人" << endl : cout << "第" << n << "个出列的是第" << N << "个人" << endl;
				}

				return (ret + i) % N;
			}
		}
	}
}

//方式二  公式法
void calret(int arr[], int n, int k)
{
	for (int i = 1; i <= n; i++)
	{
		arr[i] = (arr[i - 1] + k) % i;
	}
	cout << "最后剩下的是第" << arr[n] + 1 << "个人" << endl;
}


int main()
{
	cout << "请输入总人数：" << endl;
	int n;
	cin >> n;

	int k = 0;
	cout << "让数到k的人出列，输入k：" << endl;
	cin >> k;

	int* arr1 = new int[n];
	for (int i = 0; i < n; i++)
	{
		arr1[i] = 0;
	}
	int track = n;
	check(arr1, n, k, n);
	delete[] arr1;

	int* arr2 = new int[n + 1];
	for (int i = 0; i < n + 1; i++)
	{
		arr2[i] = 0;
	}
	calret(arr2, n, k);
	delete[] arr2;

	system("pause");

	return 0;
}