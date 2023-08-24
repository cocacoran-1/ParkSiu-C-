#include <iostream>

using namespace std;
enum RockScissorsPaper
{
	Rock,
	Scissors,
	Paper,
	END
};
void PrintRockScissorsPaper(int num)
{
	if (num == Rock)
	{
		cout << "Rock";
	}
	else if (num == Scissors)
	{
		cout << "Scissors";
	}
	else if (num == Paper)
	{
		cout << "Paper";
	}
}

void main()
{
	/*	
		함수
		똑같은 내용의 코드를 모듈화 하는 것
		반복해서 코드를 작성하는 것을 방지
		 --------------------
		ㅣ	함수 선언 공식  ㅣ 
		 --------------------
		자료형 함수명(매개변수)
		{
			함수기능 정의
		}
	*/ 
	int choice = 0;

	cout << "Choose Rock or Scissors or Paper(Rock : 0, Scissors : 1, Paper : 2,)" << endl;
	cin >> choice;
	cout << "Your Choice : ";
	PrintRockScissorsPaper(choice);
}