#include<iostream>
using namespace std;

void main()
{
	int num1 = 0;
	int num2 = 0;
	int res = 0;

	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 9; j++)
		{
			for (int k = 0; k < 3; k++)
			{
				num1 = k + 1 + (i * 3);
				num2 = j + 1;
				res = num1 * num2;
				cout << num1 << " X " << num2 << " = " << res << "\t";
			}
			cout << endl;
		}
		cout << endl;
	}
}