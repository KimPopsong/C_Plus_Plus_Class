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

		do //�޴� ����
		{
			cout << endl << "-----MENU-----" << endl;
			cout << "1. ���̵� �����ϱ�" << endl;
			cout << "2. ���� �����ϱ�" << endl;
			cout << "3. �����ϱ�" << endl;
			cout << "���� : ";

			cin >> choice;

			if (choice >= 1 && choice <= 3)	//1�̻� 3���� Ż��
				break;

			else
			{
				if (cin.fail()) //���ڰ� �ƴ� �� cin.fail()�� ture
					cout << "�߸��� �Է��Դϴ�. �ٽ� �Է����ּ���." << endl;

				else if (choice < 1) //1���� ���� ��
					cout << "�ּ� 1�� �Է��ؾ� �մϴ�." << endl;

				else  //3���� Ŭ ��
					cout << "�ִ� 3���� �����մϴ�." << endl;

				cin.clear(); //��������
				cin.ignore(INT_MAX, '\n'); //��������
			}
		} while (1);
		
		if (choice == 1)
		{
			do //���̵� �Է¹ޱ�
			{
				cout << endl << "-----Difficulty-----" << endl;
				cout << "1. ���� 2. ���� 3. �����" << endl;
				cout << "���� : ";

				cin >> difficulty;

				if (difficulty >= 1 && difficulty <= 3)	//1�̻� 3���� Ż��
				{
					if (difficulty == 1)
					{
						enemy = new Enemy[3];
						round = 3;
						cout << "���� ����" << endl;
					}

					else if (difficulty == 2)
					{
						enemy = new Enemy[4];
						round = 4;
						cout << "���� ����" << endl;
					}

					else
					{
						enemy = new Enemy[5];
						round = 5;
						cout << "����� ����" << endl;
					}

					break;
				}

				else
				{
					if (cin.fail()) //���ڰ� �ƴ� �� cin.fail()�� ture
						cout << "�߸��� �Է��Դϴ�. �ٽ� �Է����ּ���." << endl;

					else if (difficulty < 1) //1���� ���� ��
						cout << "�ּ� 1�� �Է��ؾ� �մϴ�." << endl;

					else  //3���� Ŭ ��
						cout << "�ִ� 3���� �����մϴ�." << endl;

					cin.clear(); //��������
					cin.ignore(INT_MAX, '\n'); //��������
				}
			} while (1);
		}
		
		else if (choice == 2)
		{
			do //���� �Է¹ޱ�
			{
				cout << endl << "-----Class-----" << endl;
				cout << "1. ���� 2. ������ 3. ����" << endl;
				cout << "���� : ";

				cin >> job;

				if (job >= 1 && job <= 3)	//1�̻� 3���� Ż��
				{
					if (job == 1)
					{
						user = new Warrior();
						cout << "���� ����" << endl;
					}

					else if (job == 2)
					{
						user = new Wizard();
						cout << "������ ����" << endl;
					}

					else
					{
						user = new Rogue();
						cout << "���� ����" << endl;
					}
					break;
				}

				else
				{
					if (cin.fail()) //���ڰ� �ƴ� �� cin.fail()�� ture
						cout << "�߸��� �Է��Դϴ�. �ٽ� �Է����ּ���." << endl;

					else if (job < 1) //1���� ���� ��
						cout << "�ּ� 1�� �Է��ؾ� �մϴ�." << endl;

					else  //3���� Ŭ ��
						cout << "�ִ� 3���� �����մϴ�." << endl;

					cin.clear(); //��������
					cin.ignore(INT_MAX, '\n'); //��������
				}
			} while (1);
		}

		else
		{
			if ((job >= 1 && job <= 3) && (difficulty >= 1 && difficulty <= 3))
			{
				cout << "������ �����մϴ�!" << endl;
				break;
			}

			else
				cout << "���̵��� ������ ��� �������ּ���." << endl;
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
			cout << "��� : HP : (" << user->GetHp() << ") MP : (" << user->GetMP() << ")" << endl;
			cout << "�� : HP : (" << enemy[cntEnemy].GetHp() << ")" << endl;

			Attack(cntEnemy);
			
			if (user->GetHp() <= 0)
				return;

			else if (enemy[cntEnemy].GetHp() <= 0)
			{
				cout << "���� óġ�Ͽ����ϴ�." << endl;
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
		cout << "1. �Ϲݰ��� 2. ��ų���" << endl;
		cout << "���� : ";

		cin >> atk;

		if (atk >= 1 && atk <= 2)	//1�̻� 2���� Ż��
			return atk;

		else
		{
			if (cin.fail()) //���ڰ� �ƴ� �� cin.fail()�� ture
				cout << "�߸��� �Է��Դϴ�. �ٽ� �Է����ּ���." << endl;

			else if (atk < 1) //1���� ���� ��
				cout << "�ּ� 1�� �Է��ؾ� �մϴ�." << endl;

			else  //2���� Ŭ ��
				cout << "�ִ� 2���� �����մϴ�." << endl;

			cin.clear(); //��������
			cin.ignore(INT_MAX, '\n'); //��������
		}
	} while (1);
}

void Game::Attack(int cntSrnd)
{
	if (SelectAttack() == 1)
		cout << "����� ��뿡�� " << enemy[cntSrnd].GetDamaged(user->GetDamage()) << "�� ���ظ� �������ϴ�." << endl;

	else
		cout << "����� ��뿡�� " << enemy[cntSrnd].GetDamaged(user->Skill()) << "�� ���ظ� �������ϴ�." << endl;

	cout << "����� ��뿡�� " << user->GetDamaged(enemy[cntSrnd].GetDamage()) << "�� ���ظ� �Ծ����ϴ�." << endl;

	cout << endl;
}

void Game::GameEnd()
{
	if (user->GetHp() <= 0)
		cout << "Game Over" << endl;

	else
		cout << "You Win!" << endl;
}