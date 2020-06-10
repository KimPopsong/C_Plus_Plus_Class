#include <iostream>

using namespace std;

class Rectangle {
public:
	int width, height;

	bool isSquare();

	Rectangle();
	Rectangle(int a);
	Rectangle(int w, int h);
};

bool Rectangle::isSquare()
{
	if (width == height)
		return true;

	else
		return false;
}

Rectangle::Rectangle() :Rectangle(1, 1) {}
Rectangle::Rectangle(int a) : Rectangle(a, a) {}
Rectangle::Rectangle(int w, int h) : width{ w }, height{ h } {}

int main() {
	Rectangle rect1;
	Rectangle rect2(3, 5);
	Rectangle rect3(3);

	if (rect1.isSquare()) cout << "rect1�� ���簢���̴�." << endl;
	if (rect2.isSquare()) cout << "rect2�� ���簢���̴�." << endl;
	if (rect3.isSquare()) cout << "rect3�� ���簢���̴�." << endl;

	system("pause");
	return 0;
}
