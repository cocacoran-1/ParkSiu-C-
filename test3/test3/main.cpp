#include<iostream>
#define MY_VALUE 3
#define MY_MACRO << endl

using namespace std;

void main()
{
	// 전처리기
	cout << MY_VALUE MY_MACRO;
	cout << MY_VALUE MY_MACRO;
}