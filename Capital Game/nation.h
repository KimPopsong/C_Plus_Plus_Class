#include <iostream>
#include <string>
#include <map>
#include <vector>
#include <iterator>
#include <fstream>
#include <ctime>

using namespace std;

class Nation
{
	map<string, string> dic;
	bool cntopen = false;

public:
	map<string, string> GetNation() { return dic; }
	Nation();
	int Select_Menu();
	int Select_Number(int min, int max, int exception);
	void Insert(string nt, string cp);
	void FileOpen();
	void Update();
	void ModifyCapital();
	void AddNation();
	void DelNation();
	void BackUp();
	void SearchByNation();
	void PrintAll();
	void Quiz();
	friend ostream& operator<< (ostream& out, map<string, string> m);
	friend istream& operator>>(istream& in, map<string, string> &m);
};