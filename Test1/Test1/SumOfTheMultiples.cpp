#include<iostream>
#include<vector>
using namespace std;

/*
	- 1 ~ 1000������ ���� �߿��� 2�� ����� 3�� ����� ���� �� (��, 6�� ����� �����Ѵ�)
	- 2�� ����̰ų� 3�� ����� ���� �迭�� �߰��ϰ� 2�� ���,3�� ����� ������ ��� �����ϴ� ���� �߰����� �ʴ´�
	- �迭�� ũ�⸸ŭ �迭�� ������ ��� ����Ѵ�
*/
void main()
{
	vector<int> multiple;

	for (int i = 1; i <= 1000; i++)
	{

		if ((i % 2 == 0 || i % 3 == 0) && !(i % 6 == 0))
		{
			multiple.push_back(i);
		}
	}

	for (int i = 0; i < multiple.size(); i++)
	{
		cout << multiple[i] << endl;
	}
}