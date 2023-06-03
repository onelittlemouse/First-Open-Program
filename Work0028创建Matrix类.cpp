#include<iostream>
using namespace std;
#include<cmath>

enum VerticalOrHorizontal
{
	Vertical,
	Horizontal
};

enum Create
{
	Random,
	ZeroCenter,
	FullRank,
	Magic
};

class Fraction
{
	friend Fraction operator+(double a, const Fraction& f)
	{
		Fraction fa = a;
		return fa + f;
	}

	friend Fraction operator-(double a, const Fraction& f)
	{
		Fraction fa = a;
		return fa - f;
	}

	friend Fraction operator*(double a, const Fraction& f)
	{
		Fraction fa = a;
		return fa * f;
	}

	friend Fraction operator/(double a, const Fraction& f)
	{
		Fraction fa = a;
		return fa / f;
	}

	friend Fraction operator+=(double a, const Fraction& f)
	{
		Fraction fa = a;
		return fa + f;
	}

	friend Fraction operator-=(double a, const Fraction& f)
	{
		Fraction fa = a;
		return fa - f;
	}

	friend Fraction operator*=(double a, const Fraction& f)
	{
		Fraction fa = a;
		return fa * f;
	}

	friend Fraction operator/=(double a, const Fraction& f)
	{
		Fraction fa = a;
		return fa / f;
	}

	friend bool operator>(double a, const Fraction& f)
	{
		Fraction fa = a;
		return fa > f;
	}

	friend bool operator<(double a, const Fraction& f)
	{
		Fraction fa = a;
		return fa < f;
	}

	friend bool operator>=(double a, const Fraction& f)
	{
		Fraction fa = a;
		return fa >= f;
	}

	friend bool operator<=(double a, const Fraction& f)
	{
		Fraction fa = a;
		return fa <= f;
	}

	friend bool operator==(double a, const Fraction& f)
	{
		Fraction fa = a;
		return fa == f;
	}

	friend bool operator!=(double a, const Fraction& f)
	{
		Fraction fa = a;
		return fa != f;
	}

	friend ostream& operator<<(ostream& out, const Fraction& f)
	{
		//f.reduceSelf();
		int signf = f.sign();
		if (signf == 0)
		{
			out << 0;
		}
		else if (abs(f.m_Denominator) == 1)
		{
			out << signf * f.m_Numerator;
		}
		else
		{
			cout << signf * abs(f.m_Numerator) << "/" << abs(f.m_Denominator);
		}
		return out;
	}

	friend istream& operator>>(istream& in, Fraction& f)
	{
		cout << "请依次输入分数的分子、分母：" << endl;
		in >> f.m_Numerator >> f.m_Denominator;
		return in;
	}

	int getGreatestCommonDivisor(int x, int y)
	{
		//return y ? getGreatestCommonDivisor(y, x % y) : x;
		x = abs(x);
		y = abs(y);
		while (1)
		{
			if (x == 0)
			{
				break;
			}
			if (x < y)
			{
				int temp = x;
				x = y;
				y = temp;
			}
			x = x % y;
		}
		return y;
	}

	friend double abs(const Fraction& f)
	{
		return std::abs((double)f.m_Numerator / f.m_Denominator);
	}

public:
	Fraction(int a = 0, int b = 1)
	{
		this->m_Numerator = a;
		this->m_Denominator = b;
	}

	Fraction(double d, int n = 5)
	{
		int i = 1;
		int count = pow(10, n);
		while (i <= count)
		{
			double di = d * i;
			if (abs(floor(di) - di) < 1E-7)
			{
				this->m_Numerator = floor(di);
				this->m_Denominator = i;
				return;
			}
			if (abs(ceil(di) - di) < 1E-7)
			{
				this->m_Numerator = ceil(di);
				this->m_Denominator = i;
				return;
			}
			++i;
		}
		cout << d << "没有表示为分数！" << endl;
		this->m_Numerator = 0;
		this->m_Denominator = 0;
		throw;
	}

	Fraction(const Fraction& f)
	{
		this->m_Numerator = f.m_Numerator;
		this->m_Denominator = f.m_Denominator;
	}

	~Fraction()
	{

	}

	Fraction& operator=(const Fraction& f)
	{
		this->m_Numerator = f.m_Numerator;
		this->m_Denominator = f.m_Denominator;
		return *this;
	}

	Fraction& operator=(double d)
	{
		int i = 1;
		int count = 10000;
		while (i <= count)
		{
			double di = d * i;
			if (abs(floor(di) - di) < 1E-7)
			{
				this->m_Numerator = floor(di);
				this->m_Denominator = i;
				return *this;
			}
			if (abs(ceil(di) - di) < 1E-7)
			{
				this->m_Numerator = ceil(di);
				this->m_Denominator = i;
				return *this;
			}
			++i;
		}
		cout << d << "没有表示为分数！" << endl;
		this->m_Numerator = 0;
		this->m_Denominator = 0;
		throw;
	}

	Fraction& operator=(int num)
	{
		this->m_Numerator = num;
		this->m_Denominator = 1;
		return *this;
	}

	void reduceSelf()
	{
		int divisor = getGreatestCommonDivisor(this->m_Numerator, this->m_Denominator);
		this->m_Numerator /= divisor;
		this->m_Denominator /= divisor;
	}

	void makeCommonDivisor(Fraction& f)
	{
		int divisor = getGreatestCommonDivisor(this->m_Denominator, f.m_Denominator);
		int sameDenominator = this->m_Denominator * f.m_Denominator / divisor;
		this->m_Denominator = sameDenominator;
		f.m_Denominator = sameDenominator;
		this->m_Numerator *= (f.m_Denominator / divisor);
		f.m_Numerator *= (this->m_Denominator / divisor);
	}

	int sign() const
	{
		int m = this->m_Numerator * this->m_Denominator;
		return m > 0 ? 1 : (m < 0 ? -1 : 0);
	}

	Fraction operator+(const Fraction& f)
	{
		Fraction temp(this->m_Numerator * f.m_Denominator + this->m_Denominator * f.m_Numerator, this->m_Denominator * f.m_Denominator);
		temp.reduceSelf();
		return temp;
	}

	Fraction operator-(const Fraction& f)
	{
		Fraction temp(this->m_Numerator * f.m_Denominator - this->m_Denominator * f.m_Numerator, this->m_Denominator * f.m_Denominator);
		temp.reduceSelf();
		return temp;
	}

	Fraction operator-()
	{
		Fraction temp(-this->m_Numerator, this->m_Denominator);
		temp.reduceSelf();
		return temp;
	}

	Fraction operator*(const Fraction& f)
	{
		Fraction temp(this->m_Numerator * f.m_Numerator, this->m_Denominator * f.m_Denominator);
		temp.reduceSelf();
		return temp;
	}

	Fraction operator/(const Fraction& f)
	{
		Fraction temp(this->m_Numerator * f.m_Denominator, this->m_Denominator * f.m_Numerator);
		temp.reduceSelf();
		return temp;
	}

	Fraction& operator+=(const Fraction& f)
	{
		int num1 = this->m_Numerator * f.m_Denominator + this->m_Denominator * f.m_Numerator;
		int num2 = this->m_Denominator * f.m_Denominator;
		this->m_Numerator = num1;
		this->m_Denominator = num2;
		this->reduceSelf();
		return *this;
	}

	Fraction& operator-=(const Fraction& f)
	{
		int num1 = this->m_Numerator * f.m_Denominator - this->m_Denominator * f.m_Numerator;
		int num2 = this->m_Denominator * f.m_Denominator;
		this->m_Numerator = num1;
		this->m_Denominator = num2;
		this->reduceSelf();
		return *this;
	}

	Fraction& operator*=(const Fraction& f)
	{
		int num1 = this->m_Numerator * f.m_Numerator;
		int num2 = this->m_Denominator * f.m_Denominator;
		this->m_Numerator = num1;
		this->m_Denominator = num2;
		this->reduceSelf();
		return *this;
	}

	Fraction& operator/=(const Fraction& f)
	{
		int num1 = this->m_Numerator * f.m_Denominator;
		int num2 = this->m_Denominator * f.m_Numerator;
		this->m_Numerator = num1;
		this->m_Denominator = num2;
		this->reduceSelf();
		return *this;
	}

	bool operator>(const Fraction& f)
	{
		return ((*this) - f).sign() == 1;
	}

	bool operator<(const Fraction& f)
	{
		return ((*this) - f).sign() == -1;
	}

	bool operator>=(const Fraction& f)
	{
		return ((*this) - f).sign() >= 0;
	}

	bool operator<=(const Fraction& f)
	{
		return ((*this) - f).sign() <= 0;
	}

	bool operator==(const Fraction& f)
	{
		return ((*this) - f).sign() == 0;
	}

	bool operator!=(const Fraction& f)
	{
		return ((*this) - f).sign() != 0;
	}

	//operator double()
	//{
	//	return (double)this->m_Numerator / this->m_Numerator;
	//}

private:
	int m_Numerator;  //分子
	int m_Denominator;  //分母
};

class Complex
{
	friend Complex operator+(const Complex& c1, const Complex& c2)
	{
		Complex temp(c1.real + c2.real, c1.image + c2.image);
		return temp;
	}

	friend Complex operator-(const Complex& c1, const Complex& c2)
	{
		Complex temp(c1.real - c2.real, c1.image - c2.image);
		return temp;
	}

	friend Complex operator*(const Complex& c1, const Complex& c2)
	{
		Complex temp(c1.real * c2.real - c1.image * c2.image, c1.real * c2.image + c1.image * c2.real);
		return temp;
	}

	friend Complex operator/(const Complex& c1, const Complex& c2)
	{
		Complex temp((c1.real * c2.real + c1.image * c2.image) / (c2.image * c2.image + c2.real * c2.real), (-c1.real * c2.image + c1.image * c2.real) / (c2.image * c2.image + c2.real * c2.real));
		return temp;
	}

	friend Complex operator+=(Complex& c1, const Complex& c2)
	{
		return c1 = c1 + c2;
	}

	friend Complex operator-=(Complex& c1, const Complex& c2)
	{
		return c1 = c1 - c2;
	}

	friend Complex operator*=(Complex& c1, const Complex& c2)
	{
		return c1 = c1 * c2;
	}

	friend Complex operator/=(Complex& c1, const Complex& c2)
	{
		return c1 = c1 / c2;
	}

	friend double abs(const Complex& c)
	{
		return std::sqrt(c.real * c.real + c.image * c.image);
	}

	//friend bool operator>(const Complex& c1, const Complex& c2)
	//{
	//	return abs(c1) - abs(c2) > 1E-8;
	//}
	//friend bool operator<(const Complex& c1, const Complex& c2)
	//{
	//	return abs(c1) - abs(c2) < 1E-8;
	//}
	//friend bool operator>=(const Complex& c1, const Complex& c2)
	//{
	//	return abs(c1) - abs(c2) >= 0;
	//}
	//friend bool operator<=(const Complex& c1, const Complex& c2)
	//{
	//	return abs(c1) - abs(c2) <= 0;
	//}

	friend bool operator==(const Complex& c1, const Complex& c2)
	{
		return std::abs(c1.real - c2.real) < 1E-8 && std::abs(c1.image - c2.image) < 1E-8 ? true : false;
	}

	friend bool operator!=(const Complex& c1, const Complex& c2)
	{
		return std::abs(c1.real - c2.real) < 1E-8 && std::abs(c1.image - c2.image) < 1E-8 ? false : true;
	}

	friend ostream& operator<<(ostream& out, const Complex& c)
	{
		if (std::abs(c.real) < 1E-10)
		{
			std::abs(c.image) < 1E-10 ? out << 0 : out << c.image << "i";
		}
		else if (std::abs(c.image) < 1E-10)
		{
			out << c.real;
		}
		else if (c.image > 0)
		{
			out << c.real << "+" << c.image << "i";
		}
		else
		{
			out << c.real << "-" << -c.image << "i";
		}
		return out;
	}

	friend istream& operator>>(istream& in, Complex& c)
	{
		cout << "请依次输入复数的实部与虚部：" << endl;
		in >> c.real >> c.image;
		return in;
	}

public:
	Complex(double r = 0, double i = 0)
	{
		this->real = r;
		this->image = i;
	}

	Complex(const Complex& c)
	{
		this->real = c.real;
		this->image = c.image;
	}

	~Complex()
	{

	}

	Complex& operator=(const Complex& c)
	{
		this->real = c.real;
		this->image = c.image;
		return *this;
	}

	double abs()
	{
		return sqrt(this->real * this->real + this->image * this->image);
	}

	Complex operator-()
	{
		Complex temp(-this->real, -this->image);
		return temp;
	}

private:
	double real;
	double image;
};

Complex operator""i(unsigned long long l)
{
	return Complex(0, l);
}

Complex operator""i(long double d)
{
	return Complex(0, d);
}

template<typename T>
class Array
{
public:
	Array<T>()
	{
		this->size = 0;
		this->capacity = 10;
		this->dataPtr = new T[10]{ 0 };
	}

	Array<T>(int num)
	{
		this->size = 0;
		this->capacity = num;
		this->dataPtr = new T[num]{ 0 };
	}

	Array<T>(int num, T data)
	{
		this->size = 0;
		this->capacity = num;
		this->dataPtr = new T[num]{ 0 };
		for (int i = 0; i < num; ++i)
		{
			this->dataPtr[i] = data;
		}
	}

	Array<T>(int num, T* initArr, int initNum)
	{
		this->size = initNum;
		this->capacity = num;
		this->dataPtr = new T[num]{ 0 };
		for (int i = 0; i < initNum; ++i)
		{
			this->dataPtr[i] = initArr[i];
		}
	}

	Array<T>(T* startPtr, T* endPtr)
	{
		if (endPtr - startPtr < 0)
		{
			throw;
		}
		this->size = endPtr - startPtr;
		this->capacity = this->size + 10;
		this->dataPtr = new T[this->capacity]{ 0 };
		int i = 0;
		for (Array<T>::Iter it = startPtr; it != endPtr; ++it)
		{
			this->dataPtr[i] = *it;
			++i;
		}
	}

	Array<T>(const Array<T>& a)
	{
		this->size = a.size;
		this->capacity = a.capacity;
		this->dataPtr = new T[a.capacity]{ 0 };
		for (int i = 0; i < a.size; ++i)
		{
			this->dataPtr[i] = a.dataPtr[i];
		}
	}

	~Array<T>()
	{
		if (this->dataPtr != NULL)
		{
			delete[]this->dataPtr;
			this->dataPtr = NULL;
		}
	}

	Array<T>& operator=(const Array<T>& a)
	{
		if (this->capacity >= a.size)
		{
			this->size = a.size;
			for (int i = 0; i < a.size; ++i)
			{
				this->dataPtr[i] = a.dataPtr[i];
			}
		}
		else
		{
			delete[]this->dataPtr;
			this->size = a.size;
			this->capacity = a.capacity;
			this->dataPtr = new T[a.capacity]{ 0 };
			for (int i = 0; i < a.size; ++i)
			{
				this->dataPtr[i] = a.dataPtr[i];
			}
		}
		return *this;
	}

	int GetSize()
	{
		return this->size;
	}

	int GetCapacity()
	{
		return this->capacity;
	}

	T* GetDataPtr()
	{
		return this->dataPtr;
	}

	T* begin()
	{
		return this->dataPtr;
	}

	T* end()
	{
		return this->dataPtr + this->size;
	}

	T at(int pos)
	{
		if (pos < 0 || pos >= this->size)
		{
			throw;
		}
		return *(this->dataPtr + pos);
	}

	T front()
	{
		return *(this->dataPtr);
	}

	T back()
	{
		return *(this->dataPtr + this->size);
	}

	void resize(int num = 10)
	{
		T* temp = this->dataPtr;
		this->capacity += num;
		this->dataPtr = new T[this->capacity]{ 0 };
		for (int i = 0; i < this->size; ++i)
		{
			this->dataPtr[i] = temp[i];
		}
		delete[]temp;
	}

	void pushBack(T ele)
	{
		if (this->size == this->capacity)
		{
			this->resize(this->capacity);
		}
		this->dataPtr[this->size] = ele;
		++this->size;
	}

	void pushBack(T ele, int num)
	{
		if (this->size + num > this->capacity)
		{
			this->resize(num + 10);
		}
		for (int i = this->size; i < this->size + num; ++i)
		{
			this->dataPtr[i] = ele;
		}
		this->size += num;
	}

	void insert(int pos, T ele)
	{
		if (this->size == this->capacity)
		{
			this->resize(this->capacity);
		}
		for (int i = this->size - 1; i >= pos; --i)
		{
			this->dataPtr[i + 1] = this->dataPtr[i];
		}
		this->dataPtr[pos] = ele;
		++this->size;
	}

	void insert(int pos, int count, T ele)
	{
		while (this->size + count > this->capacity)
		{
			this->resize(this->capacity);
		}
		for (int i = this->size - 1; i >= pos; --i)
		{
			this->dataPtr[i + count] = this->dataPtr[i];
		}
		for (int i = pos; i < pos + count; ++i)
		{
			this->dataPtr[i] = ele;
		}
		this->size += count;
	}

	void popBack()
	{
		this->dataPtr[this->size - 1] = 0;
		--this->size;
	}

	void popBack(int num)
	{
		for (int i = this->size - 1; i >= this->size - num; --i)
		{
			this->dataPtr[i] = 0;
		}
		this->size -= num;
	}

	void remove(int pos, int num = 1)
	{
		for (int i = pos; i < pos + num; ++i)
		{
			this->dataPtr[i] = 0;
		}
		for (int i = pos + num; i < this->size; ++i)
		{
			this->dataPtr[i - num] = this->dataPtr[i];
		}
		this->size -= num;
	}

	void swap(Array<T>& a)
	{
		Array<T> temp = *this;
		*this = a;
		a = temp;
	}

	void clear()
	{
		for (int i = 0; i < this->size; ++i)
		{
			this->dataPtr[i] = 0;
		}
		this->size = 0;
	}

	bool IsEmpty()
	{
		for (int i = 0; i < this->size; ++i)
		{
			if (abs(this->dataPtr[i]) > 1E-8)
			{
				return false;
			}
		}
		return true;
	}

	T operator[](int index) const
	{
		if (index >= this->size || index < 0)
		{
			throw;
		}
		return this->dataPtr[index];
	}

	class Iter
	{
	public:
		Iter()
		{

		}

		Iter(T* p)
		{
			this->ptr = p;
		}

		Iter& operator++()
		{
			++this->ptr;
			return *this;
		}

		Iter operator++(T)
		{
			Iter temp = *this;
			++this->ptr;
			return temp;
		}

		Iter& operator--()
		{
			--this->ptr;
			return *this;
		}

		Iter operator--(T)
		{
			Iter temp = *this;
			--this->ptr;
			return temp;
		}

		bool operator!=(T* p)
		{
			return this->ptr != p;
		}

		T operator*()
		{
			return *(this->ptr);
		}

	private:
		T* ptr;
	};

private:
	T* dataPtr;
	int size;
	int capacity;
};

template<typename T>
class Matrix;

template<typename T>
class Vector
{
	friend ostream& operator<< (ostream& out, const Vector<T>& v)
	{
		for (int i = 0; i < v.GetSize(); ++i)
		{
			if (abs(v.dataPtr[i]) < 1E-8)
			{
				out << 0 << "\t";
			}
			else
			{
				out << v.dataPtr[i] << "\t";
			}
		}
		return out;
	}

	friend istream& operator>>(istream& in, Vector<T>& v)
	{
		cout << "请输入向量数据：" << endl;
		for (int i = 0; i < v.size; ++i)
		{
			in >> v.dataPtr[i];
		}
		return in;
	}

	friend class Matrix<T>;

public:
	Vector<T>()
	{
		this->size = 0;
		this->dataPtr = NULL;
		this->ty = Vertical;
	}

	Vector<T>(int size, VerticalOrHorizontal t = Vertical)
	{
		this->size = size;
		this->ty = t;
		this->dataPtr = new T[size]{ 0 };
	}

	Vector<T>(int size, Create c, VerticalOrHorizontal t = Vertical)
	{
		this->size = size;
		this->ty = t;
		this->dataPtr = new T[size]{ 0 };
		srand((unsigned int)time(NULL));
		if (c == Create::Random)
		{
			for (int i = 0; i < size; ++i)
			{
				this->dataPtr[i] = (T)rand() / RAND_MAX;
			}
		}
		else if (c == Create::ZeroCenter)
		{
			for (int i = 0; i < size; ++i)
			{
				this->dataPtr[i] = ((T)rand() / RAND_MAX) - 0.5;
			}
		}
		else if (c == Create::FullRank)
		{
			for (int i = 0; i < size; ++i)
			{
				this->dataPtr[i] = (T)(rand() + 0.001) / RAND_MAX;
			}
		}
	}

	Vector<T>(int size, T* arr, VerticalOrHorizontal t = Vertical)
	{
		this->size = size;
		this->ty = t;
		this->dataPtr = new T[size]{ 0 };
		for (int i = 0; i < size; ++i)
		{
			this->dataPtr[i] = arr[i];
		}
	}

	Vector<T>(const Vector<T>& v)
	{
		this->size = v.size;
		this->ty = v.ty;
		this->dataPtr = new T[v.size]{ 0 };
		for (int i = 0; i < v.size; ++i)
		{
			this->dataPtr[i] = v.dataPtr[i];
		}
	}

	~Vector<T>()
	{
		if (this->dataPtr != NULL)
		{
			delete[]this->dataPtr;
		}
	}

	Vector<T>& operator= (const Vector<T>& v)
	{
		this->size = v.size;
		this->ty = v.ty;
		this->dataPtr = new T[v.size]{ 0 };
		for (int i = 0; i < v.size; ++i)
		{
			this->dataPtr[i] = v.dataPtr[i];
		}
		return *this;
	}

	//返回向量大小
	int GetSize() const
	{
		return this->size;
	}

	//返回向量数组指针
	T* GetData() const
	{
		return this->dataPtr;
	}

	//返回向量类型
	VerticalOrHorizontal GetVectorClass()
	{
		return this->ty;
	}

	//返回向量的模
	T GetAbs()
	{
		T sum = 0;
		for (int i = 0; i < this->size; ++i)
		{
			sum += this->dataPtr[i] * dataPtr[i];
		}
		return sqrt(sum);
	}

	//返回向量各分量和
	T GetSum()
	{
		T sum = 0;
		for (int i = 0; i < this->size; ++i)
		{
			sum = this->dataPtr[i];
		}
		return sum;
	}

	//单位化向量
	Vector<T>& Normalize()
	{
		T absV = this->GetAbs();
		for (int i = 0; i < size; ++i)
		{
			this->dataPtr[i] /= absV;
		}
		return *this;
	}

	//判断向量是否为空
	bool IsEmpty()
	{
		for (int i = 0; i < this->size; ++i)
		{
			if (abs(this->dataPtr[i]) > 1E-11)
			{
				return false;
			}
		}
		return true;
	}

	//判断两向量是否垂直
	bool IsVertical(const Vector<T>& v)
	{
		if (this->size != v.size || this->ty != v.ty)
		{
			throw;
		}
		return abs((*this) * v) < 1E-10 ? true : false;
	}

	//判断两向量是否平行
	bool IsParallel(const Vector<T>& v)
	{
		if (this->size != v.size || this->ty != v.ty)
		{
			throw;
		}
		if (this->isEmpty() || v.isEmpty())
		{
			return true;
		}
		if (abs(this->dataPtr[0]) > 1E-8 && abs(v.dataPtr[0]) < 1E-11)
		{
			return false;
		}
		T rate = this->dataPtr[0] / v.dataPtr[0];
		for (int i = 1; i < this->size; ++i)
		{
			if (abs(this->dataPtr[i] - v.dataPtr[i] * rate) > 1E-9)
			{
				return false;
			}
		}
		return true;
	}

	Vector<T> operator+(const Vector<T>& v)
	{
		if (this->size != v.size || this->ty != v.ty)
		{
			throw;
		}
		Vector<T> temp(this->size, this->ty);
		for (int i = 0; i < this->size; ++i)
		{
			temp.dataPtr[i] = this->dataPtr[i] + v.dataPtr[i];
		}
		return temp;
	}

	Vector<T> operator-(const Vector<T>& v)
	{
		if (this->size != v.size || this->ty != v.ty)
		{
			throw;
		}
		Vector<T> temp(this->size, this->ty);
		for (int i = 0; i < this->size; ++i)
		{
			temp.dataPtr[i] = this->dataPtr[i] - v.dataPtr[i];
		}
		return temp;
	}

	Vector<T> operator-()
	{
		Vector<T> temp(this->size, this->ty);
		for (int i = 0; i < this->size; ++i)
		{
			temp.dataPtr[i] = -this->dataPtr[i];
		}
		return temp;
	}

	T operator*(const Vector<T>& v)
	{
		if (this->size != v.size || this->ty == Vertical || v.ty == Horizontal)
		{
			throw;
		}
		T sum = 0;
		for (int i = 0; i < this->size; ++i)
		{
			sum += this->dataPtr[i] * v.dataPtr[i];
		}
		return sum;
	}

	Vector<T> operator*(const T& num)
	{
		Vector<T> temp(this->size, this->ty);
		for (int i = 0; i < this->size; ++i)
		{
			temp.dataPtr[i] = this->dataPtr[i] * num;
		}
		return temp;
	}

	Vector<T> operator*(const Matrix<T>& m)
	{
		if (this->size != m.row || this->ty == Vertical)
		{
			throw;
		}
		Vector<T> temp(m.col, Horizontal);
		for (int i = 0; i < m.col; ++i)
		{
			T sum = 0;
			for (int j = 0; j < this->size; ++j)
			{
				sum += this->dataPtr[j] * m.dataPtr[j][i];
			}
			temp.dataPtr[i] = sum;
		}
		return temp;
	}

	Vector<T> operator/(const T& num)
	{
		Vector<T> temp(this->size, this->ty);
		for (int i = 0; i < this->size; ++i)
		{
			temp.dataPtr[i] = this->dataPtr[i] / num;
		}
		return temp;
	}

	Vector<T>& operator+=(const Vector<T>& v)
	{
		if (this->size != v.size || this->ty != v.ty)
		{
			throw;
		}
		for (int i = 0; i < this->size; ++i)
		{
			this->dataPtr[i] += v.dataPtr[i];
		}
		return *this;
	}

	Vector<T>& operator-=(const Vector<T>& v)
	{
		if (this->size != v.size || this->ty != v.ty)
		{
			throw;
		}
		for (int i = 0; i < this->size; ++i)
		{
			this->dataPtr[i] -= v.dataPtr[i];
		}
		return *this;
	}

	Vector<T>& operator*=(const T& num)
	{
		for (int i = 0; i < this->size; ++i)
		{
			this->dataPtr[i] *= num;
		}
		return *this;
	}

	Vector<T>& operator/=(const T& num)
	{
		for (int i = 0; i < this->size; ++i)
		{
			this->dataPtr[i] /= num;
		}
		return *this;
	}

	bool operator>(const Vector<T>& v)
	{
		if (this->size != v.size)
		{
			throw;
		}
		return this->GetAbs() - v.GetAbs() > 1E-7;
	}

	bool operator<(const Vector<T>& v)
	{
		if (this->size != v.size)
		{
			throw;
		}
		return v.GetAbs() - this->GetAbs() > 1E-7;
	}

	bool operator>=(const Vector<T>& v)
	{
		if (this->size != v.size)
		{
			throw;
		}
		return this->GetAbs() >= v.GetAbs();
	}

	bool operator<=(const Vector<T>& v)
	{
		if (this->size != v.size)
		{
			throw;
		}
		return v.GetAbs() >= this->GetAbs();
	}

	bool operator==(const Vector<T>& v)
	{
		if (this->size != v.size)
		{
			return false;
		}
		for (int i = 0; i < this->size; ++i)
		{
			if (abs(this->dataPtr[i] - v.dataPtr[i]) > 1E-8)
			{
				return false;
			}
		}
		return true;
	}

	bool operator!=(const Vector<T>& v)
	{
		if (this->size != v.size)
		{
			return true;
		}
		for (int i = 0; i < this->size; ++i)
		{
			if (abs(this->dataPtr[i] - v.dataPtr[i]) > 1E-8)
			{
				return true;
			}
		}
		return false;
	}

	T operator[](int index) const
	{
		if (index >= this->size || index < 0)
		{
			throw;
		}
		return this->dataPtr[index];
	}

private:
	int size;							//size count of the Array
	T* dataPtr;							//the start fo Array array
	VerticalOrHorizontal ty;
};

template<typename T>
class Matrix
{
	friend ostream& operator<<(ostream& out, const Matrix<T>& m)
	{
		for (int i = 0; i < m.row; ++i)
		{
			for (int j = 0; j < m.col; ++j)
			{
				if (abs(m.dataPtr[i][j]) < 1E-8)
				{
					out << 0 << "  ";
				}
				else
				{
					out << m.dataPtr[i][j] << "  ";
				}
			}
			out << endl;
		}
		return out;
	}

	friend istream& operator>>(istream& in, Matrix<T>& m)
	{
		for (int i = 0; i < m.row; ++i)
		{
			cout << "开始输入第" << i + 1 << "行元素：" << endl;
			for (int j = 0; j < m.col; ++j)
			{
				in >> m.dataPtr[i][j];
			}
		}
		return in;
	}

public:
	Matrix<T>()
	{
		this->row = this->col = 0;
		this->dataPtr = NULL;
	}

	Matrix<T>(int size)
	{
		this->row = size;
		this->col = size;
		this->dataPtr = new T * [size];
		for (int i = 0; i < size; ++i)
		{
			dataPtr[i] = new T[size]{ 0 };
			dataPtr[i][i] = 1;
		}
	}

	Matrix<T>(int size, Create c)
	{
		this->row = size;
		this->col = size;
		srand((unsigned int)time(NULL));
		this->dataPtr = new T * [size];
		for (int i = 0; i < size; ++i)
		{
			this->dataPtr[i] = new T[size]{ 0 };
			if (c == Create::Random)
			{
				for (int j = 0; j < size; ++j)
				{
					this->dataPtr[i][j] = (T)rand() / RAND_MAX;
				}
			}
			else if (c == Create::ZeroCenter)
			{
				for (int j = 0; j < size; ++j)
				{
					this->dataPtr[i][j] = ((T)rand() / RAND_MAX) - 0.5;
				}
			}
		}
		if (c == Create::FullRank)
		{
			for (int i = 0; i < size; ++i)
			{
				for (int j = 0; j < size; ++j)
				{
					this->dataPtr[i][j] = ((T)rand() / RAND_MAX) - 0.5;
				}
			}
			while (!this->IsFullRank())
			{
				this->dataPtr[rand() % size][rand() % size] += ((T)rand() / RAND_MAX) - 0.5;
			}
		}
		if (c == Create::Magic && size != 2)
		{
			switch (size % 4)
			{
			case 0:
			{
				int num = 1;
				for (int i = 0; i < size; ++i)
				{
					for (int j = 0; j < size; ++j)
					{
						this->dataPtr[i][j] = num;
						++num;
					}
				}
				const int sum = size * size + 1;
				for (int i = 0; i < size; i += 4)
				{
					for (int j = 0; j < size; j += 4)
					{
						for (int k = 0; k < 4; ++k)
						{
							this->dataPtr[i + k][j + k] = sum - this->dataPtr[i + k][j + k];
							this->dataPtr[i + k][j - k + 3] = sum - this->dataPtr[i + k][j - k + 3];
						}
					}
				}
				break;
			}
			case 1:
			case 3:
			{
				int row = 0;
				int col = (size - 1) / 2;
				for (int i = 1; i <= size * size; ++i)
				{
					this->dataPtr[row][col] = i;
					int rowtemp = row;
					int coltemp = col;
					--row;
					++col;
					if (row < 0)
					{
						row = size - 1;
					}
					if (col > size - 1)
					{
						col = 0;
					}
					if (this->dataPtr[row][col] != 0)
					{
						++rowtemp;
						if (rowtemp > size - 1)
						{
							rowtemp = 0;
						}
						row = rowtemp;
						col = coltemp;
					}
				}
				break;
			}
			case 2:
			{
				const int n = size >> 1;
				const int k = (n - 1) >> 1;
				int row = 0;
				int col = k;
				for (int i = 1; i <= n * n; ++i)
				{
					this->dataPtr[row][col] = i;
					int rowtemp = row;
					int coltemp = col;
					--row;
					++col;
					if (row < 0)
					{
						row = n - 1;
					}
					if (col > n - 1)
					{
						col = 0;
					}
					if (this->dataPtr[row][col] != 0)
					{
						++rowtemp;
						if (rowtemp > n - 1)
						{
							rowtemp = 0;
						}
						row = rowtemp;
						col = coltemp;
					}
				}
				row = n;
				col = n + k;
				for (int i = n * n + 1; i <= size * n; ++i)
				{
					this->dataPtr[row][col] = i;
					int rowtemp = row;
					int coltemp = col;
					--row;
					++col;
					if (row < n)
					{
						row = size - 1;
					}
					if (col > size - 1)
					{
						col = n;
					}
					if (this->dataPtr[row][col] != 0)
					{
						++rowtemp;
						if (rowtemp > size - 1)
						{
							rowtemp = n;
						}
						row = rowtemp;
						col = coltemp;
					}
				}
				row = 0;
				col = n + k;
				for (int i = size * n + 1; i <= 3 * n * n; ++i)
				{
					this->dataPtr[row][col] = i;
					int rowtemp = row;
					int coltemp = col;
					--row;
					++col;
					if (row < 0)
					{
						row = n - 1;
					}
					if (col > size - 1)
					{
						col = n;
					}
					if (this->dataPtr[row][col] != 0)
					{
						++rowtemp;
						if (rowtemp > n - 1)
						{
							rowtemp = 0;
						}
						row = rowtemp;
						col = coltemp;
					}
				}
				row = n;
				col = k;
				for (int i = 3 * n * n + 1; i <= size * size; ++i)
				{
					this->dataPtr[row][col] = i;
					int rowtemp = row;
					int coltemp = col;
					--row;
					++col;
					if (row < n)
					{
						row = size - 1;
					}
					if (col > n - 1)
					{
						col = 0;
					}
					if (this->dataPtr[row][col] != 0)
					{
						++rowtemp;
						if (rowtemp > size - 1)
						{
							rowtemp = n;
						}
						row = rowtemp;
						col = coltemp;
					}
				}
				for (int i = 0; i < k; ++i)
				{
					for (int j = 0; j < k; ++j)
					{
						swap(this->dataPtr[i][j], this->dataPtr[i + n][j]);
						swap(this->dataPtr[i + k + 1][j], this->dataPtr[i + k + 1 + n][j]);
					}
					swap(this->dataPtr[k][k + i], this->dataPtr[k + n][k + i]);
				}
				for (int i = 0; i < k - 1; ++i)
				{
					for (int j = 0; j < n; ++j)
					{
						swap(this->dataPtr[j][n + k - i], this->dataPtr[j + n][n + k - i]);
					}
				}
				break;
			}
			default:
				break;
			}
		}
	}

	Matrix<T>(int rowCount, int colCount)
	{
		this->row = rowCount;
		this->col = colCount;
		this->dataPtr = new T * [rowCount];
		for (int i = 0; i < rowCount; ++i)
		{
			dataPtr[i] = new T[colCount]{ 0 };
		}
	}

	Matrix<T>(int rowCount, int colCount, Create c)
	{
		this->row = rowCount;
		this->col = colCount;
		srand((unsigned int)time(NULL));
		this->dataPtr = new T * [rowCount];
		for (int i = 0; i < rowCount; ++i)
		{
			this->dataPtr[i] = new T[colCount]{ 0 };
			if (c == Create::Random)
			{
				for (int j = 0; j < colCount; ++j)
				{
					this->dataPtr[i][j] = (T)rand() / RAND_MAX;
				}
			}
			else if (c == Create::ZeroCenter)
			{
				for (int j = 0; j < colCount; ++j)
				{
					this->dataPtr[i][j] = ((T)rand() / RAND_MAX) - 0.5;
				}
			}
		}
		if (c == Create::FullRank)
		{
			for (int i = 0; i < rowCount; ++i)
			{
				for (int j = 0; j < colCount; ++j)
				{
					this->dataPtr[i][j] = ((T)rand() / RAND_MAX) - 0.5;
				}
			}
			while (!this->IsFullRank())
			{
				this->dataPtr[rand() % rowCount][rand() % colCount] += ((T)rand() / RAND_MAX) - 0.5;
			}
		}
	}

	Matrix<T>(int rowCount, int colCount, T* valueArr, int valueArrSize)
	{
		this->row = rowCount;
		this->col = colCount;
		this->dataPtr = new T * [rowCount];
		for (int i = 0; i < rowCount; ++i)
		{
			dataPtr[i] = new T[colCount]{ 0 };
		}
		for (int i = 0; i < rowCount; ++i)
		{
			for (int j = 0; j < colCount; ++j)
			{
				if (valueArrSize > 0)
				{
					this->dataPtr[i][j] = *valueArr;
					--valueArrSize;
					++valueArr;
				}
				else
				{
					break;
				}
			}
		}
	}

	Matrix<T>(const Matrix<T>& m)
	{
		this->row = m.row;
		this->col = m.col;
		this->dataPtr = new T * [m.row];
		for (int i = 0; i < m.row; ++i)
		{
			this->dataPtr[i] = new T[m.col]{ 0 };
			for (int j = 0; j < m.col; ++j)
			{
				this->dataPtr[i][j] = m.dataPtr[i][j];
			}
		}
	}

	~Matrix<T>()
	{
		if (this->dataPtr != NULL)
		{
			for (int i = 0; i < this->row; ++i)
			{
				if (this->dataPtr[i] != NULL)
				{
					delete[]this->dataPtr[i];
				}
			}
			delete[]this->dataPtr;
		}
	}

	Matrix<T>& operator= (const Matrix<T>& m)
	{
		if (this->row != m.row || this->col != m.col)
		{
			if (this->dataPtr != NULL)
			{
				for (int i = 0; i < this->row; ++i)
				{
					if (this->dataPtr[i] != NULL)
					{
						delete[]this->dataPtr[i];
						this->dataPtr[i] = NULL;
					}
				}
				delete[]this->dataPtr;
				this->dataPtr = NULL;
			}
			this->row = m.row;
			this->col = m.col;
			this->dataPtr = new T * [m.row];
			for (int i = 0; i < m.row; ++i)
			{
				dataPtr[i] = new T[m.col]{ 0 };
				for (int j = 0; j < m.col; ++j)
				{
					this->dataPtr[i][j] = m.dataPtr[i][j];
				}
			}
		}
		else
		{
			for (int i = 0; i < this->row; ++i)
			{
				for (int j = 0; j < this->col; ++j)
				{
					this->dataPtr[i][j] = m.dataPtr[i][j];
				}
			}
		}
		return *this;
	}

	//返回矩阵的行数
	int GetRow()
	{
		return this->row;
	}

	//返回矩阵的列数
	int GetCol()	
	{
		return this->col;
	}
	
	//返回矩阵的二维数组指针
	T** GetData() 
	{ 
		return dataPtr;
	}

	//返回矩阵大小
	int GetSize()
	{
		return this->col * this->row;
	}

	//判断矩阵是否为空
	bool IsEmpty()
	{
		bool isEmpty = true;
		if (this->row * this->col == 0)
		{
			return false;
		}
		for (int i = 0; i < this->row; ++i)
		{
			for (int j = 0; j < this->col; ++j)
			{
				if (abs(this->dataPtr[i][j]) > 1E-10)
				{
					return false;
				}
			}
		}
		return true;
	}

	//返回矩阵的秩
	int GetRank()
	{
		if (this->col * this->row == 0)
		{
			throw;
		}
		Matrix<T> temp = *this;
		int size = temp.row;
		for (int i = 0; i < size; ++i)
		{
			if (abs(temp.dataPtr[i][i]) < 1E-11)
			{
				bool b = true;
				for (int j = i + 1; j < size; ++j)
				{
					if (abs(temp.dataPtr[j][i]) > 1E-11)
					{
						temp.TransformRowSum(i, j);
						b = false;
					}
				}
				if (b)
				{
					continue;
				}
			}
			for (int j = 0; j < size && j != i; ++j)
			{
				temp.TransformRow(j, 1.0, i, -temp.dataPtr[j][i] / temp.dataPtr[i][i]);
			}
		}
		int rank = min(temp.row, temp.col);
		for (int i = 0; i < size; ++i)
		{
			if (abs(temp.dataPtr[i][i]) < 1E-10)
			{
				--rank;
			}
		}
		return rank;
	}

	//判断矩阵是否满秩
	bool IsFullRank()
	{
		return this->GetRank() == min(this->row, this->col) ? true : false;
	}

	//判断矩阵是否为魔方
	bool IsMagic()
	{
		if (this->row != this->col || this->row == 2 || this->row == 0)
		{
			return false;
		}
		int size = this->row;
		int* arr = new int[size * size + 1] {0};
		for (int i = 0; i < size; ++i)
		{
			for (int j = 0; j < size; ++j)
			{
				if (arr[this->dataPtr[i][j]]++)
				{
					return false;
				}
			}
		}
		int check = size * (size * size + 1) >> 1;
		for (int i = 0; i < size; ++i)
		{
			int sum1 = 0;
			int sum2 = 0;
			for (int j = 0; j < size; ++j)
			{
				sum1 += this->dataPtr[i][j];
				sum2 += this->dataPtr[j][i];
			}
			if (sum1 != check || sum2 != check)
			{
				return false;
			}
		}
		int sum3 = 0;
		int sum4 = 0;
		for (int i = 0; i < size; ++i)
		{
			sum3 += this->dataPtr[i][i];
			sum4 += this->dataPtr[i][size - i - 1];
		}
		if (sum3 != check || sum4 != check)
		{
			return false;
		}
		return true;
	}

	//返回矩阵的一列
	Vector<T> GetColData(int colIndex)
	{
		Vector<T> temp(this->row);
		for (int i = 0; i < this->row; ++i)
		{
			temp.GetData()[i] = this->dataPtr[i][colIndex];
		}
		return temp;
	}

	//Row[row] /= factor
	void TransformRowDiv(int row, T factor)
	{
		for (int i = 0; i < this->col; ++i)
		{
			this->dataPtr[row][i] /= factor;
		}
	}
		
	//Row[row1] += Row[row2]
	void TransformRowSum(int row1, int row2)
	{
		for (int i = 0; i < this->col; ++i)
		{
			this->dataPtr[row1][i] += this->dataPtr[row2][i];
		}
	}
	
	//Row[row1] -= Row[row2]
	void TransformRowSub(int row1, int row2)
	{
		for (int i = 0; i < this->col; ++i)
		{
			this->dataPtr[row1][i] -= this->dataPtr[row2][i];
		}
	}
	
	//Row[row1] = Row[row1] * factor1 + Row[row2] * factor2
	void TransformRow(int row1, T factor1, int row2, T factor2)
	{
		for (int i = 0; i < this->col; ++i)
		{
			this->dataPtr[row1][i] = this->dataPtr[row1][i] * factor1 + this->dataPtr[row2][i] * factor2;
		}
	}

	//返回矩阵的上三角式
	Matrix<T> GetUpperTriangleMatrix()
	{
		if (this->row != this->col && this->row + 1 != this->col)
		{
			throw;
		}
		Matrix<T> m = *this;
		int size = this->row;
		for (int i = 0; i < size; ++i)
		{
			if (abs(m.dataPtr[i][i]) < 1E-11)
			{
				bool b = true;
				for (int j = i + 1; j < size; ++j)
				{
					if (abs(m.dataPtr[j][i]) > 1E-11)
					{
						m.TransformRowSum(i, j);
						b = false;
					}
				}
				if (b)
				{
					continue;
				}
			}
			for (int j = i + 1; j < size; ++j)
			{
				m.TransformRow(j, 1.0, i, -m.dataPtr[j][i] / m.dataPtr[i][i]);
			}
		}
		return m;
	}

	//返回矩阵的行列式
	T Determinant()
	{
		if (this->row != this->col)
		{
			throw;
		}
		Matrix<T> temp = this->GetUpperTriangleMatrix();
		T result = 1;
		for (int i = 0; i < this->row; ++i)
		{
			result *= temp.dataPtr[i][i];
		}
		return result;
	}

	//返回矩阵的迹
	T Trace()
	{
		if (this->row != this->col)
		{
			throw;
		}
		T sum = 0;
		for (int i = 0; i < this->row; ++i)
		{
			sum += this->dataPtr[i][i];
		}
		return sum;
	}

	//通过矩阵m和向量v创建增广矩阵
	Matrix<T> CreateAugmentedMatrix(const Vector<T>& v)
	{
		if (this->col != this->GetRow()) throw;
		if (this->row != v.GetSize()) throw;

		Matrix<T> temp(this->row, this->col + 1);
		for (int i = 0; i < this->row; ++i)
		{
			for (int j = 0; j < this->col; ++j)
			{
				temp.GetData()[i][j] = this->dataPtr[i][j];
			}
			temp.GetData()[i][this->col] = v.GetData()[i];
		}
		return temp;
	}

	//高斯消去法，获得一个单位阵
	bool GaussianElimination()
	{
		bool isSolved = true;
		if (this->col - this->row != 1)
		{
			throw;
		}
		int size = this->row;
		for (int i = 0; i < size; ++i)
		{
			if (abs(this->dataPtr[i][i]) < 1E-11)
			{
				bool b = true;
				for (int j = i + 1; j < size; ++j)
				{
					if (abs(this->dataPtr[j][i]) > 1E-11)
					{
						this->TransformRowSum(i, j);
						b = false;
					}
				}
				if (b)
				{
					cout << "方程组无解或有无穷多解" << endl;
					return false;
				}
			}
			for (int j = i + 1; j < size; ++j)
			{
				this->TransformRow(j, 1.0, i, -this->dataPtr[j][i] / this->dataPtr[i][i]);
			}
		}
		for (int i = size - 1; i >= 0; --i)
		{
			this->TransformRowDiv(i, this->dataPtr[i][i]);
			for (int j = 0; j < i; ++j)
			{
				this->TransformRow(j, 1.0, i, -this->dataPtr[j][i]);
			}
		}
		return true;
	}

	//解出线性方程组，返回解向量
	Vector<T> GetSolutionResult(const Vector<T>& v)
	{
		Matrix<T> temp = this->CreateAugmentedMatrix(v);
		return temp.GaussianElimination() ? temp.GetColData(temp.col - 1) : Vector<T>();
	}

	//垂直方向合并矩阵
	Matrix<T> MergeTwoMatrixInH(const Matrix<T>& m)
	{
		if (this->row != m.row)
		{
			throw;
		}
		Matrix<T> temp(this->row, this->col + m.col);
		for (int i = 0; i < this->row; ++i)
		{
			for (int j = 0; j < this->col; ++j)
			{
				temp.dataPtr[i][j] = this->dataPtr[i][j];
			}
			for (int k = this->col; k < this->col + m.col; ++k)
			{
				temp.dataPtr[i][k] = m.dataPtr[i][k - this->col];
			}
		}
		return temp;
	}

	//返回逆矩阵
	Matrix<T> GetInvMatrix()
	{
		if (this->col != this->row)
		{
			throw;
		}
		Matrix<T> eye(this->col);
		Matrix<T> tmp = this->MergeTwoMatrixInH(eye);
		int size = tmp.row;
		for (int i = 0; i < size; ++i)
		{
			if (abs(tmp.dataPtr[i][i]) < 1E-11)
			{
				bool b = true;
				for (int j = i + 1; j < size; ++j)
				{
					if (abs(tmp.dataPtr[j][i]) > 1E-11)
					{
						tmp.TransformRowSum(i, j);
						b = false;
					}
				}
				if (b)
				{
					throw;
					return Matrix<T>(1);
				}
			}
			for (int j = i + 1; j < size; ++j)
			{
				tmp.TransformRow(j, 1.0, i, -tmp.dataPtr[j][i] / tmp.dataPtr[i][i]);
			}
		}
		for (int i = size - 1; i >= 0; --i)
		{
			tmp.TransformRowDiv(i, tmp.dataPtr[i][i]);
			for (int j = 0; j < i; ++j)
			{
				tmp.TransformRow(j, 1.0, i, -tmp.dataPtr[j][i]);
			}
		}
		Matrix<T> ret(this->row, this->col);
		for (int i = 0; i < this->row; ++i)
		{
			for (int j = 0; j < this->col; ++j)
			{
				ret.dataPtr[i][j] = tmp.dataPtr[i][j + this->row];
			}
		}
		return ret;
	}

	//返回矩阵元素的代数余子式
	T GetCofactor(int r, int c)
	{
		if (this->row <= 1 || this->col <= 1 || this->row != this->col)
		{
			throw;
		}
		T* arr = new T[(this->row - 1) * (this->col - 1)]{ 0 };
		for (int i = 0; i < this->row && i != r; ++i)
		{
			for (int j = 0; j < this->col && j != c; ++j)
			{
				arr = this->dataPtr[i][j];
				++arr;
			}
		}
		Matrix<T> temp(this->row - 1, this->col - 1, arr, (this->row - 1) * (this->col - 1));
		return pow(-1, r + c) * this->dataPtr[r][c] * temp.Determinant();
	}

	//返回伴随矩阵
	Matrix<T> GetAdjugateMatrix()
	{
		T det = this->Determinant();
		Matrix<T> temp = this->GetInvMatrix();
		for (int i = 0; i < this->row; ++i)
		{
			for (int j = 0; j < this->col; ++j)
			{
				temp.dataPtr[i][j] *= det;
			}
		}
		return temp;
	}

	//返回转置矩阵
	Matrix<T> GetTurn()
	{
		Matrix<T> temp(this->col, this->row);
		for (int i = 0; i < this->row; ++i)
		{
			for (int j = 0; j < this->col; ++j)
			{
				temp.dataPtr[j][i] = this->dataPtr[i][j];
			}
		}
		return temp;
	}

	//返回矩阵的方幂
	Matrix<T> GetPowerMatrix(int index)
	{
		if (index <= 0 || this->col != this->row)
		{
			throw;
		}
		Matrix<T> temp(*this);
		while (--index)
		{
			temp = temp * (*this);
		}
		return temp;
	}

	Matrix<T> operator+(const Matrix<T>& m)
	{
		if (this->row != m.row || this->col != m.col)
		{
			throw;
		}
		Matrix<T> temp(this->row, this->col);
		for (int i = 0; i < this->row; ++i)
		{
			for (int j = 0; j < this->col; ++j)
			{
				temp.dataPtr[i][j] = this->dataPtr[i][j] + m.dataPtr[i][j];
			}
		}
		return temp;
	}

	Matrix<T> operator+(const T& t)
	{
		Matrix temp = *this;
		for (int i = 0; i < this->col; ++i)
		{
			temp.dataPtr[i][i] += t;
		}
		return temp;
	}

	Matrix<T> operator-(const Matrix<T>& m)
	{
		if (this->row != m.row || this->col != m.col)
		{
			throw;
		}
		Matrix<T> temp(this->row, this->col);
		for (int i = 0; i < this->row; ++i)
		{
			for (int j = 0; j < this->col; ++j)
			{
				temp.dataPtr[i][j] = this->dataPtr[i][j] - m.dataPtr[i][j];
			}
		}
		return temp;
	}

	Matrix<T> operator-(const T& t)
	{
		Matrix temp = *this;
		for (int i = 0; i < this->col; ++i)
		{
			temp.dataPtr[i][i] -= t;
		}
		return temp;
	}

	Matrix<T> operator-()
	{
		Matrix<T> temp(this->row, this->col);
		for (int i = 0; i < this->row; ++i)
		{
			for (int j = 0; j < this->col; ++j)
			{
				temp.dataPtr[i][j] = -this->dataPtr[i][j];
			}
		}
		return temp;
	}

	Matrix<T> operator*(const Matrix<T>& m)
	{
		if (this->col != m.row)
		{
			throw;
		}
		Matrix<T> temp(this->row, m.col);
		for (int i = 0; i < this->row; ++i)
		{
			for (int j = 0; j < m.col; ++j)
			{
				T sum = 0;
				for (int k = 0; k < this->col; ++k)
				{
					sum += this->dataPtr[i][k] * m.dataPtr[k][j];
				}
				temp.dataPtr[i][j] = sum;
			}
		}
		return temp;
	}

	Matrix<T> operator*(const T& t)
	{
		Matrix<T> temp(this->row, this->col);
		for (int i = 0; i < this->row; ++i)
		{
			for (int j = 0; j < this->col; ++j)
			{
				temp.dataPtr[i][j] *= t;
			}
		}
		return temp;
	}

	Vector<T> operator*(const Vector<T>& v)
	{
		if (this->col != v.size || v.ty == Horizontal)
		{
			throw;
		}
		Vector<T> temp(this->row, Vertical);
		for (int i = 0; i < this->row; ++i)
		{
			T sum = 0;
			for (int j = 0; j < this->col; ++j)
			{
				sum += this->dataPtr[i][j] * v.dataPtr[j];
			}
			temp.dataPtr[i] = sum;
		}
		return temp;
	}

	Matrix<T> operator/(const T& t)
	{
		Matrix<T> temp(this->row, this->col);
		for (int i = 0; i < this->row; ++i)
		{
			for (int j = 0; j < this->col; ++j)
			{
				temp.dataPtr[i][j] /= t;
			}
		}
		return temp;
	}

	Matrix<T>& operator+=(const Matrix<T>& m)
	{
		if (this->row != m.row || this->col != m.col)
		{
			throw;
		}
		for (int i = 0; i < this->row; ++i)
		{
			for (int j = 0; j < this->col; ++j)
			{
				this->dataPtr[i][j] += m.dataPtr[i][j];
			}
		}
		return *this;
	}

	Matrix<T>& operator+=(const T& t)
	{
		for (int i = 0; i < this->col; ++i)
		{
			this->dataPtr[i][i] += t;
		}
		return *this;
	}

	Matrix<T>& operator-=(const Matrix<T>& m)
	{
		if (this->row != m.row || this->col != m.col)
		{
			throw;
		}
		for (int i = 0; i < this->row; ++i)
		{
			for (int j = 0; j < this->col; ++j)
			{
				this->dataPtr[i][j] -= m.dataPtr[i][j];
			}
		}
		return *this;
	}

	Matrix<T>& operator-=(const T& t)
	{
		for (int i = 0; i < this->col; ++i)
		{
			this->dataPtr[i][i] -= t;
		}
		return *this;
	}

	Matrix<T>& operator*=(const T& t)
	{
		for (int i = 0; i < this->row; ++i)
		{
			for (int j = 0; j < this->col; ++j)
			{
				this->dataPtr[i][j] *= t;
			}
		}
		return *this;
	}

	Matrix<T>& operator/=(const T& t)
	{
		for (int i = 0; i < this->row; ++i)
		{
			for (int j = 0; j < this->col; ++j)
			{
				this->dataPtr[i][j] /= t;
			}
		}
		return *this;
	}

	bool operator>(const Matrix<T>& m)
	{
		return this->GetRank() > m.GetRank();
	}

	bool operator<(const Matrix<T>& m)
	{
		return this->GetRank() < m.GetRank();
	}

	bool operator>=(const Matrix<T>& m)
	{
		return this->GetRank() >= m.GetRank();
	}

	bool operator<=(const Matrix<T>& m)
	{
		return this->GetRank() <= m.GetRank();
	}

	bool operator==(const Matrix<T>& m)
	{
		if (this->row != m.row || this->col != m.col)
		{
			return false;
		}
		for (int i = 0; i < this->row; ++i)
		{
			for (int j = 0; j < this->row; ++j)
			{
				if (abs(this->dataPtr[i][j] - m.dataPtr[i][j]) > 1E-8)
				{
					return false;
				}
			}
		}
		return true;
	}

	bool operator!=(const Matrix<T>& m)
	{
		if (this->row != m.row || this->col != m.col)
		{
			return true;
		}
		for (int i = 0; i < this->row; ++i)
		{
			for (int j = 0; j < this->row; ++j)
			{
				if (abs(this->dataPtr[i][j] - m.dataPtr[i][j]) > 1E-8)
				{
					return true;
				}
			}
		}
		return false;
	}

	T* operator[](int index) const
	{
		if (index >= this->row || index < 0)
		{
			throw;
		}
		return this->dataPtr[index];
	}

private:
	int row;				//row count of the matrix
	int col;				//col count of the matrix
	T** dataPtr;			//the start fo Array array
};

void test01()
{
	//利用数组准备数据
	double matrixArr[] = { 1, 3, 4, 6, 8, -2, 1, 4, 3 };
	double vectorArr[] = { 13, 32, 14 };

	//创建3x3矩阵A
	Matrix<double> A(3, 3, matrixArr, 9);

	//创建3维向量B
	Vector<double> B(3, vectorArr);

	////建立增广矩阵
	//Matrix<double> M = A.CreateAugmentedMatrix(B);
	////对矩阵进行高斯变换
	//M.GaussianElimination();
	////提取增广矩阵的最后一列作为解
	//Vector<double> result = M.GetColData(M.GetCol() - 1);

	//输出矩阵的解
	cout << "方程的三个解为：" << A.GetSolutionResult(B) << endl;

	//double arr[] = { 5,4,3,2,1,5,4,3,2,1,5,4,3,2,1,5 };
	//Matrix<double> m(4, 4, arr, 16);
	//Matrix<double> r = m.GetInvMatrix();
	//for (int i = 0; i < 4; ++i)
	//{
	//	for (int j = 0; j < 4; ++j)
	//	{
	//		cout << r[i][j] << "  ";
	//	}
	//	cout << endl;
	//}

	//double arr[] = { 1,2,0,3,1,-2,4,3,-1 };
	//Matrix<double> m(3, 3, arr, 9);
	//Matrix<double> r = m.GetAdjugateMatrix();
}

template<typename T>
void test02()
{
	int num = 0;
	cout << "请输入矩阵行数：" << endl;
	cin >> num;
	Matrix<T> m(num, num);
	cin >> m;
	cout << m << endl;
	cout << "行数：" << m.GetRow() << "，列数：" << m.GetCol() << "，元素个数：" << m.GetSize() << "，迹：" << m.Trace() << endl;
	cout << "转置：" << endl << m.GetTurn();
	cout << "逆矩阵：" << endl << m.GetInvMatrix();
	cout << "伴随矩阵：" << endl << m.GetAdjugateMatrix();
	cout << "m^2：" << endl << m.GetPowerMatrix(2);
	cout << "m^3：" << endl << m.GetPowerMatrix(3);
	cout << "m^4：" << endl << m.GetPowerMatrix(4);
	cout << "秩：" << m.GetRank() << endl;
	cout << "上三角形式：" << endl << m.GetUpperTriangleMatrix();
	cout << "行列式：" << m.Determinant() << endl;
}

void test03()
{
	int k = 3;
	double XArr[] = { 1.7, 1.5, 0.2, 1.1, 2.9, 5.6, 5.8, 8, 2.3, 2.3, 7.8, 4.1, 11.4, 0.8, 24, 2.5, 4.6, 8.8, 6.1, 4, 4, 4, 14, 1.9, 10.4, 3.3, 9.6, 5.4, 2.8, 12.6, 4.9, 5.4, 5.7, 4.7, 1.4, 7.2, 6.2, 13.8, 7.1, 8, 2.2, 20.3, 0.7, 13.2, 11.1, 54.6, 9.1, 2.6, 1.2, 5, 0.54, 3.3, 8.9, 79.3, 16.5, 5, 7.5, 26.2, 20, 2.6, 8.8, 22.5 };
	double YArr[] = { 4.2, 5.6, 6.5, 4.9, 3.1, 6.4, 4.6, 2.5, 6.8, 3.5, 2.2, 5.8, 5, 6.3, 1.4, 6.7, 3.5, 4.4, 3.7, 3, 3.7, 3.36, 3.7, 4.3, 3.9, 5.05, 12, 4.6, 4.09, 3.2, 6.68, 4.5, 6.1, 4.9, 5.7, 6.9, 3.4, 4, 5.3, 2.8, 4, 3.6, 8.3, 2.4, 3.9, 1.6, 6.63, 4.9, 4.8, 6.4, 4.2, 3.9, 2.37, 0.4, 3.3, 3.3, 1.7, 1.3, 1.68, 5.24, 5, 1.6 };

	int n = sizeof(XArr) / sizeof(double);

	Matrix<double> Y(n, 1, YArr, n);
	Matrix<double> M(n, k + 1);

	for (int row = 0; row < n; row++)
	{
		double val = 1;
		for (int col = k; col >= 0; col--)
		{
			M[row][col] = val;
			val *= XArr[row];
		}
	}

	Matrix<double> A = (M.GetTurn() * M).GetInvMatrix() * M.GetTurn() * Y;

	cout << "A=" << endl;

	cout << A << endl;
}


int main()
{
	//test01();

	test02<double>();

	//test03();

	//Complex c = 2 + 3i;
	//cout << c << endl;

	//int n = 1000;
	//Matrix<double> m(n, n, Create::FullRank);
	//cout << (Matrix<double>(n) - m).GetInvMatrix() * (Matrix<double>(n) - m.GetPowerMatrix(2)) * m.GetInvMatrix() << endl;

	//Array<int> a(5);
	//a.pushBack(1);
	//a.pushBack(3);
	//a.pushBack(7);
	//a.pushBack(9);
	//a.pushBack(11);
	//for (Array<int>::Iter it = a.begin(); it != a.end(); ++it)
	//{
	//	cout << *it << "\t";
	//}


	//Matrix<Fraction> m(5, Create::Magic);
	//cout << m << endl;
	//cout << m.GetInvMatrix() << endl;

	//Matrix<int> m(4000, Magic);
	//cout << m.IsMagic() << endl;





	system("pause");

	return 0;
}
