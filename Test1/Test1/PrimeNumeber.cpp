#include<iostream>
#include<vector>
using namespace std;
/*
	- 1 ~ 1000까지의 숫자 중에서 소수들만 더해서 출력하기
	- 숫자들을 저장할 배열 선언
	- 소수는 1과 자기 자신으로만 나누어진다
	- 자기 자신보다 작은 수로 나누어서 나머지가 0이면 제외
*/
void main()
{
	vector<int> primeNum;

	for (int i = 2; i <= 1000; i++)
	{
		bool isPrime = true;
		for (int j = 2; j< i; j++)
		{
			if (i % j == 0)
			{
				isPrime = false;
				break;
			}
		}

		if (isPrime)
		{
			primeNum.push_back(i);
		}
	}

	for (int i = 0; i < primeNum.size(); i++)
	{
		cout << primeNum[i] << endl;
	}
}