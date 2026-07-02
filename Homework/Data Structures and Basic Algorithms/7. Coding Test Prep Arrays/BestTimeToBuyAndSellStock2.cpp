#include <iostream>
using namespace std;

const int length = 30000;

void Buy()
{
	
}
void Sell()
{
	
}

int main()
{
	int size{};
	int prices[length];
	cin >> size;

	for (int i = 0; i < size; ++i)
		cin >> prices[i];

	int sum{};
	for (int i = 1; i < size; ++i)
	{
		if (prices[i] > prices[i - 1])
			sum += prices[i] - prices[i - 1];
	}
	

	cout << sum;
}