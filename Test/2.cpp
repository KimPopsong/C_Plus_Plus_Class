#include <iostream>

using namespace std;

class Rectangle {
	int width, height, area;

public:
	Rectangle();
	Rectangle(int a, int b);

	int computeArea();
	void show();

	int getWidth();
	int getHeight();
	int getArea(int a, int b);
};

Rectangle::Rectangle():Rectangle(0,0) {};
Rectangle::Rectangle(int a, int b) :width{ a }, height{ b } {};

int Rectangle::getWidth() {
	return width;
};
int Rectangle::getHeight() {
	return height;
};
int Rectangle::getArea(int a, int b) {
	a = width, b = height;
	return a * b;
}
int Rectangle::computeArea() {
	area = width * height;
	return area;
};

void Rectangle::show() {
	cout << computeArea() << endl;
}

int main()
{
	Rectangle r1(5, 10), r2(20, 30);

	r1.show();
	r2.show();
	
}