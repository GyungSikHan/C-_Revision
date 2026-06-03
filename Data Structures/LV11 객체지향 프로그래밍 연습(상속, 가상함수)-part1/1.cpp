#include <iostream>

using namespace std;

class Animal
{
public:
	Animal():age()
	{
		cout << "Animal 생성자" << endl;
	}
	int age;
	void Eat()
	{
		cout << "먹는다" << endl;
	}
	virtual void Bark()
	{
		cout << "xx!" << endl;
	}
};

class Dog:public Animal
{
public:
	Dog() : smell()
	{
		cout << "Dog 생성자" << endl;
	}
	int smell;
	void Bark()
	{
		cout << "멍멍!" << endl;
	}
};

class Cat : public Animal
{
public:
	Cat():jump()
	{
		cout << "Cat 생성자" << endl;
	}
	int jump;
	void Bark()
	{
		cout << "야옹" << endl;
	}
};

int main()
{
	Dog d;
	d.Eat();
	d.Bark();

	Cat c;
	c.Eat();
	c.Bark();

	Animal* a[2]= {&d, &c};
	for (int i = 0; i < 2; ++i)
	{
		a[i]->Bark();
	}
}