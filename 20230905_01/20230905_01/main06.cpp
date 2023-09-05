#include <iostream>
#include <vector>

using namespace std;

void main()
{
	vector<int> myVec;

	for (int i = 0; i < 10; i++)
	{
		myVec.push_back(i + 1);
	}

	//	�� ��ȸ ���� ���
	//	1.
	cout << "1��" << endl;
	for (int i = 0; i < myVec.size(); i++)
	{
		cout << myVec[i] << endl;
	}
	//	2. iterator : ��ȸ�� �� �ʿ��� ���� ��ġ
	cout << "2��" << endl;

	for (vector<int>::iterator iter = myVec.begin(); iter < myVec.end(); iter++)
	{
		cout << *iter << endl;
	}
	for (auto iter = myVec.begin(); iter < myVec.end(); iter++)
	{
		cout << *iter << endl;
	}
	// ����
	for (vector<int>::reverse_iterator iter = myVec.rbegin(); iter < myVec.rend(); iter++)
	{
		cout << *iter << endl;
	}
	for (auto iter = myVec.rbegin(); iter < myVec.rend(); iter++)
	{
		cout << *iter << endl;
	}
	
	//	auto 
	//	������ �ܰ� �� � �ڷ����� ���� �����ȴ�
	//	��ȣ�ϴ� ���� ���� ������ ���� ������ ��� ���� �ʴ´�
	//	auto&, auto*, auto => ���� auto �ڷ����� ������ ���� ���?
	auto num = 1.1;
	cout << "num : " << num << endl;

	cout << "3��" << endl;
	//	3.
	// �ش� ������δ� �� ������ ���� �ʰ� ���縸 �Ǽ� �ٲ��� �ʴ´�
	for (int number : myVec)
	{
		if (number == 2)
		{
			number = 20;
		}
	}
	for (int number : myVec)
	{
		cout << number << endl;
	}
	// �Ʒ� ������δ� ���� �ٲ� �� �ִ� ������ index�� ���� ���Ѵ�
	for (int& number : myVec)
	{
		if (number == 2)
		{
			number = 20;
		}
	}
	for (int number : myVec)
	{
		cout << number << endl;
	}

	//	�� ����
	vector<int>::iterator iter = myVec.begin();
	// 3��° �ε����� �����Ѵ�
	myVec.erase(iter + 3);
	for (int number : myVec)
	{
		cout << number << endl;
	}

}