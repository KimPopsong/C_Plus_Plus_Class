#include "Game.h"

Game::Game(int t)
{
	gamer = new Horse[t]; //gamer��� ��ü ����
}

void Game::printGame(int num)
{
	cout << "Turn : " << turn++ << endl; //������ �� ���
	cout << "==================================================" << endl;

	for (int i = 0; i < num; i++)
	{
		for (int j = 0; j < gamer[i].getNow(); j++) //�� ���� ������ġ�� ���
			cout << "-"; //���� ������ �ڸ� ���
		cout << "(  ) => " << gamer[i].getNow() << endl; //���� ��� ���
	}
	cout << "==================================================" << endl;

	clock_t sleep = clock(); //ctime�ȿ� �ִ� �Լ� ���
	while(clock() - sleep < 1000); //1�ʾ� �������Ѽ� ����ϴ� �Լ�
}

void Game::gameStart(int num) //num�� ���� ������
{
	while (1)
	{
		for (int i = 0; i < num; i++) //������ 0~5�� ������ ����ŭ �����̵��� �� 
		{
			gamer[i].Go(); //Go�Լ� ȣ��
			Check(i, gamer[i].getNow()); //������ ��ġ�� �˻��ϴ� �Լ� ȣ��
		}

		printGame(num); //������ ���� ��ġ�� ���

		int cnt = 0; //������ ���� ������

		for (int i = 0; i < num; i++)
			if (gamer[i].getNow() >= 20) //�����Ѹ��� ������ cnt++
				cnt++;
		
		if (cnt == num) //cnt�� �����ϴ� ���� ���ڿ� ������ ������ ����
			break;
	}
}

void Game::Check(int i, int t) //���� ������ġ�� �˻�
{
	if (t >= 20) //20�̻��̸� setNow�Լ� ȣ��
		gamer[i].setNow();
}

void Game::gameEnd(int num, int choice) //���������ϴ� �Լ�
{
	int winner = 0; //������� rank�� ����

	for (int i = 0; i < num; i++)
		if (winner < gamer[i].getRank()) //rank�� ���� winner���� ũ�� winner�� rank�� ����
			winner = gamer[i].getRank();

	cout << "����ڴ� ";

	for (int i = 0; i < num; i++)
		if (winner == gamer[i].getRank()) //winner���� rank���� ������ ����� �� ���. ���ÿ�� ����
			cout << (i + 1) << "�� ";

	cout << "���Դϴ�." << endl;

	if (gamer[choice - 1].getRank() == winner) //winner�� ���� rank�� ���� ������ ���
		cout << "�����մϴ�. ����ϼ̽��ϴ�. " << endl;

	else
		cout << "�й��ϼ̽��ϴ�." << endl;
}

Game::~Game()
{
	delete[] gamer;
}

void Horse::Go()
{
	int r = rand() % 6; //r�� 0 ~ 5�� ������ ���� ����.

	now += r; //���� �̵���
}

int Horse::getNow()const
{
	return now; //���� ������ġ ��ȯ
}

void Horse::setNow() //���� ������ġ�� 20�̻��̸�
{
	rank++;  //rank���� 1�� �ø�. ���� ���� ������ ���� rank���� ���� ŭ. ���ÿ� �����ϸ� rank���� ����
	now = 20; //���� ������ġ�� �ٽ� 20���� ����
}

int Horse::getRank()const
{
	return rank; //���� rank���� ��ȯ
}