#include<iostream>
using namespace std;
#include<cmath>
#include<string>
#include<fstream>

template<class T>
class Stack
{
public:
	Stack<T>(int num = 20)
	{
		this->capacity = num;
		this->size = 0;
		this->data = new T[num]{ 0 };
	}

	Stack<T>(const Stack<T>& s)
	{
		this->capacity = s.capacity;
		this->size = s.size;
		this->data = new T[s.capacity]{ 0 };
		for (int i = 0; i < s.size; ++i)
		{
			this->data[i] = s.data[i];
		}
	}

	~Stack()
	{
		if (this->data != NULL)
		{
			delete[]this->data;
			this->data = NULL;
		}
	}

	void expand(int num = 10)
	{
		this->capacity += num;
		T* temp = this->data;
		this->data = new T[this->capacity]{ 0 };
		for (int i = 0; i < this->size; ++i)
		{
			this->data[i] = temp[i];
		}
		delete[]temp;
	}

	int GetSize()
	{
		return this->size;
	}

	int GetCapacity()
	{
		return this->capacity;
	}

	void push(const T& ele)
	{
		if (this->size >= this->capacity)
		{
			this->expand();
		}
		this->data[this->size] = ele;
		++this->size;
	}

	T pop()
	{
		if (this->size == 0)
		{
			throw;
		}
		--this->size;
		return this->data[this->size];
	}

	T at(int pos)
	{
		if (pos >= this->size)
		{
			throw;
		}
		return this->data[pos];
	}

	void clear()
	{
		this->size = 0;
	}

private:
	T* data;
	int size;
	int capacity;
};

class Transnum
{
public:
	Transnum(int num = 0)
	{
		this->num = num;
		this->sign = num > 0 ? 1 : (num == 0 ? 0 : -1);
	}

	Stack<int>& Trans(int n)
	{
		int temp = this->num;
		while (temp != 0)
		{
			this->s.push(temp % n);
			temp /= n;
		}
		return this->s;
	}

private:
	int sign;
	int num;
	Stack<int> s;
};

int main()
{
	Transnum num(100);
	Stack<int> s = num.Trans(16);
	while (s.GetSize() > 0)
	{
		cout << (s.pop()) << "  ";
	}

	cout << endl;


	system("pause");

	return 0;
}

//ofstream ofs;
//class transnum
//{
//public:
//	transnum(int n, int num)
//	{
//		this->m_Sign = num > 0 ? 1 : (num < 0 ? -1 : 0);
//		this->m_Number = abs(num);
//		this->m_N = n;
//		this->m_Digit = int(log(this->m_Number) / log(this->m_N)) + 1;
//		for (int i = 0; i < this->m_Digit; i++)
//		{
//			this->m_Retarr[i] = 0;
//		}
//		cout << "将" << num << "转换为" << n << "进制数的结果为：" << endl;
//		ofs << "将" << num << "转换为" << n << "进制数的结果为：" << endl;
//	}
//
//	transnum(const transnum& t)
//	{
//		this->m_N = t.m_N;
//		this->m_Number = t.m_Number;
//		this->m_Sign = t.m_Sign;
//		this->m_Digit = t.m_Digit;
//		for (int i = 0; i < this->m_Digit; i++)
//		{
//			this->m_Retarr[i] = t.m_Retarr[i];
//		}
//	}
//
//	~transnum()
//	{
//		string numSeed[] = { "A","B","C","D","E","F","G","H","I","J","K","L","M","N","O","P","Q","R","S","T","U","V","W","X","Y","Z" };
//		if (this->m_Number != 0)
//		{
//			this->m_Sign == -1 ? cout << "-" : cout << "";
//			this->m_Sign == -1 ? ofs << "-" : ofs << "";
//			for (int i = 0; i < this->m_Digit; i++)
//			{
//				if (this->m_Retarr[i] > 9)
//				{
//					cout << numSeed[this->m_Retarr[i] - 10];
//					ofs << numSeed[this->m_Retarr[i] - 10];
//				}
//				else
//				{
//					cout << this->m_Retarr[i];
//					ofs << this->m_Retarr[i];
//				}
//			}
//			cout << endl;
//			ofs << endl;
//		}
//		else
//		{
//			cout << 0 << endl;
//			ofs << 0 << endl;
//		}
//	}
//
//	void doTransWork()
//	{
//		int tempnumber = this->m_Number;
//		for (int i = 1; i <= this->m_Digit; i++)
//		{
//			int power = pow(this->m_N, this->m_Digit - i);
//			for (int j = 1; j <= this->m_N; j++)
//			{
//				tempnumber -= power;
//				if (tempnumber < 0)
//				{
//					this->m_Retarr[i - 1] = j - 1;
//					tempnumber += power;
//					break;
//				}
//
//				else if (tempnumber == 0)
//				{
//					this->m_Retarr[i - 1] = j;
//					break;
//				}
//			}
//		}
//	}
//
//
//	int m_Number;
//	int m_N;
//	int m_Sign;
//	int m_Digit;
//	int m_Retarr[200];
//};
//
//void test01()
//{
//	int num = 0;
//	int n = 0;
//	cout << "请输入一个整数：" << endl;
//	ofs << "请输入一个整数：" << endl;
//	cin >> num;
//	ofs << num << endl;
//	cout << "将其转换为进制：" << endl;
//	ofs << "将其转换为进制：" << endl;
//	cin >> n;
//	ofs << n << endl;
//
//	transnum T(n, num);
//	T.doTransWork();
//}
//
//
//int main()
//{
//	ofs.open("结果.txt", ios::out);
//
//	cout << "Work1" << endl;
//	ofs << "Work1" << endl;
//
//	while (1)
//	{
//		test01();
//
//		int check = 0;
//		cout << "1---continue" << endl;
//		cout << "0---break" << endl;
//		ofs << "1---continue" << endl;
//		ofs << "0---break" << endl;
//		cin >> check;
//		ofs << check << endl;
//		if (check == 0)
//		{
//			break;
//		}
//	}
//
//	ofs << endl;
//	ofs.close();
//
//	system("pause");
//
//	return 0;
//}