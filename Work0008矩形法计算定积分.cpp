#include<iostream>
using namespace std;
#include<cmath>

double func(double t)
{
	return t * sin(t);
}

double actualret(double M,double N)
{
	return (sin(N) - N * cos(N))- (sin(M) - M * cos(M));
}

double cal(double M, double N)
{
	double S = 0;  
	double bit = 0.0000001;

	for (double x = M; x <= N; x += bit)
	{
		S += bit * func(x);
	}
	return S;
}


int main()
{	
	cout << "计算x*sin(x)的积分" << endl;
	double M = 0;
	double N = 1;
	cout << "请输入积分下限：" << endl;  
	cin >> M;
	cout << "请输入积分上限：" << endl;  
	cin >> N;

	cout << "x*sin(x)在" << M << "到" << N << "之间的图线与x轴所围面积为：" << cal(M,N) << endl;
	cout << "实际值为：" << actualret(M,N) << endl;

	system("pause");

	return 0;
}