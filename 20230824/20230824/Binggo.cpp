#include <iostream>
#include<time.h>
#include<Windows.h>

int _input[25] = {};
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
	int Binggo[25];
	int binggoLine;
	bool isPlayer;

	void init()
	{
		for (int i = 0; i < 25; i++)
		{
			Binggo[i] = i + 1;
		}
	}
	void shuffle(int binggo[])
	{
		for (int i = 0; i < 10000; i++)
		{
			int rand1 = rand() % 25;
			int rand2 = rand() % 25;
			int temp = binggo[rand1];
			binggo[rand1] = binggo[rand2];
			binggo[rand2] = temp;
		}
	}
	void showBinggo(int binggo[], int input[])
	{
		int num = 1;

		for (int i = 0; i < 25; i++)
		{
			bool isSame = false;
			for (int j = 0; j < 25; j++)
			{
				if (binggo[i] == input[j])
				{
					isSame = true;
				}
			}
			if (isSame)
			{
				cout << "#\t";
			}
			else
			{
				cout << binggo[i] << "\t";
			}

			if (num == 5)
			{
				cout << endl;
				num = 0;
			}
			num++;
		}
	}
};


void numInput(int myBinggo[], int comBinggo[], int input[], int& playTime, bool isPlayer)
{
	bool isSame = true;
	if (isPlayer)
	{
		while (isSame)
		{
			cout << "\t[�÷��̾� ����]" << endl;
			cout << "1~25������ ���� �� �ϳ��� �������ּ���" << endl;
			cin >> input[playTime];
			cout << "�÷��̾� ���� : " << input[playTime] << endl;

			for (int i = 0; i < 25; i++)
			{
				if (i != playTime)
				{
					if (input[playTime] == input[i])
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
		cout << "\t[��ǻ�� ����]" << endl;

		while (isSame)
		{
			input[playTime] = rand() % 25 + 1;
			isSame = false;
			for (int i = 0; i < 25; i++)
			{
				if (i != playTime)
				{
					if (input[playTime] == input[i])
					{
						isSame = true;
						break;
					}
				}
			}
		}
		cout << "��ǻ�� ���� : " << input[playTime] << endl;
	}

	playTime++;
}
void checkBinggo(int binggo[], int& binggoLine, int input[])
{
	// ���� Ȯ��
	for (int i = 0; i < 5; i++)
	{
		int same = 0;
		for (int j = 0; j < 5; j++)
		{
			for (int k = 0; k < 25; k++)
			{
				if (binggo[i + j * 5] == input[k])
				{
					same++;
				}
			}

		}
		if (same == 5)
		{
			binggoLine++;
		}
	}
	//���� Ȯ��
	for (int i = 0; i < 5; i++)
	{
		int same = 0;
		for (int j = 0; j < 5; j++)
		{
			for (int k = 0; k < 25; k++)
			{
				if (binggo[i * 5 + j] == input[k])
				{
					same++;
				}
			}
		}
		if (same == 5)
		{
			binggoLine++;
		}
	}
}

void main()
{
	Unit my;
	Unit com;
	my.isPlayer = true;
	my.binggoLine = 0;
	com.isPlayer = false;
	com.binggoLine = 0;
	int playTime = 0;
	bool isBinggo = false;

	srand(time(NULL));

	system("cls");

	cout << "\t  �÷��̾� ����" << endl;
	my.init();
	my.shuffle(my.Binggo);
	my.showBinggo(my.Binggo, _input);
	cout << endl;
	cout << "\t   ��ǻ�� ����" << endl;
	com.init();
	com.shuffle(com.Binggo);
	com.showBinggo(com.Binggo, _input);

	do
	{
		numInput(my.Binggo, com.Binggo, _input, playTime, my.isPlayer);
		cout << "\t  �÷��̾� ����" << endl;
		my.showBinggo(my.Binggo, _input);
		cout << "\t   ��ǻ�� ����" << endl;
		com.showBinggo(com.Binggo, _input);

		numInput(my.Binggo, com.Binggo, _input, playTime, com.isPlayer);
		cout << "\t  �÷��̾� ����" << endl;
		my.showBinggo(my.Binggo, _input);
		cout << "\t   ��ǻ�� ����" << endl;
		com.showBinggo(com.Binggo, _input);

		checkBinggo(my.Binggo, my.binggoLine, _input);
		checkBinggo(com.Binggo, com.binggoLine, _input);

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