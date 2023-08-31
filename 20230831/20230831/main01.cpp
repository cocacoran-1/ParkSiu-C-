#include <iostream>

using namespace std;

void main()
{
	/*	1. 포인터 - 배열
		포인터
		4바이트로 이루어진 주소값
		* => 뒤에 오는 변수가 주소값이라고 했을 때, 해당 값에 접근
		& => 뒤에 오는 변수의 주소값

	*/
	int** a = nullptr;
	/*
		int* 이라고 생긴 변수의 주소값
		nullptr => 주소값이 없음.(할당된 값이 없다.)
	*/

	// 포인터 = 배열
	int arr[52] = { 0 };

	int* ptr = arr;
	cout << "arr : " << arr << endl;
	cout << "ptr: " << ptr << endl;
	for (int i = 0; i < 52; i++)
	{
		arr[i] = i;
	}
	cout << "arr[0] : " << arr[0] << endl;
	cout << "arr[1] : " << arr[1] << endl;
	cout << "*ptr :" << *ptr << endl;
	cout << "*(ptr + 1) :" << *(ptr + 1) << endl;

	for (int i = 0; i < 52; i++)
	{
		cout << "*(ptr + " << i << ") :" << *(ptr + i) << endl;
	}

	//1차원 배열은 1차원 포인터와 같다
	//2차원 배열은 2차원 포인터와 같다


}