#include <iostream>

using namespace std;

void main()
{
	/* 
		동적 할당?
		런타임 도중에 메모리를 할당
		우리 맘대로 삭제도 가능

		메모리 개념
		Stack, Heap

		Stack => 메모리 공간이 작은대신, 빠르다. 정적할당 , 2MB
		Heap => 메모리 공간이 큰대신, 느리다. 동적할당 , RAM 크기

		
	*/

	//동적할당 
	//int* num = new int(3);
	/*
		num -> 에러 발생
		new int(값)
		int라는 자료형을 생성하고 생성된 주소값을 리턴한다.
	*/
	int* num = nullptr;
	num = new int(3);
	//new, delete

	if (true)
	{
		//num3 생성
		int num3 = 0;
	}
	// num3 파괴
	
	// num 파괴
	delete num;
	num = nullptr;

	// new를 해줬으면
	// delete를 해주는 코드도 어딘가에 있어야 한다.

	/*	class
		class => 동적할당

		가위바위보
		MainGame 이라는 클래스를 만들고 
		동적할당으로 다루는 형식
	*/ 
}