#include <iostream>
#include <vector>

using namespace std;

void main()
{
	vector<int> myVec;

	for (int i = 0; i < 10; i++)
	{
		myVec.push_back(i + 1);
	}

	//	값 조회 여러 방식
	//	1.
	cout << "1번" << endl;
	for (int i = 0; i < myVec.size(); i++)
	{
		cout << myVec[i] << endl;
	}
	//	2. iterator : 조회할 때 필요한 도움 장치
	cout << "2번" << endl;

	for (vector<int>::iterator iter = myVec.begin(); iter < myVec.end(); iter++)
	{
		cout << *iter << endl;
	}
	for (auto iter = myVec.begin(); iter < myVec.end(); iter++)
	{
		cout << *iter << endl;
	}
	// 역순
	for (vector<int>::reverse_iterator iter = myVec.rbegin(); iter < myVec.rend(); iter++)
	{
		cout << *iter << endl;
	}
	for (auto iter = myVec.rbegin(); iter < myVec.rend(); iter++)
	{
		cout << *iter << endl;
	}
	
	//	auto 
	//	컴파일 단계 때 어떤 자료형이 될지 결정된다
	//	비선호하는 곳이 많다 공부할 때는 가급적 사용 하지 않는다
	//	auto&, auto*, auto => 기존 auto 자료형이 포인터 형태 라면?
	auto num = 1.1;
	cout << "num : " << num << endl;

	cout << "3번" << endl;
	//	3.
	// 해당 방식으로는 값 참조가 되지 않고 복사만 되서 바뀌지 않는다
	for (int number : myVec)
	{
		if (number == 2)
		{
			number = 20;
		}
	}
	for (int number : myVec)
	{
		cout << number << endl;
	}
	// 아래 방식으로는 값을 바꿀 수 있다 하지만 index는 알지 못한다
	for (int& number : myVec)
	{
		if (number == 2)
		{
			number = 20;
		}
	}
	for (int number : myVec)
	{
		cout << number << endl;
	}

	//	값 삭제
	vector<int>::iterator iter = myVec.begin();
	// 3번째 인덱스를 삭제한다
	myVec.erase(iter + 3);
	for (int number : myVec)
	{
		cout << number << endl;
	}

}