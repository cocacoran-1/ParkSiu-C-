#include <iostream>

using namespace std;

void main()
{
	/* 
		���� �Ҵ�?
		��Ÿ�� ���߿� �޸𸮸� �Ҵ�
		�츮 ����� ������ ����

		�޸� ����
		Stack, Heap

		Stack => �޸� ������ �������, ������. �����Ҵ� , 2MB
		Heap => �޸� ������ ū���, ������. �����Ҵ� , RAM ũ��

		
	*/

	//�����Ҵ� 
	//int* num = new int(3);
	/*
		num -> ���� �߻�
		new int(��)
		int��� �ڷ����� �����ϰ� ������ �ּҰ��� �����Ѵ�.
	*/
	int* num = nullptr;
	num = new int(3);
	//new, delete

	if (true)
	{
		//num3 ����
		int num3 = 0;
	}
	// num3 �ı�
	
	// num �ı�
	delete num;
	num = nullptr;

	// new�� ��������
	// delete�� ���ִ� �ڵ嵵 ��򰡿� �־�� �Ѵ�.

	/*	class
		class => �����Ҵ�

		����������
		MainGame �̶�� Ŭ������ ����� 
		�����Ҵ����� �ٷ�� ����
	*/ 
}