#include <iostream>
using namespace std;
/*
	- 구구단 만들기
	- 사용자에게서 몇단까지 만들지 물어본다
	- 사용자가 입력한 값을 저장한다 (int tableSize)
	- 사용자가 입력한 값의 크기와 같은 배열을 선언한다 (int* table = new int[tableSize]) 
	- 1부터 크기만큼 각 단의 숫자에 곱한 값을 출력한다
	- 현재 단을 i 현재 곱할 수를 j로 하고 반복문 생성

*/


void main()
{
	int tableSize = 0;
	cout << "\t\t 구구단" << endl;
	cout << "[원하시는 구구단의 단 개수를 입력해주세요.]"<<endl;
	cin >> tableSize;
	int* table = new int[tableSize];

	for (int i = 1; i <= tableSize; i++)
	{
		for (int j = 1; j <= tableSize; j++)
		{
			cout << j << "X" << i << "=" << i * j <<"\t";
		}
		cout << endl;
	}

}