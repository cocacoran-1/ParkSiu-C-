#include "stdafx.h"
#include "MainGame.h"


void main()
{
	CustomConsole.SetTitle("TamaGotchi");
	CustomConsole.SetWindowSize(240, 63);
	CustomConsole.SetScreenFufferSize(240, 63);

	MainGame* mainGame = new MainGame();
	mainGame->Init();

	long prevTick = GetTickCount64();
	long currentTick = GetTickCount64();
	while (false == mainGame->IsGameEnd())
	{
		long currentTick = GetTickCount64();
		
		mainGame->Update(currentTick - prevTick);
		prevTick = currentTick;
	}

	mainGame->Release();
	delete mainGame;
	mainGame = nullptr;
}