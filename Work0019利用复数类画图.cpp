#include <iostream>
#include <fstream>
#include <cstdlib>
#include <ctime>
#include <cmath>
#define DOTSIZE 0.0001

using namespace std;

struct Complex
{
	double m_Real;
	double m_Image;
};

Complex operator+(const Complex& c1, const Complex& c2)
{
	Complex temp;
	temp.m_Real = c1.m_Real + c2.m_Real;
	temp.m_Image = c1.m_Image + c2.m_Image;
	return temp;
}

Complex operator-(const Complex& c1, const Complex& c2)
{
	Complex temp;
	temp.m_Real = c1.m_Real - c2.m_Real;
	temp.m_Image = c1.m_Image - c2.m_Image;
	return temp;
}

Complex operator*(const Complex& c1, const Complex& c2)
{
	Complex temp;
	temp.m_Real = c1.m_Real * c2.m_Real - c1.m_Image * c2.m_Image;
	temp.m_Image = c1.m_Real * c2.m_Image + c1.m_Image * c2.m_Real;
	return temp;
}

Complex operator/(const Complex& c1, const Complex& c2)
{
	Complex temp;
	temp.m_Real = (c1.m_Real * c2.m_Real + c1.m_Image * c2.m_Image) / (c2.m_Image * c2.m_Image + c2.m_Real * c2.m_Real);
	temp.m_Image = (-c1.m_Real * c2.m_Image + c1.m_Image * c2.m_Real) / (c2.m_Image * c2.m_Image + c2.m_Real * c2.m_Real);
	return temp;
}

Complex operator+(const Complex& c, double d)
{
	Complex temp;
	temp.m_Real = c.m_Real + d;
	temp.m_Image = c.m_Image;
	return temp;
}

Complex operator+(double d, const Complex& c)
{
	Complex temp;
	temp.m_Real = c.m_Real + d;
	temp.m_Image = c.m_Image;
	return temp;
}

Complex operator-(const Complex& c, double d)
{
	Complex temp;
	temp.m_Real = c.m_Real - d;
	temp.m_Image = c.m_Image;
	return temp;
}

Complex operator-(double d, const Complex& c)
{
	Complex temp;
	temp.m_Real = -c.m_Real + d;
	temp.m_Image = -c.m_Image;
	return temp;
}

Complex operator*(const Complex& c, double d)
{
	Complex temp;
	temp.m_Real = c.m_Real * d;
	temp.m_Image = c.m_Image * d;
	return temp;
}

Complex operator*(double d, const Complex& c)
{
	Complex temp;
	temp.m_Real = c.m_Real * d;
	temp.m_Image = c.m_Image * d;
	return temp;
}

Complex operator/(const Complex& c, double d)
{
	Complex temp;
	temp.m_Real = c.m_Real / d;
	temp.m_Image = c.m_Image / d;
	return temp;
}

Complex operator/(double d, const Complex& c)
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

Complex f5m(const Complex& z, const Complex& z0)
{
	return z * z * z * z * z + z0;
}

void Scan(int* dataToFill, int width, int height, double r1, double r2, double i1, double i2, Complex f(const Complex& z, const Complex& p), int maxDepth, double escapeR)
{
	for (int y = 0; y < height; ++y)
	{
		for (int x = 0; x < width; ++x)
		{
			Complex z0;
			z0.m_Real = (r2 - r1) * x / (width - 1) + r1;
			z0.m_Image = (i2 - i1) * y / (height - 1) + i1;

			Complex z = z0;
			int t;
			for (t = 0; t < maxDepth; ++t)
			{
				z = f(z, z0);
				if (z.m_Real * z.m_Real + z.m_Image * z.m_Image > escapeR * escapeR)
				{
					break;
				}
			}

			dataToFill[y * width + x] = t;

		}
		cout << y << "\r";
	}
}

Complex solveFunc(Complex c)
{
	Complex temp = c - (c * c * c * c * c * c - 1) / (6 * c * c * c * c * c);
	return temp;
}

void Scan(int* dataToFill, int width, int height, double dotSize, int depth)
{
	for (int i = 0; i < height; ++i)
	{
		for (int j = 0; j < width; ++j)
		{
			Complex c;
			c.m_Real = -dotSize * j + (width - 1) * dotSize / 2.0;
			c.m_Image = dotSize * i - (height - 1) * dotSize / 2.0;

			for (int k = 0; k < depth; ++k)
			{
				c = solveFunc(c);
			}

			if (c.m_Real > 0.98)
			{
				dataToFill[i * width + j] = 230;
			}
			else if (c.m_Real < -0.98)
			{
				dataToFill[i * width + j] = 190;
			}
			else if (abs(c.m_Real - 0.5) < 0.05 && c.m_Image > 0)
			{
				dataToFill[i * width + j] = 150;
			}
			else if (abs(c.m_Real - 0.5) < 0.05 && c.m_Image < 0)
			{
				dataToFill[i * width + j] = 110;
			}
			else if (abs(c.m_Real + 0.5) < 0.05 && c.m_Image > 0)
			{
				dataToFill[i * width + j] = 70;
			}
			else if (abs(c.m_Real + 0.5) < 0.05 && c.m_Image < 0)
			{
				dataToFill[i * width + j] = 30;
			}
		}
		cout << i << "\r";
	}
}


//Scan(36, 36, -1.1, +1.1, -1.1, +1.1, f5m, 100, 100);

#pragma pack(1)
struct BitmapHead
{
	char h1 = 'B';
	char h2 = 'M';
	int fileSize = 54;
	int unknown = 0;
	int dataStart = 54;

	int headSize = 40;
	int width = 0;
	int height = 0;
	short colorPlane = 1;
	short bitsPerPixcel = 24;
	int pressureType = 0;
	int imageDataSize = 0;
	int xPixcelPerMeter = 0;
	int yPixcelPerMeter = 0;
	int colorCount = 0;
	int importentColorCount = 0;
};

typedef unsigned char byte;

struct BGR
{
	byte B;
	byte G;
	byte R;
};

struct Bitmap
{
	void InitBitmap(int newWidth, int newHeight);
	void DestoryBitmap();
	void SaveBitmap(const char* filename);
	void DrawBitmap();
	
	BitmapHead head;
	BGR* data;
};


void Bitmap::InitBitmap(int newWidth, int newHeight)
{
	(*this).head.width = newWidth;
	this->head.height = newHeight;

	int lineSize = newWidth * 3;
	while (lineSize % 4)
		lineSize++;

	this->head.imageDataSize = lineSize * newHeight;
    this->head.fileSize = this->head.dataStart + this->head.imageDataSize;

	int dataCount = newWidth * newHeight;
	this->data = new BGR[dataCount];
}

void Bitmap::DestoryBitmap()
{
	delete[] this->data;
}

void Bitmap::SaveBitmap(const char* filename)
{
	char space[4] = { 0 };
	ofstream fout(filename, ios::binary);
	fout.write((char*)&(this->head), this->head.headSize + 14);

	for (int y = this->head.height - 1; y >= 0; --y)
	{
		char* lineStart = (char*)(this->data + this->head.width * y);
		int lineBytes = this->head.width * 3;
		int lineSpace = 0;
		while ((lineBytes + lineSpace) % 4)
			lineSpace++;
		fout.write(lineStart, lineBytes);
		fout.write(space, lineSpace);
	}
	fout.close();
}


//------------------------------------------------
void Bitmap::DrawBitmap()
{
	int w = this->head.width;
	int h = this->head.height;
	int* colorData = new int[w * h];
	Scan(colorData, w, h, DOTSIZE, 1000);

	for (int y = 0; y < h; ++y)
	{
		for (int x = 0; x < w; ++x)
		{
			int d = colorData[y * w + x];
			byte R = sin(d * d) * 127 + 127;
			byte G = sin(3 * d) * 127 + 127;
			byte B = sin(1 * d) * 127 + 127;

			this->data[y * w + w - 1 - x].R = R;
			this->data[y * w + w - 1 - x].G = G;
			this->data[y * w + w - 1 - x].B = B;
		}
	}
}
//------------------------------------------------

int main()
{
	Bitmap bmp;
	bmp.InitBitmap(20000, 20000);
	bmp.DrawBitmap();
	bmp.SaveBitmap("D:\\colorfulComplex.bmp");
	bmp.DestoryBitmap();


	system("pause");

	return 0;
}