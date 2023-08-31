#include "Main.h"
#include "MainGame.h"

void main()
{
	MainGame* mainGame = new MainGame();

	while(!mainGame->IsEnd())
	{
		mainGame->Update();
	}
	mainGame->Release();
	delete mainGame;
	mainGame = nullptr;

}