#include<iostream>
using namespace std;

class Person
{
public:
    Person()
    :name{}, tel()
    {}

    char* GetName()
    {
        return name;
    }
    char* GetTel()
    {
        return tel;
    }

    void Set(char* name, char* tel)
    {
        strcpy_s(this->name, sizeof(this->name), name );        
        strcpy_s(this->tel, sizeof(this->tel), tel );        
    }

private:
    char name[256];
    char tel[256];
};

int main()
{
    Person person[3]{};

    for (size_t i = 0; i < 3; i++)
    {
        char name[256]{};
        char tel[256]{};

        cin>>name>>tel;

        person[i].Set(name, tel);
    }

    for (size_t i = 0; i < 3; i++)
    {
        cout<<person[i].GetName()<<" "<<person[i].GetTel()<<endl;
    }
    
    
}