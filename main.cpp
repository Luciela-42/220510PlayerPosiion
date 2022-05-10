//P가 상하좌우로 움직이기 위해선 무엇이 필요할까
//while(1)
//{
//Input()
//1. 엔터키 없이 키 입력을 받는다.

//Process()
//2. 원하는 위치에 출력 한다.
//3. 화면을 지운다.

//Render()
//}
#include <iostream>
#include <conio.h>
#include <windows.h>

using namespace std;

struct FVector2D
{
	int X;
	int Y;
};

void SetLocation(FVector2D NewLocation);
void MapBoundary();

int main()
{
	bool bRunning = true;
	FVector2D PlayerPosition;
	PlayerPosition.X = 5;
	PlayerPosition.Y = 6;


	while (bRunning)
	{

		int KeyCode = _getch();

		switch (KeyCode)
		{
		case 'w':
		case 'W':
			PlayerPosition.Y--;
			break;
		case 's':
		case 'S':
			PlayerPosition.Y++;
			break;
		case 'a':
		case 'A':
			PlayerPosition.X--;
			break;
		case 'd':
		case 'D':
			PlayerPosition.X++;
			break;
		case 27:
			bRunning = 0;
		}

		PlayerPosition.X = PlayerPosition.X < 1 ? 1 : PlayerPosition.X;
		PlayerPosition.Y = PlayerPosition.Y < 1 ? 1 : PlayerPosition.Y;
		PlayerPosition.X = PlayerPosition.X > 8 ? 8 : PlayerPosition.X;
		PlayerPosition.Y = PlayerPosition.Y > 8 ? 8 : PlayerPosition.Y;

		system("cls");

		MapBoundary();

		SetLocation(PlayerPosition);
		cout << "P";
	}

	return 0;
}

void SetLocation(FVector2D NewLocation)
{
	COORD Cur;
	Cur.X = NewLocation.X;
	Cur.Y = NewLocation.Y;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), Cur);
}

void MapBoundary()
{
	int Map[10][10] =
	{
		1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
		1, 0, 0, 0, 0, 0, 0, 0, 0, 1,
		1, 0, 0, 0, 0, 0, 0, 0, 0, 1,
		1, 0, 0, 0, 0, 0, 0, 0, 0, 1,
		1, 0, 0, 0, 0, 0, 0, 0, 0, 1,
		1, 0, 0, 0, 0, 0, 0, 0, 0, 1,
		1, 0, 0, 0, 0, 0, 0, 0, 0, 1,
		1, 0, 0, 0, 0, 0, 0, 0, 0, 1,
		1, 0, 0, 0, 0, 0, 0, 0, 0, 1,
		1, 1, 1, 1, 1, 1, 1, 1, 1, 1
	};

	for (int i = 0; i < 10; ++i)
	{
		for (int j = 0; j < 10; ++j)
		{
			switch (Map[i][j])
			{
			case 0:
				cout << " ";
				break;
			case 1:
				cout << "@";
				break;
			}
			
		}
		cout << endl;
	}
	//cout << "##########" << endl;
	//cout << "#	 #" << endl;
	//cout << "#	 #" << endl;
	//cout << "#	 #" << endl;
	//cout << "#	 #" << endl;
	//cout << "#	 #" << endl;
	//cout << "#	 #" << endl;
	//cout << "#	 #" << endl;
	//cout << "#	 #" << endl;
	//cout << "##########" << endl;
}

