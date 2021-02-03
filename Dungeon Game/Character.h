#pragma once;

#include <iostream>

using namespace std;

class Character
{
protected:
	int hp;
	int mp;
	int armor;
	int damage;
	
public:
	virtual int Skill() = 0;
	int GetHp();
	int GetMP();
	int GetDamage();
	int GetDamaged(int d);
};

class Enemy : public Character
{
public:
	Enemy();
	int Skill() { return 0; };
	int GetMP() { return 0; }
};

class Warrior : public Character
{
public:
	Warrior();
	int Skill();
};

class Wizard : public Character
{
public:
	Wizard();
	int Skill();
};

class Rogue : public Character
{
public:
	Rogue();
	int Skill();
};