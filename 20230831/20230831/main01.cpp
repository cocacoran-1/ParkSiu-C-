#include <iostream>

using namespace std;

void main()
{
	/*	1. ������ - �迭
		������
		4����Ʈ�� �̷���� �ּҰ�
		* => �ڿ� ���� ������ �ּҰ��̶�� ���� ��, �ش� ���� ����
		& => �ڿ� ���� ������ �ּҰ�

	*/
	int** a = nullptr;
	/*
		int* �̶�� ���� ������ �ּҰ�
		nullptr => �ּҰ��� ����.(�Ҵ�� ���� ����.)
	*/

	// ������ = �迭
	int arr[52] = { 0 };

	int* ptr = arr;
	cout << "arr : " << arr << endl;
	cout << "ptr: " << ptr << endl;
	for (int i = 0; i < 52; i++)
	{
		arr[i] = i;
	}
	cout << "arr[0] : " << arr[0] << endl;
	cout << "arr[1] : " << arr[1] << endl;
	cout << "*ptr :" << *ptr << endl;
	cout << "*(ptr + 1) :" << *(ptr + 1) << endl;

	for (int i = 0; i < 52; i++)
	{
		cout << "*(ptr + " << i << ") :" << *(ptr + i) << endl;
	}

	//1���� �迭�� 1���� �����Ϳ� ����
	//2���� �迭�� 2���� �����Ϳ� ����


}