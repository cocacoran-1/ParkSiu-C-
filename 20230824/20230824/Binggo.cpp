#include <iostream>
#include<time.h>
#include<Windows.h>
#define BINGO_SIZE 5
#define BOARD_SIZE (BINGO_SIZE * BINGO_SIZE)

int _input[BOARD_SIZE] = {};
int playTime = 0;
using namespace std;
/*
	���� ����
	5x5�� �̷���� ��ǻ�Ϳ� ���� ��
	�� ������ �ȿ��� 1~25�� ���ڰ� ����
	����� -> ��ǻ�� -> ����� -> ��ǻ�� ������ �ݺ�
	���� ������ �� �θ� ���ڴ� ���ڷ� ǥ�� �ȵǰ� #�� ǥ��
*/

struct Unit
{
	int Binggo[BOARD_SIZE];
	int binggoLine;
	bool isPlayer;

	void init()
	{
		for (int i = 0; i < BOARD_SIZE; i++)
		{
			Binggo[i] = i + 1;
		}
	}
	void shuffle()
	{
		for (int i = 0; i < 10000; i++)
		{
			int rand1 = rand() % BOARD_SIZE;
			int rand2 = rand() % BOARD_SIZE;
			int temp = Binggo[rand1];
			Binggo[rand1] = Binggo[rand2];
			Binggo[rand2] = temp;
		}
	}
	void showBinggo()
	{
		int num = 1;

		for (int i = 0; i < BOARD_SIZE; i++)
		{
			bool isSame = false;
			for (int j = 0; j < BOARD_SIZE; j++)
			{
				if (Binggo[i] == _input[j])
				{
					isSame = true;
				}
			}
			if (isSame)
			{
				cout << "��\t";
			}
			else
			{
				cout << Binggo[i] << "\t";
			}

			if (num == 5)
			{
				cout << endl;
				num = 0;
			}
			num++;
		}
	}
	void checkBinggo()
	{
		// ���� Ȯ��
		for (int i = 0; i < BINGO_SIZE; i++)
		{
			int same = 0;
			for (int j = 0; j < BINGO_SIZE; j++)
			{
				for (int k = 0; k < BOARD_SIZE; k++)
				{
					if (Binggo[i + j * BINGO_SIZE] == _input[k])
					{
						same++;
					}
				}

			}
			if (same == BINGO_SIZE)
			{
				binggoLine++;
			}
		}
		//���� Ȯ��
		for (int i = 0; i < BINGO_SIZE; i++)
		{
			int same = 0;
			for (int j = 0; j < BINGO_SIZE; j++)
			{
				for (int k = 0; k < BOARD_SIZE; k++)
				{
					if (Binggo[i * BINGO_SIZE + j] == _input[k])
					{
						same++;
					}
				}
			}
			if (same == BINGO_SIZE)
			{
				binggoLine++;
			}
		}
		// �밢�� Ȯ��
		for (int i = 0; i < BINGO_SIZE; i++)
		{
			int same = 0;
			for (int j = 0; j < BOARD_SIZE; j++)
			{
				if (Binggo[i * 6] == _input[j])
				{
					same++;
				}
			}
			if (same == BINGO_SIZE)
			{
				binggoLine++;
			}
		}
		for (int i = 0; i < BINGO_SIZE; i++)
		{
			int same = 0;
			for (int j = 0; j < BOARD_SIZE; j++)
			{
				if (Binggo[i * 4] == _input[j])
				{
					same++;
				}
			}
			if (same == BINGO_SIZE)
			{
				binggoLine++;
			}
		}
	}
	void numInput()
	{
		bool isSame = true;
		if (isPlayer)
		{
			while (isSame)
			{
				cout << endl << "\t  [�÷��̾� ����]" << endl;
				cout << "1~25������ ���� �� �ϳ��� �������ּ���" << endl;
				cin >> _input[playTime];
				cout << "�÷��̾� ���� : " << _input[playTime] << endl << endl;

				for (int i = 0; i < BOARD_SIZE; i++)
				{
					if (i != playTime)
					{
						if (_input[playTime] == _input[i])
						{
							cout << "�̹� ���õ� �����Դϴ�. �ٽ� �������ּ���" << endl;
							isSame = true;
						}
						else
						{
							isSame = false;
						}
					}
				}
			}
		}
		else
		{
			isSame = true;
			cout << endl << "\t   [��ǻ�� ����]" << endl;

			while (isSame)
			{
				_input[playTime] = rand() % BOARD_SIZE + 1;
				isSame = false;
				for (int i = 0; i < BOARD_SIZE; i++)
				{
					if (i != playTime)
					{
						if (_input[playTime] == _input[i])
						{
							isSame = true;
							break;
						}
					}
				}
			}
			cout << "��ǻ�� ���� : " << _input[playTime] << endl << endl;
		}
		playTime++;
	}
};





void main()
{
	Unit my;
	my.isPlayer = true;
	my.binggoLine = 0;

	Unit com;
	com.isPlayer = false;
	com.binggoLine = 0;

	bool isBinggo = false;

	srand(time(NULL));

	system("cls");

	cout << "\t  �÷��̾� ����" << endl;
	my.init();
	my.shuffle();
	my.showBinggo();
	cout << endl;
	cout << "\t   ��ǻ�� ����" << endl;
	com.init();
	com.shuffle();
	com.showBinggo();

	do
	{
		my.numInput();
		cout << "\t  �÷��̾� ����" << endl;
		my.showBinggo();
		cout << endl << "\t   ��ǻ�� ����" << endl;
		com.showBinggo();

		com.numInput();
		cout << "\t  �÷��̾� ����" << endl;
		my.showBinggo();
		cout << endl << "\t   ��ǻ�� ����" << endl;
		com.showBinggo();

		my.checkBinggo();
		com.checkBinggo();

		if (my.binggoLine == 3)
		{
			cout << "\t\t�÷��̾� �¸�!!!";
			isBinggo = true;
		}
		else if (com.binggoLine == 3)
		{
			cout << "\t\t��ǻ�� �¸�....";
			isBinggo = true;
		}
		else
		{
			my.binggoLine = 0;
			com.binggoLine = 0;
		}

	} while (!isBinggo);


	system("pause");

}