#include "Game.h"

using namespace std;

int main()
{
	int num = 0, choice; //num = ���� ��, choice = ������ ��
	srand((unsigned int)time(nullptr)); //srand�� �õ尪 ����

	cout << "�� ������ ���� �÷����Ͻðڽ��ϱ�? : ";

	do //���� �� �Է¹ޱ�
	{
		cin >> num;

		if (num >= 2 && num <= 5) //2���� �̻�, 5���� ���ϸ� ����Ż��
			break;

		else
		{
			if (cin.fail()) //���ڰ� �ƴ� �͵��̸� cin.fail()�� ture
				cout << "�߸��� ���� �Է��Դϴ�. �ٽ� �Է����ּ���." << endl;

			else if (num < 2) //2���� ���� ��
				cout << "�ּ� 2������ ���� �ʿ��մϴ�." << endl;

			else  //5���� Ŭ ��
				cout << "�ִ� 5������ ������ �����մϴ�." << endl;

			cin.clear(); //��������
			cin.ignore(INT_MAX, '\n'); //��������
		}
	} while (1);

	cout << "�� ��° ���� �����Ͻðڽ��ϱ�? : ";

	do //���� ��ȣ ����
	{
		cin >> choice;

		if (choice >= 1 && choice <= num) //1�̻�, ���� �� �����϶� ���� Ż��
			break;

		else
		{
			if (cin.fail())
				cout << "�߸��� ���� �Է��Դϴ�. �ٽ� �Է����ּ���." << endl;

			else if (choice < 1)
				cout << "1�������� �����մϴ�." << endl;

			else
				cout << "�ִ� "<<num<<"�������� �����մϴ�." << endl;

			cin.clear();
			cin.ignore(INT_MAX, '\n');
		}
	} while (1);

	Game horses(num); //��ü ����
	
	horses.gameStart(num); //���� ����, ���� ���� �Ű������� �־���

	horses.gameEnd(num, choice); //���� ��. ���� ��, ���� ������ ���� ��ȣ�� �Ű������� �־���

	return 0;
}