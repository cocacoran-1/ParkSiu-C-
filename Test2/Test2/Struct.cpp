#include <iostream>
using namespace std;

struct Unit
{
	float Hp;
	float Damage;
	bool Dead;
};

void main()
{
	bool isDead = false;

	Unit Hero = { 200,15,false };
	Unit Slime = { 100,10,false };


	while (!isDead)
	{
		cout << "Hero Hp : " << Hero.Hp << "\t\t";
		cout << "Slime Hp : " << Slime.Hp << endl;
		cout << "Hero Damage : " << Hero.Damage << "\t";
		cout << "Slime Damage : " << Slime.Damage << endl;
		Hero.Hp -= Slime.Damage;
		Slime.Hp -= Hero.Damage;
		if (Hero.Hp <= 0)
		{
			Hero.Dead = true;
			isDead = true;
		}
		else if (Slime.Hp <= 0)
		{
			Slime.Dead = true;
			isDead = true;
		}
	}
	if (Slime.Dead)
	{
		cout << "슬라임을 잡았습니다!!!";
	}
	else if (Hero.Dead)
	{
		cout << "사망하였습니다...";
	}

}