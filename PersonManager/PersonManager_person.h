#include <iostream>
#include <string>

using namespace std;

#ifndef Person_H
#define Person_H

class Person 
{
	string name;
	string tel;

public:
	string getName() { return name; }
	string getTel() { return tel; }
	void set(string name, string tel);
};

#endif