#include<iostream>
using namespace std;

double calaverage(double* arr, double* n)
{
	double sum = 0;
	for (int i = 0; i < *n; i++)
	{
		sum += arr[i];
	}
	return sum / *n;
}

void calStandardDeviation(double* arr, double* n)
{
	double average = calaverage(arr, n);
	double sumSquare = 0;
	for (int i = 0; i < *n; i++)
	{
		sumSquare += (arr[i] - average) * (arr[i] - average);
	}
	cout << "数组标准差为：" << sqrt(sumSquare / *n) << endl;
}


int main()
{
	double* arr = new double[1000000];
	double n = 0;
	cout << "请输入数组个数：" << endl;
	cin >> n;

	for (int i = 0; i < n; i++)
	{
		cout << "输入第" << i + 1 << "个数：" << "\t";
		cin >> arr[i];
	}

	calStandardDeviation(arr,&n);
	delete[] arr;

	system("pause");
	return 0;
}