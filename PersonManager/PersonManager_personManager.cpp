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

	cout << "이름 & 번호 입력 : ";

	for (int i = 0; i < 3; i++) 
	{
		cin >> name >> tel;
		p[i].set(name, tel);
	}
}

void PersonManager::show()
{
	cout << "모든 사람의 이름 : ";

	for (int i = 0; i < 3; i++) 
	{
		cout << p[i].getName() << ' ';
	}

	cout << endl;
}

void PersonManager::search()
{
	string name;

	cout << "전화번호 검색합니다. 이름을 입력 : ";
	cin >> name;

	for (int i = 0; i < 3; i++)
	{
		if (name == p[i].getName())
		{
			cout << "전화 번호 : " << p[i].getTel() << endl;
			return;
		}
	}

	cout << "없는 사람입니다" << endl;
}
