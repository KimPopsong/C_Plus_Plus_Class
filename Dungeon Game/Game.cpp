#include "Game.h"

Game::Game()
{
	GameChoice();
	GameStart();
	GameEnd();
}

void Game::GameChoice()
{
	cout << "Dungeon Adventure!" << endl;

	do
	{
		int choice;

		do //메뉴 선택
		{
			cout << endl << "-----MENU-----" << endl;
			cout << "1. 난이도 설정하기" << endl;
			cout << "2. 직업 선택하기" << endl;
			cout << "3. 게임하기" << endl;
			cout << "선택 : ";

			cin >> choice;

			if (choice >= 1 && choice <= 3)	//1이상 3이하 탈출
				break;

			else
			{
				if (cin.fail()) //숫자가 아닌 것 cin.fail()이 ture
					cout << "잘못된 입력입니다. 다시 입력해주세요." << endl;

				else if (choice < 1) //1보다 작을 때
					cout << "최소 1을 입력해야 합니다." << endl;

				else  //3보다 클 때
					cout << "최대 3까지 가능합니다." << endl;

				cin.clear(); //버퍼제거
				cin.ignore(INT_MAX, '\n'); //버퍼제거
			}
		} while (1);
		
		if (choice == 1)
		{
			do //난이도 입력받기
			{
				cout << endl << "-----Difficulty-----" << endl;
				cout << "1. 쉬움 2. 보통 3. 어려움" << endl;
				cout << "선택 : ";

				cin >> difficulty;

				if (difficulty >= 1 && difficulty <= 3)	//1이상 3이하 탈출
				{
					if (difficulty == 1)
					{
						enemy = new Enemy[3];
						round = 3;
						cout << "쉬움 선택" << endl;
					}

					else if (difficulty == 2)
					{
						enemy = new Enemy[4];
						round = 4;
						cout << "보통 선택" << endl;
					}

					else
					{
						enemy = new Enemy[5];
						round = 5;
						cout << "어려움 선택" << endl;
					}

					break;
				}

				else
				{
					if (cin.fail()) //숫자가 아닌 것 cin.fail()이 ture
						cout << "잘못된 입력입니다. 다시 입력해주세요." << endl;

					else if (difficulty < 1) //1보다 작을 때
						cout << "최소 1을 입력해야 합니다." << endl;

					else  //3보다 클 때
						cout << "최대 3까지 가능합니다." << endl;

					cin.clear(); //버퍼제거
					cin.ignore(INT_MAX, '\n'); //버퍼제거
				}
			} while (1);
		}
		
		else if (choice == 2)
		{
			do //직업 입력받기
			{
				cout << endl << "-----Class-----" << endl;
				cout << "1. 전사 2. 마법사 3. 도적" << endl;
				cout << "선택 : ";

				cin >> job;

				if (job >= 1 && job <= 3)	//1이상 3이하 탈출
				{
					if (job == 1)
					{
						user = new Warrior();
						cout << "전사 선택" << endl;
					}

					else if (job == 2)
					{
						user = new Wizard();
						cout << "마법사 선택" << endl;
					}

					else
					{
						user = new Rogue();
						cout << "도적 선택" << endl;
					}
					break;
				}

				else
				{
					if (cin.fail()) //숫자가 아닌 것 cin.fail()이 ture
						cout << "잘못된 입력입니다. 다시 입력해주세요." << endl;

					else if (job < 1) //1보다 작을 때
						cout << "최소 1을 입력해야 합니다." << endl;

					else  //3보다 클 때
						cout << "최대 3까지 가능합니다." << endl;

					cin.clear(); //버퍼제거
					cin.ignore(INT_MAX, '\n'); //버퍼제거
				}
			} while (1);
		}

		else
		{
			if ((job >= 1 && job <= 3) && (difficulty >= 1 && difficulty <= 3))
			{
				cout << "게임을 시작합니다!" << endl;
				break;
			}

			else
				cout << "난이도와 직업을 모두 선택해주세요." << endl;
		}
	} while (1);
}

void Game::GameStart()
{
	int cntBrnd = 1, cntEnemy = 0;
	
	while (cntBrnd <= round)
	{
		int rnd = 1;

		while(1)
		{
			cout << endl << "<Round " << cntBrnd << "-" << rnd++ << ">" << endl << endl;
			cout << "당신 : HP : (" << user->GetHp() << ") MP : (" << user->GetMP() << ")" << endl;
			cout << "적 : HP : (" << enemy[cntEnemy].GetHp() << ")" << endl;

			Attack(cntEnemy);
			
			if (user->GetHp() <= 0)
				return;

			else if (enemy[cntEnemy].GetHp() <= 0)
			{
				cout << "적을 처치하였습니다." << endl;
				cntEnemy++;
				rnd++;
				break;
			}
		}

		cntBrnd++;
	}
}

int Game::SelectAttack()
{
	int atk;

	do
	{
		cout << endl << "-----Select Attack-----" << endl;
		cout << "1. 일반공격 2. 스킬사용" << endl;
		cout << "선택 : ";

		cin >> atk;

		if (atk >= 1 && atk <= 2)	//1이상 2이하 탈출
			return atk;

		else
		{
			if (cin.fail()) //숫자가 아닌 것 cin.fail()이 ture
				cout << "잘못된 입력입니다. 다시 입력해주세요." << endl;

			else if (atk < 1) //1보다 작을 때
				cout << "최소 1을 입력해야 합니다." << endl;

			else  //2보다 클 때
				cout << "최대 2까지 가능합니다." << endl;

			cin.clear(); //버퍼제거
			cin.ignore(INT_MAX, '\n'); //버퍼제거
		}
	} while (1);
}

void Game::Attack(int cntSrnd)
{
	if (SelectAttack() == 1)
		cout << "당신은 상대에게 " << enemy[cntSrnd].GetDamaged(user->GetDamage()) << "의 피해를 입혔습니다." << endl;

	else
		cout << "당신은 상대에게 " << enemy[cntSrnd].GetDamaged(user->Skill()) << "의 피해를 입혔습니다." << endl;

	cout << "당신은 상대에게 " << user->GetDamaged(enemy[cntSrnd].GetDamage()) << "의 피해를 입었습니다." << endl;

	cout << endl;
}

void Game::GameEnd()
{
	if (user->GetHp() <= 0)
		cout << "Game Over" << endl;

	else
		cout << "You Win!" << endl;
}