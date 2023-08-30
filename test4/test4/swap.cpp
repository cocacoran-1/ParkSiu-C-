#include<iostream>
using namespace std;

void Swap1(int a, int b)
{
	int temp = a;
	a = b;
	b = temp;
}
void Swap2(int* a, int* b)
{
	int temp = *a;
	*a = *b;
	*b = temp;
}
void Swap3(int& a, int& b)
{
	int temp = a;
	a = b;
	b = temp;
}
void main()
{
	int num1 = 10;
	int num2 = 20;
	Swap1(num1, num2);
	cout << "Swap1" << endl;
	cout << num1 << endl;
	cout << num2 << endl;

	num1 = 10;
	num2 = 20;
	Swap2(&num1, &num2);
	cout << "Swap2" << endl;
	cout << num1 << endl;
	cout << num2 << endl;

	num1 = 10;
	num2 = 20;
	Swap3(num1, num2);
	cout << "Swap3" << endl;
	cout << num1 << endl;
	cout << num2 << endl;

}