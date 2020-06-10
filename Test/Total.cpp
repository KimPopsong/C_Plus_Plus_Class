#include <iostream>

using namespace std;

class Total {
public:
	int cnt = 0, odd = 0, even = 0, odd_sum = 0, even_sum = 0, input = 0;
	void show();
	void Put();
};

void Total::show() {
	cout << "데이터의 개수 : " << cnt << endl;
	cout << "짝수의 합 & 개수 : " << even_sum << " " << even << endl;
	cout << "홀수의 합 & 개수 : " << odd_sum << " " << odd << endl;
}

void Total::Put() {
	cout << "정수 입력 : ";
	cin >> input;
}

int main()
{
	Total total;
	
	total.Put();

	//while 문

	while (total.input != -1)
	{
		total.cnt++;

		if (total.input % 2 == 0)
		{
			total.even++;
			total.even_sum += total.input;
		}

		else
		{
			total.odd++;
			total.odd_sum += total.input;
		}

		total.Put();
	}

	//do while문

	do
	{
		total.Put();

		if (total.input == -1)
			break;

		else if(total.input % 2 == 0)
		{
			total.even++;
			total.even_sum += total.input;
		}

		else
		{
			total.odd++;
			total.odd_sum += total.input;
		}

		total.cnt++;
	} while (total.input != -1);

	//for 문

	for (;;)
	{
		total.Put();

		if (total.input == -1)
			break;

		else if (total.input % 2 == 0)
		{
			total.even++;
			total.even_sum += total.input;
		}

		else
		{
			total.odd++;
			total.odd_sum += total.input;
		}

		total.cnt++;
	}

	total.show();

	return 0;
}