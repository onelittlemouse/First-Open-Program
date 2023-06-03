#include<iostream>
#include<windows.h>
#include<stdio.h>
#include<conio.h>
#include<ctime>
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

class Game
{
private:
	int cursorX = 0;
	int cursorY = 0;
	int playerIndex = 0;
	int data[3][3] = { 0 };

	int select()
	{
		int choice = 0;
		cout << "ÇëÑ¡ÔñÄ£Ê½£º" << endl;
		cout << "1---Person To Person" << endl;
		cout << "2---Person To Computer" << endl;
		cout << "3---Computor To Person" << endl;
		cin >> choice;
		system("cls");
		return choice;
	}

	void Draw()
	{
		gotoxy(0, 0);
		setColor(4, 10);
		//cout <<"©³©×©·©Ç©ï©Ï©»©ß©¿©¤©¤©§©¥¨s¨r¨q¨t©À©°©°©Ð©´©À©à©È©¸©Ø©¼¨q¨r©¤©¦¨w¨v¨u¨v¨Z¨[¨v¨v¨v¨v¨u¨u¨u¨u"
		cout << "©° ©¤ ©¤ ©¤ ©Ð ©¤ ©¤ ©¤ ©Ð ©¤ ©¤ ©¤ ©´ " << endl;
		cout << "©¦ ¡¡¡¡¡¡©¦ ¡¡¡¡¡¡©¦ ¡¡¡¡¡¡©¦ " << endl;
		cout << "©¦ ¡¡¡¡¡¡©¦ ¡¡¡¡¡¡©¦ ¡¡¡¡¡¡©¦ " << endl;
		cout << "©¦ ¡¡¡¡¡¡©¦ ¡¡¡¡¡¡©¦ ¡¡¡¡¡¡©¦ " << endl;
		cout << "©À ©¤ ©¤ ©¤ ©à ©¤ ©¤ ©¤ ©à ©¤ ©¤ ©¤ ©È " << endl;
		cout << "©¦ ¡¡¡¡¡¡©¦ ¡¡¡¡¡¡©¦ ¡¡¡¡¡¡©¦ " << endl;
		cout << "©¦ ¡¡¡¡¡¡©¦ ¡¡¡¡¡¡©¦ ¡¡¡¡¡¡©¦ " << endl;
		cout << "©¦ ¡¡¡¡¡¡©¦ ¡¡¡¡¡¡©¦ ¡¡¡¡¡¡©¦ " << endl;
		cout << "©À ©¤ ©¤ ©¤ ©à ©¤ ©¤ ©¤ ©à ©¤ ©¤ ©¤ ©È " << endl;
		cout << "©¦ ¡¡¡¡¡¡©¦ ¡¡¡¡¡¡©¦ ¡¡¡¡¡¡©¦ " << endl;
		cout << "©¦ ¡¡¡¡¡¡©¦ ¡¡¡¡¡¡©¦ ¡¡¡¡¡¡©¦ " << endl;
		cout << "©¦¡¡ ¡¡¡¡©¦ ¡¡¡¡¡¡©¦ ¡¡¡¡¡¡©¦ " << endl;
		cout << "©¸ ©¤ ©¤ ©¤ ©Ø ©¤ ©¤ ©¤ ©Ø ©¤ ©¤ ©¤ ©¼ " << endl;
	}

	bool isFull()
	{
		for (int i = 0; i < 3; i++)
		{
			for (int j = 0; j < 3; j++)
			{
				if (data[i][j] == 0)
				{
					return false;
				}
			}
		}
		gotoxy(0, 15);
		return true;
	}

	bool check()
	{
		for (int i = 0; i < 3; i++)
		{
			if (data[0][i] == data[1][i] && data[0][i] == data[2][i] && data[0][i] != 0)
			{
				gotoxy(0, 15);
				data[0][i] == -1 ? cout << "¡Á" : cout << "¡ð";
				cout << " win the game!" << endl;
				return true;
			}
			else if (data[i][0] == data[i][1] && data[i][0] == data[i][2] && data[i][0] != 0)
			{
				gotoxy(0, 15);
				data[i][0] == -1 ? cout << "¡Á" : cout << "¡ð";
				cout << " win the game!" << endl;
				return true;
			}
		}
		if (data[0][0] == data[1][1] && data[0][0] == data[2][2] && data[0][0] != 0)
		{
			gotoxy(0, 15);
			data[0][0] == -1 ? cout << "¡Á" : cout << "¡ð";
			cout << " win the game!" << endl;
			return true;
		}
		else if (data[0][2] == data[1][1] && data[0][2] == data[2][0] && data[0][2] != 0)
		{
			gotoxy(0, 15);
			data[0][2] == -1 ? cout << "¡Á" : cout << "¡ð";
			cout << " win the game!" << endl;
			return true;
		}
		return false;
	}

	int judgeGame()
	{
		if (check())
		{
			return 1;
		}
		else if (isFull())
		{
			return 0;
		}
		else
		{
			return -1;
		}
	}

	void checkOperationIsCorrect(int* x, int* y)
	{
		if (*x < 0)
		{
			*x = 0;
		}
		if (*x > 2)
		{
			*x = 2;
		}
		if (*y < 0)
		{
			*y = 0;
		}
		if (*y > 2)
		{
			*y = 2;
		}
	}

	bool Player_0()
	{
		if (data[cursorY][cursorX] == 0)
		{
			gotoxy(cursorX * 8 + 2, cursorY * 4 + 1);
			cout << "¨v ¡¡¨u";
			gotoxy(cursorX * 8 + 2, cursorY * 4 + 2);
			cout << "¡¡¨w ¡¡";
			gotoxy(cursorX * 8 + 2, cursorY * 4 + 3);
			cout << "¨u ¡¡¨v";
			data[cursorY][cursorX] = -1;
			playerIndex = 1;

			int judge = judgeGame();
			if (judge >= 0)
			{
				if (judge == 0)
				{
					cout << "Draw!" << endl;
				}
				cout << "Game completed!" << endl;
				exit(0);
			}
			return true;
		}
		return false;
	}

	bool Player_1()
	{
		if (data[cursorY][cursorX] == 0)
		{
			gotoxy(cursorX * 8 + 2, cursorY * 4 + 1);
			cout << "¨q ©¤ ¨r";
			gotoxy(cursorX * 8 + 2, cursorY * 4 + 2);
			cout << "£ü¡¡£ü";
			gotoxy(cursorX * 8 + 2, cursorY * 4 + 3);
			cout << "¨t ©¤ ¨s";
			data[cursorY][cursorX] = 1;
			playerIndex = 0;

			int judge = judgeGame();
			if (judge >= 0)
			{
				if (judge == 0)
				{
					cout << "Draw!" << endl;
				}
				cout << "Game completed!" << endl;
				exit(0);
			}
			return true;
		}
		return false;
	}

public:
	void Run()
	{
		srand((unsigned int)time(NULL));
		int choice = select();
		Draw();
		gotoxy(cursorX * 8 + 4, cursorY * 4 + 2);
		int lastCh = 0;

		while (choice == 1)
		{
			int ch = _getch();
			//cout << ch << endl;

			if (lastCh == 224 && ch == 72)
			{
				cursorY--;
			}
			if (lastCh == 224 && ch == 80)
			{
				cursorY++;
			}
			if (lastCh == 224 && ch == 75)
			{
				cursorX--; 
			}
			if (lastCh == 224 && ch == 77)
			{
				cursorX++;
			}

			checkOperationIsCorrect(&cursorX, &cursorY);

			if (ch == 32)
			{
				if (playerIndex == 0)
				{
					Player_0();
				}
				else
				{
					Player_1();
				}
			}

			gotoxy(cursorX * 8 + 4, cursorY * 4 + 2);
			lastCh = ch;
		};

		while (choice == 2)
		{
			int ch = _getch();
			//cout << ch << endl;

			if (lastCh == 224 && ch == 72)
			{
				cursorY--;
			}
			if (lastCh == 224 && ch == 80)
			{
				cursorY++;
			}
			if (lastCh == 224 && ch == 75)
			{
				cursorX--;
			}
			if (lastCh == 224 && ch == 77)
			{
				cursorX++;
			}

			checkOperationIsCorrect(&cursorX, &cursorY);

			if (ch == 32)
			{
				Player_0();
				while (1)
				{
					cursorX = rand() % 3;
					cursorY = rand() % 3;
					if (Player_1())
					{
						break;
					}
				}
			}
			gotoxy(cursorX * 8 + 4, cursorY * 4 + 2);
			lastCh = ch;
		}

		while (choice == 3)
		{
			static int FirstOutput = 0;
			while (FirstOutput == 0)
			{
				cursorX = rand() % 3;
				cursorY = rand() % 3;
				if (Player_0())
				{
					FirstOutput = 1;
					break;
				}
			}

			int ch = _getch();
			//cout << ch << endl;

			if (lastCh == 224 && ch == 72)
			{
				cursorY--;
			}
			if (lastCh == 224 && ch == 80)
			{
				cursorY++;
			}
			if (lastCh == 224 && ch == 75)
			{
				cursorX--;
			}
			if (lastCh == 224 && ch == 77)
			{
				cursorX++;
			}

			checkOperationIsCorrect(&cursorX, &cursorY);

			if (ch == 32)
			{
				Player_1();
				while (1)
				{
					cursorX = rand() % 3;
					cursorY = rand() % 3;
					if (Player_0())
					{
						break;
					}
				}
			}
			gotoxy(cursorX * 8 + 4, cursorY * 4 + 2);
			lastCh = ch;
		}
	}
};


int main()
{
	Game g;
	g.Run();
	return 0;
}