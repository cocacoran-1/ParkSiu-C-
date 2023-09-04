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
	//자기자신을 그리는 함수
	void Direction();
	void Animation(int index);
	void StayRender();
	void RightRender();
	void LeftRender();
	//자기자신을 지우는 함수
	void Erase();
	void EatFood(int type);
	void Sleep(int type);
	void EnjoyPlay(int type);
	void LevelUp(int type);
	void Status();
	void Release();
};

