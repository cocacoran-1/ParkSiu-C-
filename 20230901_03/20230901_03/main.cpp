#include<iostream>
#include<Windows.h>

using namespace std;

void main()
{
	// ������ - �迭 �����Ҵ�

	int* ptrArr = nullptr;
	ptrArr = new int(3);
	// �����ʹ� *�����ڸ� ����Ҽ� �ִ�
	cout << *ptrArr;
	int* myNumber = new int(3);

	delete ptrArr;
	ptrArr = nullptr;
	delete myNumber;
	myNumber = nullptr;

	int input;
	cin >> input;
	//int arr[input] = { 0, };
	// ��Ÿ�� ���߿� ������ ���̸�ŭ �迭������ �Ұ����ϴ�
	// ������ �츮�� �˴� �����迭�� ���̰� �������� �ʴ�

	int* ptrArr = new int[input] {0, };
	//new int[�迭ũ��[ {�ʱ�ȭ ����}

	for (int i = 0; i < input; i++)
	{
		ptrArr[i] = i;
	}

	int arr[52] = { 0, };
	for (int i = 0; i < 52; i++)
	{
		*(arr + i) = i;
	}

	delete[] ptrArr;
}