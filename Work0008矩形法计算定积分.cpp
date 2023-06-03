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
	cout << "����x*sin(x)�Ļ���" << endl;
	double M = 0;
	double N = 1;
	cout << "������������ޣ�" << endl;  
	cin >> M;
	cout << "������������ޣ�" << endl;  
	cin >> N;

	cout << "x*sin(x)��" << M << "��" << N << "֮���ͼ����x����Χ���Ϊ��" << cal(M,N) << endl;
	cout << "ʵ��ֵΪ��" << actualret(M,N) << endl;

	system("pause");

	return 0;
}