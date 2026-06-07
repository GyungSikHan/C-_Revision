#include <iostream>
using namespace std;

class Component
{
public:
	virtual void Display() = 0;
};

class Leaf : public Component
{
public:
	Leaf() : name{} {}
	Leaf(const char* name)
	{
		strcpy_s(this->name, sizeof(this->name), name);
	}
	void Display() override
	{
		cout << name << endl;
	}
private:
	char name[256];
};

class Composite : public Component
{
public:
	Composite(const char* name)
		:count()
	{
		curr[count++] = name;
	}
	void Add(Leaf* node)
	{
		curr[count++] = *node;
	}
	void Display() override
	{
		for (int i = 0; i < count; ++i)
		{
			cout << "index: " << i << endl;
			curr[i].Display();
		}	
	}
private:
	Leaf curr[10];
	int count;
};

int main()
{
	Leaf l1("Item1"); Leaf l2("Item2");

	Composite comp("Folder");
	comp.Add(&l1); comp.Add(&l2);
	Component* components[] = { &l1, &comp };
	for (int i = 0; i < 2; ++i)
		components[i]->Display();
}