#include "Game.h"

Game::Game(int t)
{
	gamer = new Horse[t]; //gamer라는 객체 생성
}

void Game::printGame(int num)
{
	cout << "Turn : " << turn++ << endl; //진행한 턴 출력
	cout << "==================================================" << endl;

	for (int i = 0; i < num; i++)
	{
		for (int j = 0; j < gamer[i].getNow(); j++) //각 말의 현재위치를 출력
			cout << "-"; //말이 지나간 자리 출력
		cout << "(  ) => " << gamer[i].getNow() << endl; //말의 모습 출력
	}
	cout << "==================================================" << endl;

	clock_t sleep = clock(); //ctime안에 있는 함수 사용
	while(clock() - sleep < 1000); //1초씩 지연시켜서 출력하는 함수
}

void Game::gameStart(int num) //num은 말의 마릿수
{
	while (1)
	{
		for (int i = 0; i < num; i++) //말들이 0~5의 랜덤한 값만큼 움직이도록 함 
		{
			gamer[i].Go(); //Go함수 호출
			Check(i, gamer[i].getNow()); //말들의 위치를 검사하는 함수 호출
		}

		printGame(num); //말들의 현재 위치를 출력

		int cnt = 0; //도착한 말의 마리수

		for (int i = 0; i < num; i++)
			if (gamer[i].getNow() >= 20) //도착한말이 있으면 cnt++
				cnt++;
		
		if (cnt == num) //cnt가 게임하는 말의 숫자와 같으면 게임을 종료
			break;
	}
}

void Game::Check(int i, int t) //말의 현재위치를 검사
{
	if (t >= 20) //20이상이면 setNow함수 호출
		gamer[i].setNow();
}

void Game::gameEnd(int num, int choice) //게임종료하는 함수
{
	int winner = 0; //우승자의 rank값 저장

	for (int i = 0; i < num; i++)
		if (winner < gamer[i].getRank()) //rank의 값이 winner보다 크면 winner의 rank값 저장
			winner = gamer[i].getRank();

	cout << "우승자는 ";

	for (int i = 0; i < num; i++)
		if (winner == gamer[i].getRank()) //winner값과 rank값이 같으면 우승한 말 출력. 동시우승 가능
			cout << (i + 1) << "번 ";

	cout << "말입니다." << endl;

	if (gamer[choice - 1].getRank() == winner) //winner의 값과 rank의 값이 같으면 우승
		cout << "축하합니다. 우승하셨습니다. " << endl;

	else
		cout << "패배하셨습니다." << endl;
}

Game::~Game()
{
	delete[] gamer;
}

void Horse::Go()
{
	int r = rand() % 6; //r에 0 ~ 5의 랜덤한 값을 저장.

	now += r; //말이 이동함
}

int Horse::getNow()const
{
	return now; //말의 현재위치 반환
}

void Horse::setNow() //말의 현재위치가 20이상이면
{
	rank++;  //rank값을 1씩 늘림. 가장 먼저 도착한 말은 rank값이 가장 큼. 동시에 도착하면 rank값이 같음
	now = 20; //말의 현재위치를 다시 20으로 설정
}

int Horse::getRank()const
{
	return rank; //말의 rank값을 반환
}