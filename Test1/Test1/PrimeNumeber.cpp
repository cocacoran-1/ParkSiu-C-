#include<iostream>
#include<vector>
using namespace std;
/*
	- 1 ~ 1000������ ���� �߿��� �Ҽ��鸸 ���ؼ� ����ϱ�
	- ���ڵ��� ������ �迭 ����
	- �Ҽ��� 1�� �ڱ� �ڽ����θ� ����������
	- �ڱ� �ڽź��� ���� ���� ����� �������� 0�̸� ����
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