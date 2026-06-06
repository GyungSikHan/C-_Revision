#include <iostream>
using namespace std;

class Builder
{
public:
	Builder(){}
	virtual ~Builder(){}
	virtual void BuildPart1() = 0;
	virtual void BuildPart2() = 0;
	virtual void GetResult() const = 0;
	
protected:
	char ret[256];
};

class ConcreteBuilderA : public Builder
{
public:
	ConcreteBuilderA() { strcpy_s(ret, sizeof(ret), "ConcreteA"); }
	~ConcreteBuilderA() override {}
	void BuildPart1() override
	{
		cout << "Concrete Builder A Build Part1" << endl;
	}
	void BuildPart2() override
	{
		cout << "Concrete Builder A Build Part2" << endl;
	}
	void GetResult() const override
	{
		cout << ret << " 완성" << endl;
	}
};

class ConcreteBuilderB : public Builder
{
public:
	ConcreteBuilderB() { strcpy_s(ret, sizeof(ret), "ConcreteB"); }
	~ConcreteBuilderB() override {}
	void BuildPart1() override
	{
		cout << "Concrete Builder B Build Part1" << endl;
	}
	void BuildPart2() override
	{
		cout << "Concrete Builder B Build Part2" << endl;
	}
	void GetResult() const override
	{
		cout << ret << " 완성" << endl;
	}
};

int main()
{
	ConcreteBuilderA builderA; ConcreteBuilderB builderB;
	Builder* builders[] = { &builderA, &builderB };
	for (int i = 0; i < 2; ++i) {
		builders[i]->BuildPart1();
		builders[i]->BuildPart2();
		builders[i]->GetResult();
	}
}