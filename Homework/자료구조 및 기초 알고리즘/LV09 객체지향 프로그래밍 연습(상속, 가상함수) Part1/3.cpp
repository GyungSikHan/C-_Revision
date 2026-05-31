#include <iostream>
using namespace std;

class Employee
{
public:
	Employee() : name{}, basicSalary() {}
	virtual ~Employee() {}
	virtual float CalculateSalary() { return basicSalary; }
protected:
	char name[256];
	int basicSalary;
};

class Manager : public Employee
{
public:
	Manager(const char* name, const int basicSalary)
	{
		strcpy_s(this->name, sizeof(this->name), name);
		this->basicSalary = basicSalary;
	}
	~Manager() override{}
	float CalculateSalary() override
	{
		return basicSalary+(basicSalary * 0.5 );
	}
};

class Developer : public Employee
{
public:
	Developer(const char* name, const int basicSalary)
	{
		strcpy_s(this->name, sizeof(this->name), name);
		this->basicSalary = basicSalary;
	}
	~Developer() override{}
	float CalculateSalary() override
	{
		return (float)(basicSalary+(basicSalary * 0.1));
	}
};

int main()
{
	Manager m("Kim", 5000); 
	Developer d("Lee", 3000);
	Employee* staff[] = { &m, &d };
	for (int i = 0; i < 2; ++i)
		std::cout << staff[i]->CalculateSalary() << std::endl;

}