#pragma once
class User;

enum eRockScissorsPaper
{
	ROCK,
	SCISSORS,
	PAPER,
	END
};

class MainGame
{
public:
	User* _player;
	User* _computer;

	int _menuX;
	int _menuY;
	int _playerShapeX;
	int _playerShapeY;
	int _computerShapeX;
	int _computerShapeY;

	void Init();
	void Update();
	void Release();

	bool IsEnd();
};

