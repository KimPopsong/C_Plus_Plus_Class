#include <iostream>

using namespace std;

class Rectangle {
public:
	int width;
	int height;
	int getArea();
	int getArea(int a, int b);
};

int Rectangle::getArea() {
	cout << "get_1" << endl;
	return width * height;
}

int Rectangle::getArea(int width, int height) {
	cout << "get_2" << endl;
	return getArea();
}

int main() 
{
	Rectangle rect;

	cin >> rect.width;
	cin >> rect.height;

	cout << "사각형의 면적은 " << rect.getArea(rect.width, rect.height) << endl;

	system("pause");
	return 0;
}
