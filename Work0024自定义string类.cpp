#include <iostream>
using namespace std;
#include<string>
#include<cmath>

/*
string���Һ��滻
����������
���ң�����ָ���ַ����Ƿ����
�滻����ָ����λ���滻�ַ���
����ԭ�ͣ�
int find(const string& str, int pos = 0) const;          //����str��һ�γ���λ��,��pos��ʼ����
int find(const char* s, int pos = 0) const;              //����s��һ�γ���λ��,��pos��ʼ����
int find(const char* s, int pos, int n) const;           //��posλ�ò���s��ǰn���ַ���һ��λ��
int find(const char c, int pos = 0) const;               //�����ַ�c��һ�γ���λ��
int rfind(const string& str, int pos = npos) const;      //����str���һ��λ��,��pos��ʼ����
int rfind(const char* s, int pos = npos) const;          //����s���һ�γ���λ��,��pos��ʼ����
int rfind(const char* s, int pos, int n) const;          //��pos����s��ǰn���ַ����һ��λ��
int rfind(const char c, int pos = 0) const;              //�����ַ�c���һ�γ���λ��
string& replace(int pos, int n, const string& str);      //�滻��pos��ʼn���ַ�Ϊ�ַ���str
string& replace(int pos, int n, const char* s);          //�滻��pos��ʼ��n���ַ�Ϊ�ַ���s
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
			cout << "�滻ʧ��" << endl;
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
	case 0:return "��";
	case 1:return "һ";
	case 2:return "��";
	case 3:return "��";
	case 4:return "��";
	case 5:return "��";
	case 6:return "��";
	case 7:return "��";
	case 8:return "��";
	case 9:return "��";
	default:break;
	}
}

String GetCExpression(int i, int j)
{
	int x = i * j;
	String s = GetCC(i) + GetCC(j);
	if (x < 10)s += "��" + GetCC(x) + "  ";
	else
	{
		s += GetCC(x / 10) + "ʮ";
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
	cout << "����ǰ��" << s1 << "  " << s2 << endl;
	ReplaceTwoString(s1, s2);
	cout << "������" << s1 << "  " << s2 << endl;

	//string str1 = "abcdefgde";
	//str1.replace(1, 3, "1111");
	//cout << "str1 = " << str1 << endl;

	String str1("abcdefgde");
	str1.Myreplace(1, 3, "1111");
	cout << "str1 = " << str1 << endl;




	system("pause");

	return 0;
}