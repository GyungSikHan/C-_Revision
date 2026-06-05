#include <iostream>
using namespace std;

class Memento
{
	friend class Originator;

public:
	Memento(const char* state)
	{
		strcpy_s(this->state, sizeof(this->state), state);
	}
private:
	const char* GetState()const
	{
		return state;
	}
private:
	char state[256];
};

class Originator
{
public:
	void SetState(const char* state)
	{
		strcpy_s(this->state, sizeof(this->state), state);
	}
	Memento* CreateMemento()
	{
		return new Memento(state);
	}
	void RestoreMemento(Memento* memento)
	{
		strcpy_s(state,sizeof(state),  memento->GetState());
	}
	void ShowState()
	{
		cout << state << endl;
	}
private:
	char state[256];
};

class Caretaker
{
public:
	void Save(Memento* m)
	{
		memento = m;
	}
	Memento* GetMemento()
	{
		return memento;
	}
private:
	Memento* memento;
};

int main()
{
	Originator originator;
	Caretaker caretaker;
	originator.SetState("State1");
	caretaker.Save(originator.CreateMemento());
	originator.SetState("State2");
	originator.ShowState();
	originator.RestoreMemento(caretaker.GetMemento());
	originator.ShowState();
}