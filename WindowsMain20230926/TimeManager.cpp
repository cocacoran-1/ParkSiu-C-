#include "stdafx.h"
#include "TimeManager.h"

void TimeManager::Init()
{
	//������ Ÿ�̸�
	QueryPerformanceFrequency(reinterpret_cast<LARGE_INTEGER*>(&_frequency));
	QueryPerformanceCounter(reinterpret_cast<LARGE_INTEGER*>(&_prevCount));
}

void TimeManager::Release()
{
}

void TimeManager::Update()
{
	//long tick = GetTickCount64();
	//_deltaTime = tick - prevTick

	//GetTickCount64()
	// => ���ϰԾ����ִ� ��ſ� ���е��鿡�� ������ (�����Լ�)

	//8����Ʈ¥�� ���� ���� �ڷ���
	unsigned long long currentCount;
	QueryPerformanceCounter(reinterpret_cast<LARGE_INTEGER*>(&currentCount));

	_deltaTime = (currentCount - _prevCount) / static_cast<float>(_frequency);
	_prevCount = currentCount;

	//FPS, FrameCount���ϱ�

	//FrameCount => ȭ����ȯ�� ����Ǵ°�? (�������� �ε巴��) 
	//FPS => Frame Per Seconds (1�ʿ� ȭ����ȯ�� ��� �Ǿ��°�?)
	// (���� 60, 144, 240, ���Ѿ���) (��ȭ, ���� 24, 30)

	_frameTime += _deltaTime;
	_frameCount++;
	if (_frameTime >= 1.0f)
	{
		_fps = static_cast<unsigned int>(_frameCount / _frameTime);

		_frameTime = 0.0f;
		_frameCount = 0;
	}
}
