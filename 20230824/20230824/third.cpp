#include <iostream>

using namespace std;
/*
	�Ű� ������ �Է� �� ���� 
	�޸𸮿� ���� ����� variable�� ������
*/
void PlusOne1(int variable)
{
	variable++;
	cout << "Variable : " << variable << endl;
}

/*
	�ڷ��� �ڿ�& �� ���� ���
	variable �Ű� ������ �Է� �� ������ ���Ͻ� �Ѵ�
	�Ű������� ���� ���� variable�� ���� ��ȭ�ϸ� �Ű������� ���� ��ȭ �Ѵ�
*/ 
void PlusOne2(int& variable)
{
	variable++;
	cout << "Variable : " << variable << endl;
}

void main()
{
	int a = 3;
	// a �� 4�� �ȵȴ�. 3���� ���
	PlusOne1(a);
	cout << "a : " << a << endl;

	int b = 3;
	// b �� 4�� �ȴ�
	PlusOne2(b);
	cout << "b : " << b << endl;
}