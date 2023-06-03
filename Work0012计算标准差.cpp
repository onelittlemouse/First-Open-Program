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
	cout << "�����׼��Ϊ��" << sqrt(sumSquare / *n) << endl;
}


int main()
{
	double* arr = new double[1000000];
	double n = 0;
	cout << "���������������" << endl;
	cin >> n;

	for (int i = 0; i < n; i++)
	{
		cout << "�����" << i + 1 << "������" << "\t";
		cin >> arr[i];
	}

	calStandardDeviation(arr,&n);
	delete[] arr;

	system("pause");
	return 0;
}