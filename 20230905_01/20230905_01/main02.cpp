#include <iostream>
using namespace std;

class NumberInt
{
public:
	void Init();
	void Release();

	NumberInt();
	~NumberInt();
};

void NumberInt::Init()
{
	cout << "Unit::Init()" << endl;
}

void NumberInt::Release()
{
	cout << "Unit::Release()" << endl;
}

NumberInt::NumberInt()
{
	// new ���ً� ȣ�� (��ü�� �����ɋ� ȣ��) �ѹ��� 
	cout << "������" << endl;
}

NumberInt::~NumberInt()
{
	// delete ���ً� ȣ�� (��ü�� �Ҹ�ɋ� ȣ��) �ѹ��� 
	cout << "�Ҹ���" << endl;
}

void main()
{
	// �����ڿ� �Ҹ���
	NumberInt* myUnit = new NumberInt();
	myUnit->Init();

	{
		NumberInt myUnit2;
		system("pause");
	}

	myUnit->Release();
	delete myUnit;
	myUnit = nullptr;
	
	// ������ �Ҹ��� ��� Init�� Release�� ����ؾ��ϴ� ����

	// 1. �����ڿ� �Ҹ��ڴ� �� �ѹ��� ȣ���

	// new, delete�� ��� �ſ� ���̱� ������ 
	// �ε������� new, delete�� �̷������
	// �ʱ�ȭ�� �����ش�
	// ���� ����� �� Init ,Release�� ����Ѵ�
}

