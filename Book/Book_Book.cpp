#include "Book.h"

Book::Book(const string t, int p)
{
	title = t;
	price = p;
}

Book::Book(Book& b)
{
	title = b.title;
	price = b.price;
}

void Book::set(const string t, int p)
{
	title = t;
	price = p;
}

void Book::show()
{
	cout << title << " " << price << "¿ø" << endl;
}