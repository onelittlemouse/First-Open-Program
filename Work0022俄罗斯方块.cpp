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

class Game
{
public:
	Game(int width, int height, int initDepth = 3)
	{
		this->width = width;
		this->height = height;
		data = new int[width * height] {0};
		lastData = new int[width * height] {0};

		for (int y = height - initDepth; y < height; ++y)
		{
			for (int x = 0; x < width; ++x)
			{
				if (rand() % 3 > 0)
				{
					SetBlock(x, y, 1);
				}
			}
			SetBlock(rand() % this->width, y, 0);
		}
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
					}
					lastData[id] = data[id];
				}
			}
		}
		gotoxy(0, height + 2);
	}

	void CreateNewBlocks()
	{
		int selectBlock = rand() % 5;
		this->blockType = selectBlock;
		int locationOfBlocks = (rand() % (this->width - 3)) + 1;
		switch (selectBlock)
		{
		case 0:
		{
			this->score += 4;
			for (int j = 0; j < 2; j++)
			{
				for (int k = 0; k < 2; k++)
				{
					checkIfOver(locationOfBlocks + j - 1, k);
					SetBlock(locationOfBlocks + j - 1, k, 2);
				}
			}
			break;
		}
		case 1:
		{
			this->score += 3;
			for (int j = 0; j < 3; j++)
			{
				checkIfOver(locationOfBlocks + j - 1, 0);
				SetBlock(locationOfBlocks + j - 1, 0, 2);
			}
			break;
		}
		case 2:
		{
			this->score += 4;
			for (int j = 0; j < 3; j++)
			{
				checkIfOver(locationOfBlocks + j - 1, 0);
				SetBlock(locationOfBlocks + j - 1, 0, 2);
			}
			checkIfOver(locationOfBlocks, 1);
			SetBlock(locationOfBlocks, 1, 2);
			break;
		}
		case 3:
		{
			this->score += 4;
			for (int j = 0; j < 3; j++)
			{
				checkIfOver(locationOfBlocks + j - 1, 0);
				SetBlock(locationOfBlocks + j - 1, 0, 2);
			}
			checkIfOver(locationOfBlocks - 1, 1);
			SetBlock(locationOfBlocks - 1, 1, 2);
			break;
		}
		case 4:
		{
			this->score += 5;
			for (int j = 0; j < 3; j++)
			{
				checkIfOver(locationOfBlocks + j - 1, 0);
				SetBlock(locationOfBlocks + j - 1, 0, 2);
			}
			checkIfOver(locationOfBlocks - 1, 1);
			SetBlock(locationOfBlocks - 1, 1, 2);
			checkIfOver(locationOfBlocks, 1);
			SetBlock(locationOfBlocks, 1, 2);
			break;
		}
		}
	}

	void FixBlocks()
	{
		for (int y = height - 1; y >= 0; --y)
		{
			for (int x = 0; x < width; ++x)
			{
				if (GetBlock(x, y) == 2)
				{
					SetBlock(x, y, 1);
				}
			}
		}
	}

	void CheckAndDeleteLines()
	{
		for (int y = 0; y < height; y++)
		{
			bool checkIfDeleteLines = true;
			for (int x = 0; x < width; x++)
			{
				if (data[y * width] != data[y * width + x])
				{
					checkIfDeleteLines = false;
					break;
				}
			}
			if (checkIfDeleteLines == true)
			{
				for (int x = 0; x < width; x++)
				{
					data[y * width + x] = 0;
					if (data[(y - 1) * width + x] == 1 && y >= 1)
					{
						data[y * width + x] = 1;
						data[(y - 1) * width + x] = 0;
					}
				}
			}
		}
	}

	void MoveUp()
	{
		switch (this->blockType)
		{
		case 1:
		{
			for (int y = 1; y < height; y++)
			{
				for (int x = 2; x <= width - 1; x++)
				{
					if (data[y * width + x - 2] == 2 && data[y * width + x - 1] == 2 && data[y * width + x] == 2 && data[(y - 1) * width + x - 1] != 1 && data[(y + 1) * width + x - 1] != 1)
					{
						data[y * width + x - 2] = data[y * width + x] = 0;
						data[(y - 1) * width + x - 1] = data[(y + 1) * width + x - 1] = 2;
						goto FLAG0;
					}
					if (data[y * width + x - 2] != 1 && data[y * width + x - 1] == 2 && data[y * width + x] != 1 && data[(y - 1) * width + x - 1] == 2 && data[(y + 1) * width + x - 1] == 2)
					{
						data[y * width + x - 2] = data[y * width + x] = 2;
						data[(y - 1) * width + x - 1] = data[(y + 1) * width + x - 1] = 0;
						goto FLAG0;
					}
				}
			}
			FLAG0:
			break;
		}
		case 2:
		{
			for (int y = 1; y < height; y++)
			{
				for (int x = 2; x <= width - 1; x++)
				{
					if (data[y * width + x - 2] == 2 && data[y * width + x - 1] == 2 && data[y * width + x] == 2 && data[(y + 1) * width + x - 1] == 2 && data[(y - 1) * width + x - 1] != 1)
					{
						data[y * width + x] = 0;
						data[(y - 1) * width + x - 1] = 2;
						goto FLAG1;
					}
					if (data[y * width + x - 2] == 2 && data[y * width + x - 1] == 2 && data[y * width + x] != 1 && data[(y + 1) * width + x - 1] == 2 && data[(y - 1) * width + x - 1] == 2)
					{
						data[y * width + x] = 2;
						data[(y + 1) * width + x - 1] = 0;
						goto FLAG1;
					}
					if (data[y * width + x - 2] == 2 && data[y * width + x - 1] == 2 && data[y * width + x] == 2 && data[(y + 1) * width + x - 1] != 1 && data[(y - 1) * width + x - 1] == 2)
					{
						data[y * width + x - 2] = 0;
						data[(y + 1) * width + x - 1] = 2;
						goto FLAG1;
					}
					if (data[y * width + x - 2] != 1 && data[y * width + x - 1] == 2 && data[y * width + x] == 2 && data[(y + 1) * width + x - 1] == 2 && data[(y - 1) * width + x - 1] == 2)
					{
						data[y * width + x - 2] = 2;
						data[(y - 1) * width + x - 1] = 0;
						goto FLAG1;
					}
				}
			}
		FLAG1:
			break;
		}
		case 3:
		{
			for (int y = 0; y < height; y++)
			{
				for (int x = 1; x <= width; x++)
				{
					if (x >= 2 && x <= width - 2 && data[y * width + x - 1] == 2 && data[y * width + x] == 2 && data[y * width + x + 1] == 2 && data[(y + 1) * width + x - 1] == 2 && data[y * width + x - 2] != 1 && data[(y + 2) * width + x - 1] != 1)
					{
						data[y * width + x - 2] = 2;
						data[y * width + x] = data[y * width + x + 1] = 0;
						data[(y + 2) * width + x - 1] = 2;
						goto FLAG2;
					}
					if (x >= 3 && y >= 1 && data[y * width + x - 2] == 2 && data[y * width + x - 1] == 2 && data[(y + 1) * width + x - 1] == 2 && data[(y + 2) * width + x - 1] == 2 && data[y * width + x - 3] != 1)
					{
						data[(y + 1) * width + x - 1] = data[(y + 2) * width + x - 1] = 0;
						data[y * width + x - 3] = 2;
						data[(y - 1) * width + x - 1] = 2;
						goto FLAG2;
					}
					if (y >= 2 && x <= width - 1 && data[y * width + x - 3] == 2 && data[y * width + x - 2] == 2 && data[y * width + x - 1] == 2 && data[(y - 1) * width + x - 1] == 2 && data[y * width + x] != 1)
					{
						data[y * width + x - 3] = data[y * width + x - 2] = 0;
						data[(y - 2) * width + x - 1] = 2;
						data[y * width + x] = 2;
						goto FLAG2;
					}
					if (y >= 2 && x <= width - 2 && data[y * width + x - 1] == 2 && data[(y - 1) * width + x - 1] == 2 && data[(y - 2) * width + x - 1] == 2 && data[y * width + x] == 2 && data[y * width + x + 1] != 1 && data[(y + 1) * width + x - 1] != 1)
					{
						data[(y - 1) * width + x - 1] = data[(y - 2) * width + x - 1] = 0;
						data[y * width + x + 1] = 2;
						data[(y + 1) * width + x - 1] = 2;
						goto FLAG2;
					}
				}
			}
			FLAG2:
			break;
		}
		case 4:
		{
			for (int y = 1; y < height; y++)
			{
				for (int x = 2; x <= width - 1; x++)
				{
					if (data[y * width + x - 2] == 2 && data[y * width + x - 1] == 2 && data[y * width + x] == 2 && data[(y + 1) * width + x - 1] == 2 && data[(y + 1) * width + x - 2] == 2 && data[(y - 1) * width + x - 1] != 1 && data[(y - 1) * width + x - 2] != 1)
					{
						data[(y + 1) * width + x - 2] = data[y * width + x] = 0;
						data[(y - 1) * width + x - 1] = data[(y - 1) * width + x - 2] = 2;
						goto FLAG3;
					}
					if (data[y * width + x - 2] == 2 && data[y * width + x - 1] == 2 && data[(y + 1) * width + x - 1] == 2 && data[(y - 1) * width + x - 1] == 2 && data[(y - 1) * width + x - 2] == 2 && data[y * width + x] != 1 && data[(y - 1) * width + x] != 1)
					{
						data[y * width + x] = data[(y - 1) * width + x] = 2;
						data[(y + 1) * width + x - 1] = data[(y - 1) * width + x - 2] = 0;
						goto FLAG3;
					}
					if (data[y * width + x - 2] == 2 && data[y * width + x - 1] == 2 && data[y * width + x] == 2 && data[(y - 1) * width + x - 1] == 2 && data[(y - 1) * width + x] == 2 && data[(y + 1) * width + x - 1] != 1 && data[(y + 1) * width + x] != 1)
					{
						data[y * width + x - 2] = data[(y - 1) * width + x] = 0;
						data[(y + 1) * width + x - 1] = data[(y + 1) * width + x] = 2;
						goto FLAG3;
					}
					if (data[(y - 1) * width + x - 1] == 2 && data[y * width + x - 1] == 2 && data[y * width + x] == 2 && data[(y + 1) * width + x - 1] == 2 && data[(y + 1) * width + x] == 2 && data[y * width + x - 2] != 1 && data[(y + 1) * width + x - 2] != 1)
					{
						data[y * width + x - 2] = data[(y + 1) * width + x - 2] = 2;
						data[(y + 1) * width + x] = data[(y - 1) * width + x - 1] = 0;
						goto FLAG3;
					}
				}
			}
			FLAG3:
			break;
		}
		default:
		{
			break;
		}
		}

	}

	void MoveLeft()
	{
		bool canMoveLeft = true;
		for (int x = 0; x < width; ++x)
		{
			for (int y = 0; y < height; ++y)
			{
				if (GetBlock(x, y) == 2)
				{
					if (x <= 0 || GetBlock(x - 1, y) == 1)
					{
						canMoveLeft = false;
						break;
					}
				}
			}
			if (!canMoveLeft)
			{
				break;
			}
		}

		if (canMoveLeft)
		{
			for (int x = 0; x < width; ++x)
			{
				for (int y = 0; y < height; ++y)
				{
					if (GetBlock(x, y) == 2)
					{
						SetBlock(x - 1, y, 2);
						SetBlock(x, y, 0);
					}
				}
			}
		}
	}

	void MoveRight()
	{
		bool canMoveRight = true;
		for (int x = width - 1; x >= 0; --x)
		{
			for (int y = 0; y < height; ++y)
			{
				if (GetBlock(x, y) == 2)
				{
					if (x >= width - 1 || GetBlock(x + 1, y) == 1)
					{
						canMoveRight = false;
						break;
					}
				}
			}
			if (!canMoveRight)
			{
				break;
			}
		}

		if (canMoveRight)
		{
			for (int x = width - 1; x >= 0; --x)
			{
				for (int y = 0; y < height; ++y)
				{
					if (GetBlock(x, y) == 2)
					{
						SetBlock(x + 1, y, 2);
						SetBlock(x, y, 0);
					}
				}
			}
		}
	}

	void MoveDown()
	{
		bool canMoveDown = true;
		for (int y = height - 1; y >= 0; --y)
		{
			for (int x = 0; x < width; ++x)
			{
				if (GetBlock(x, y) == 2)
				{
					if (y == height - 1 || GetBlock(x, y + 1) == 1)
					{
						canMoveDown = false;
						break;
					}
				}
			}
			if (!canMoveDown)
			{
				break;
			}
		}

		if (canMoveDown)
		{
			for (int y = height - 1; y >= 0; --y)
			{
				for (int x = 0; x < width; ++x)
				{
					if (GetBlock(x, y) == 2)
					{
						SetBlock(x, y + 1, 2);
						SetBlock(x, y, 0);
					}
				}
			}
		}
		else
		{
			FixBlocks();
			CheckAndDeleteLines();
			CreateNewBlocks();
		}
	}

	void checkIfOver(int x, int y)
	{
		if (data[y * width + x] == 1)
		{
			cout << "score:" << score << endl;
			cout << "Game Over!" << endl;
			system("pause");
			exit(0);
		}
	}


public:
	void Run()
	{
		this->score = 0;
		CreateNewBlocks();
		DrawFrame();
		DrawBlocks();

		int lastCh = 0;
		long long t1 = ::GetTickCount64();
		while (1)
		{
			if (_kbhit())
			{
				int ch = _getch();

				if (lastCh == 224 && ch == 72)//U
				{
					MoveUp();
				}
				if (lastCh == 224 && ch == 80)//D
				{
					MoveDown();
				}
				if (lastCh == 224 && ch == 75)//L
				{
					MoveLeft();
				}
				if (lastCh == 224 && ch == 77)//R
				{
					MoveRight();
				}
				lastCh = ch;
			}
			Sleep(1);
			long long t2 = ::GetTickCount64();
			if (t2 - t1 >= 500)
			{
				MoveDown();
				t1 = t2;
			}
			DrawBlocks();
			CheckAndDeleteLines();
		}
		gotoxy(0, height + 2);
	}


private:
	int width;
	int height;
	int* data;
	int* lastData;
	int score;
	int blockType;
};


int main()
{
	srand(time(0));
	Game g(12, 20);
	g.Run();
	return 0;
}