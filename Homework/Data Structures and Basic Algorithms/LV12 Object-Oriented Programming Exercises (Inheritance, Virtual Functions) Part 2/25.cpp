#include <iostream>
using namespace std;

class IControllable
{
public:
	IControllable(){}
	virtual ~IControllable(){}
	virtual void OnInput() = 0;
};

class ICollectable
{
public:
	ICollectable() {}
	virtual ~ICollectable() {}
	virtual void OnCollect() = 0;
};

class GameObject
{
public:
	GameObject():name{}{}
	GameObject(const char* name)
	{
		strcpy_s(this->name, sizeof(this->name), name);
	}
	virtual ~GameObject(){}
	virtual void Update()
	{
		cout << "Game Object Update" << endl;
	}
	virtual void Render()
	{
		cout << "Game Object Render" << endl;
	}
protected:
	char name[256];
};

class Character : public GameObject, public IControllable
{
public:
	Character(){}
	Character(const char* name):GameObject(name){}
	~Character()override{}
	void Update() override
	{
		cout << "Character " << name << "  Update" << endl;
	}
	void Render() override
	{
		cout << "Character  " << name << " Render" << endl;
	}
	void OnInput() override
	{
		cout << name<< " Input" << endl;
	}
};

class Item : public GameObject, public ICollectable
{
public:
	Item() {}
	Item(const char* name) :GameObject(name) {}
	~Item()override {}
	void Update() override
	{
		cout << "Item " << name << " Update" << endl;
	}
	void Render() override
	{
		cout << "Item "<<name<< " Render" << endl;
	}
	void OnCollect() override
	{
		cout << name<<" Collect" << endl;
	}
};

class Effect : public GameObject
{
public:
	Effect() {}
	Effect(const char* name) :GameObject(name) {}
	~Effect()override {}
	void Update() override
	{
		cout << "Effect " << name << " Update" << endl;
	}
	void Render() override
	{
		cout << "Effect " << name << " Render" << endl;
	}
};

class GameManager
{
public:
	GameManager():objects{}, count(){}
	void Add(GameObject* object)
	{
		objects[count++] = object;
	}
	~GameManager(){}
	void Update()
	{
		for (int i = 0; i < count; ++i)
		{
			objects[i]->Update();
		}
	}
	void Render()
	{
		for (int i = 0; i < count; ++i)
		{
			objects[i]->Render();
		}
	}
	void ProcessInput()
	{
		for (int i = 0; i < count; ++i)
		{
			if (IControllable* ctr = dynamic_cast<IControllable*>(objects[i]))
				ctr->OnInput();
		}
	}
	void ProcessCollect()
	{
		for (int i = 0; i < count; ++i)
		{
			if (ICollectable* collect = dynamic_cast<ICollectable*>(objects[i]))
				collect->OnCollect();
		}
	}
private:
	GameObject* objects[10];
	int count;
};

int main()
{
	Character player("Hero"); Item sword("Sword"); Effect explosion("Boom");
	
	GameManager manager;
	manager.Add(&player);
	manager.Add(&sword);
	manager.Add(&explosion);

	manager.Update();
	manager.Render();

	manager.ProcessInput();
	manager.ProcessCollect();
}