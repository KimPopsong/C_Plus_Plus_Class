#include <iostream>

using namespace std;

class Book {
	string title;   // 제목 문자열
	int price;     // 가격

public:
	Book(const string title, int price);
	Book(Book& b);
	void set(const string title, int price);
	void show();
};
