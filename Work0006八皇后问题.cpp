#include<iostream>
using namespace std;

#include<string>

int queenArr[10000];
int n;
int num = 0;

//判断m行之前皇后位置是否正确
bool check(int queenArr[], int m)
{
	for (int i = 0; i < m; ++i)
	{
		if (queenArr[i] == queenArr[m] || abs(m - i) == abs(queenArr[m] - queenArr[i]))
		{
			return false;
		}
	}
	return true;
}

//递推到下一行，若已结束则输出结果
void backtrack(int k)
{	
	//输出成立的图表
	if (k > n - 1)
	{
		cout << "Graph" << num + 1 << ":" << endl;
		
		for (int i = 0; i < n; i++)
		{			
			for (int j = 0; j < queenArr[i]; ++j)
			{
				cout << "□";
			}

			cout << "★";

			for (int l = queenArr[i] + 1; l < n; ++l)
			{
				cout << "□";
			}

			cout << endl;
		}

		cout << endl;
		++num;
	}

	//进行递推
	else
	{
		for (int i = 0; i < n; ++i)
		{
			queenArr[k] = i;

			if (check(queenArr, k) == true)
			{
				backtrack(k + 1);
			}
		}
	}

}

int main()
{		
	while (1)
	{
		cout << "请输入一个正整数：" << endl;
		cin >> n;

		num = 0;

		backtrack(0);

		cout << n << "皇后问题解的个数为：" << num << endl;
		
		//确认是否退出系统
		string select;
		cout << "1 --- continue" << endl;
		cout << "else --- pause" << endl;
		cin >> select;
		if (select != "1")
		{
			break;
		}
	}

	/*
	int queenArr[8];
	int num = 0;

	for (queenArr[0] = 0; queenArr[0] < 8; queenArr[0]++)
	{
		for (queenArr[1] = 0; queenArr[1] < 8; queenArr[1]++)
		{
			for (queenArr[2] = 0; queenArr[2] < 8; queenArr[2]++)
			{
				for (queenArr[3] = 0; queenArr[3] < 8; queenArr[3]++)
				{
					for (queenArr[4] = 0; queenArr[4] < 8; queenArr[4]++)
					{
						for (queenArr[5] = 0; queenArr[5] < 8; queenArr[5]++)
						{
							for (queenArr[6] = 0; queenArr[6] < 8; queenArr[6]++)
							{
								for (queenArr[7] = 0; queenArr[7] < 8; queenArr[7]++)
								{
									int check = 0;
									
									for (int i = 0; i < 8; i++)
									{
										for (int j = 0; j < i; j++)
										{
											if (queenArr[i] != queenArr[j] && abs(i - j) != abs(queenArr[i] - queenArr[j]))
											{
												check++;
											}
										}
									}

									if (check == 28)
									{
										num++;
										for (int k = 0; k < 8; k++)
										{
											cout << queenArr[k] << "  ";
										}
										cout << endl;
									}
								}

							}

						}

					}

				}

			}

		}

	}
	
	cout << num << endl;
	*/

	system("pause");
	return 0;
}