#include <iostream>
#include<vector>
using namespace std;

#define SAFE_DELETE(p) {if(p) {delete p; p = nullptr;}}
#define SAFE_DELETE_ARRAY(pArr) {if(pArr) {delete [] pArr; pArr = nullptr;}}
#define SAFE_RELEASE(p) {if(p) {p->Release(); p = NULL;}}

template <typename DataType>
class MyVector
{
public:
	DataType* _arr;
	// 실제 벡터의 길이
	int _size;
	// 벡터가 할당하고 있는 배열 크기
	int _capacity;
	MyVector()
	{
		// 길이가 1인 배열을 하나 생성
		_arr = new DataType[1] { };
		_capacity = 1;
		_size = 0;
	}
	~MyVector()
	{
		SAFE_DELETE_ARRAY(_arr);
		_size = 0;
		_capacity = 0;
	}
	void push_back(DataType data)
	{
		// 새로운 배열을 생성한다. (동적할당 배열)
		// capacity보다 size가 커지면
		// [기존 데이터를 옮긴다.
		// 새로운 배열 마지막 인덱스에 새로운 값을 추가한다]
		// 
		// 사이즈를 늘려준다
		_size++;
		if (_capacity < _size)
		{
			_capacity = _size * 2;
			DataType* newArr = new DataType[_capacity] {};
			for (int i = 0; i < _size - 1; i++)
			{
				newArr[i] = _arr[i];
			}
			SAFE_DELETE_ARRAY(_arr);

			_arr = newArr;
		}
		_arr[_size - 1] = data;
	}
	void pop_back()
	{
		_size--;
	}
	int size()
	{
		return _size;
	}
	DataType at(int index)
	{
		return _arr[index];
	}

	DataType operator [] (int index)
	{
		return this->at(index);
	}
};

void main() 
{
	//1. vector 구현

	vector<int> myVec;
	myVec.push_back(1);
	myVec.push_back(2);
	myVec.push_back(3);

	for (int i = 0; i < myVec.size(); i++)
	{
		cout << myVec[i] << endl;
	}

	myVec.pop_back();

	cout << "Last Value : " << myVec[myVec.size() - 1] << endl;

	// vector의 원리
	// new, delete ==> 무거운 함수
	
	cout << "MyVector 사용" << endl;
	// MyVector 사용 
	MyVector<float> myVec1;


	myVec1.push_back(1.1);
	myVec1.push_back(2.2);
	myVec1.push_back(3.3);

	for (int i = 0; i < myVec1.size(); i++)
	{
		cout << myVec1[i] << endl;
	}
	myVec1.pop_back();

	cout << "Last Value : " << myVec1[myVec1.size() - 1] << endl;

}