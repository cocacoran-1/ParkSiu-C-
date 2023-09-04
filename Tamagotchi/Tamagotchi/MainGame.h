#pragma once
class Character;
class MainGame
{
public:
	//������ => �ּҰ�
	Character* _character;

	int _boradX;
	int _boradY;
	int _textX;
	int _textY;
	int _currentSelect;

	bool _isGameEnd;

	void Init();
	void Update(int deltaTime);
	void SelectTextBoard(int currentSelect);
	void CleanBoard();
	void Release();

	bool IsGameEnd();
};

