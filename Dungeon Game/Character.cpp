#include "Character.h"

int Character::GetHp()
{
	return hp;
}

int Character::GetMP()
{
	return mp;
}

int Character::GetDamage()
{
	return damage;
}

int Character::GetDamaged(int d)
{
	int bhp = hp;

	hp = hp - (d - armor);

	return bhp - hp;
}

Enemy::Enemy()
{
	hp = 40;
	mp = 0;
	armor = 5;
	damage = 15;
}

Warrior::Warrior()
{
	hp = 150;
	mp = 60;
	armor = 10;
	damage = 13;
}

int Warrior::Skill()
{
	if (mp < 10)
	{
		cout << "Mp가 부족합니다.스킬 사용에 실패했습니다." << endl;
		return 5;
	}

	else
	{
		mp -= 10;
		return 15;
	}
}

Wizard::Wizard()
{
	hp = 120;
	mp = 80;
	armor = 7;
	damage = 10;
}

int Wizard::Skill()
{
	if (mp < 10)
	{
		cout << "Mp가 부족합니다.스킬 사용에 실패했습니다." << endl;
		return 5;
	}

	else
	{
		mp -= 10;
		return 30;
	}
}

Rogue::Rogue()
{
	hp = 120;
	mp = 60;
	armor = 7;
	damage = 16;
}

int Rogue::Skill()
{
	if (mp < 10)
	{
		cout << "Mp가 부족합니다.스킬 사용에 실패했습니다." << endl;
		return 5;
	}

	else
	{
		mp -= 10;
		return damage * 1.5;
	}
}