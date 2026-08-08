#include <iostream>
#include <ctime>
using namespace std;

double One(std::clock_t start, std::clock_t end)
{
	start = std::clock();
	for (int i = 0; i < 10000; ++i)
	{
		cout << "#";
	}
	end = std::clock();

	return (end - start) / CLOCKS_PER_SEC;
}

double Two(std::clock_t start, std::clock_t end)
{
	int n{};
	cin >> n;
	start = std::clock();
	for (int y = 0; y < n; ++y)
		for (int x = 0; x <= y; ++x)
			cout << "#";
	end = std::clock();

	return (end - start) / CLOCKS_PER_SEC;
}

int n{};
void abc()
{
	for (int i = 0; i < n; i++)
		cout << "#";
}
double Three(std::clock_t start, std::clock_t end)
{
	start = std::clock();
	for (int i = 0; i < n; ++i)
	{
		abc();
		abc();
		abc();
	}
	end = std::clock();
	return (end - start) / CLOCKS_PER_SEC;
}

double Four(std::clock_t start, std::clock_t end)
{
	start = std::clock();

	cin >> n;
	for (int i = 0; i < n; ++i)
		for (int j = 0; j < 5; ++j)
			for (int z = 0; z < n; ++z)
				cout << "#";

	end = std::clock();

	return (end - start) / CLOCKS_PER_SEC;
}

enum eFunc
{
	one,
	two,
	three,
	four,
	Max
};
int main()
{
	int data;
	cin >> data;
	std::clock_t start{}, end{};
	eFunc eFuncRet = eFunc::Max;
	switch (data)
	{
	case 1:
		One(start,end);
		eFuncRet = eFunc::one;
		break;
	case 2:
		eFuncRet = eFunc::two;
		Two(start, end);
		break;
	case 3:
		eFuncRet = eFunc::three;
		Three(start, end);
		break;
	case 4:
		eFuncRet = eFunc::four;
		Four(start, end);
		break;
	default:
		break;
	}

	cout << (end - start) / CLOCKS_PER_SEC << endl;
	if (eFuncRet == eFunc::one)
		cout << 21 << endl;
	else
		cout << 2 << endl;
}