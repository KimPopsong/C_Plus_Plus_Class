#include <iostream>

using namespace std;

class Total {
public:
	int cnt = 0, odd = 0, even = 0, odd_sum = 0, even_sum = 0, input = 0;
	void show();
	void Put();
};

void Total::show() {
	cout << "�������� ���� : " << cnt << endl;
	cout << "¦���� �� & ���� : " << even_sum << " " << even << endl;
	cout << "Ȧ���� �� & ���� : " << odd_sum << " " << odd << endl;
}

void Total::Put() {
	cout << "���� �Է� : ";
	cin >> input;
}

int main()
{
	Total total;
	
	total.Put();

	//while ��

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

	//do while��

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

	//for ��

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