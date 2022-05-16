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

char Map[10][10] = {
	{'#','#','#','#','#','#','#','#','#','#'},
	{'#',' ',' ',' ',' ',' ',' ',' ',' ','#'},
	{'#',' ',' ',' ',' ',' ',' ',' ',' ','#'},
	{'#',' ',' ',' ',' ',' ',' ',' ',' ','#'},
	{'#',' ',' ',' ',' ','#',' ',' ',' ','#'},
	{'#',' ',' ',' ',' ',' ',' ',' ',' ','#'},
	{'#',' ',' ',' ','#',' ',' ',' ',' ','#'},
	{'#',' ',' ',' ',' ',' ',' ',' ',' ','#'},
	{'#',' ',' ',' ',' ',' ',' ',' ',' ','#'},
	{'#','#','#','#','#','#','#','#','#','#'}
};


void SetLocation(FVector2D NewLocation);

//bool IsCollide(FVector2D& NewPlayerPosition, FVector2D& OutPlayerPosition)
//{
//	if (Map[NewPlayerPosition.Y][NewPlayerPosition.X] == '#')
//	{
//		return false;
//	}
//	else
//	{
//		OutPlayerPosition = NewPlayerPosition;
//		return true;
//	}
//}

void DrawBG(FVector2D StartPosition)
{
	for (int Y = 0; Y < 10; ++Y)
	{
		for (int X = 0; X < 10; ++X)
		{
			FVector2D Temp;
			Temp.X = X + StartPosition.X;
			Temp.Y = Y + StartPosition.Y;
			SetLocation(Temp);
			cout << Map[Y][X];
		}
	}

}

int main()
{
	bool bRunning = true;
	FVector2D PlayerPosition;
	PlayerPosition.X = 1;
	PlayerPosition.Y = 1;

	srand(static_cast<unsigned int>(time(nullptr)));
	FVector2D StartPosition;
	StartPosition.X = rand() % 10 + 1;
	StartPosition.Y = rand() % 10 + 1;

	while (bRunning)
	{
		int KeyCode = _getch();

		//FVector2D NewPlayerPosition = PlayerPosition;

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
			bRunning = false;
			break;

		}

		PlayerPosition.X = PlayerPosition.X < 1 ? 1 : PlayerPosition.X;
		PlayerPosition.Y = PlayerPosition.Y < 1 ? 1 : PlayerPosition.Y;
		PlayerPosition.X = PlayerPosition.X >= 9 ? 8 : PlayerPosition.X;
		PlayerPosition.Y = PlayerPosition.Y >= 9 ? 8 : PlayerPosition.Y;

		if (Map[PlayerPosition.Y][PlayerPosition.X] == '#')
		{
			if (KeyCode == 'w' || KeyCode == 'W')
			{
				PlayerPosition.Y++;
			}
			else if (KeyCode == 's' || KeyCode == 'S')
			{
				PlayerPosition.Y--;
			}
			else if (KeyCode == 'a' || KeyCode == 'A')
			{
				PlayerPosition.X++;
			}
			else if (KeyCode == 'd' || KeyCode == 'D')
			{
				PlayerPosition.X--;
			}
		}

		system("cls");

		DrawBG(StartPosition);
		FVector2D Temp;
		Temp.X = PlayerPosition.X + StartPosition.X;
		Temp.Y = PlayerPosition.Y + StartPosition.Y;
		SetLocation(Temp);
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