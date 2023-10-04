#pragma once
#include <bitset>
using namespace std;
//STL (vector�� ���� ����)
// �ξ�����, 
#define KEYMAX 256
class KeyManager
{
	DECLARE_SINGLE(KeyManager)

private:
	bitset<KEYMAX> _keyDown = {};
	//256���� �迭�� �������ش�.
	//�ڷ����� ��� BIT
public:
	//Ű�� ���� ��������?
	bool GetKeyDown(int vKey);
	//Ű�� ������ �ִ���?
	bool GetKey(int vKey);

	void Init();
	void Release();
};
