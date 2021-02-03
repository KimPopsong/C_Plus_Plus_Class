#include "GraphicEditor.h"

int GraphicEditor::Select()
{
	cout << "삽입 : 1, 삭제 : 2, 모두보기 : 3, 통계정보 : 4, 종료 : 5 >> ";

	int select;

	do //메뉴 선택
	{
		cin >> select;

		if (select >= 1 && select <= 5)	//1이상 3이하 탈출
			break;

		else
		{
			if (cin.fail()) //숫자가 아닌 것 cin.fail()이 ture
				cout << "잘못된 입력입니다. 다시 입력해주세요." << endl;

			else if (select < 1)
				cout << "최소 1을 입력해야 합니다." << endl;

			else
				cout << "최대 5까지 가능합니다." << endl;

			cin.clear(); //버퍼제거
			cin.ignore(INT_MAX, '\n'); //버퍼제거
		}
	} while (1);

	switch (select)
	{
	case 1:
		Insert();
		break;

	case 2:
		Delete();
		break;

	case 3:
		ShowAll();
		break;

	case 4:
		ShowFigure();
		break;

	default:
		return 5;
	}
}

void GraphicEditor::Insert()
{
	int s;

	cout << "선 : 1, 원 : 2, 사각형 : 3 >> ";

	do //메뉴 선택
	{
		cin >> s;

		if (s >= 1 && s <= 3)	//1이상 3이하 탈출
			break;

		else
		{
			if (cin.fail()) //숫자가 아닌 것 cin.fail()이 ture
				cout << "잘못된 입력입니다. 다시 입력해주세요." << endl;

			else if (s < 1)
				cout << "최소 1을 입력해야 합니다." << endl;

			else
				cout << "최대 3까지 가능합니다." << endl;

			cin.clear(); //버퍼제거
			cin.ignore(INT_MAX, '\n'); //버퍼제거
		}
	} while (1);

	switch (s)
	{
	case 1:
		temp = new Line;
		cntL++;
		break;

	case 2:
		temp = new Circle;
		cntC++;
		break;

	default:
		temp = new Rect;
		cntR++;
	}

	if (pStart == nullptr)
		pStart = temp;

	else
	{
		nxt = pStart;

		while (1)
		{
			if (nxt->getNext() != nullptr)
				nxt = nxt->getNext();

			else
			{
				nxt->add(temp);
				pLast = nxt;
				break;
			}
		}
	}
}

void GraphicEditor::Delete()
{
	int del;

	cout << "삭제하고자 하는 도형의 인덱스 >> ";

	do //메뉴 선택
	{
		cin >> del;

		if (del >= 0 && del <= cntL + cntC + cntR - 1)	//1이상 3이하 탈출
			break;

		else
		{
			if (cin.fail()) //숫자가 아닌 것 cin.fail()이 ture
				cout << "잘못된 입력입니다. 다시 입력해주세요." << endl;

			else if (del < 0)
				cout << "최소 0을 입력해야 합니다." << endl;

			else
				cout << "최대 " << cntL + cntC + cntR - 1 << "까지 가능합니다." << endl;

			cin.clear(); //버퍼제거
			cin.ignore(INT_MAX, '\n'); //버퍼제거
		}
	} while (1);

	if (del == 0)
		pStart = pStart->getNext();

	else
	{
		temp = pStart;
		nxt = pStart;

		for (int i = 0; i < del - 1; i++)
			nxt = nxt->getNext();

		for (int i = 0; i < del; i++)
			temp = temp->getNext();

		nxt->add(temp->getNext());

		if (temp->Check() == 1)
			cntL--;

		else if (temp->Check() == 2)
			cntC--;

		else
			cntR--;
		
		free(temp);
	}

}

void GraphicEditor::ShowAll()
{
	nxt = pStart;
	int i = 0;

	while (1)
	{
		if (nxt->getNext() == nullptr)
		{
			cout << i++ << " : ";
			nxt->paint();
			break;
		}
			
		else
		{
			cout << i++ << " : ";
			nxt->paint();
			nxt = nxt->getNext();
		}
	}
}

void GraphicEditor::ShowFigure()
{
	cout << "Line : " << cntL << endl;
	cout << "Circle : " << cntC << endl;
	cout << "Rect : " << cntR << endl;
}