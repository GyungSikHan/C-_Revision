#include <iostream>
#include <ctime>

int main()
{
	std::clock_t start{}, end{};
	double duration{};

	start = std::clock();

	for (int i = 0; i < 10; ++i)
	{
		std::cout << i << std::endl;
	}

	end = std::clock();

	duration = (double)(end - start) / CLOCKS_PER_SEC;
	std::cout << duration << "초";
}