#include "stdafx.h"
#include "MainGame.h"

void main()
{
	srand(time(NULL));
	MainGame mainGame;
	// Ÿ��Ʋ ����
	CustomConsole.SetTitle("����������");
	// ���ڻ� ����
	CustomConsole.SetTextColor(BLACK);
	// ���ڻ� ������ �����Ѵ�
	CustomConsole.SetBkColor(WHITE);
	//Ŀ���� ���ش�
	CustomConsole.SetCursor(tvision::CURSOR_OFF);
	//������ ����� �����Ѵ�
	CustomConsole.SetWindowSize(120, 30);
	//������ ��ü ����� �����Ѵ�
	CustomConsole.SetScreenFufferSize(120, 30);
	
	mainGame.Init();
	while (!mainGame.IsEnd())
	{
		mainGame.Update();
	}
	mainGame.Release();
	
}

/*	���������� �ϳ�����
	�÷��̾ ���������� �� �ϳ��� �����Ѵ�
	���� �� 2�� �ݺ��Ѵ�
	��ǻ�Ͱ� ���������� �� �ϳ��� �����Ѵ�
*/