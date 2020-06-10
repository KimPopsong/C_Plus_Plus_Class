#pragma once

#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

class Horse
{
	int now = 0; //���� ���� ��ġ
	int rank = 0; //���� ������ �������� ������ turn, �������� ����� ����

public:
	void Go(); //�����ϴ� �Լ�
	int getNow()const; //������ ������ġ�� �������� �Լ�
	void setNow(); //���� ��ġ�� 20�̻��϶� 20���� ����������
	int getRank()const; //���� ����� ������
};

class Game 
{
	Horse* gamer; //Horse��ü
	int turn = 0; //����Ǵ� ��

public:
	Game(int t); //������
	void gameStart(int num); //���� �����ϴ� �Լ�
	void printGame(int num); //������ ���� ��Ȳ�� ����ϴ� �Լ�
	void Check(int i, int t); //������ ���� ��ġ�� Ȯ��. 20�̻��̸� setNow�� ȣ��
	void gameEnd(int num, int choice); //��������.
	~Game(); //�Ҹ���
};
