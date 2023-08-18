#include<iostream>
#include<time.h>
#include<vector>
using namespace std;

/*
	- 로또 번호 생성기
	- 당첨 번호를 저장할 배열 선언
	- 1~45 까지의 수 중 랜덤으로 하나 선택
	- 중복되는 숫자가 있으면 다시 뽑기
	- 선택된 값을 배열에 저장
	- 위를 총 6번 시행
	- 당첨 번호를 작은 순서대로 출력
*/

void main()
{
	srand(time(NULL));
	vector<int> lotto;

	// 랜덤으로 숫자 선택
	for (int i = 0; i < 6; i++)
	{
		int num = rand() % 45 + 1;
		lotto.push_back(num);

	}

	for (int i = 0; i < 6; i++)
	{
		for (int j = 0; j < 6; j++)
		{
			if (i != j)
			{
				while (lotto[i] == lotto[j])
				{
					int num = rand() % 45 + 1;
					lotto[j] = num;
				}
			}
		}
	}

	// 순서대로 정렬
	for (int i = 0; i < 6; i++)
	{
		for (int j = 0; j < 6; j++)
		{
			if (i != j)
			{
				if (lotto[i] < lotto[j])
				{
					int temp = lotto[i];
					lotto[i] = lotto[j];
					lotto[j] = temp;
				}
			}
		}
	}
	for (int i = 0; i < lotto.size(); i++)
	{
		cout << lotto[i] << "\t";
	}
}