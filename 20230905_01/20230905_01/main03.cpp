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
	// 매크로 (#define)
	// #define 매크로명 기능
	// 아래 코드에서 매크로명을 쓰면 기능으로 매핑 시켜주는 기능 
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
	// 매크로 함수를 사용하여 계산기 만들기

	/*int num1, num2 = 0;
	int choice = 0;
	cout << "숫자 1을 입력해주세요 : ";
	cin >> num1;
	cout << "숫자 2를 입력해주세요 : ";
	cin >> num2;
	cout << "어떤 사칙연산을 하시겠습니까 (더하기 : 0, 빼기 : 1, 곱하기 : 2, 나누기 : 3)" << endl;
	cout << "선택 : ";
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
	// 만약 slime = nullptr; 을 하지 않으면 delete를 했음에도 남아있다
	if (slime)
	{
		cout << "유닛 스탯 약화1" << endl;
	}

	NumberInt* slime1 = new NumberInt();
	slime1->Init();
	slime1->Release();

	SAFE_DELETE(slime1);

	if (!slime1)
	{
		cout << "존재하지 않는다" << endl;
	}

	// 포인터를 출력하면 주소값이 출력된다.
	// delete를 하면 쓰레기값이 들어간다
	cout << "slime : " << slime << endl;
	cout << "slime1 : " << slime1 << endl;
	
	NumberInt* UnitList = new NumberInt[100]{};
	SAFE_DELETE_ARRAY(UnitList);
}