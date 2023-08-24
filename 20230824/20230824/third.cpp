#include <iostream>

using namespace std;

void PlusOne1(int variable)
{
	variable++;
	cout << "Variable : " << variable << endl;
}

void PlusOne2(int& variable)
{
	variable++;
	cout << "Variable : " << variable << endl;
}

void main()
{
	int a = 3;
	// a 는 4가 안된다.
	PlusOne1(a);
	cout << "a : " << a << endl;

	int b = 3;

	PlusOne2(b);
	cout << "b : " << b << endl;
}