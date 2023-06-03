#include<iostream>
using namespace std;

void search()
{
	int times = 0;  //统计结果个数
	for (int x = 0; x <= 20; x++)  //公鸡个数
	{
		for (int y = 0; y <= 33; y++)  //母鸡个数
		{
			int z = 100 - x - y;  //小鸡个数

			if (z % 3 == 0)
			{
				if (5 * x + 3 * y + z / 3 == 100)
				{
					times++;
					cout << "公鸡个数为：" << x << "，母鸡个数为；" << y << "，小鸡个数为：" << z << endl;
				}
			}
		}
	}
	cout << "问题解的个数为：" << times << endl;
}

int main()
{
	search();
	
	system("pause");
	return 0;
}