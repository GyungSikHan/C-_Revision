#include<iostream>
#include<string.h>
using namespace std;

class Person
{
public:
    Person()
    :name{},address{},number{}, id(),mi()
    {}
    ~Person(){}
    void SetName(const char* name)
    {
        strcpy(this->name, name);
    }
    void SetAddress(const char* address)
    {
        strcpy(this->address, address);
    }
    void SetNumber(const char* number)
    {
        strcpy(this->number, number);
    }
    void SetID(const int id)
    {
        this->id = id;
    } 
    void SetMi(const int mi)
    {
        this->mi = mi;
    }

    const char* GetName() const
    {
        return name;
    }
    const char* GetAddreess()const
    {
        return address;
    }
    const char* GetNumber()const
    {
        return number;
    }
    int GetID()const
    {
        return id;
    }
    int GetMi()const
    {
        return mi;
    }

private:
    char name[256];
    char address[256];
    char number[256];
    int id;
    int mi;
};

int main()
{
    Person person{};

    char name[256]{};
    cout<<"이름을 입력하세요: ";
    cin>>name;
    person.SetName(name);
    char address[256]{};
    cout<<"주소를 입력하세요: ";
    cin>>address;
    person.SetAddress(address);
    char number[256]{};
    cout<<"연락처를 입력하세요 : ";
    cin>>number;
    person.SetNumber(number);
    int id{};
    cout<<"ID를 입력하세요 : ";
    cin>>id;
    person.SetID(id);
    int mi{};
    cout<<"마일리지 입력하세요 : ";
    cin>>mi;
    person.SetMi(1500);

    cout<<"-----고객 정보-----"<<endl;
    cout<<"이름: "<<person.GetName()<<endl;
    cout<<"주소: "<<person.GetAddreess()<<endl;
    cout<<"연락처: " <<person.GetNumber()<<endl;
    cout<<"고객ID: "<<person.GetID()<<endl;
    cout<<"마일리지: "<<person.GetMi()<<endl;    
}