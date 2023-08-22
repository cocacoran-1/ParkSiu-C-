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
	int x[2];
	int y[2];
	int num;
};
struct Rect
{
	int x[4];
	int y[4];
	int num;
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
		case eDrawType ::DRAWTYPE_Point:
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
			line.num = 1;
			for (int i = 0; i < 2; i++)
			{
				cout << "점 " << i + 1 << "의 x 좌표를 입력해주세요.";
				cin >> line.x[i];
				cout << "점 " << i + 1 << "의 y 좌표를 입력해주세요.";
				cin >> line.y[i];
				cout << "점 " << i + 1 << " [" << line.x[i] << "," << line.y[i] << "]" << endl;
			}
			// y 좌표가 같을 때
			if (line.y[0] == line.y[1])
			{
				if (line.x[0] > line.x[1])
				{
					for (int i = line.x[1]; i < line.x[0]; i++)
					{
						board[line.y[0]][i] = 'L';
					}
				}
				else if (line.x[0] < line.x[1])
				{
					for (int i = line.x[0]; i < line.x[1]; i++)
					{
						board[line.y[0]][i] = 'L';
					}
				}
			}
			// x 좌표가 같을 때
			else if (line.x[0] == line.y[1])
			{
				if (line.y[0] > line.y[1])
				{
					for (int i = line.y[1]; i < line.y[0]; i++)
					{
						board[i][line.x[0]] = 'L';
					}
				}
				else if (line.y[0] < line.y[1])
				{
					for (int i = line.y[0]; i < line.y[1]; i++)
					{
						board[i][line.x[0]] = 'L';
					}
				}
			}
			// 같은 좌표가 없을 때
			else
			{
				if (line.x[0] > line.x[1] && line.y[0] > line.y[1])
				{
					for (int i = line.x[1]; i < line.x[0]; i++)
					{
						board[line.y[1] + line.num][i+1] = 'L';
						line.num++;
					}
				}
				else if (line.x[1] > line.x[0] && line.y[1] > line.y[0])
				{
					for (int i = line.x[0]; i < line.x[1]; i++)
					{
						board[line.y[0] + line.num][i+1] = 'L';
						line.num++;
					}
				}
				else if (line.x[1] > line.x[0] && line.y[1] < line.y[0])
				{
					for (int i = line.x[0]; i < line.x[1]; i++)
					{
						board[line.y[1] + line.num][i + 1] = 'L';
						line.num++;
					}
				}
				else if (line.x[1] < line.x[0] && line.y[1] > line.y[0])
				{
					for (int i = line.x[1]; i < line.x[0]; i++)
					{
						board[line.y[1] - line.num][i + 1] = 'L';
						line.num++;
					}
				}
			}
			break;
		case eDrawType::DRAWTYPE_Rect:
			Rect rect;
			
			for (int i = 0; i < 4; i++)
			{
				cout << "점 " << i + 1 << "의 x 좌표를 입력해주세요.";
				cin >> rect.x[i];
				cout << "점 " << i + 1 << "의 y 좌표를 입력해주세요.";
				cin >> rect.y[i];
				cout << "점 " << i + 1 << " [" << rect.x[i] << "," << rect.y[i] << "]" << endl;
				board[rect.x[i]][rect.y[i]] = 'R';
				cout << board[rect.x[i]][rect.y[i]];
			}
			for (int i = 0; i < 4; i++)
			{
				for (int j = 0; j < 4; j++)
				{
					// x 좌표가 같을 때
					if (rect.x[i] == rect.x[j] && rect.y[i] != rect.y[j])
					{
						if (rect.y[i] > rect.y[j])
						{
							for (int k = rect.y[j]; k < rect.y[i]; k++)
							{
								board[k][rect.x[i]] = 'R';
							}	
						}
						else
						{
							for (int k = rect.y[i]; k < rect.y[j]; k++)
							{
								board[k][rect.x[i]] = 'R';
							}
						}
					}
					// y 좌표가 같을 때
					else if (rect.y[i] == rect.y[j] && rect.x[i] != rect.x[j])
					{
						if (rect.x[i] > rect.x[j])
						{
							for (int k = rect.x[j]; k < rect.x[i]; k++)
							{
								board[rect.y[i]][k] = 'R';
							}
						}
						else
						{
							for (int k = rect.x[i]; k < rect.x[j]; k++)
							{
								board[rect.y[i]][k] = 'R';
							}
						}
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