#include <iostream>
using namespace std;
// 전역변수 선언
int _myVariable = 0;

void main()
{
	/*	전역변수
		삭제되지 않는 변수
	*/


	// 변수는 기본적으로 자신이 만들어진 중괄호를 끝을 만나면 메모리가 삭제된다.
	int a = 0;

	for (int i = 0; i < 2; i++)
	{
		// myVariable을 메모리에 선언 
		int myVariable = 0;
		// for 문이 한번 끝날때 myVariable이 삭제
		// 다시 한번 반복할때 다른 메모리 위치에 선언
	}
}