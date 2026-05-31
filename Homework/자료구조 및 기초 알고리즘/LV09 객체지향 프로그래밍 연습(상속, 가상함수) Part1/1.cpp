#include <iostream>
using namespace std;

class Animal
{
public:
	Animal(): name{}{}
	virtual ~Animal(){}
	virtual void Speak(){}
protected:
	char name[256];
};

class Dog : public Animal
{
public:
	Dog(const char* name)
	{
		strcpy_s(this->name, sizeof(this->name), name);
	}
	~Dog() override{}
	void Speak() override
	{
		cout << "barks!" << endl;
	}
};

class Cat : public Animal
{
public:
	Cat(const char* name)
	{
		strcpy_s(this->name, sizeof(this->name), name);
	}
	~Cat() override {}
	void Speak() override
	{
		cout << "meows!" << endl;
	}
};

int main()
{
	Dog d1("Baekgu");
	Cat c1("Nabi");
	Animal* animals[] = { &d1, &c1 };
	for (int i = 0; i < 2; ++i)
		animals[i]->Speak();
}