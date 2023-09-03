#pragma once
class Character;
class MainGame
{
public:
	//포인터 => 주소값
	Character* _character;

	int _boradX;
	int _boradY;
	int _textX;
	int _textY;

	bool _isGameEnd;

	void Init();
	void Update(int deltaTime);
	void SelectTextBoard(int currentSelect);
	void Release();

	bool IsGameEnd();
};

