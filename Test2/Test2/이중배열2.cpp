#include<iostream>
#include<Windows.h>
using namespace std;

enum eDrawType
{
	DRAWTYPE_Point,
	DRAWTYPE_Line,
	DRAWTYPE_Rect,
	END
};

struct Point
{
	int x;
	int y;
};
struct Line
{
	int lineType;
	Point startPos;
	int length;
};
struct Rect
{
	Point LeftTop;
	Point RightBottom;
};

void main()
{
	int arr[25][25] = { 0, };

	for (int i = 0; i < 25; i++)
	{
		for (int j = 0; j < 25; j++)
		{
			arr[i][j] = 0;
		}
	}

	char board[25][25] = {};
	for (int i = 0; i < 25; i++)
	{
		for (int j = 0; j < 25; j++)
		{
			board[i][j] = ' ';
		}
	}
	while (true)
	{
		system("cls");
		for (int i = 0; i < 25; i++)
		{
			for (int j = 0; j < 25; j++)
			{
				cout << board[i][j];
			}
			cout << endl;
		}
		cout << "그릴 유형을 선택해주세요 (0: 점, 1: 라인, 2: 네모)" << endl;
		int drawtype = 0;
		cin >> drawtype;

		switch (drawtype)
		{
		case eDrawType::DRAWTYPE_Point:
			Point point;
			cout << "그릴 x 좌표를 입력해주세요.";
			cin >> point.x;
			cout << "그릴 y 좌표를 입력해주세요.";
			cin >> point.y;
			cout << "점 [" << point.x << "," << point.y << "]" << endl;
			board[point.y][point.x] = 'P';
			break;
		case eDrawType::DRAWTYPE_Line:
			Line line;
			cout << "Line 유형을 골라주세요 (가로 : 0, 세로 : 1)";
			cin >> line.lineType;
			cout << "그릴 x 좌표를 입력해주세요.";
			cin >> line.startPos.x;
			cout << "그릴 y 좌표를 입력해주세요.";
			cin >> line.startPos.y;
			cout << "길이를 입력해주세요.";
			cin >> line.length;
			for (int i = 0; i < line.length; i++)
			{
				if (line.lineType == 0)
				{
					board[line.startPos.y][line.startPos.x + i] = 'L';
				}
				else
				{
					board[line.startPos.y + i][line.startPos.x] = 'L';
				}
			}
			break;
		case eDrawType::DRAWTYPE_Rect:
		{
			Rect rect;
			cout << "x1을 입력해주세요.";
			cin >> rect.LeftTop.x;
			cout << "y1을 입력해주세요.";
			cin >> rect.LeftTop.y;
			cout << "x2을 입력해주세요.";
			cin >> rect.RightBottom.x;
			cout << "y2을 입력해주세요.";
			cin >> rect.RightBottom.y;

			// 배열과 함께쓰는 포문이 아닐때는 
			// 어디부터 어디까지라는 의미를 가진다
			int x1 = rect.LeftTop.x;
			int x2 = rect.RightBottom.x;
			int y1 = rect.LeftTop.y;
			int y2 = rect.RightBottom.y;
			for (int x = x1; x <= x2; x++)
			{
				for (int y = y1; y <= y2; y++)
				{
					board[y][x] = 'R';
				}
			}
		}
			break;
		default:
			break;
		}

		system("pause");
	}

}