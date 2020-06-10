#include <iostream>

using namespace std;

class Point {
	double x, y;

public:
	Point();
	Point(double xx, double yy);
	double getX();
	double getY();
	void setX(double);
	void setY(double);
	void showPoint();
};

Point::Point() :Point(0, 0) {};

Point::Point(double xx, double yy) :x{ xx }, y{ yy } {};

double Point:: getX() {
	return x;
}
double Point::getY() {
	return y;
}

void Point::setX(double a) {
	x = a;
}
void Point::setY(double b) {
	y = b;
}


void Point::showPoint() {
	cout << "(" << x << "," << y << ")" << endl;
}

int main()
{
	Point p1(1, 2), p2;

	p2.setX(10);
	p2.setY(20);

	p1.showPoint();
	p2.showPoint();

	return 0;
}