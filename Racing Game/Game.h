#pragma once

#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

class Horse
{
	int now = 0; //말의 현재 위치
	int rank = 0; //말이 완주한 순간부터 지나간 turn, 높을수록 등수가 높음

public:
	void Go(); //진행하는 함수
	int getNow()const; //말들의 현재위치를 가져오는 함수
	void setNow(); //말의 위치가 20이상일때 20으로 보정시켜줌
	int getRank()const; //말의 등수를 가져옴
};

class Game 
{
	Horse* gamer; //Horse객체
	int turn = 0; //진행되는 턴

public:
	Game(int t); //생성자
	void gameStart(int num); //게임 시작하는 함수
	void printGame(int num); //게임의 현재 상황을 출력하는 함수
	void Check(int i, int t); //말들의 현재 위치를 확인. 20이상이면 setNow를 호출
	void gameEnd(int num, int choice); //게임종료.
	~Game(); //소멸자
};
