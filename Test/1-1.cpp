#include <iostream>
#include <string>

using namespace std;

class Person {
	string name;
	int age;
	void show();

public:
	Person();
	Person(string n);
	Person(string n, int m);
};

Person::Person():Person("No Name", 0) {};

Person::Person(string n):Person(n, 0) {};

Person::Person(string n, int m) :name{ n }, age{ m } {
	show();
};

void Person::show(){
	cout << "Name : " << name << endl;
	cout << "Age : " << age << endl;
}

int main()
{
	Person p1("KIM", 10), p2("POP", 15), p3("PARK");
}