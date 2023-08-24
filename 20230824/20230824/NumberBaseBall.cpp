#include <iostream>

using namespace std;
int _answer[4] = { };
int _input[4] = { };
int _strike = 0;
int _ball = 0;
int _out = 4;

bool isDuplication(int arr[])
{
	// 중복된 숫자 찾기
	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < 4; j++)
		{
			if (i != j)
			{
				// 중복인 경우
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
		랜덤한 숫자 뽑기
		컴퓨터가 뽑은 수 answer[4]로 정의
		해당 배열에 랜덤한 숫자를 넣는다 
		넣은 값이 중복되는 경우 다시 뽑는다

		사용자가 숫자를 고른다 
		사용자가 고른 숫자 input[4]로 정의
		사용자가 입력한 숫자를 각 자릿수마다 나눠서 해당 배열에 넣는다

		스트라이크 볼 아웃 판별하기
	*/
	srand(time(NULL));
	bool answerDuplication = true;
	bool inputDuplication = true;
	do
	{

		for (int i = 0; i < 4; i++)
		{
			// 첫 자리는 1~9
			if (i == 0)
			{
				_answer[i] = rand() % 9 + 1;
			}
			// 나머지는 0~9
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
		// 사용자가 숫자 고르기
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