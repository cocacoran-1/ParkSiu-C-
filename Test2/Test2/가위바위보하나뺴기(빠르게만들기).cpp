#include<iostream>
#include <time.h>
using namespace std;

/*	
	- ���������� �ϳ�����
	- ����ڰ� ���� ���� �� �߿� 2���� �����Ѵ�
	- ��ǻ�Ͱ� ���� ���� �� �߿� 2���� �����Ѵ�
	- ����ڿ� ��ǻ�Ͱ� ������ �� 2���� ����Ѵ�
	- ����ڰ� �ڽ��� ������ 2���߿� �ϳ��� �����Ѵ�
	- ��ǻ�Ͱ� ������ 2�� �߿� �ϳ��� �����Ѵ�
	- ���������� ������ �͵� ���� ���и� ���Ѵ�
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
		cout << "���� ";
	}
	else if (num == Rock)
	{
		cout << "���� ";
	}
	else if (num == Paper)
	{
		cout << "�� ";
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

	cout << "\t\t���� ���� �� �ϳ� ����" << endl;;
	cout << "���� ���� ������ 2���� �������ּ��� (���� : 0 , ���� : 1, �� : 2 )" << endl;
	cout << "����1 : ";
	cin >> playerChoice[0];
	cout << "����2 : ";
	cin >> playerChoice[1];

	for (int i = 0; i < 2; i++)
	{
		randomNum = rand() % 3;
		computerChoice[i] = randomNum;
	}
	cout << "�÷��̾� : ";
	printRockScissorsPaper(playerChoice[0]);
	printRockScissorsPaper(playerChoice[1]);
	cout << "\t��ǻ�� : ";
	printRockScissorsPaper(computerChoice[0]);
	printRockScissorsPaper(computerChoice[1]);
	cout << endl;
	printRockScissorsPaper(playerChoice[0]);
	printRockScissorsPaper(playerChoice[1]);
	cout << "���� �ϳ��� ������ �ּ��� (���� 1 : 0, ���� 2: 1)" << endl;
	cout << "������ ���� : ";
	cin >> playerFinal;

	randomNum = rand() % 2;
	computerFinal = randomNum;
	cout << "�÷��̾� : ";
	printRockScissorsPaper(playerChoice[playerFinal]);
	cout << "\t��ǻ�� : ";
	printRockScissorsPaper(computerChoice[computerFinal]);
	cout << endl;

	if (playerChoice[playerFinal] == computerChoice[computerFinal])
	{
		cout << "���º�!!!";
	}
	else if (playerChoice[playerFinal] == Scissors && computerChoice[computerFinal] == Rock)
	{
		cout << "�й�...";
	}
	else if (playerChoice[playerFinal] == Rock && computerChoice[computerFinal] == Paper)
	{
		cout << "�й�...";
	}
	else if (playerChoice[playerFinal] == Paper && computerChoice[computerFinal] == Scissors)
	{
		cout << "�й�...";
	}
	else if (playerChoice[playerFinal] == Scissors && computerChoice[computerFinal] == Paper)
	{
		cout << "�¸�!!!";
	}
	else if (playerChoice[playerFinal] == Rock && computerChoice[computerFinal] == Scissors)
	{
		cout << "�¸�!!!";
	}
	else if (playerChoice[playerFinal] == Paper && computerChoice[computerFinal] == Rock)
	{
		cout << "�¸�!!!";
	}
}