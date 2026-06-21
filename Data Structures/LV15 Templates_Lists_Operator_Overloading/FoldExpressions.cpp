#include <iostream>
#include <print>
using namespace std;

template <typename... Args>
auto Sum(Args... args)
{
	return (... + args);
}

template <typename... Args>
void printAll(Args... args)
{
	(std::print("{} ", args), ...);
	std::print("\n");
}

int main()
{
	int result = Sum(1, 2, 3, 4, 5);
	cout << result << endl;
	printAll(1,2,3,4,5);
}