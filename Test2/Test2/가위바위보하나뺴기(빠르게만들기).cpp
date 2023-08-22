#include<iostream>
#include <time.h>
using namespace std;

/*	
	- 가위바위보 하나빼기
	- 사용자가 가위 바위 보 중에 2개를 선택한다
	- 컴퓨터가 가위 바위 보 중에 2개를 선택한다
	- 사용자와 컴퓨터가 선택한 것 2개를 출력한다
	- 사용자가 자신이 선택한 2개중에 하나를 선택한다
	- 컴퓨터가 선택한 2개 중에 하나를 선택한다
	- 최종적으로 선택한 것들 끼리 승패를 비교한다
*/
enum RockScissorsPaper
{
	Scissors,
	Rock,
	Paper
};
void printRockScissorsPaper(int num)
{
	if (num == Scissors)
	{
		cout << "가위 ";
	}
	else if (num == Rock)
	{
		cout << "바위 ";
	}
	else if (num == Paper)
	{
		cout << "보 ";
	}
}
void main()
{
	srand(time(NULL));
	int playerChoice[2] = { 0, };
	int playerFinal = 0;
	int computerChoice[2] = { 0, };
	int computerFinal = 0;
	int randomNum = 0;

	cout << "\t\t가위 바위 보 하나 빼기" << endl;;
	cout << "가위 바위 보에서 2개를 선택해주세요 (가위 : 0 , 바위 : 1, 보 : 2 )" << endl;
	cout << "선택1 : ";
	cin >> playerChoice[0];
	cout << "선택2 : ";
	cin >> playerChoice[1];

	for (int i = 0; i < 2; i++)
	{
		randomNum = rand() % 3;
		computerChoice[i] = randomNum;
	}
	cout << "플레이어 : ";
	printRockScissorsPaper(playerChoice[0]);
	printRockScissorsPaper(playerChoice[1]);
	cout << "\t컴퓨터 : ";
	printRockScissorsPaper(computerChoice[0]);
	printRockScissorsPaper(computerChoice[1]);
	cout << endl;
	printRockScissorsPaper(playerChoice[0]);
	printRockScissorsPaper(playerChoice[1]);
	cout << "에서 하나를 선택해 주세요 (선택 1 : 0, 선택 2: 1)" << endl;
	cout << "마지막 선택 : ";
	cin >> playerFinal;

	randomNum = rand() % 2;
	computerFinal = randomNum;
	cout << "플레이어 : ";
	printRockScissorsPaper(playerChoice[playerFinal]);
	cout << "\t컴퓨터 : ";
	printRockScissorsPaper(computerChoice[computerFinal]);
	cout << endl;

	if (playerChoice[playerFinal] == computerChoice[computerFinal])
	{
		cout << "무승부!!!";
	}
	else if (playerChoice[playerFinal] == Scissors && computerChoice[computerFinal] == Rock)
	{
		cout << "패배...";
	}
	else if (playerChoice[playerFinal] == Rock && computerChoice[computerFinal] == Paper)
	{
		cout << "패배...";
	}
	else if (playerChoice[playerFinal] == Paper && computerChoice[computerFinal] == Scissors)
	{
		cout << "패배...";
	}
	else if (playerChoice[playerFinal] == Scissors && computerChoice[computerFinal] == Paper)
	{
		cout << "승리!!!";
	}
	else if (playerChoice[playerFinal] == Rock && computerChoice[computerFinal] == Scissors)
	{
		cout << "승리!!!";
	}
	else if (playerChoice[playerFinal] == Paper && computerChoice[computerFinal] == Rock)
	{
		cout << "승리!!!";
	}
}