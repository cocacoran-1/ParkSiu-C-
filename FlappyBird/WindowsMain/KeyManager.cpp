#include "stdafx.h"
#include "KeyManager.h"
#include <Windows.h>

void KeyManager::Init()
{
	//push ���ٶ�����
	//�ڱ� capacity�� �ѰԵǸ�
	//�����Ҵ��� ���Ӱ� �Ͼ�⶧����
	//ū�뷮�� pushback������쿡�� ���� ������ Ȯ���ϴ°� ����.

	_states.resize(KEY_TYPE_COUNT, KeyState::None);
}


void KeyManager::Release()
{

}

void KeyManager::Update()
{
	BYTE asciikeys[KEY_TYPE_COUNT] = {};
	//GetAsyncKeyState
	bool result = GetKeyboardState(asciikeys);
	if (result == false)
	{
		return;
	}
	


	for (uint32 key = 0; key < KEY_TYPE_COUNT; key++)
	{
		//�� Ű�� �����ٸ�
		if (asciikeys[key] & 0x80)
		{
			KeyState& state = _states[key];

			//���� �������־��ٸ�
			if (state == KeyState::Press || state == KeyState::Down)
			{
				//�������ִ���
				state = KeyState::Press;
			}
			//���� �ȴ����� �־��ٸ�
			else {
				//�̹��� ����
				state = KeyState::Down;
			}
		}
		else
		{
			KeyState& state = _states[key];

			//���� �������ִ� ���¶��
			if (state == KeyState::Press || state == KeyState::Down)
			{
				state = KeyState::Up;
			}
			else
			{
				state = KeyState::None;
			}
		}
	}

}

bool KeyManager::GetKeyDown(KeyType key)
{
	return _states[static_cast<uint32>(key)] == KeyState::Down;
}

bool KeyManager::GetKey(KeyType key)
{
	return _states[static_cast<uint32>(key)] == KeyState::Press;
}

bool KeyManager::GetKeyUp(KeyType key)
{
	return _states[static_cast<uint32>(key)] == KeyState::Up;
}