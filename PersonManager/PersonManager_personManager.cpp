#include <iostream>
#include <string>
#include "PersonManager_personManager.h"

using namespace std;

PersonManager::PersonManager(int n)
{
	p = new Person[n];
	size = n;
	
}

PersonManager::~PersonManager()
{
	delete[] p;
}

void PersonManager::input()
{
	string name, tel;

	cout << "�̸� & ��ȣ �Է� : ";

	for (int i = 0; i < 3; i++) 
	{
		cin >> name >> tel;
		p[i].set(name, tel);
	}
}

void PersonManager::show()
{
	cout << "��� ����� �̸� : ";

	for (int i = 0; i < 3; i++) 
	{
		cout << p[i].getName() << ' ';
	}

	cout << endl;
}

void PersonManager::search()
{
	string name;

	cout << "��ȭ��ȣ �˻��մϴ�. �̸��� �Է� : ";
	cin >> name;

	for (int i = 0; i < 3; i++)
	{
		if (name == p[i].getName())
		{
			cout << "��ȭ ��ȣ : " << p[i].getTel() << endl;
			return;
		}
	}

	cout << "���� ����Դϴ�" << endl;
}
