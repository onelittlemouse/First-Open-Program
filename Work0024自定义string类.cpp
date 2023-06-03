#include <iostream>
using namespace std;
#include<string>
#include<cmath>

/*
string查找和替换
功能描述：
查找：查找指定字符串是否存在
替换：在指定的位置替换字符串
函数原型：
int find(const string& str, int pos = 0) const;          //查找str第一次出现位置,从pos开始查找
int find(const char* s, int pos = 0) const;              //查找s第一次出现位置,从pos开始查找
int find(const char* s, int pos, int n) const;           //从pos位置查找s的前n个字符第一次位置
int find(const char c, int pos = 0) const;               //查找字符c第一次出现位置
int rfind(const string& str, int pos = npos) const;      //查找str最后一次位置,从pos开始查找
int rfind(const char* s, int pos = npos) const;          //查找s最后一次出现位置,从pos开始查找
int rfind(const char* s, int pos, int n) const;          //从pos查找s的前n个字符最后一次位置
int rfind(const char c, int pos = 0) const;              //查找字符c最后一次出现位置
string& replace(int pos, int n, const string& str);      //替换从pos开始n个字符为字符串str
string& replace(int pos, int n, const char* s);          //替换从pos开始的n个字符为字符串s
*/

class String
{
	friend ostream& operator<<(ostream& cout, const String& s);

	int capacity = 3;
	char* str = new char[capacity] {0};
	int length = 0;

	int GetLength(const char* s)
	{
		int i = 0;
		for (; s[i]; ++i);
		return i;
	}

	void CopyString(char* target, const char* source)
	{
		while (*(target++) = *(source++));
	}

	const char* GetString() const
	{
		return str;
	}

public:
	String(const char* s)
	{
		this->length = GetLength(s);
		CheckLength(this->length);
		CopyString(this->str, s);
	}

	String(const String& s)
	{
		this->capacity = s.capacity;
		this->length = s.length;
		this->str = new char[this->capacity] {0};
		char* source = s.str;
		char* target = this->str;
		this->CopyString(target, source);
	}

	~String()
	{
		delete[]str;
	}

	void CheckLength(int lengthNeeded)
	{
		if (lengthNeeded >= capacity)
		{
			while (lengthNeeded >= capacity)
			{
				capacity *= 2;
			}

			char* newStr = new char[capacity] {0};

			char* source = str;
			char* target = newStr;
			CopyString(target, source);
			delete[]str;
			str = newStr;
		}
	}

	String operator+=(const String& s2)
	{
		int newLength = this->length + s2.length;
		CheckLength(newLength);

		CopyString(this->str + this->length, s2.str);
		this->length = newLength;
		return *this;
	}

	String& operator=(const String& s)
	{
		this->capacity = s.capacity;
		this->length = s.length;
		this->str = new char[this->capacity] {0};
		char* source = s.str;
		char* target = this->str;
		this->CopyString(target, source);
		return *this;
	}

	String& Myreplace(int pos, int n, const String& str)
	{
		if (n > this->length - pos)
		{
			cout << "替换失败" << endl;
		}
		else
		{
			CheckLength(this->length + str.length - n);
			this->length += str.length - n;
			if (str.length == n)
			{
				for (int i = pos; i < pos + str.length; ++i)
				{
					this->str[i] = str.str[i - pos];
				}
			}
			if (str.length > n)
			{
				for (int i = this->length + str.length - n - 1; i >= str.length + pos; --i)
				{
					this->str[i] = this->str[i - str.length + n];
				}
				for (int i = pos; i < pos + str.length; ++i)
				{
					this->str[i] = str.str[i - pos];
				}
			}
			if (str.length < n)
			{
				for (int i = pos; i < pos + str.length; ++i)
				{
					this->str[i] = str.str[i - pos];
				}
				for (int i = pos + n; i <= this->length; ++i)
				{
					this->str[i - 1] = this->str[i];
				}
				this->str[length] = '\0';
			}
		}
		return *this;
	}

};

String operator+(const String& s1, const String& s2)
{
	String s = s1;
	s += s2;
	return s;
}

ostream& operator<<(ostream& cout, const String& s)
{
	return cout << s.GetString();
}

String GetCC(int n)
{
	switch (n)
	{
	case 0:return "〇";
	case 1:return "一";
	case 2:return "二";
	case 3:return "三";
	case 4:return "四";
	case 5:return "五";
	case 6:return "六";
	case 7:return "七";
	case 8:return "八";
	case 9:return "九";
	default:break;
	}
}

String GetCExpression(int i, int j)
{
	int x = i * j;
	String s = GetCC(i) + GetCC(j);
	if (x < 10)s += "得" + GetCC(x) + "  ";
	else
	{
		s += GetCC(x / 10) + "十";
		if (x % 10)
		{
			s += GetCC(x % 10);
		}
		else
		{
			s += "  ";
		}
	}
	return s;
}

void ReplaceTwoString(String& s1, String& s2)
{
	String temp = s1;
	s1 = s2;
	s2 = temp;
}


int main()
{
	for (int i = 1; i <= 9; ++i)
	{
		for (int j = 1; j <= i; ++j)
		{
			cout << GetCExpression(j, i) << "   ";
		}
		cout << endl;
	}
	cout << endl;

	String s1("ABC");
	String s2("DE");
	cout << "交换前：" << s1 << "  " << s2 << endl;
	ReplaceTwoString(s1, s2);
	cout << "交换后：" << s1 << "  " << s2 << endl;

	//string str1 = "abcdefgde";
	//str1.replace(1, 3, "1111");
	//cout << "str1 = " << str1 << endl;

	String str1("abcdefgde");
	str1.Myreplace(1, 3, "1111");
	cout << "str1 = " << str1 << endl;




	system("pause");

	return 0;
}