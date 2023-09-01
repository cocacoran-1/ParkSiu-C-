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

	cout << "1. �÷��̾��� Hp�� �����ּ���." << endl;
	cin >> player.Hp;

	cout << "2. �÷��̾��� Damage�� �����ּ���." << endl;
	cin >> player.Damage;

	cout << "3. �÷��̾��� AttackSpeed�� �����ּ���." << endl;
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
	cout << "�÷��̾� ü�� :" << player.Hp << "\t";
	cout << "���� " << count + 1 << " ü�� : " << monsterGroup[count][0] << endl;

	int monsterSize = monsterGroup.size();

	while (count < monsterSize)
	{

		if (player.AttackSpeed - monsterGroup[count][2] >= 1)
		{
			int AttackCount = player.AttackSpeed - monsterGroup[count][2];
			cout << AttackCount << "ȸ �߰� ����!!" << endl;
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
			cout << "���Ͱ� " << AttackCount << "ȸ �߰� �����մϴ�" << endl;
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
		cout << "�÷��̾� ü�� :" << player.Hp << "\t";
		cout << "���� " << count + 1 << " ü�� : " << monsterGroup[count][0] << endl;
		if (player.Hp == 0)
		{
			cout << "�÷��̾ �׾����ϴ�..." << endl;
			cout << "���� ���� �� : " << count + 1;
			break;
		}
	}
	cout << "��� ���͸� ��ҽ��ϴ� !!!" << endl;
	cout << "���� ���� �� : " << count + 1;
}