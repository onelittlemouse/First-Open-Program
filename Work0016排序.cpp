#include<iostream>
using namespace std;
#include<map>
#include<algorithm>
#include<ctime>
//#include<fstream>
#include<deque>
#define _CRT_SECURE_NO_WARNINGS

//ofstream ofs;
void test01(int* arr, int n)
{
	cout << "test01:mutimap进行排序" << endl;
	multimap<int, int>m;
	for (int i = 0; i < n; ++i)
	{
		m.insert(make_pair(arr[i], i));
	}
	for (multimap<int, int>::const_iterator it = m.begin(); it != m.end(); it++)
	{
		//ofs << (*it).first << "                 " << it->second << endl;
		cout << (*it).first << "\t\t" << it->second << endl;
	}
	if (arr != NULL)
	{
		delete[]arr;
		arr = NULL;
	}
}


class lessGreat
{
public:
	bool operator()(int num1, int num2)
	{
		return num1 > num2;
	}
};
void test02(int* arr, int n)
{
	cout << "test02:deque容器用sort算法,仿函数降序" << endl;
	deque<int>d;
	srand((unsigned int)time(NULL));
	for (int i = 0; i < n; i++)
	{
		d.push_back(arr[i]);
	}
	sort(d.begin(), d.end(), lessGreat());

	for (deque<int>::iterator it = d.begin(); it != d.end(); it++)
	{
		cout << *it << endl;
	}
	if (arr != NULL)
	{
		delete[]arr;
		arr = NULL;
	}
}


template<class T1>
void bubbleSort(T1* arr, int len)
{
	for (int i = 0; i < len - 1; i++)
	{
		for (int j = 0; j < len - i - 1; j++)
		{
			if (arr[j] > arr[j + 1])
			{
				T1 temp = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = temp;
			}
		}
	}
}
void test03(int* arr, int n)
{
	cout << "test03BubbleSort:" << endl;
	bubbleSort<>(arr, n);
	for (int i = 0; i < n; ++i)
	{
		cout << arr[i] << endl;
	}
	if (arr != NULL)
	{
		delete[]arr;
		arr = NULL;
	}
}


void QuickSort(int arr[], int start, int end)
{
	int i = start;
	int j = end;

	int temp = arr[start];
	while (i < j)
	{
		while (i < j && arr[j] >= temp)
		{
			--j;
		}

		if (i < j)
		{
			arr[i] = arr[j];
			++i;
		}

		while (i < j && arr[i] < temp)
		{
			++i;
		}

		if (i < j)
		{
			arr[j] = arr[i];
			--j;
		}

		arr[i] = temp;

		QuickSort(arr, start, i - 1);

		QuickSort(arr, i + 1, end);
	}
}
void test04(int arr[], int n)
{
	cout << "test04Quicksort:" << endl;
	QuickSort(arr, 0, n - 1);
	for (int i = 0; i < n; ++i)
	{
		cout << arr[i] << endl;
	}
	if (arr != NULL)
	{
		delete[]arr;
		arr = NULL;
	}
}
//#include <iostream>
//using namespace std;
//#include<ctime>
//
//void PrintArray(int arr[], int len)
//{
//	for (int i = 0; i < len; ++i)
//	{
//		cout << arr[i] << endl;
//	}
//}
//void QuickSort(int arr[], int start, int end)
//{
//	int i = start;
//	int j = end;
//	int temp = arr[start];
//
//	while (i < j)
//	{
//		while (i < j && arr[j] > temp)
//		{
//			--j;
//		}
//
//		arr[i] = arr[j];
//
//		while (i < j && arr[i] <= temp)
//		{
//			++i;
//		}
//
//		arr[j] = arr[i];
//
//	}
//
//	arr[i] = temp;
//
//	if (start < i - 1)
//	{
//		QuickSort(arr, start, i - 1);
//	}
//
//	if (end > i + 1)
//	{
//		QuickSort(arr, i + 1, end);
//	}
//}
//
//
//int main()
//{
//	const int n = 1000000000;
//	srand((unsigned int)time(NULL));
//	int* arr = new int[n];
//
//	for (int i = 0; i < n; ++i)
//	{
//		arr[i] = 2 * (rand() + 32768 * rand()) + (rand() % 2);
//	}
//
//	cout << "Quicksort running" << endl;
//	QuickSort(arr, 0, n - 1);
//	cout << "Quicksort completed" << endl;
//
//	//PrintArray(arr, n);
//
//	if (arr != NULL)
//	{
//		delete[]arr;
//		arr = NULL;
//	}
//
//
//	system("pause");
//
//	return 0;
//}


void SORT(int len)
{
	const int n = len;
	//char numSeed[10] = { '0','1','2','3','4','5','6','7','8','9' };
	//string* arr = new string[n];
	//for (int i = 0; i < n; ++i)
	//{
	//	for (int j = 0; j < 4; ++j)  //可在此修改整数位数
	//	{
	//		arr[i] += numSeed[rand() % 10];
	//	}
	//}

	while (1)
	{
		int* arr = new int[n];
		cout << "进行排序前的数组：" << endl;
		cout << "-----------------" << endl;
		for (int i = 0; i < n; ++i)
		{
			arr[i] = (rand()) + 32768 * (rand());
			cout << arr[i] << endl;
		}
		cout << "-----------------" << endl;
		cout << "|请输入排序方式:|" << endl;
		cout << "|-------1-------|" << endl;
		cout << "|-------2-------|" << endl;
		cout << "|-------3-------|" << endl;
		cout << "|-------4-------|" << endl;
		cout << "|----0：退出----|" << endl;
		cout << "-----------------" << endl;

		int select = 0;
		cin >> select;

		switch (select)
		{
		case 1:
		{
			//ofs.open("排序.txt", ios::out);
			test01(arr, n);
			//ofs.close();
			system("pause");
			system("cls");
			break;
		}

		case 2:
		{
			test02(arr, n);
			system("pause");
			system("cls");
			break;
		}

		case 3:
		{
			test03(arr, n);
			system("pause");
			system("cls");
			break;
		}

		case 4:
		{
			//int* arr4 = new int[n];
			//for (int i = 0; i < n; i++)
			//{
			//	arr4[i] = rand();
			//}
			test04(arr, n);
			system("pause");
			system("cls");
			break;
		}

		case 0:
		{
			cout << "系统已退出" << endl;
			if (arr != NULL)
			{
				delete[]arr;
				arr = NULL;
			}
			system("pause");
			exit(0);
		}

		default:
		{
			cout << "输入有误，请重新输入" << endl;
			if (arr != NULL)
			{
				delete[]arr;
				arr = NULL;
			}
			system("pause");
			system("cls");
			break;
		}
		}
	}
}


int main()
{
	srand((unsigned int)time(NULL));
	cout << "请输入要进行排序的个数：" << endl;
	int len = 0;
	cin >> len;
	cout << endl;
	SORT(len);

	system("pause");

	return 0;
}