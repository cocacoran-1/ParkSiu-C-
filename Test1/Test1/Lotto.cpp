#include<iostream>
#include<time.h>
#include<vector>
using namespace std;

/*
	- �ζ� ��ȣ ������
	- ��÷ ��ȣ�� ������ �迭 ����
	- 1~45 ������ �� �� �������� �ϳ� ����
	- �ߺ��Ǵ� ���ڰ� ������ �ٽ� �̱�
	- ���õ� ���� �迭�� ����
	- ���� �� 6�� ����
	- ��÷ ��ȣ�� ���� ������� ���
*/

void main()
{
	srand(time(NULL));
	vector<int> lotto;

	// �������� ���� ����
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

	// ������� ����
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