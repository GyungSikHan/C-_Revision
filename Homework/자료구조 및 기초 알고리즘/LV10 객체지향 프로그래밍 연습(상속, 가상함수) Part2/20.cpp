#include <iostream>
using namespace std;

class Handler
{
public:
	Handler() : nextHandler() {}
	virtual ~Handler(){}
	virtual void HandleRequest(int level) = 0;
	virtual void SetNext(Handler* next) = 0;

protected:
	Handler* nextHandler;
};

class ConcreteHandlerA : public Handler
{
public:
	ConcreteHandlerA()
	{
		
	}
	~ConcreteHandlerA() override {}
	void HandleRequest(int level) override
	{
		if (level == 1)
		{
			cout << "A에서 처리" << endl;
		}
		else if (nextHandler)
		{
			nextHandler->HandleRequest(level);
		}
		else
			cout << "처리할 수 없음" << endl;
	}
	void SetNext(Handler* next) override
	{
		nextHandler = next;
	}
};

class ConcreteHandlerB : public Handler
{
public:
	ConcreteHandlerB()
	{
		
	}
	~ConcreteHandlerB() override {}
	void HandleRequest(int level) override
	{
		if (level == 2)
		{
			cout << "B에서 처리" << endl;
		}
		else if (nextHandler)
		{
			nextHandler->HandleRequest(level);
		}
		else
			cout << "처리할 수 없음" << endl;
	}
	void SetNext(Handler* next) override
	{
		nextHandler = next;
	}
};

class ConcreteHandlerC : public Handler
{
public:
	ConcreteHandlerC()
	{

	}
	~ConcreteHandlerC() override {}
	void HandleRequest(int level) override
	{
		if (level == 3)
		{
			cout << "C에서 처리" << endl;
		}
		else if (nextHandler)
		{
			nextHandler->HandleRequest(level);
		}
		else
			cout << "처리할 수 없음" << endl;
	}
	void SetNext(Handler* next) override
	{
		nextHandler = next;
	}
};


int main()
{
	ConcreteHandlerA handlerA; ConcreteHandlerB handlerB; ConcreteHandlerC handlerC;
	handlerA.SetNext(&handlerB);
	handlerB.SetNext(&handlerC);
	handlerA.HandleRequest(1);
	handlerA.HandleRequest(3);
}