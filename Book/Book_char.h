#include <iostream>

using namespace std;

class Book {
	char* title;   // 제목 문자열
	int price;     // 가격
public:
	Book(const char* title, int price);
	Book(Book& b);
	~Book();
	void set(const char* title, int price);
	void show()
	{
		cout << title << " " << price << "원" << endl;
	}
};

Book::Book(const char* t, int p)
{
	int len = strlen(t);
	title = new char[len + 1];
	strcpy(title, t);
	price = p;
}

Book::Book(Book& b)
{
	int len = strlen(b.title);
	this->title = new char[len + 1];
	strcpy(this->title, b.title);
}

Book::~Book()
{
	delete title;
}

void Book::set(const char* t, int p)
{
	int len = strlen(t);
	title = new char[len + 1];
	strcpy(title, t);
	price = p;
}