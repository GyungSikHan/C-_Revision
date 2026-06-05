#include<iostream>
using namespace std;

class Observer
{
public:
	Observer(){}
	virtual ~Observer(){}
	virtual void OnNotify() = 0;
private:
};

class ConcreteObserverA : public Observer
{
public:
	ConcreteObserverA(){}
	~ConcreteObserverA()override{}
	virtual void OnNotify() override
	{
		cout << "Concreate Observer A" << endl;
	}
};
class ConcreteObserverB : public Observer
{
public:
	ConcreteObserverB() {}
	~ConcreteObserverB()override {}
	virtual void OnNotify() override
	{
		cout << "Concreate Observer B" << endl;
	}
};

class Subject
{
public:
	Subject():observers{}, count(){}
	virtual ~Subject(){}
	void RegisterObserver(Observer* observer)
	{
		observers[count++] = observer;
	}
	virtual void Notify()
	{
		for (int i = 0; i < count; ++i)
		{
			observers[i]->OnNotify();
		}
	}

private:
	Observer* observers[10];
	int count;
};

int main()
{
	Subject subject;
	ConcreteObserverA obsA; ConcreteObserverB obsB;
	subject.RegisterObserver(&obsA);
	subject.RegisterObserver(&obsB);
	subject.Notify();  // 모든 Observer에게 통지
}