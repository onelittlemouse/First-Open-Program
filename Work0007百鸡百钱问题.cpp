#include<iostream>
using namespace std;

void search()
{
	int times = 0;  //ͳ�ƽ������
	for (int x = 0; x <= 20; x++)  //��������
	{
		for (int y = 0; y <= 33; y++)  //ĸ������
		{
			int z = 100 - x - y;  //С������

			if (z % 3 == 0)
			{
				if (5 * x + 3 * y + z / 3 == 100)
				{
					times++;
					cout << "��������Ϊ��" << x << "��ĸ������Ϊ��" << y << "��С������Ϊ��" << z << endl;
				}
			}
		}
	}
	cout << "�����ĸ���Ϊ��" << times << endl;
}

int main()
{
	search();
	
	system("pause");
	return 0;
}