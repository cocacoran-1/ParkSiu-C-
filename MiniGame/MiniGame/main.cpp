#include "stdafx.h"


void main()
{
	// 타이틀 설정
	CustomConsole.SetTitle("Mini Game");
	// 글자색 변경
	CustomConsole.SetTextColor(BLACK);
	// 글자색 배경색을 변경한다
	CustomConsole.SetBkColor(WHITE);
	//커서를 없앤다
	CustomConsole.SetCursor(tvision::CURSOR_OFF);
	//윈도우 사이즈를 조정한다
	CustomConsole.SetWindowSize(100, 30);
	//윈도우 전체 사이즈를 조정한다
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
				cout << "■" << endl;
			}
			else if (ch == 's')
			{
				CustomConsole.ClearArea(x, y, x + 2, y);
				y--;
				cout << "■" << endl;
				
			}
			else if (ch == 'a')
			{
				CustomConsole.ClearArea(x, y, x + 2, y);
				x++;
				cout << "■" << endl;
			}
			else if (ch == 'd')
			{
				CustomConsole.ClearArea(x, y, x + 2, y);
				x--;
				cout << "■" << endl;
			}
		}

	}
}