#include <iostream>
#include <print>
using namespace std;

template <typename... Args>
auto Add(Args... args)
{
	return(... + args);
}
template <typename... Args>
void PrintAll(Args... args)
{
	((std::print("{} ", args), ...));
	std::print("\n");
}
int main()
{
	int ret = Add(1, 2, 3, 4, 5);
	cout << ret << endl;
	PrintAll(1, 2, 3, 4, 5);
}