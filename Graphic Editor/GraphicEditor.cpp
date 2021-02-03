#include "GraphicEditor.h"

int GraphicEditor::Select()
{
	cout << "���� : 1, ���� : 2, ��κ��� : 3, ������� : 4, ���� : 5 >> ";

	int select;

	do //�޴� ����
	{
		cin >> select;

		if (select >= 1 && select <= 5)	//1�̻� 3���� Ż��
			break;

		else
		{
			if (cin.fail()) //���ڰ� �ƴ� �� cin.fail()�� ture
				cout << "�߸��� �Է��Դϴ�. �ٽ� �Է����ּ���." << endl;

			else if (select < 1)
				cout << "�ּ� 1�� �Է��ؾ� �մϴ�." << endl;

			else
				cout << "�ִ� 5���� �����մϴ�." << endl;

			cin.clear(); //��������
			cin.ignore(INT_MAX, '\n'); //��������
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

	cout << "�� : 1, �� : 2, �簢�� : 3 >> ";

	do //�޴� ����
	{
		cin >> s;

		if (s >= 1 && s <= 3)	//1�̻� 3���� Ż��
			break;

		else
		{
			if (cin.fail()) //���ڰ� �ƴ� �� cin.fail()�� ture
				cout << "�߸��� �Է��Դϴ�. �ٽ� �Է����ּ���." << endl;

			else if (s < 1)
				cout << "�ּ� 1�� �Է��ؾ� �մϴ�." << endl;

			else
				cout << "�ִ� 3���� �����մϴ�." << endl;

			cin.clear(); //��������
			cin.ignore(INT_MAX, '\n'); //��������
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

	cout << "�����ϰ��� �ϴ� ������ �ε��� >> ";

	do //�޴� ����
	{
		cin >> del;

		if (del >= 0 && del <= cntL + cntC + cntR - 1)	//1�̻� 3���� Ż��
			break;

		else
		{
			if (cin.fail()) //���ڰ� �ƴ� �� cin.fail()�� ture
				cout << "�߸��� �Է��Դϴ�. �ٽ� �Է����ּ���." << endl;

			else if (del < 0)
				cout << "�ּ� 0�� �Է��ؾ� �մϴ�." << endl;

			else
				cout << "�ִ� " << cntL + cntC + cntR - 1 << "���� �����մϴ�." << endl;

			cin.clear(); //��������
			cin.ignore(INT_MAX, '\n'); //��������
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