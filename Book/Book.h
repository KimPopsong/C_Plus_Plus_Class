#include <iostream>

using namespace std;

class Book {
	string title;   // ���� ���ڿ�
	int price;     // ����

public:
	Book(const string title, int price);
	Book(Book& b);
	void set(const string title, int price);
	void show();
};
