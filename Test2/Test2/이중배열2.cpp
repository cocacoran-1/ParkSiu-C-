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
		cout << "�׸� ������ �������ּ��� (0: ��, 1: ����, 2: �׸�)" << endl;
		int drawtype = 0;
		cin >> drawtype;

		switch (drawtype)
		{
		case eDrawType::DRAWTYPE_Point:
			Point point;
			cout << "�׸� x ��ǥ�� �Է����ּ���.";
			cin >> point.x;
			cout << "�׸� y ��ǥ�� �Է����ּ���.";
			cin >> point.y;
			cout << "�� [" << point.x << "," << point.y << "]" << endl;
			board[point.y][point.x] = 'P';
			break;
		case eDrawType::DRAWTYPE_Line:
			Line line;
			cout << "Line ������ ����ּ��� (���� : 0, ���� : 1)";
			cin >> line.lineType;
			cout << "�׸� x ��ǥ�� �Է����ּ���.";
			cin >> line.startPos.x;
			cout << "�׸� y ��ǥ�� �Է����ּ���.";
			cin >> line.startPos.y;
			cout << "���̸� �Է����ּ���.";
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
			cout << "x1�� �Է����ּ���.";
			cin >> rect.LeftTop.x;
			cout << "y1�� �Է����ּ���.";
			cin >> rect.LeftTop.y;
			cout << "x2�� �Է����ּ���.";
			cin >> rect.RightBottom.x;
			cout << "y2�� �Է����ּ���.";
			cin >> rect.RightBottom.y;

			// �迭�� �Բ����� ������ �ƴҶ��� 
			// ������ ��������� �ǹ̸� ������
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