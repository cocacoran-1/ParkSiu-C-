#pragma once
enum eBetChoice
{
	HIGH,
	LOW,
	SEVEN,
	NOBET,
	END
};

class MainGame
{
public:
	int _card[52];
	int _playerBet;
	int _playerMoney;
	int _choice;
	int _currentIndex;

	void Init();
	void Update();
	void Release();
	bool IsEnd();
};
