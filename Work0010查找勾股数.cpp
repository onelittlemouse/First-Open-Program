#include<iostream>
using namespace std;
#include<cmath>
#include<string>
#include<fstream>

ofstream ofs;

void findnum(int num)
{
	for (int i = 1; i < num; i++)
	{
		for (int j = 1; j < num; j++)
		{
			if (i * i + j * j == num * num && i > j)
			{
				ofs << "c=" << num << "\t" << "a=" << j << "\t" << "b=" << i << "\t" << endl;
			}
		}
	}
}


int main()
{
	ofs.open("查找勾股数结果.txt", ios::out);
	
	for (int n = 1; n <= 5000; n++)
	{
		findnum(n);
	}

	ofs.close();

	ifstream ifs;
	ifs.open("查找勾股数结果.txt", ios::in);
	if (!ifs.is_open())
	{
		cout << "文件打开失败" << endl;
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