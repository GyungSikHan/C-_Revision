#include <iostream>
using namespace std;

class Employee
{
public:
	Employee()
		:name{},department{}, baseSalary(),years(),bonusRate()
	{
		
	}
	Employee (const char* name, const char* department, const int baseSalary, const int years, const int bonusRate)
		:baseSalary(baseSalary), years(years), bonusRate(bonusRate)
	{
		strcpy_s(this->name, sizeof(this->name), name);
		strcpy_s(this->department, sizeof(this->department), department);
	}
	~Employee(){}
	void CalculationTotalSalary()
	{
		totalSalary = baseSalary * bonusRate + baseSalary;
	}

	void Print()
	{
		cout << "Employee: " << name << " | Department: " << department << " | Years: " << years << endl;
		cout << "Base: " << baseSalary << ", Bonus: " << bonusRate << "%" << endl;
		cout << "Total Salary: " << totalSalary << endl;
	}

private:
	char name[256];
	char department[256];
	int baseSalary;
	int years;
	int bonusRate;
	int totalSalary;
};

int main()
{
	Employee employee = Employee("Jane", "HR", 3000, 5, 15);
	employee.CalculationTotalSalary();
	employee.Print();
}