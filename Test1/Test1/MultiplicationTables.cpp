#include <iostream>
using namespace std;
/*
	- ������ �����
	- ����ڿ��Լ� ��ܱ��� ������ �����
	- ����ڰ� �Է��� ���� �����Ѵ� (int tableSize)
	- ����ڰ� �Է��� ���� ũ��� ���� �迭�� �����Ѵ� (int* table = new int[tableSize])
	- 1���� ũ�⸸ŭ �� ���� ���ڿ� ���� ���� ����Ѵ�
	- ���� ���� i ���� ���� ���� j�� �ϰ� �ݺ��� ����

*/


void main()
{
	int tableSize = 0;
	cout << "\t\t ������" << endl;
	cout << "[���Ͻô� �������� �� ������ �Է����ּ���.]" << endl;
	cin >> tableSize;
	int* table = new int[tableSize];
	for (int i = 1; i <= tableSize; i+=3)
	{
		for (int j = 1; j <= tableSize; j++)
		{
			for (int k = 0; k < 3; k++)
			{
				int num = i + k;
				if (num <= tableSize)
				{
					std::cout << num << " x " << j << " = " << (num * j) << "\t";
				}
				else
				{
					std::cout << "\t\t\t";
				}
			}
			cout << endl;
		}
		cout << endl;

	}

}