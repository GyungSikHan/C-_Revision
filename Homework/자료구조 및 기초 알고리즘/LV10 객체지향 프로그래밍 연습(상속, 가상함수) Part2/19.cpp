#include <iostream>
using namespace std;

class Observer
{
public:
	Observer(){}
	virtual ~Observer(){}
	virtual void OnNotify(const char* event) = 0;
};

class Subject
{
protected:
	enum EState
	{
		idle = 0,
		gameOver
	};
public:
	Subject() : observers{}, count(), state(EState::idle){}
	virtual ~Subject(){}
	virtual void Notify(const char* event)
	{
		for (int i = 0; i < count; ++i)
		{
			observers[i]->OnNotify(event);
		}
	}
	void ChangeState(const char* stateStr)
	{
		if (strcmp(stateStr, "GameOver"))
			state = EState::gameOver;
		else
			state = EState::idle;
	}
	void RegisterObserver(Observer* obserer)
	{
		observers[count++] = obserer;
	}
private:
	EState state;
	Observer* observers[10];
	int count;
};

class ConcreteSubject : public Subject
{
public:
	ConcreteSubject(){}
	~ConcreteSubject() override {}
};

class Player : public Observer
{
public:
	Player(){}
	~Player()override{}
	void OnNotify(const char* event) override
	{
		cout << "Plyaer " << event << endl;
	}
};

class UI : public Observer
{
public:
	UI() {}
	~UI()override {}
	void OnNotify(const char* event) override
	{
		cout << event << " UI" << endl;
	}
};

class SoundManager : public Observer
{
public:
	SoundManager() {}
	~SoundManager()override {}
	void OnNotify(const char* event) override
	{
		cout << event << " Sound" << endl;
	}
};

int main()
{
	ConcreteSubject subject;
	Player player; UI ui; SoundManager sound;
	subject.RegisterObserver(&player);
	subject.RegisterObserver(&ui);
	subject.RegisterObserver(&sound);
	subject.ChangeState("GameOver");
	subject.Notify("GameOver");  // 모든 Observer에게 통지
}