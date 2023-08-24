#include <iostream>

using namespace std;
/*
	매개 변수에 입력 된 값을 
	메모리에 따로 선언된 variable이 가진다
*/
void PlusOne1(int variable)
{
	variable++;
	cout << "Variable : " << variable << endl;
}

/*
	자료형 뒤에& 를 붙인 경우
	variable 매개 변수에 입력 된 변수와 동일시 한다
	매개변수의 값을 받은 variable의 값이 변화하면 매개변수의 값도 변화 한다
*/ 
void PlusOne2(int& variable)
{
	variable++;
	cout << "Variable : " << variable << endl;
}

void main()
{
	int a = 3;
	// a 는 4가 안된다. 3으로 출력
	PlusOne1(a);
	cout << "a : " << a << endl;

	int b = 3;
	// b 는 4가 된다
	PlusOne2(b);
	cout << "b : " << b << endl;
}