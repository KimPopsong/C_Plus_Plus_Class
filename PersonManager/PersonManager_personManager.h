#ifndef PersonManager_H
#define PersonMangager_H

#include <iostream>
#include <string>
#include "PersonManager_person.h"

using namespace std;

class PersonManager 
{
	Person* p;
	int size;
public:
	PersonManager();
	PersonManager(int n);
	~PersonManager();
	void input();
	void show();
	void search();
};

#endif