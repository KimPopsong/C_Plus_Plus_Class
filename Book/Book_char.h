#include <iostream>

using namespace std;

class Book {
	char* title;   // ���� ���ڿ�
	int price;     // ����
public:
	Book(const char* title, int price);
	Book(Book& b);
	~Book();
	void set(const char* title, int price);
	void show()
	{
		cout << title << " " << price << "��" << endl;
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