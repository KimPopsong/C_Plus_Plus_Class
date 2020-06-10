#include "Game.h"

using namespace std;

int main()
{
	int num = 0, choice; //num = 말의 수, choice = 선택한 말
	srand((unsigned int)time(nullptr)); //srand로 시드값 설정

	cout << "몇 마리의 말로 플레이하시겠습니까? : ";

	do //말의 수 입력받기
	{
		cin >> num;

		if (num >= 2 && num <= 5) //2마리 이상, 5마리 이하면 루프탈출
			break;

		else
		{
			if (cin.fail()) //숫자가 아닌 것들이면 cin.fail()이 ture
				cout << "잘못된 숫자 입력입니다. 다시 입력해주세요." << endl;

			else if (num < 2) //2보다 작을 때
				cout << "최소 2마리의 말이 필요합니다." << endl;

			else  //5보다 클 때
				cout << "최대 5마리의 말까지 가능합니다." << endl;

			cin.clear(); //버퍼제거
			cin.ignore(INT_MAX, '\n'); //버퍼제거
		}
	} while (1);

	cout << "몇 번째 말을 선택하시겠습니까? : ";

	do //말의 번호 선택
	{
		cin >> choice;

		if (choice >= 1 && choice <= num) //1이상, 말의 수 이하일때 루프 탈출
			break;

		else
		{
			if (cin.fail())
				cout << "잘못된 숫자 입력입니다. 다시 입력해주세요." << endl;

			else if (choice < 1)
				cout << "1번말부터 가능합니다." << endl;

			else
				cout << "최대 "<<num<<"번말까지 가능합니다." << endl;

			cin.clear();
			cin.ignore(INT_MAX, '\n');
		}
	} while (1);

	Game horses(num); //객체 생성
	
	horses.gameStart(num); //게임 시작, 말의 수를 매개변수로 넣어줌

	horses.gameEnd(num, choice); //게임 끝. 말의 수, 내가 선택한 말의 번호를 매개변수로 넣어줌

	return 0;
}