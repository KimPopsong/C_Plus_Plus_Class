#include <iostream>
#include <string>
#include "PersonManager_PersonManager.h"
#include "PersonManager_Person.h"

using namespace std;

int main()
{
	PersonManager list(3);
	list.input();
	list.show();
	list.search();

	return 0;
}