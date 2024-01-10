#include "stdafx.h"
#include "KeyManager.h"
#include <Windows.h>

void KeyManager::Init()
{
	//push 해줄때마다
	//자기 capacity를 넘게되면
	//동적할당이 새롭게 일어나기때문에
	//큰용량의 pushback같은경우에는 먼저 공간을 확보하는게 좋다.

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
		//그 키를 눌렀다면
		if (asciikeys[key] & 0x80)
		{
			KeyState& state = _states[key];

			//원래 누르고있었다면
			if (state == KeyState::Press || state == KeyState::Down)
			{
				//누르고있는중
				state = KeyState::Press;
			}
			//원래 안누르고 있었다면
			else {
				//이번에 누름
				state = KeyState::Down;
			}
		}
		else
		{
			KeyState& state = _states[key];

			//원래 누르고있던 상태라면
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