#include <iostream>
using namespace std;

struct Cat
{
	int age;
	int weight;
	char name[20]{};

	void Cat_Print()
	{
		cout << "Cat's naem: " << name << endl;
		cout << "Cat's age: " << age << endl;
		cout << "Cat's weight: " << weight << endl;
	}
	
	void Cat_SetAge(int age)
	{
		this->age = age;
	}
};



int main()
{
	Cat yamyami{};
	yamyami.age = 7;
	yamyami.weight = 4;
	const char name[20] = "yamyami";
	for (int i = 0; i < 20; ++i)
	{
		yamyami.name[i] = name[i];
	}

	yamyami.Cat_Print();
}