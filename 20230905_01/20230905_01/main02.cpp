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
	// new 해줄떄 호출 (객체가 생성될떄 호출) 한번만 
	cout << "생성자" << endl;
}

NumberInt::~NumberInt()
{
	// delete 해줄떄 호출 (객체가 소멸될떄 호출) 한번만 
	cout << "소멸자" << endl;
}

void main()
{
	// 생성자와 소멸자
	NumberInt* myUnit = new NumberInt();
	myUnit->Init();

	{
		NumberInt myUnit2;
		system("pause");
	}

	myUnit->Release();
	delete myUnit;
	myUnit = nullptr;
	
	// 생성자 소멸자 대신 Init과 Release를 사용해야하는 이유

	// 1. 생성자와 소멸자는 단 한번만 호출됨

	// new, delete의 경우 매우 무겁기 때문에 
	// 로딩씬에서 new, delete가 이루어진다
	// 초기화는 안해준다
	// 실제 사용할 때 Init ,Release를 사용한다
}

