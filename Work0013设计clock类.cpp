#include <iostream>
using namespace std;

#include<string>

class Clock
{
public:
	Clock()
	{
		this->m_Time = 0;
		this->m_Sound = "kun��";
		cout << "�뿪ʼ�������ӣ�" << endl;
	}
	
	Clock(const Clock& c)
	{
		this->m_Time = c.m_Time;
		this->m_Sound = c.m_Sound;
		if (m_Time != 0)
		{
			cout << "�ѿ���������,���콫�ٴ�����" << endl;
		}
	}
	
	~Clock()
	{
		if (judge)
		{
			retime == 1 ? cout << this->m_Time << "���Ӻ�" << this->m_Sound << "������" << endl : cout << "�ڶ��죬" << this->m_Sound << "�ٴ�����" << endl;
			if (retime == 0||judge == 2)
			{
				cout << "��������ֹͣ����" << endl;
			}
		}
	}

	void setTime(int time)
	{
		this->m_Time = time;
	}

	int getTime()
	{
		return this->m_Time;
	}

	void setSound(string sound)
	{
		this->m_Sound = sound;
	}

	string getSound()
	{
		return this->m_Sound;
	}

	int retime = 0;
	int judge = 1;

private:
	int m_Time;
	string m_Sound;
};

void showSound(Clock& c1)
{
	string soundarr[] = { "����","����","è��","����","����" };
	string sound;
	cout << "��ѡ������������" << endl;
	cout << "********************" << endl;
	for (int i = 0; i < sizeof(soundarr) / sizeof(soundarr[0]); i++)
	{
		cout << "***** " << i + 1 << "---" << soundarr[i] << " *****" << endl;
	}
	cout << "********************" << endl;
	int s = 0;
	cin >> s;
	c1.setSound(soundarr[s - 1]);
}

void setClock(Clock c1)
{

	int time = 0;
	cout << "��������������ʱ�䣺" << endl;
	cin >> time;
	c1.setTime(time);

	showSound(c1);

	cout << "�����õ����ӽ���" << c1.getTime() << "���Ӻ���������Ϊ" << c1.getSound() << endl;

	int repeat = 0;
	cout << "1---�����ظ�������" << endl;
	cout << "0---�����ظ�������" << endl;
	cin >> repeat;
	if (repeat)
	{
		Clock c2(c1);
		c2.retime = 1;
	}
	else
	{
		c1.retime = 1;
		c1.judge = 2;
	}
}


int main()
{
	Clock c;
	c.judge = 0;

	setClock(c);


	system("pause");

	return 0;
}