#pragma once
using KeyType = int32;
enum class KeyState
{
	None,		//�ȴ����ִ� ����
	Press,		//�������ִ� ����
	Down,		//�̹������ӿ� ��������
	Up,			//�̹������ӿ� ��������

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
	//Ű�� �̹������ӿ� ��������?
	bool GetKeyDown(KeyType key);
	//Ű�� ������ �ִ���?
	bool GetKey(KeyType key);
	//Ű�� �̹������ӿ� ��������?
	bool GetKeyUp(KeyType key);

	void Init();
	void Update();
	void Release();
};
