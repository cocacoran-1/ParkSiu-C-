#pragma once
//1. ������� include
// => ���� : ��ũ�̽��� ���������.
//2. Ŭ���� ���漱��
//3. ���漱��� �Բ� ����
// => ���� : ���������·θ� ���簡����
//	=>	���������´� 4����Ʈ¥�� �ּҰ��̰� ���빰�� 
//		�ƹ��͵� ���� ���¶� �����Ϸ��� �ν��ϴµ� ��������.
class SceneManager
{
	DECLARE_SINGLE(SceneManager)
public:
	void Init();
	void Render(HDC hdc);
	void Update();
	void Release();
	void ChangeScene();
private:
	class Scene* _scene = 0;
};

