#include "stdafx.h"


void main()
{
	// Ÿ��Ʋ ����
	CustomConsole.SetTitle("Mini Game");
	// ���ڻ� ����
	CustomConsole.SetTextColor(BLACK);
	// ���ڻ� ������ �����Ѵ�
	CustomConsole.SetBkColor(WHITE);
	//Ŀ���� ���ش�
	CustomConsole.SetCursor(tvision::CURSOR_OFF);
	//������ ����� �����Ѵ�
	CustomConsole.SetWindowSize(100, 30);
	//������ ��ü ����� �����Ѵ�
	CustomConsole.SetScreenFufferSize(100, 30);


	int x, y = 0;
	x = 0;
	y = 0;
	while (true)
	{
		if (_kbhit())
		{
			char ch = _getch();
			if (ch == 'w')
			{
				CustomConsole.ClearArea(x, y, x + 2, y);
				y++;
				cout << "��" << endl;
			}
			else if (ch == 's')
			{
				CustomConsole.ClearArea(x, y, x + 2, y);
				y--;
				cout << "��" << endl;
				
			}
			else if (ch == 'a')
			{
				CustomConsole.ClearArea(x, y, x + 2, y);
				x++;
				cout << "��" << endl;
			}
			else if (ch == 'd')
			{
				CustomConsole.ClearArea(x, y, x + 2, y);
				x--;
				cout << "��" << endl;
			}
		}

	}
}