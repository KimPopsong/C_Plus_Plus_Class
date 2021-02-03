#include "nation.h"

Nation::Nation() {}

ostream& operator<< (ostream& out, map<string, string> m)
{
	for (pair<string, string> p : m)
	{
		cout << p.first << " : " << p.second << endl;
	}

	return out;
}


istream& operator>>(istream& in, map<string, string> &m)
{
	string s1, s2;

	cout << "Write National Name : ";
	cin >> s1;

	if (s1 == "No")
		return in;

	map<string, string>::iterator it;

	it = m.find(s1);

	if (m.end() == m.find(s1))
	{
		cout << "Write Capital Name : ";
		cin >> s2;

		m[s1] = s2;
		cout << s1 << " & " << s2 << " Added" << endl << endl;
	}

	else
	{
		cout << "Error!" << endl << s1 << " Already Exist!" << endl << endl;
	}

	return in;
}

int Nation::Select_Menu()
{
	while (1)
	{
		int s;

		cout << "[1] �ҽ����� ���ε�" << endl;
		cout << "[2] ���� ����" << endl;
		cout << "[3] ���� ���� �˻�" << endl;
		cout << "[4] ����" << endl;
		cout << "[5] ����" << endl;

		s = Select_Number(1, 5, 5);

		switch (s)
		{
		case 1: //�ҽ����� ���ε�
			FileOpen();
			break;

		case 2: //���� ����
			cout << "(1) �����̸� ����" << endl;
			cout << "(2) ���ο� ���� �߰�" << endl;
			cout << "(3) ���� ����" << endl;
			cout << "(4) �ҽ����� ���" << endl;
			Update();
			break;

		case 3: //���� ���� �˻�
			cout << "(1) �����̸����� ���� �˻�" << endl;
			cout << "(2) �������� ��ü ���" << endl;

			s = Select_Number(1, 2, 2);

			if (s == 1) //�����̸����� ���� �˻�
				SearchByNation();

			else //�������� ��ü ���
				PrintAll();
			break;

		case 4: //����
			Quiz();
			break;

		case 5: //����
			return 0;
		}
	};
}

int Nation::Select_Number(int min, int max, int exception) //�ּ�, �ִ�, ����
{
	while (1)
	{
		int select;

		cout << "���� : ";
		cin >> select;
		cout << endl;

		if ((select >= min && select <= max) || select == exception)	//min�̻� max����, ���� Ż��
		{
			if (cntopen == false && select != 1 && select != 5)
			{
				cout << "Source File must be Uploaded" << endl;
				continue;
			}

			return select;
		}


		else
		{
			if (cin.fail()) //���ڰ� �ƴ� �� cin.fail()�� ture
				cout << "�߸��� �Է��Դϴ�. �ٽ� �Է����ּ���." << endl << endl;

			else if (select < min) //min���� ���� ��
				cout << "�ּ� " << min << "�� �Է��ؾ� �մϴ�." << endl << endl;

			else  //max���� Ŭ ��
				cout << "�ִ� " << max << "���� �����մϴ�." << endl << endl;

			cin.clear(); //��������
			cin.ignore(INT_MAX, '\n'); //��������
		}
	}

}

void Nation::Insert(string nt, string cap)
{
	dic[nt] = cap;
}

void Nation::FileOpen()
{
	ifstream fin("Nation.txt");

	if (!fin)
		cout << "File Open Failed" << endl << endl;

	else
	{
		string s;

		cntopen = true;
		cout << "Done" << endl << endl;

		while (getline(fin, s))
		{
			string front, rear;
			int i;

			for (i = 0; s[i] != ';'; i++)
			{
				front += s[i];
			}

			i++;
			for (; i < s.length(); i++)
			{
				rear += s[i];
			}

			Insert(front, rear);
		}
	}
}

void Nation::Update()
{
	int s = Select_Number(1, 4, 4);

	switch (s)
	{
	case 1: //�����̸� ����
		ModifyCapital();
		break;

	case 2: //���ο� ���� �߰�
		AddNation();
		break;

	case 3: //���� ����
		DelNation();
		break;

	case 4: //�ҽ����� ���
		BackUp();
		break;
	}
}

void Nation::ModifyCapital()
{
	string s1, s2;
	map<string, string>::iterator it;

	cout << "Select Nation to Modify : ";
	cin >> s1; //������ ������ ���� �Է�

	it = dic.find(s1);

	if (dic.end() == dic.find(s1)) //ã�� ����
	{
		cout << "Can't Find " << endl;
		return;
	}

	else
	{
		dic.erase(it);
		cout << "How to Modify? ; ";
		cin >> s2;

		Insert(s1, s2);
	}
}

void Nation::AddNation()
{
	//string s1, s2;
	int s1, s2;

	cout << "If you type 'No' Then Quit" << endl;

	while (true)
	{
		s1 = dic.size();

		cin >> dic;
		
		s2 = dic.size();

		if (s1 == s2)
			break;
	}

}

void Nation::DelNation()
{
	string s;
	map<string, string>::iterator it;

	cout << "Which Nation do you want to delete? : ";
	cin >> s;

	it = dic.find(s);

	if (it == dic.end())
		cout << "Can't Find" << endl;

	else
	{
		cout << "Deleted" << endl;
		dic.erase(it);
	}
}

void Nation::BackUp()
{
	ofstream fout;

	fout.open("Nation.txt");

	map<string, string>::iterator iter;

	for (iter = dic.begin(); iter != dic.end(); iter++)
	{
		string s1 = iter->first; //map�� Ű
		string s2 = iter->second; //map�� ��

		for (int i = 0; i < s1.length(); i++)
		{
			fout.put(s1[i]); //�ѱ��ھ� ����
		}

		fout.put(';'); //�����ݷ� �߰�

		for (int i = 0; i < s2.length(); i++)
		{
			fout.put(s2[i]); //�ѱ��ھ� ����
		}

		fout.put('\n');
	}

	cout << "Done" << endl;
}

void Nation::SearchByNation()
{
	string s;
	map<string, string>::iterator it;

	cout << "Which Capital do you want to find? Enter Nation : ";
	cin >> s;

	it = dic.find(s);

	if (it == dic.end())
		cout << "Can't Find" << endl;

	else
	{
		cout << dic.at(s) << endl << endl;
	}
}

void Nation::PrintAll()
{
	cout << dic;
}

void Nation::Quiz()
{
	srand((unsigned int)time(0));

	double right = 0, wrong = 0;
	int i = 0;

	while (true)
	{
		int num[4] = { 0 };
		int ans = rand() % 4; //����
		string example[4]; //��
		string na;

		for (int j = 0; j < 4; j++)
		{
			int t = rand() % dic.size();

			num[j] = t;

			for (int k = 0; k < j; k++)
			{
				if (t == num[k])
				{
					j--;
					break;
				}
			}
		}

		for (int j = 0; j < 4; j++)
		{
			map<string, string>::iterator iter;
			iter = dic.begin();
			for (int k = 0; k < num[j]; k++, iter++)
			{

			}

			if (j == ans)
				na = iter->first;
			example[j] = iter->second;
		}

		cout << "Quiz " << ++i << endl;
		cout << "What is " << na << "'s Capital?" << endl;

		for (int j = 0; j < 4; j++)
		{
			cout << j + 1 << ". " << example[j] << " ";
		}

		cout << endl;
		int sel = Select_Number(1, 4, 9);

		if (sel == 9)
			break;

		else if ((ans + 1) == sel)
		{
			cout << "Right" << endl << endl;
			right++;
		}

		else
		{
			cout << "Wrong" << endl << endl;
			wrong++;
		}
	}

	double percent = (right) / (wrong + right) * 100;
	cout << "����� : " << percent << "%" << endl << endl;
}