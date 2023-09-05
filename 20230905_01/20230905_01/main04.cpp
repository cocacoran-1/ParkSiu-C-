#include <iostream>

using namespace std;

class NumberInt
{
public:
	int _number;

	void Init(int number);
	void Release();

	NumberInt operator+(NumberInt otherNumber);
	NumberInt operator-(NumberInt otherNumber);
	NumberInt operator*(NumberInt otherNumber);
	NumberInt operator/(NumberInt otherNumber);
};

void NumberInt::Init(int number) 
{
	_number = number;
}

void NumberInt::Release() 
{

}
NumberInt NumberInt ::operator+(NumberInt otherNumber)
{
	NumberInt returnValue;
	int number = this->_number + otherNumber._number;

	returnValue.Init(number);
	return returnValue;
}
NumberInt NumberInt ::operator-(NumberInt otherNumber)
{
	NumberInt returnValue;
	int number = this->_number - otherNumber._number;
	returnValue.Init(number);
	return returnValue;
}
NumberInt NumberInt ::operator*(NumberInt otherNumber)
{
	NumberInt returnValue;
	int number = this->_number * otherNumber._number;
	returnValue.Init(number);
	return returnValue;
}
NumberInt NumberInt ::operator/(NumberInt otherNumber)
{
	NumberInt returnValue;
	int number = this->_number / otherNumber._number;
	returnValue.Init(number);
	return returnValue;
}

void main()
{
	NumberInt myNum1;
	myNum1.Init(5);

	NumberInt myNum2;
	myNum2.Init(3);

	NumberInt myNum3 = myNum1 + myNum2;
	NumberInt myNum4 = myNum1 - myNum2;
	NumberInt myNum5 = myNum1 * myNum2;
	NumberInt myNum6 = myNum1 / myNum2;

	cout << "myNumber3 : " << myNum3._number << endl;
	cout << "myNumber4 : " << myNum4._number << endl;
	cout << "myNumber5 : " << myNum5._number << endl;
	cout << "myNumber6 : " << myNum6._number << endl;

	int num1, num2 = 0;
	int choice = 0; 
	cout << "���� 1�� �������ּ��� : ";
	cin >> num1;
	cout << "���� 2�� �������ּ��� : ";
	cin >> num1;
	cout << "� ��Ģ������ �Ͻðڽ��ϱ� (���ϱ� : 0, ���� : 1, ���ϱ� : 2, ������ : 3)" << endl;
	cout << "���� : ";
	cin >> choice;
	NumberInt myNum7;
	switch (choice)
	{
	case 0:
	{
		myNum1.Init(num1);
		myNum2.Init(num2);
		NumberInt myNum7 = myNum1 + myNum2;
		cout << myNum1._number << " + " << myNum2._number << " = " << myNum7._number << endl;
		break;
	}
	case 1:
	{
		myNum1.Init(num1);
		myNum2.Init(num2);
		NumberInt myNum7 = myNum1 - myNum2;
		cout << myNum1._number << " - " << myNum2._number << " = " << myNum7._number << endl;
		break;
	}
	case 2:
		myNum1.Init(num1);
		myNum2.Init(num2);
		myNum7 = myNum1 * myNum2;
		cout << myNum1._number << " * " << myNum2._number << " = " << myNum7._number << endl;
		break;
	case 3:
		myNum1.Init(num1);
		myNum2.Init(num2);
		myNum7 = myNum1 / myNum2;
		cout << myNum1._number << " / " << myNum2._number << " = " << myNum7._number << endl;
		break;
	default:
		break;
	}
}