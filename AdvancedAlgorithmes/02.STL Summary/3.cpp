#include <iostream>
#include <vector>
#include <functional>

int add(int a, int b)
{
	return a + b;
}

int main()
{
	//기본 형태
	int(*fun)(int, int) = &add;
	std::cout << fun(2, 3) << std::endl;

	//STL 제공 형태
	std::function<int(int, int)>f1 = add;
	std::cout << f1(2, 3) << std::endl;

	std::function<int(int, int)> f2 = [](int a, int b) { return a * b; };
	std::cout << f2(4, 5) << std::endl;

	std::vector<int >v{ 1,2,3,4,5,6,7,8,9,10 };
	std::function<bool(int)> pred = [](int x) {return x % 2 == 0; };

	for (int x : v)
		if (pred(x))
			std::cout << x << " ";
	std::cout << std::endl;
}
