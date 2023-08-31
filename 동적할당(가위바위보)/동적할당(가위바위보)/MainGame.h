#pragma once
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
	int _choice;
	int _randomChoice;
	int _round;
	bool _isEnd;

	void Init();
	void Update();
	bool IsEnd();
	void Release();

};