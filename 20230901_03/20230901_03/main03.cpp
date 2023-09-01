#include<iostream>
#include<vector>
#include<time.h>

using namespace std;

struct Unit
{
	int Hp;
	int Damage;
	int AttackSpeed;
};

void main()
{
	srand(time(NULL));

	Unit player;
	Unit monster;
	vector<vector<int>> monsterGroup;

	cout << "1. 플레이어의 Hp를 정해주세요." << endl;
	cin >> player.Hp;

	cout << "2. 플레이어의 Damage를 정해주세요." << endl;
	cin >> player.Damage;

	cout << "3. 플레이어의 AttackSpeed를 정해주세요." << endl;
	cin >> player.AttackSpeed;

	for (int i = 0; i < 100;i++)
	{
		vector<int> temp;

		monster.Hp = 100;
		monster.Damage = 10;
		monster.AttackSpeed = 1;

		temp.push_back(monster.Hp);
		temp.push_back(monster.Damage);
		temp.push_back(monster.AttackSpeed);

		monsterGroup.push_back(temp);
	}
	int count = 0;
	cout << "플레이어 체력 :" << player.Hp << "\t";
	cout << "몬스터 " << count + 1 << " 체력 : " << monsterGroup[count][0] << endl;

	int monsterSize = monsterGroup.size();

	while (count < monsterSize)
	{

		if (player.AttackSpeed - monsterGroup[count][2] >= 1)
		{
			int AttackCount = player.AttackSpeed - monsterGroup[count][2];
			cout << AttackCount << "회 추가 공격!!" << endl;
			monsterGroup[count][0] -= player.Damage;
			while (AttackCount > 0)
			{
				monsterGroup[count][0] -= player.Damage;
				AttackCount--;
			}
		}
		else
		{
			monsterGroup[count][0] -= player.Damage;
		}

		if (monsterGroup[count][0] <= 0)
		{
			count++;
			if (count >= monsterSize)
			{
				break;
			}
		}
		else if (player.AttackSpeed - monsterGroup[count][2] < 0)
		{
			int AttackCount = monsterGroup[count][2] - player.AttackSpeed;
			cout << "몬스터가 " << AttackCount << "회 추가 공격합니다" << endl;
			player.Hp -= monsterGroup[count][1];
			while (AttackCount > 0)
			{
				player.Hp -= monsterGroup[count][1];
				AttackCount--;
			}
		}
		else
		{
			player.Hp -= monsterGroup[count][1];
		}
		cout << "플레이어 체력 :" << player.Hp << "\t";
		cout << "몬스터 " << count + 1 << " 체력 : " << monsterGroup[count][0] << endl;
		if (player.Hp == 0)
		{
			cout << "플레이어가 죽었습니다..." << endl;
			cout << "잡은 몬스터 수 : " << count + 1;
			break;
		}
	}
	cout << "모든 몬스터를 잡았습니다 !!!" << endl;
	cout << "잡은 몬스터 수 : " << count + 1;
}