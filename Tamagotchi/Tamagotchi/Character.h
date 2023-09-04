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
	int _type;
	bool isStay;
	bool moveLeft;
	bool moveRight;

	void Init();
	void Update(int deltaTime, char inputKey);
	//�ڱ��ڽ��� �׸��� �Լ�
	void Direction();
	void Animation(int index);
	void StayRender();
	void RightRender();
	void LeftRender();
	//�ڱ��ڽ��� ����� �Լ�
	void Erase();
	void EatFood(int type);
	void Sleep(int type);
	void EnjoyPlay(int type);
	void LevelUp(int type);
	void Status();
	void Release();
};

