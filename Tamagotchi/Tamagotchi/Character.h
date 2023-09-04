#pragma once
//#include "MainGame.h"


class Character
{
public:
	int _x, _y;
	int _animationIndex;
	int _animationTime;
	int _showTextTime;
	int _foodGauge;
	int _activityGauge;
	int _happinessGauge;
	int _textX ;
	int _textY;
	int _level;
	bool isStay;
	bool moveLeft;
	bool moveRight;

	void Init();
	void Update(int deltaTime, char inputKey);
	//�ڱ��ڽ��� �׸��� �Լ�
	void Direction();
	void StayRender();
	void RightRender();
	void LeftRender();
	//�ڱ��ڽ��� ����� �Լ�
	void Erase();
	void EatFood( );
	void Sleep( );
	void EnjoyPlay( );
	void LevelUp( );
	void Status();
	void Release();
};

