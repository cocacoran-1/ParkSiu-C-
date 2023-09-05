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
	cout << "실수 정수 어떤 수로 계산 하시겠습니까 (실수 : 0, 정수 : 1)" << endl;
	cout << "선택 : ";
	cin >> choice1;
	if (choice1 == 0)
	{
		Number<float> num1;
		Number<float> num2;
		Number<float> num3;
		num3._number = 0;

		cout << "숫자 1을 선택해주세요 : ";
		cin >> num1._number;
		cout << "숫자 2를 선택해주세요 : ";
		cin >> num2._number;
		cout << "어떤 사칙연산을 하시겠습니까 (더하기 : 0, 빼기 : 1, 곱하기 : 2, 나누기 : 3)" << endl;
		cout << "선택 : ";
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

		cout << "숫자 1을 선택해주세요 : ";
		cin >> num1._number;
		cout << "숫자 2를 선택해주세요 : ";
		cin >> num2._number;
		cout << "어떤 사칙연산을 하시겠습니까 (더하기 : 0, 빼기 : 1, 곱하기 : 2, 나누기 : 3)" << endl;
		cout << "선택 : ";
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
	
	
	

	// template : 하나의 코드로 여러 개의 자료형을 포함 시킬 수 있는 문법
	// 실제 컴파일 시, 여러 개의 자료형을 직접 코딩한 것과 같은 효과를 낸다
}