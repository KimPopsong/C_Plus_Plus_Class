#pragma once;

#include "Character.h"

class Game
{
	int difficulty;
	int job;
	int round;

public:
	Character* user;
	Character* enemy;

	Game();
	void GameChoice();
	void GameStart();
	int SelectAttack();
	void Attack(int cntBrnd);
	void GameEnd();
};