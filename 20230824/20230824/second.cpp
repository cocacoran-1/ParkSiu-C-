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
		�Լ�
		�Ȱ��� ������ �ڵ带 ���ȭ �ϴ� ��
		�ݺ��ؼ� �ڵ带 �ۼ��ϴ� ���� ����
		 --------------------
		��	�Լ� ���� ����  �� 
		 --------------------
		�ڷ��� �Լ���(�Ű�����)
		{
			�Լ���� ����
		}
	*/ 
	int choice = 0;

	cout << "Choose Rock or Scissors or Paper(Rock : 0, Scissors : 1, Paper : 2,)" << endl;
	cin >> choice;
	cout << "Your Choice : ";
	PrintRockScissorsPaper(choice);
}