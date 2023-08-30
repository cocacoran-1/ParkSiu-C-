#include "Main.h"
#include "MainGame.h"

void main()
{
	MainGame  mainGame;
	mainGame.Init();
	mainGame.Update();
	
	while (!mainGame.IsEnd())
	{
		mainGame.Update();
	}

	mainGame.Release();

}