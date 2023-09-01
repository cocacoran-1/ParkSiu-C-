#include "stdafx.h"
#include "MainGame.h"

void main()
{
	srand(time(NULL));
	MainGame mainGame;
	// 타이틀 설정
	CustomConsole.SetTitle("가위바위보");
	// 글자색 변경
	CustomConsole.SetTextColor(BLACK);
	// 글자색 배경색을 변경한다
	CustomConsole.SetBkColor(WHITE);
	//커서를 없앤다
	CustomConsole.SetCursor(tvision::CURSOR_OFF);
	//윈도우 사이즈를 조정한다
	CustomConsole.SetWindowSize(120, 30);
	//윈도우 전체 사이즈를 조정한다
	CustomConsole.SetScreenFufferSize(120, 30);
	
	mainGame.Init();
	while (!mainGame.IsEnd())
	{
		mainGame.Update();
	}
	mainGame.Release();
	
}

/*	가위바위보 하나빼기
	플레이어가 가위바위보 중 하나를 선택한다
	위를 총 2번 반복한다
	컴퓨터가 가위바위보 중 하나를 선택한다
*/