#include<iostream>
using namespace std;

//����һ  �ݹ��㷨
int check(int arr[], int n, int k, int N)
{
	if (n == 1)
	{
		arr[k % N] = 1;
		k % N == 0 ? cout << "��1�����е��ǵ�" << N << "����" << endl : cout << "��1�����е��ǵ�" << k % N << "����" << endl;
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
					n == N ? cout << "���ʣ�µ��ǵ�" << (ret + i) % N << "����" << endl : cout << "��" << n << "�����е��ǵ�" << (ret + i) % N << "����" << endl;
				}
				else
				{
					n == N ? cout << "���ʣ�µ��ǵ�" << N << "����" << endl : cout << "��" << n << "�����е��ǵ�" << N << "����" << endl;
				}

				return (ret + i) % N;
			}
		}
	}
}

//��ʽ��  ��ʽ��
void calret(int arr[], int n, int k)
{
	for (int i = 1; i <= n; i++)
	{
		arr[i] = (arr[i - 1] + k) % i;
	}
	cout << "���ʣ�µ��ǵ�" << arr[n] + 1 << "����" << endl;
}


int main()
{
	cout << "��������������" << endl;
	int n;
	cin >> n;

	int k = 0;
	cout << "������k���˳��У�����k��" << endl;
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