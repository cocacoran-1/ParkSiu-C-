#pragma once
//#include "MainGame.h"

enum eMovement
{
	STAY,
	RIGHT,
	LEFT,
	END
};

class Character
{
public:
	int _x, _y;
	int _shapeX, _shapeY;
	int _textX, _textY;
	int _animationIndex;
	int _animationTime;
	int _showTextTime;
	int _foodGauge;
	int _activityGauge;
	int _happinessGauge;
	int _level;
	int _textType;
	int _movementType;

	void Init();
	void Update(int deltaTime, char inputKey);
	//자기자신을 그리는 함수
	void Direction();
	void Animation(int index);
	void StayRender();
	void RightRender();
	void LeftRender();
	void HeartRender();
	//자기자신을 지우는 함수
	void Erase();
	void EatFood(int index);
	void Sleep(int index);
	void EnjoyPlay(int index);
	void LevelUp(int index);
	void Status();
	void Release();
};

