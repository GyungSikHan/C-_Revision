#include <iostream>
using namespace std;

class IRenderable
{
public:
	IRenderable(){}
	virtual ~IRenderable(){}
	virtual void Render() = 0;
};

class IUpdatable
{
public:
	IUpdatable(){}
	virtual ~IUpdatable(){}
	virtual void Update() = 0;
};

class GameObject : public IUpdatable, public IRenderable
{
public:
	GameObject(const char* name)
	{
		strcpy_s(this->name, sizeof(this->name), name);
	}
	~GameObject() override{}
	void Render() override { cout << name<<" Render" << endl; }
	void Update() override { cout << name<<" Update" << endl; }
protected:
	char name[256];
};

class Player : public GameObject
{
public:
	Player(const char* name)
		:GameObject(name){}
	~Player()override{}
};

class Enemy : public GameObject
{
public:
	Enemy(const char* name)
		:GameObject(name) {}
	~Enemy()override {}
};

int main()
{
	Player p("Hero"); Enemy e("Goblin");
	IRenderable* renderables[] = { &p, &e };
	IUpdatable* updatables[] = { &p, &e };
	for (int i = 0; i < 2; ++i)
	{
		updatables[i]->Update();
		renderables[i]->Render();
	}
}