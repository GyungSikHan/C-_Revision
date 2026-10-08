#include <iostream>

int main()
{
	int d{};
	int result{};
	int count{};

	std::cin >> d;

	for (int i = 0; i < 8; ++i)
	{
		result = (d >> i) & 0x1;

		if (result)
		{
			count++;
		}
	}

	std::cout << count;
}