#include <iostream>

using namespace std;

class NumberInt
{
public:
	int _number;
	void Init(int number);
	void Release();

private:

};

void NumberInt::Init(int number)
{
	_number = number;
}

void NumberInt::Release()
{

}

template <typename T>
class Number
{
public:
	T _number;
	void Init(T data);
	void Release();

	Number operator+(Number otherNumber);
	Number operator-(Number otherNumber);
	Number operator*(Number otherNumber);
	Number operator/(Number otherNumber);
};
template <typename T>
void Number<T>::Init(T data)
{
	_number = data;
}
template <typename T>
void Number<T>::Release()
{

}

template <typename T>
Number<T> Number<T> ::operator+(Number<T> otherNumber)
{
	Number<T> returnValue;
	T number = this->_number + otherNumber._number;

	returnValue.Init(number);
	return returnValue;
}
template <typename T>
Number<T> Number<T> ::operator-(Number<T> otherNumber)
{
	Number<T> returnValue;
	T number = this->_number - otherNumber._number;
	returnValue.Init(number);
	return returnValue;
}
template <typename T>
Number<T> Number<T> ::operator*(Number<T> otherNumber)
{
	Number<T> returnValue;
	T number = this->_number * otherNumber._number;
	returnValue.Init(number);
	return returnValue;
}
template <typename T>
Number<T> Number<T> ::operator/(Number<T> otherNumber)
{
	Number<T> returnValue;
	T number = this->_number / otherNumber._number;
	returnValue.Init(number);
	return returnValue;
}
void main()
{
	// template

	int choice1, choice2 = 0;
	cout << "�Ǽ� ���� � ���� ��� �Ͻðڽ��ϱ� (�Ǽ� : 0, ���� : 1)" << endl;
	cout << "���� : ";
	cin >> choice1;
	if (choice1 == 0)
	{
		Number<float> num1;
		Number<float> num2;
		Number<float> num3;
		num3._number = 0;

		cout << "���� 1�� �������ּ��� : ";
		cin >> num1._number;
		cout << "���� 2�� �������ּ��� : ";
		cin >> num2._number;
		cout << "� ��Ģ������ �Ͻðڽ��ϱ� (���ϱ� : 0, ���� : 1, ���ϱ� : 2, ������ : 3)" << endl;
		cout << "���� : ";
		cin >> choice2;
		switch (choice2)
		{
		case 0:
		{
			num3 = num1 + num2;
			cout << num1._number << " + " << num2._number << " = " << num3._number << endl;
			break;
		}
		case 1:
		{
			num3 = num1 - num2;
			cout << num1._number << " - " << num2._number << " = " << num3._number << endl;
			break;
		}
		case 2:
			num3 = num1 * num2;
			cout << num1._number << " * " << num2._number << " = " << num3._number << endl;
			break;
		case 3:
			num3 = num1 / num2;
			cout << num1._number << " / " << num2._number << " = " << num3._number << endl;
			break;
		default:
			break;
		}
	}
	else if (choice1 == 1)
	{
		Number<int> num1;
		Number<int> num2;
		Number<int> num3;
		num3._number = 0;

		cout << "���� 1�� �������ּ��� : ";
		cin >> num1._number;
		cout << "���� 2�� �������ּ��� : ";
		cin >> num2._number;
		cout << "� ��Ģ������ �Ͻðڽ��ϱ� (���ϱ� : 0, ���� : 1, ���ϱ� : 2, ������ : 3)" << endl;
		cout << "���� : ";
		cin >> choice2;
		switch (choice2)
		{
		case 0:
		{
			num3 = num1 + num2;
			cout << num1._number << " + " << num2._number << " = " << num3._number << endl;
			break;
		}
		case 1:
		{
			num3 = num1 - num2;
			cout << num1._number << " - " << num2._number << " = " << num3._number << endl;
			break;
		}
		case 2:
			num3 = num1 * num2;
			cout << num1._number << " * " << num2._number << " = " << num3._number << endl;
			break;
		case 3:
			num3 = num1 / num2;
			cout << num1._number << " / " << num2._number << " = " << num3._number << endl;
			break;
		default:
			break;
		}
	}
	
	
	

	// template : �ϳ��� �ڵ�� ���� ���� �ڷ����� ���� ��ų �� �ִ� ����
	// ���� ������ ��, ���� ���� �ڷ����� ���� �ڵ��� �Ͱ� ���� ȿ���� ����
}