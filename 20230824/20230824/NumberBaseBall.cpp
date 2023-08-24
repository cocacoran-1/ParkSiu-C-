#include <iostream>

using namespace std;
int _answer[4] = { };
int _input[4] = { };
int _strike = 0;
int _ball = 0;
int _out = 4;

bool isDuplication(int arr[])
{
	// �ߺ��� ���� ã��
	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < 4; j++)
		{
			if (i != j)
			{
				// �ߺ��� ���
				if (arr[i] == arr[j])
				{
					return false;
				}
			}

		}
	}
	return true;
}

void main()
{
	/*
		������ ���� �̱�
		��ǻ�Ͱ� ���� �� answer[4]�� ����
		�ش� �迭�� ������ ���ڸ� �ִ´� 
		���� ���� �ߺ��Ǵ� ��� �ٽ� �̴´�

		����ڰ� ���ڸ� ���� 
		����ڰ� �� ���� input[4]�� ����
		����ڰ� �Է��� ���ڸ� �� �ڸ������� ������ �ش� �迭�� �ִ´�

		��Ʈ����ũ �� �ƿ� �Ǻ��ϱ�
	*/
	srand(time(NULL));
	bool answerDuplication = true;
	bool inputDuplication = true;
	do
	{

		for (int i = 0; i < 4; i++)
		{
			// ù �ڸ��� 1~9
			if (i == 0)
			{
				_answer[i] = rand() % 9 + 1;
			}
			// �������� 0~9
			else
			{
				_answer[i] = rand() % 10;
			}
		}
		answerDuplication = isDuplication(_answer);
	} while (!answerDuplication);

	for (int i = 0; i < 4; i++)
	{
		cout << _answer[i] << endl;
	}

	while (true)
	{
		_strike = 0;
		_ball = 0;
		_out = 4;
		// ����ڰ� ���� ����
		do
		{
			int playerNum;
			cin >> playerNum;
			_input[0] = playerNum / 1000;
			_input[1] = playerNum / 100 % 10;
			_input[2] = playerNum / 10 % 10;
			_input[3] = playerNum % 10;
			inputDuplication = isDuplication(_input);
		} while (!inputDuplication);

		for (int i = 0; i < 4; i++)
		{
			cout << _input[i] << endl;
		}

		for (int i = 0; i < 4; i++)
		{
			for (int j = 0; j < 4; j++)
			{
				if (_answer[i] == _input[j])
				{
					if (i == j)
					{
						_strike++;
					}
					else
					{
						_ball++;
					}
				}
			}
		}
		_out -= (_strike + _ball);

		cout << "Strike : " << _strike << endl;
		cout << "Ball : " << _ball << endl;
		cout << "Out : " << _out << endl;
		
		if (_strike == 4)
		{
			cout << "\t\tG A M E O V E R";
			break;
		}
		
	}
	
}