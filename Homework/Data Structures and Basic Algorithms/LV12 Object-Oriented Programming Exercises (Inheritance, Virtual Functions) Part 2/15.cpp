#include <iostream>
using namespace std;

class AbstractClass
{
public:
	AbstractClass(){}
	virtual ~AbstractClass(){}
	virtual void TemplateMethod()
	{
		Step1();
		Step2();
	}
	virtual void Step1() = 0;
	virtual void Step2() = 0;
};

class ConcreteClassA : public AbstractClass
{
public:
	ConcreteClassA(){}
	~ConcreteClassA()override{}
	void Step1() override
	{
		cout << "Concrete Builder A Build Step1" << endl;
	}
	void Step2() override
	{
		cout << "Concrete Builder A Build Step2" << endl;
	}
};

class ConcreteClassB : public AbstractClass
{
public:
	ConcreteClassB() {}
	~ConcreteClassB()override {}
	void Step1() override
	{
		cout << "Concrete Builder B Build Step1" << endl;
	}
	void Step2() override
	{
		cout << "Concrete Builder B Build Step2" << endl;
	}
};

int main()
{
	ConcreteClassA a; ConcreteClassB b;
	AbstractClass* classes[] = { &a, &b };
	for (int i = 0; i < 2; ++i)
		classes[i]->TemplateMethod();
}