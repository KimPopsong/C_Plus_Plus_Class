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

		cout << "[1] 소스파일 업로드" << endl;
		cout << "[2] 정보 갱신" << endl;
		cout << "[3] 수도 정보 검색" << endl;
		cout << "[4] 퀴즈" << endl;
		cout << "[5] 종료" << endl;

		s = Select_Number(1, 5, 5);

		switch (s)
		{
		case 1: //소스파일 업로드
			FileOpen();
			break;

		case 2: //정보 갱신
			cout << "(1) 수도이름 수정" << endl;
			cout << "(2) 새로운 나라 추가" << endl;
			cout << "(3) 나라 삭제" << endl;
			cout << "(4) 소스파일 백업" << endl;
			Update();
			break;

		case 3: //수도 정보 검색
			cout << "(1) 나라이름으로 개별 검색" << endl;
			cout << "(2) 나라정보 전체 출력" << endl;

			s = Select_Number(1, 2, 2);

			if (s == 1) //나라이름으로 개별 검색
				SearchByNation();

			else //나라정보 전체 출력
				PrintAll();
			break;

		case 4: //퀴즈
			Quiz();
			break;

		case 5: //종료
			return 0;
		}
	};
}

int Nation::Select_Number(int min, int max, int exception) //최소, 최대, 예외
{
	while (1)
	{
		int select;

		cout << "선택 : ";
		cin >> select;
		cout << endl;

		if ((select >= min && select <= max) || select == exception)	//min이상 max이하, 예외 탈출
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
			if (cin.fail()) //숫자가 아닌 것 cin.fail()이 ture
				cout << "잘못된 입력입니다. 다시 입력해주세요." << endl << endl;

			else if (select < min) //min보다 작을 때
				cout << "최소 " << min << "을 입력해야 합니다." << endl << endl;

			else  //max보다 클 때
				cout << "최대 " << max << "까지 가능합니다." << endl << endl;

			cin.clear(); //버퍼제거
			cin.ignore(INT_MAX, '\n'); //버퍼제거
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
	case 1: //수도이름 수정
		ModifyCapital();
		break;

	case 2: //새로운 나라 추가
		AddNation();
		break;

	case 3: //나라 삭제
		DelNation();
		break;

	case 4: //소스파일 백업
		BackUp();
		break;
	}
}

void Nation::ModifyCapital()
{
	string s1, s2;
	map<string, string>::iterator it;

	cout << "Select Nation to Modify : ";
	cin >> s1; //수정할 수도의 나라 입력

	it = dic.find(s1);

	if (dic.end() == dic.find(s1)) //찾지 못함
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
		string s1 = iter->first; //map의 키
		string s2 = iter->second; //map의 값

		for (int i = 0; i < s1.length(); i++)
		{
			fout.put(s1[i]); //한글자씩 쓰기
		}

		fout.put(';'); //세미콜론 추가

		for (int i = 0; i < s2.length(); i++)
		{
			fout.put(s2[i]); //한글자씩 쓰기
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
		int ans = rand() % 4; //정답
		string example[4]; //예
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
	cout << "정답률 : " << percent << "%" << endl << endl;
}