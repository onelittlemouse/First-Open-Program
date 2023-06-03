#include<iostream>
using namespace std;

class Complex
{
public:
	double m_Real;
	double m_Image;
};

Complex operator+(Complex c1, Complex c2)
{
	Complex temp;
	temp.m_Real = c1.m_Real + c2.m_Real;
	temp.m_Image = c1.m_Image + c2.m_Image;
	return temp;
}

Complex operator-(Complex c1, Complex c2)
{
	Complex temp;
	temp.m_Real = c1.m_Real - c2.m_Real;
	temp.m_Image = c1.m_Image - c2.m_Image;
	return temp;
}

Complex operator*(Complex c1, Complex c2)
{
	Complex temp;
	temp.m_Real = c1.m_Real * c2.m_Real - c1.m_Image * c2.m_Image;
	temp.m_Image = c1.m_Real * c2.m_Image + c1.m_Image * c2.m_Real;
	return temp;
}

Complex operator/(Complex c1, Complex c2)
{
	Complex temp;
	temp.m_Real = (c1.m_Real * c2.m_Real + c1.m_Image * c2.m_Image) / (c2.m_Image * c2.m_Image + c2.m_Real * c2.m_Real);
	temp.m_Image = (-c1.m_Real * c2.m_Image + c1.m_Image * c2.m_Real) / (c2.m_Image * c2.m_Image + c2.m_Real * c2.m_Real);
	return temp;
}

Complex operator+(Complex c, double d)
{
	Complex temp;
	temp.m_Real = c.m_Real + d;
	temp.m_Image = c.m_Image;
	return temp;
}

Complex operator+(double d, Complex c)
{
	Complex temp;
	temp.m_Real = c.m_Real + d;
	temp.m_Image = c.m_Image;
	return temp;
}

Complex operator-(Complex c, double d)
{
	Complex temp;
	temp.m_Real = c.m_Real - d;
	temp.m_Image = c.m_Image;
	return temp;
}

Complex operator-(double d, Complex c)
{
	Complex temp;
	temp.m_Real = -c.m_Real + d;
	temp.m_Image = -c.m_Image;
	return temp;
}

Complex operator*(Complex c, double d)
{
	Complex temp;
	temp.m_Real = c.m_Real * d;
	temp.m_Image = c.m_Image * d;
	return temp;
}

Complex operator*(double d, Complex c)
{
	Complex temp;
	temp.m_Real = c.m_Real * d;
	temp.m_Image = c.m_Image * d;
	return temp;
}

Complex operator/(Complex c, double d)
{
	Complex temp;
	temp.m_Real = c.m_Real / d;
	temp.m_Image = c.m_Image / d;
	return temp;
}

Complex operator/(double d, Complex c)
{
	Complex temp;
	temp.m_Real = d * c.m_Real / (c.m_Real * c.m_Real + c.m_Image * c.m_Image);
	temp.m_Image = -d * c.m_Image / (c.m_Real * c.m_Real + c.m_Image * c.m_Image);
	return temp;
}

ostream& operator<<(ostream& cout, Complex c)
{
	cout << c.m_Real << "+" << c.m_Image << "i";
	return cout;
}

Complex solveFunc(Complex c)
{
	Complex temp = c - (c * c * c - 1) / (c * c * 3);
	return temp;
}


void Scan(double length, double height, double dotSize, double depth, const char* dot1 = "¡ñ", const char* dot2 = "¡õ", const char* dot3 = "¡ø")
{
	for (int i = 0; i <= 2 * height / dotSize; i++)
	{
		for (int j = 0; j <= 2 * length / dotSize; j++)
		{
			Complex c;
			c.m_Real = -length + dotSize * j;
			c.m_Image = height - dotSize * i;

			for (int k = 0; k < depth; k++)
			{
				c = solveFunc(c);
			}

			if (c.m_Real > 0)
			{
				cout << dot1;
			}
			else if (c.m_Real < 0 && c.m_Image > 0)
			{
				cout << dot2;
			}
			else if (c.m_Real < 0 && c.m_Image < 0)
			{
				cout << dot3;
			}
		}
		cout << endl;
	}
}


int main()
{
	const double n = 1;
	Scan(n, n, n/75.0, 1000);

	system("pause");

	return 0;
}



//Complex func(Complex& c1, Complex& c2)
//{
//	return c1 * c1 * c1 * c1 * c1 + c2;
//}

//void Scan(int width, int height, Complex& c1, Complex& c2, int maxDepth, double escapeR, const char* dotOfTrue = "¡ñ", const char* dotOfFalse = "¡ð")
//{
//	for (int i = 0; i < height; i++)
//	{
//		for (int j = 0; j < width; j++)
//		{
//			Complex z0((c2.m_Real - c1.m_Real) * j / (width - 1) + c1.m_Real, (c2.m_Image - c1.m_Image) * i / (height - 1) + c1.m_Image);
//
//			Complex z = z0;
//			bool escape = false;
//
//			for (int t = 0; t < maxDepth; t++)
//			{
//				z = func(z, z0);
//				if (z.m_Real * z.m_Real + z.m_Image * z.m_Image > escapeR * escapeR)
//				{
//					escape = true;
//					break;
//				}
//			}
//			cout << (escape ? dotOfTrue : dotOfFalse);
//		}
//		cout << endl;
//	}
//}

//Complex c1(-1.1, -1.1);
//Complex c2(1.1, 1.1);
//Scan(36, 36, c1, c2, 100, 100);
