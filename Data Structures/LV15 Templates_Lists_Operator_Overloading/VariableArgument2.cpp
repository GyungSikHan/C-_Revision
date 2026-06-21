#include <iostream>
using namespace std;

void Print()
{
	cout << endl;
}
template <typename T, typename... Args>
void Print(T first, Args... args)
{
	cout << first << " ";
	Print(args...);
}

int main()
{
	Print(1, "Hello", 2.2, 'A');
}