#include <iostream>
#include <windows.h>
#include <stdio.h>
#include <conio.h>
using namespace std;


void gotoxy(int x, int y)
{
	COORD pos = { x, y };
	HANDLE hOut = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleCursorPosition(hOut, pos);
}

void setColor(int backColor, int foreColor)
{
	HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(h, BACKGROUND_INTENSITY | backColor * 16 | FOREGROUND_INTENSITY | foreColor);
}

struct Point
{
	int x;
	int y;
};

class Snack
{
public:
	Snack(int maxWidth, int maxHeight, int initLength)
	{
		this->SnackLength = initLength;
		this->SnackMoveDirection = 1;
		SnackData = new Point[maxWidth * maxHeight];
		int randx = rand() % (maxWidth - SnackLength - 2);
		int randy = rand() % (maxHeight - 2);
		for (int i = 0; i < SnackLength; i++)
		{
			SnackData[i].x = randx + i;
			SnackData[i].y = randy;
		}
		this->SnackHead = SnackData[SnackLength - 1];
	}

	~Snack()
	{
		delete[]SnackData;
	}

	int getSnackLength()
	{
		return this->SnackLength;
	}

	int getSnackMoveDirection()
	{
		return this->SnackMoveDirection;
	}

	Point getSnackHead()
	{
		return SnackHead;
	}

	Point getSnackData(int l)
	{
		return SnackData[l];
	}

	void ModifySnackData(int x, int y, int l)
	{
		SnackData[l].x = x;
		SnackData[l].y = y;
	}

	void ModifySnackHead(int x, int y)
	{
		SnackHead.x = x;
		SnackHead.y = y;
		SnackData[SnackLength - 1].x = x;
		SnackData[SnackLength - 1].y = y;
	}

	void ModifySnackMoveDirection(int d)
	{
		SnackMoveDirection = d;
	}

	void IncreaseSnackLength()
	{
		this->SnackLength++;
	}

private:
	int SnackLength;
	int SnackMoveDirection;
	Point SnackHead;
	Point* SnackData;
};

class Game
{
public:
	Game(int width, int height, int applenum) :m_snack(width, height, 3)
	{
		this->width = width;
		this->height = height;
		this->appleNum = applenum;
		data = new int[width * height] {0};
		lastData = new int[width * height] {0};
		appleArr = new Point[applenum];
	}

	void SetBlock(int x, int y, int val)
	{
		this->data[y * this->width + x] = val;
	}

	int GetBlock(int x, int y)
	{
		return data[y * this->width + x];
	}

	~Game()
	{
		delete[] data;
		delete[] lastData;
	}

	void DrawFrame()
	{
		gotoxy(0, 0);
		cout << "¨X ";
		for (int x = 0; x < width; ++x)
		{
			cout << "¨T ";
		}
		cout << "¨[ ";
		for (int y = 0; y < height; ++y)
		{
			gotoxy(0, y + 1);
			cout << "¨U ";
			gotoxy(width * 2 + 2, y + 1);
			cout << "¨U ";
		}
		gotoxy(0, height + 1);
		cout << "¨^ ";
		for (int x = 0; x < width; ++x)
		{
			cout << "¨T ";
		}
		cout << "¨a ";
	}

	void DrawBlocks()
	{
		for (int y = 0; y < height; ++y)
		{
			for (int x = 0; x < width; ++x)
			{
				int id = y * width + x;
				if (data[id] != lastData[id])
				{
					gotoxy(x * 2 + 2, y + 1);
					switch (data[id])
					{
					case 0:
					{
						cout << "¡¡";
						break;
					}
					case 1:
					{
						cout << "¡ö";
						break;
					}
					case 2:
					{
						cout << "¡õ";
						break;
					}
					case 3:
					{
						cout << "¡ï";
					}
					}
					lastData[id] = data[id];
				}
			}
		}
		gotoxy(0, height + 2);
	}

	void DrawSnack()
	{
		for (int i = 0; i < this->m_snack.getSnackLength() - 1; i++)
		{
			SetBlock(this->m_snack.getSnackData(i).x, this->m_snack.getSnackData(i).y, 1);
		}
		SetBlock(this->m_snack.getSnackHead().x, this->m_snack.getSnackHead().y, 2);
	}

	void CreateNewApples()
	{
		int temp = this->appleNum;
		for (int i = 0; i < temp; i++)
		{
			while (1)
			{
				int x = rand() % width;
				int y = rand() % height;
				if (data[y * width + x] == 0)
				{
					this->appleArr[i].x = x;
					this->appleArr[i].y = y;
					SetBlock(x, y, 3);
					break;
				}
			}
		}
	}

	void ModifyDataWhenMovingForward()
	{
		int snacklength = this->m_snack.getSnackLength();
		for (int i = 0; i < snacklength - 1; ++i)
		{
			this->m_snack.ModifySnackData(this->m_snack.getSnackData(i + 1).x, this->m_snack.getSnackData(i + 1).y, i);
		}
	}

	void MoveForward()
	{
		int snackmovedirection = this->m_snack.getSnackMoveDirection();
		int tempx = this->m_snack.getSnackData(0).x;
		int tempy = this->m_snack.getSnackData(0).y;
		switch (snackmovedirection)
		{
		case 0:
			ModifyDataWhenMovingForward();
			this->m_snack.ModifySnackHead(this->m_snack.getSnackHead().x - 1, this->m_snack.getSnackHead().y);
			if (this->m_snack.getSnackHead().x < 0 || data[this->m_snack.getSnackHead().y * width + this->m_snack.getSnackHead().x] == 1)
			{
				cout << "score:" << this->m_snack.getSnackLength() << endl;
				cout << "Game Over!" << endl;
				system("pause");
				exit(0);
			}
			this->SetBlock(tempx, tempy, 0);
			break;

		case 1:
			ModifyDataWhenMovingForward();
			this->m_snack.ModifySnackHead(this->m_snack.getSnackHead().x + 1, this->m_snack.getSnackHead().y);
			if (this->m_snack.getSnackHead().x >= width || data[this->m_snack.getSnackHead().y * width + this->m_snack.getSnackHead().x] == 1)
			{
				cout << "score:" << this->m_snack.getSnackLength() << endl;
				cout << "Game Over!" << endl;
				system("pause");
				exit(0);
			}
			this->SetBlock(tempx, tempy, 0);
			break;

		case 2:
			ModifyDataWhenMovingForward();
			this->m_snack.ModifySnackHead(this->m_snack.getSnackHead().x, this->m_snack.getSnackHead().y - 1);
			if (this->m_snack.getSnackHead().y < 0 || data[this->m_snack.getSnackHead().y * width + this->m_snack.getSnackHead().x] == 1)
			{
				cout << "score:" << this->m_snack.getSnackLength() << endl;
				cout << "Game Over!" << endl;
				system("pause");
				exit(0);
			}
			this->SetBlock(tempx, tempy, 0);
			break;

		case 3:
			ModifyDataWhenMovingForward();
			this->m_snack.ModifySnackHead(this->m_snack.getSnackHead().x, this->m_snack.getSnackHead().y + 1);
			if (this->m_snack.getSnackHead().y >= height || data[this->m_snack.getSnackHead().y * width + this->m_snack.getSnackHead().x] == 1)
			{
				cout << "score:" << this->m_snack.getSnackLength() << endl;
				cout << "Game Over!" << endl;
				system("pause");
				exit(0);
			}
			this->SetBlock(tempx, tempy, 0);
			break;

		default:
			exit(0);
		}
	}

	void ChangeSnackDirection(int select)
	{
		this->m_snack.ModifySnackMoveDirection(select);
	}

	void IncreaseSnack()
	{
		switch (this->m_snack.getSnackMoveDirection())
		{
		case 0:
			this->m_snack.ModifySnackHead(this->m_snack.getSnackData(this->m_snack.getSnackLength() - 2).x - 1, this->m_snack.getSnackData(this->m_snack.getSnackLength() - 2).y);
			break;

		case 1:
			this->m_snack.ModifySnackHead(this->m_snack.getSnackData(this->m_snack.getSnackLength() - 2).x + 1, this->m_snack.getSnackData(this->m_snack.getSnackLength() - 2).y);
			break;

		case 2:
			this->m_snack.ModifySnackHead(this->m_snack.getSnackData(this->m_snack.getSnackLength() - 2).x, this->m_snack.getSnackData(this->m_snack.getSnackLength() - 2).y - 1);
			break;

		case 3:
			this->m_snack.ModifySnackHead(this->m_snack.getSnackData(this->m_snack.getSnackLength() - 2).x, this->m_snack.getSnackData(this->m_snack.getSnackLength() - 2).y + 1);
			break;

		default:
			break;
		}
	}

	void CheckIfIncreaseSnackLength()
	{
		for (int i = 0; i < this->appleNum; i++)
		{
			if (this->m_snack.getSnackHead().x == this->appleArr[i].x && this->m_snack.getSnackHead().y == this->appleArr[i].y)
			{
				this->m_snack.IncreaseSnackLength();
				this->appleArr[i].x = -1;
				this->appleArr[i].y = -1;
				IncreaseSnack();
				while (width * height - this->m_snack.getSnackLength() - 10)
				{
					int x = rand() % width;
					int y = rand() % height;
					if (data[y * width + x] == 0)
					{
						this->appleArr[i].x = x;
						this->appleArr[i].y = y;
						SetBlock(x, y, 3);
						break;
					}
				}
			}
		}
	}

public:
	void Run()
	{
		DrawFrame();
		DrawSnack();
		DrawBlocks();
		CreateNewApples();

		int lastCh = 0;
		long long t1 = ::GetTickCount64();
		while (1)
		{
			if (_kbhit())
			{
				int ch = _getch();

				if (lastCh == 224 && ch == 72)//U
				{
					ChangeSnackDirection(2);
				}
				if (lastCh == 224 && ch == 80)//D
				{
					ChangeSnackDirection(3);
				}
				if (lastCh == 224 && ch == 75)//L
				{
					ChangeSnackDirection(0);
				}
				if (lastCh == 224 && ch == 77)//R
				{
					ChangeSnackDirection(1);
				}
				lastCh = ch;
			}
			Sleep(1);
			long long t2 = ::GetTickCount64();
			if (t2 - t1 >= 500)
			{
				MoveForward();
				t1 = t2;
			}
			DrawSnack();
			DrawBlocks();
			CheckIfIncreaseSnackLength();
		}
		gotoxy(0, height + 2);
	}

private:
	int width;
	int height;
	int* data;
	int* lastData;
	Snack m_snack;
	Point* appleArr;
	int appleNum;
};


int main()
{
	srand(time(0));
	Game g(50, 30, 120);
	g.Run();
	return 0;
}