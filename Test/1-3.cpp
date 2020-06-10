#include <iostream>
#include <string>

using namespace std;

class Person {
	string name;
	int age;

public:
	void show();
	Person();
	Person(string n);
	Person(string n, int m);
	string getName();
	void setName(string s);
	int getAge();
	void setAge(int a);
};

Person::Person() :Person("No Name", 0) {};

Person::Person(string n) :Person(n, 0) {};

Person::Person(string n, int m) :name{ n }, age{ m } {};

string Person::getName() {
	return name;
};

void Person::setName(string s) {
	name = s;
};

int Person::getAge() {
	return age;
};

void Person::setAge(int a) {
	age = a;
};

void Person::show() {
	cout << "Name : " << name << endl;
	cout << "Age : " << age << endl;
}

int main()
{
	Person p1, p2("POP", 15), p3("PARK");
	p1.setName("±èÆË¼Û");
	p1.setAge(100);

	p1.show();
	p2.show();
	p3.show();
}