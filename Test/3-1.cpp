#include <iostream>

using namespace std;

class Point {
	double x, y;
public:
	Point();
	Point(double xx, double yy);
	void show();
};

Point::Point():Point(0, 0) {};

Point::Point(double xx, double yy) :x{ xx }, y{ yy } {};

void Point::show() {
	cout << "(" << x << "," << y << ")" << endl;
};

int main()
{
	Point p1, p2(10, 10);

	p1.show();
	p2.show();

	system("pause");
	return 0;
}