#pragma once
//#include "MainGame.h"
class Character
{
public:
	int _x, _y;
	int _animationIndex;
	int _animationTime;
	int _foodGauge;
	int _fatigueGauge;
	int _happinessGauge;
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
	void EatFood();
	void Sleep();
	void EnjoyPlay();
	void Status();
	void Release();
};

