#include <iostream>
using namespace std;

class Target
{
public:
	Target(){}
	virtual ~Target(){}
	virtual void Request() = 0;
};

class Adaptee
{
public:
	Adaptee(){}
	~Adaptee(){}
	void SpecificRequest()
	{
		cout << "Adaptee" << endl;
	}
};

class Adapter : public Target
{
public:
	Adapter():adaptee(){}
	Adapter(Adaptee* adaptee):adaptee(adaptee){}
	~Adapter()override{}
	void Request() override
	{
		cout << "Adapter, ";
		if (!adaptee)
		{
			cout << "Adaptee is null" << endl;
			return;
		}
		adaptee->SpecificRequest();
	}
private:
	Adaptee* adaptee;
};

int main()
{
	Adaptee adaptee;
	Adapter adapter(&adaptee);
	Target* targets[] = { &adapter };
	for (int i = 0; i < 1; ++i)
		targets[i]->Request();
}