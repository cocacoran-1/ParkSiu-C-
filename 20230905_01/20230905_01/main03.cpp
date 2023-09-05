#include<iostream>
#define MY_NUMBER 10
#define BRACKET_LEFT [
#define BRACKET_RIGHT ]

#define ADD(a, b) a + b
#define MULTIPLE(a,b) a * b
#define	MINUS(a,b) a - b
#define DIVISION(a,b) a / b

#define SAFE_DELETE(p) {if(p) {delete p; p = nullptr;}}
#define SAFE_DELETE_ARRAY(pArr) {if(pArr) {delete [] pArr; pArr = nullptr;}}
#define SAFE_RELEASE(p) {if(p) {p->Release(); p = NULL;}}

using namespace std;

class NumberInt {
public:
	int _hp;
	int	_damage;

	void Init() {
		_hp = 100;
		_damage = 10;
	}
	void Release() {

	}
};

void main()
{
	// ��ũ�� (#define)
	// #define ��ũ�θ� ���
	// �Ʒ� �ڵ忡�� ��ũ�θ��� ���� ������� ���� �����ִ� ��� 
	/*int arr[10];
	for (int i = 0; i < 10; i++)
	{
		arr[i] = i;
	}
	for (int i = 0; i < 10; i++)
	{
		cout << arr[i]<<endl;
	}

	for (int i = 0; i < 10; i++)
	{
		arr BRACKET_LEFT i BRACKET_RIGHT = i;
	}
	for (int i = 0; i < 10; i++)
	{
		cout << arr BRACKET_LEFT i BRACKET_RIGHT << endl;
	}

	cout << 1 << " + " << 2 << " = " << ADD(1, 2) << endl;*/
	// ��ũ�� �Լ��� ����Ͽ� ���� �����

	/*int num1, num2 = 0;
	int choice = 0;
	cout << "���� 1�� �Է����ּ��� : ";
	cin >> num1;
	cout << "���� 2�� �Է����ּ��� : ";
	cin >> num2;
	cout << "� ��Ģ������ �Ͻðڽ��ϱ� (���ϱ� : 0, ���� : 1, ���ϱ� : 2, ������ : 3)" << endl;
	cout << "���� : ";
	cin >> choice;

	switch (choice)
	{
	case 0:
		cout << num1 << " + " << num2 << " = " << ADD(num1, num2) << endl;
		break;
	case 1:
		cout << num1 << " - " << num2 << " = " << MINUS(num1, num2) << endl;
		break;
	case 2:
		cout << num1 << " * " << num2 << " = " << MULTIPLE(num1, num2) << endl;
		break;
	case 3:
		cout << num1 << " / " << num2 << " = " << DIVISION(num1, num2) << endl;
		break;
	default:
		break;
	}*/

	NumberInt* slime = new NumberInt();
	slime->Init();

	slime->Release();
	delete slime;
	// ���� slime = nullptr; �� ���� ������ delete�� �������� �����ִ�
	if (slime)
	{
		cout << "���� ���� ��ȭ1" << endl;
	}

	NumberInt* slime1 = new NumberInt();
	slime1->Init();
	slime1->Release();

	SAFE_DELETE(slime1);

	if (!slime1)
	{
		cout << "�������� �ʴ´�" << endl;
	}

	// �����͸� ����ϸ� �ּҰ��� ��µȴ�.
	// delete�� �ϸ� �����Ⱚ�� ����
	cout << "slime : " << slime << endl;
	cout << "slime1 : " << slime1 << endl;
	
	NumberInt* UnitList = new NumberInt[100]{};
	SAFE_DELETE_ARRAY(UnitList);
}