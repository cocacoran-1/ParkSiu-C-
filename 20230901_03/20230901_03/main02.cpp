#include <iostream>
#include <vector>
using namespace std;

void main()
{
	// ����

	/*	���Ͷ�? (�ڷᱸ��)
		���� �迭
		���� �迭 <== [�迭 �����Ҵ�]
		ũ�Ⱑ ���� �� �ִ� �迭
	*/
	vector<int> myVec;
	myVec.push_back(0);
	myVec.push_back(10);
	myVec.push_back(20);

	for (int i = 0; i < myVec.size(); i++)
	{
		cout << "myVec[" << i << "] : " << myVec[i] << endl;
	}
	vector<float> myVec2;
	myVec2.push_back(1.5);
	myVec2.push_back(3.2);
	myVec2.push_back(1.5);

	for (int i = 0; i < myVec2.size(); i++)
	{
		cout << "myVec[" << i << "] : " << myVec2[i] << endl;
	}

	//2���� �迭�� ���ͷ� �ٲٴ� ���
	vector<vector<int>> myBoard;
	for (int i = 0; i < 5; i++)
	{
		vector<int> row;
		for (int j = 0; j < 5 j++)
		{
			row.push_back(i * 5 + j);
		}
		myBoard.push_back(row);
	}
}