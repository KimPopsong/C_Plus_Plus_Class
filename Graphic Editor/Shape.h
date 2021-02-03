#pragma once

#include <iostream>

using namespace std;

class Shape
{
	Shape* next = nullptr;

protected:
	virtual void draw() = 0;

public:
	Shape() { next = nullptr; }
	virtual ~Shape() { }
	void paint() { draw(); };
	Shape* add(Shape* p) 
	{
		this->next = p;
		return p;
	}
	Shape* getNext() { return next; }
	virtual int Check() = 0;
};

class Line : public Shape
{
	virtual ~Line() { }
	void draw() { cout << "Line " << endl; }
	int Check() { return 1; }
};

class Circle : public Shape
{
	virtual ~Circle() { }
	void draw() { cout << "Circle " << endl; }
	int Check() { return 2; }
};

class Rect : public Shape
{
	virtual ~Rect() { }
	void draw() { cout << "Rect " << endl; }
	int Check() { return 0; }
};