#include <iostream>
using namespace std;

void prints()
{
	cout<<endl;
}

template <typename T, typename... Args>
void prints(T first, Args... args)
{
	cout << first << " ";
	prints(args...);
}
int main()
{
	prints(1, "Hello", 3.14, 'A');
}