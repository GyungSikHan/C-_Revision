#include <iostream>
using namespace std;

class State
{
public:
	State(){}
	virtual ~State(){}
	virtual void Handle() = 0;
};

class IdleState : public State
{
public:
	IdleState(){}
	~IdleState()override{}
	void Handle() override
	{
		cout << "Idle State" << endl;
	}
};

class RunningState : public State
{
public:
	RunningState() {}
	~RunningState()override {}
	void Handle() override
	{
		cout << "Running State" << endl;
	}
};

class StoppedState : public State
{
public:
	StoppedState() {}
	~StoppedState()override {}
	void Handle() override
	{
		cout << "Stopped State" << endl;
	}
};

int main()
{
	IdleState idle; RunningState running; StoppedState stopped;
	State* states[] = { &idle, &running, &stopped };
	for (int i = 0; i < 3; ++i)
		states[i]->Handle();
}