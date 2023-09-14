#include <iostream>
#include <string>
#include <vector>

using namespace std;

void main()
{

	for (int i = 1; i < 8; i++)
	{
		for (int j = 1; j < 10; j++)
		{
			for (int k = 0; k < 3; k++)
			{
				int num = i + k;
				cout << num << "X" << j << "\t";
			}
			cout << endl;

		}
		cout << endl;

	}

}