#include <iostream>
using namespace std;

void main()
{
	int lotto[45] = { 0, };
	
	for (int i = 0; i < 45; i++)
	{
		lotto[i] = i + 1;
	}

	for (int i = 0; i < 10000; i++)
	{
		int num1 = rand() % 45;
		int num2 = rand() % 45;
		int temp = lotto[num1];
		lotto[num1] = lotto[num2];
		lotto[num2] = temp;
	}
	for (int i = 0; i < 7; i++)
	{
		cout << lotto[i] << endl;
	}
}