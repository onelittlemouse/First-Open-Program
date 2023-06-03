#include <iostream>
using namespace std;

#include<string>

class Clock
{
public:
	Clock()
	{
		this->m_Time = 0;
		this->m_Sound = "kun曲";
		cout << "请开始设置闹钟：" << endl;
	}
	
	Clock(const Clock& c)
	{
		this->m_Time = c.m_Time;
		this->m_Sound = c.m_Sound;
		if (m_Time != 0)
		{
			cout << "已拷贝此闹钟,明天将再次响起" << endl;
		}
	}
	
	~Clock()
	{
		if (judge)
		{
			retime == 1 ? cout << this->m_Time << "分钟后，" << this->m_Sound << "已响起" << endl : cout << "第二天，" << this->m_Sound << "再次响起" << endl;
			if (retime == 0||judge == 2)
			{
				cout << "此闹钟已停止运行" << endl;
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
	string soundarr[] = { "鸡叫","狗叫","猫叫","坤曲","干嘛" };
	string sound;
	cout << "请选择闹钟声音：" << endl;
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
	cout << "请设置闹钟运行时间：" << endl;
	cin >> time;
	c1.setTime(time);

	showSound(c1);

	cout << "你设置的闹钟将在" << c1.getTime() << "分钟后响起，铃声为" << c1.getSound() << endl;

	int repeat = 0;
	cout << "1---明天重复此闹钟" << endl;
	cout << "0---不再重复此闹钟" << endl;
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