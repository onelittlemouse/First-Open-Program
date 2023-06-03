#include <iostream>
#include <cstdlib>
#include <ctime>
#include <Windows.h>
#include<vector>
#include<algorithm>
using namespace std;

const int N = 200000000;

#pragma region 不需要修改的代码
int* CreateArray(int size)
{
	srand(time(0));
	int* arr = new int[size];
	int* arrEnd = arr + size;

	int k = (int)(log(size) / log(2)) + 2;
	//cout << k << endl;
	k = (1 << k) - 1;

	for (int* p = arr; p < arrEnd; ++p)
		*p = (unsigned int)((rand() << 16) + rand()) & k;

	return arr;
}

void ReleaseArray(int* arr)
{
	delete[] arr;
}

void PrintArray(int* arr, int size)
{
	int* arrEnd = arr + size;
	int maxCount = 20;
	for (int* p = arr, i = 0;
		p < arrEnd && i < maxCount;
		++p, ++i)
	{
		cout << *p << " ";
	}
	cout << " ... ";
	cout << arr[size - 1] << endl;
}

unsigned long long CheckCode1 = 0;
unsigned long long CheckCode2 = 0;
unsigned long long BeginTime = 0;

void SortBegin(int* arr, int size)
{
	CheckCode1 = CheckCode2 = 0;
	int* arrEnd = arr + size;
	for (int* p = arr; p < arrEnd; ++p)
	{
		CheckCode1 += *p;
		CheckCode2 ^= *p;
	}

	BeginTime = ::GetTickCount64();
}

bool SortCheck(int* arr, int size)
{
	unsigned long long EndTime = ::GetTickCount64();

	unsigned long long c1 = *arr, c2 = *arr;

	int* arrEnd = arr + size;
	for (int* p = arr + 1; p < arrEnd; ++p)
	{
		if (p[-1] > *p)
		{
			int i = p - arr;
			cout << "排序校验错误：在位置" << i << "前面的数据大于当前数据" << endl;
			for (int j = i - 10; j <= i + 10; ++j)
			{
				if (j < 0) continue;
				if (j >= size) continue;
				cout << "[" << j << "]: " << arr[j] << endl;
			}
			return false;
		}
		c1 += *p;
		c2 ^= *p;
	}

	if (c1 != CheckCode1 || c2 != CheckCode2)
	{
		cout << "排序校验错误：校验码错误，排序前后数据不一致" << endl;
		return false;
	}

	double seconds = (EndTime - BeginTime) / 1000.0;
	int minute = (int)seconds / 60;
	seconds -= minute * 60;

	cout << "排序成功！排序耗时：" << minute << ":" << (seconds < 10 ? "0" : "") << seconds << endl;
	return true;
}

void inline Swap(int* a, int* b)
{
	int t = *a;
	*a = *b;
	*b = t;
}

void inline Swap(int& a, int& b)
{
	int t = a;
	a = b;
	b = t;
}

#pragma endregion

//----------------------------------------------------
//请修改此处的排序函数，使得算法越快越好

//void Sort(int arr[], int start, int end)
//{
//	int i = start;
//	int j = end;
//	int temp = *(arr + start);
//	while (i < j)
//	{
//		while (i < j && *(arr + j) > temp)
//		{
//			--j;
//		}
//		*(arr + i) = *(arr + j);
//		while (i < j && *(arr + i) <= temp)
//		{
//			++i;
//		}
//		*(arr + j) = *(arr + i);
//	}
//	*(arr + i) = temp;
//	if (start < i - 1)
//	{
//		Sort(arr, start, i - 1);
//	}
//
//	if (end > i + 1)
//	{
//		Sort(arr, i + 1, end);
//	}
//}

//void Sort(int arr[], int length)
//{
//	//vector<int> v;
//	//v.reserve(length);
//	//for (int i = 0; i < length; ++i)
//	//{
//	//	v.push_back(arr[i]);
//	//}
//	//sort(v.begin(), v.end());
//	//for (int i = 0; i < length; ++i)
//	//{
//	//	arr[i] = v[i];
//	//}
//	sort(arr, arr + length);
//}

//void Sort(int* arr, char* temp1, char* temp2, char* temp3, int length, int max_3)
//{
//	//INT_MAX = 2147483647   715827883
//	int i, j;
//	int* tmp = arr;
//	for (i = 0; i < length; ++i)
//	{
//		if ((*tmp) <= max_3 - 1)
//		{
//			++temp1[(*tmp)];
//		}
//		else if ((*tmp) <= 2 * max_3 - 1)
//		{
//			++temp2[(*tmp) - max_3];
//		}
//		else
//		{
//			++temp3[(*tmp) - 2 * max_3];
//		}
//		++tmp;
//	}
//	for (i = 0; i <= max_3 - 1; ++i)
//	{
//		while ((*temp1)--)
//		{
//			(*arr) = i;
//			++arr;
//		}
//		++temp1;
//	}
//	for (i = 0; i <= max_3 - 1; ++i)
//	{
//		while ((*temp2)--)
//		{
//			(*arr) = i + max_3;
//			++arr;
//		}
//		++temp2;
//	}
//	for (i = 0; i <= max_3 - 1; ++i)
//	{
//		while((*temp3)--)
//		{
//			(*arr) = i + 2 * max_3;
//			++arr;
//		}
//		++temp3;
//	}
//}

//void BinaryInsertSort(int* arr, int length)
//{
//	int temp, low, high, mid, i, j;
//	for (int i = 0; i < length; ++i)
//	{
//		temp = arr[i];
//		low = 0;
//		high = i - 1;
//		while (low <= high)
//		{
//			mid = (low + high) / 2;
//			if (temp < arr[mid])
//			{
//				high = mid - 1;
//			}
//			else
//			{
//				low = mid + 1;
//			}
//		}
//		for (j = i - 1; j >= low; --j)
//		{
//			arr[j + 1] = arr[j];
//		}
//		arr[low] = temp;
//	}
//}

//void BubbleSort(int* arr, int length)
//{
//	bool noswap;
//	int i, j, temp;
//	for (i = 0; i < length - 1; ++i)
//	{
//		noswap = true;
//		for (j = length - 1; j > i; --j)
//		{
//			if (arr[j] < arr[j - 1])
//			{
//				temp = arr[j];
//				arr[j] = arr[j - 1];
//				arr[j - 1] = temp;
//				noswap = false;
//			}
//		}
//		if (noswap)
//		{
//			break;
//		}
//	}
//}
//----------------------------------------------------


int main()
{
	//int k = (int)(log(N) / log(2)) + 2;
	//k = (1 << k) - 1;
	//int max = (unsigned int)((RAND_MAX << 16) + RAND_MAX) & k;
	////cout << max << endl;
	//int max_3 = max / 3 + 1;
	
	//cout << INT_MAX << endl;
	int* arr = CreateArray(N);
	//char* temp1 = new char[max_3] {0};   //715827883     0-715827882
	//char* temp2 = new char[max_3] {0};   //715827883     715827883-1431655765
	//char* temp3 = new char[max_3] {0};   //715827883     1431655766-2147483647(+1)

	cout << "排序前：";
	PrintArray(arr, N);
	cout << endl;

	SortBegin(arr, N);
	//Sort(arr, 0, N - 1);
	//Sort(arr, temp1, temp2, temp3, N, max_3);
	std::sort(arr, arr + N);
	//BinaryInsertSort(arr, N);
	//BubbleSort(arr, N);
	SortCheck(arr, N);

	cout << endl;
	cout << "排序后：";
	PrintArray(arr, N);

	ReleaseArray(arr);
	//delete[]temp1;
	//delete[]temp2;
	//delete[]temp3;

	system("pause");

	return 0;
}