#include<iostream>
using namespace std;
#include<cmath>

//利用反正切级数欧拉变换，这个变换随项数增加而递增
void calculatepi()
{
	double s;
	int b, x, n, c, i, j, d, l;
	cout << "计算pi值：" << endl;
	cout << "请输入精确位数：" << endl;
	cin >> x;

	//根据所要求的精度，计算需要循环次数（用公式的展开式，即一个无穷级数，对此分析得到第n项大于其余项，由此计算精度）
	for (s = 0, n = 1; n <= 500000000; n++)
	{
		s = s + log10((2 * n + 1) / n);
		if (s > x + 1)
		{
			break;
		}
	}
	cout << "n=" << n << endl;
	int* arr = new int[n + 100];

	//初始化要求精度所需的数组大小
	for (i = 0; i <= x + 5; i++)
	{
		arr[i] = 0; 
	}

	//进行嵌套的乘法运算（欧拉变换）
	//a[0]保存整数部分,a[i]保留第i位小数
	for (c = 1, j = n; j >= 1; j--)
	{
		//进行1除2j+1的操作，由数字高位向低位运算
		d = 2 * j + 1;
		for (i = 0; i <= x + 4; i++)
		{
			arr[i] = c / d;
			c = (c % d) * 10 + arr[i + 1];
		}
		arr[x + 5] = c / d;
		//进行乘j的操作，由数字低位向高位运算
		for (b = 0, i = x + 5; i >= 0; i--)
		{
			arr[i] = arr[i] * j + b;  //*j
			b = arr[i] / 10;        //计算进位数
			arr[i] = arr[i] % 10;     //留下一个0~9的整数
		}
		//将a[0]加到1，即将所求数整体加1，以继续与(j-1)/(2j-1)相乘，这样完成一个括号内的运算
		arr[0] = arr[0] + 1;
		c = arr[0];  //此处的c结果一直为1
	}

	//公式所得为pi/2，要将其乘2
	for (b = 0, i = x + 5; i >= 0; i--)
	{
		arr[i] = arr[i] * 2 + b;  //*2
		b = arr[i] / 10;        //计算进位值
		arr[i] = arr[i] % 10;     //得到留下的值，这里一定为0~9的整数
	}

	//打印输出pi的精确值
	cout << "pi=" << arr[0] << "." << endl;
	for (l = 0, i = 1; i <= x; i++)
	{
		cout << arr[i];
		l++;
		if (l % 10 == 0)
		{
			cout << "   ";
		}
		if (l % 100 == 0)
		{
			cout << endl;
		}
	}
	delete[] arr;
}


int main()
{	
	calculatepi();

	system("pause");
	return 0;
}