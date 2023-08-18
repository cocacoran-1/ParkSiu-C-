#include<iostream>
#include<vector>
using namespace std;

/*
	- 1 ~ 1000까지의 숫자 중에서 2의 배수와 3의 배수를 합한 값 (단, 6의 배수는 제외한다)
	- 2의 배수이거나 3의 배수인 수를 배열에 추가하고 2의 배수,3의 배수인 조건을 모두 만족하는 수는 추가하지 않는다
	- 배열의 크기만큼 배열의 값들을 모두 출력한다
*/
void main()
{
	vector<int> multiple;

	for (int i = 1; i <= 1000; i++)
	{

		if ((i % 2 == 0 || i % 3 == 0) && !(i % 6 == 0))
		{
			multiple.push_back(i);
		}
	}

	for (int i = 0; i < multiple.size(); i++)
	{
		cout << multiple[i] << endl;
	}
}