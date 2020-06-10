#include <iostream>
#include <string>
#include "PersonManager_person.h"

using namespace std;

void Person::set(string name, string tel)
{
	this->name = name;
	this->tel = tel;
}