#pragma once

#include "Shape.h"

class GraphicEditor
{
	int select;
	int cntC = 0, cntR = 0, cntL = 0;

	Shape* temp = nullptr;
	Shape* nxt = nullptr;
	Shape* pStart = nullptr;
	Shape* pLast = nullptr;

public:
	int Select();
	void Insert();
	void Delete();
	void ShowAll();
	void ShowFigure();
};