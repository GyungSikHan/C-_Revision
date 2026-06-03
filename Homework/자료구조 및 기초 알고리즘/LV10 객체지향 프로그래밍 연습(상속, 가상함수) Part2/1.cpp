#include <iostream>
using namespace std;

class Animal
{
public:
    Animal() {}
    ~Animal() {}
    virtual void Eat() = 0;
    virtual void Speak() {}
};

class Mammal : public Animal
{
public:
    Mammal() {}
    ~Mammal() {}
    virtual void Sleep() = 0;
};

class Dog : public Mammal
{
public:
    Dog() {}
    ~Dog() {}
    void Eat() override
    {
        cout << "개밥" << endl;
    }
    void Sleep() override
    {
        cout << "쿨쿨" << endl;
    }
    void Speak() override
    {
        cout << "멍멍" << endl;
    }
};

class Cat : public Mammal
{
public:
    Cat() {}
    ~Cat() {}
    void Eat() override
    {
        cout << "고양이 밥" << endl;
    }
    void Sleep() override
    {
        cout << "새근새근" << endl;
    }
    void Speak() override
    {
        cout << "야옹" << endl;
    }
};

class Fish : public Animal
{
public:
    Fish() {}
    ~Fish() {}
    void Eat() override
    {
        cout << "물고기 밥" << endl;
    }
};

int main()
{
    Dog d;
    Cat c;
    Fish f;
    Animal* animals[]{ &d, &c, &f };
    for (int i = 0; i < 3; i++)
    {
        animals[i]->Eat();
        if (Mammal* m = dynamic_cast<Mammal*>(animals[i]))
            m->Sleep();
    }
}