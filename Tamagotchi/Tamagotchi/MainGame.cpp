#include "stdafx.h"
#include "MainGame.h"
#include "Character.h"

void MainGame::Init()
{
	CustomConsole.SetCursor(tvision::CURSOR_OFF);
	_isGameEnd = false;

	_character = new Character();
	_character->Init();

	_character->StayRender();
}

void MainGame::Update(int deltaTime)
{
	char input = '\0';
	if (_kbhit())
	{
		input = _getch();
	}
	_character->Update(deltaTime, input);


}

void MainGame::Release()
{
	_character->Release();
	delete _character;
	_character = nullptr;
}

bool MainGame::IsGameEnd()
{
	return _isGameEnd;
}

