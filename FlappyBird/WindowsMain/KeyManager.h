#pragma once
using KeyType = int32;
enum class KeyState
{
	None,		//안눌려있는 상태
	Press,		//누르고있는 상태
	Down,		//이번프레임에 눌렀을때
	Up,			//이번프레임에 떼었을때

	End
};

enum
{
	KEY_TYPE_COUNT = static_cast<int32>(UINT8_MAX) + 1,
	KEY_STATE_COUNT = static_cast<int32>(KeyState::End)
};

class KeyManager
{
	DECLARE_SINGLE(KeyManager)

private:
	vector<KeyState> _states;
	//_states[VK_LBUTTON] = Press;

public:
	//키를 이번프레임에 눌렀는지?
	bool GetKeyDown(KeyType key);
	//키가 눌려져 있는지?
	bool GetKey(KeyType key);
	//키가 이번프레임에 떼었는지?
	bool GetKeyUp(KeyType key);

	void Init();
	void Update();
	void Release();
};
