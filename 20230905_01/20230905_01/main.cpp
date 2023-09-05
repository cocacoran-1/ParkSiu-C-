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
	// ���� ������ ����
	int _size;
	// ���Ͱ� �Ҵ��ϰ� �ִ� �迭 ũ��
	int _capacity;
	MyVector()
	{
		// ���̰� 1�� �迭�� �ϳ� ����
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
		// ���ο� �迭�� �����Ѵ�. (�����Ҵ� �迭)
		// capacity���� size�� Ŀ����
		// [���� �����͸� �ű��.
		// ���ο� �迭 ������ �ε����� ���ο� ���� �߰��Ѵ�]
		// 
		// ����� �÷��ش�
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
	//1. vector ����

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

	// vector�� ����
	// new, delete ==> ���ſ� �Լ�
	
	cout << "MyVector ���" << endl;
	// MyVector ��� 
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