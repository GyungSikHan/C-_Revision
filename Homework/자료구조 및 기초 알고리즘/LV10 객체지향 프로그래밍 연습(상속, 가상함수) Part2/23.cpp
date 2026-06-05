#include <iostream>
using namespace std;
class Element;
class ConcreteElementA;
class ConcreteElementB;

class Visitor
{
public:
	Visitor(){}
	virtual ~Visitor(){}
	virtual void Visit(ConcreteElementA* element) = 0;
	virtual void Visit(ConcreteElementB* element) = 0;
};

class Element
{
public:
	Element(): name{}{}
	virtual ~Element(){}
	virtual void Accept(Visitor* visitor) = 0;
	const char* GetName()const { return name; }
protected:
	char name[256];
};

class ConcreteElementA : public Element
{
public:
	ConcreteElementA()
	{
		strcpy_s(name, sizeof(name), "ElementA");
	}
	~ConcreteElementA()override{}
	void Accept(Visitor* visitor) override
	{
		visitor->Visit(this);
	}
};

class ConcreteElementB : public Element
{
public:
	ConcreteElementB()
	{
		strcpy_s(name, sizeof(name), "ElementB");
	}
	~ConcreteElementB()override {}
	void Accept(Visitor* visitor) override
	{
		visitor->Visit(this);
	}
};

class ConcreteVisitor : public Visitor
{
public:
	ConcreteVisitor() {}
	~ConcreteVisitor()override {}
	void Visit(ConcreteElementA* element) override
	{
		cout << element->GetName() << " visit" << endl;
	}
	void Visit(ConcreteElementB* element) override
	{
		cout << element->GetName() << " visit" << endl;
	}
};

int main()
{
	ConcreteElementA elementA; ConcreteElementB elementB;
	ConcreteVisitor visitor;
	Element* elements[] = { &elementA, &elementB };
	for (int i = 0; i < 2; ++i)
		elements[i]->Accept(&visitor);
}