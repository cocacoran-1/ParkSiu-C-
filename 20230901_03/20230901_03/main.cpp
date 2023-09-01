#include<iostream>
#include<Windows.h>

using namespace std;

void main()
{
	// 포인터 - 배열 동적할당

	int* ptrArr = nullptr;
	ptrArr = new int(3);
	// 포인터는 *연산자를 사용할수 있다
	cout << *ptrArr;
	int* myNumber = new int(3);

	delete ptrArr;
	ptrArr = nullptr;
	delete myNumber;
	myNumber = nullptr;

	int input;
	cin >> input;
	//int arr[input] = { 0, };
	// 런타임 도중에 결정된 길이만큼 배열생성이 불가능하다
	// 기존에 우리가 알던 정석배열은 길이가 자유롭지 않다

	int* ptrArr = new int[input] {0, };
	//new int[배열크기[ {초기화 내용}

	for (int i = 0; i < input; i++)
	{
		ptrArr[i] = i;
	}

	int arr[52] = { 0, };
	for (int i = 0; i < 52; i++)
	{
		*(arr + i) = i;
	}

	delete[] ptrArr;
}