#include <iostream>
using namespace std;

char scoring(int score)
{
	score /= 10;
	char c{};
	switch (score)
	{
	case 10:
	case 9:
		c = 'A';
		break;
	case 8:
		c = 'B';
		break;
	case 7:
		c = 'C';
		break;
	default:
		c = 'D';
		break;
	}

	return c;
}

int main()
{
	int score{};
	cin >> score;

	cout<<scoring(score);
}