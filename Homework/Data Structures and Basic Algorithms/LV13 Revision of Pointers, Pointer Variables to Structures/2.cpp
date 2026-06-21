#include <iostream>
using namespace  std;

struct Human
{
	int age;
};

int main()
{
	Human a;
	Human b;
	Human c;
	Human d;
	Human e;
	Human* simData[5]{ &a,&b,&c,&d,&e };

	for (int i = 0; i < 5; ++i)
	{
		cin >> simData[i]->age;
	}

	int min = 987654321, max = -1;
	for (int i = 0; i < 5; ++i)
	{
		if (simData[i]->age < min)
			min = simData[i]->age;
		if (simData[i]->age > max)
			max = simData[i]->age;
	}

	cout << "MAX:" << max << endl;
	cout << "MIN:" << min << endl;
}
