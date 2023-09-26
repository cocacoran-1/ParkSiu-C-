#pragma once
//1. 헤더파일 include
// => 문제 : 링크이슈가 생길수있음.
//2. 클래스 전방선언
//3. 전방선언과 함께 선언
// => 문제 : 포인터형태로만 존재가능함
//	=>	포인터형태는 4바이트짜리 주소값이고 내용물은 
//		아무것도 없는 상태라 컴파일러가 인식하는데 문제없음.
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

