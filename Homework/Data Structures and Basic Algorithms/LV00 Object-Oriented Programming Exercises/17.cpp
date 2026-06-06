#include <iostream>
using namespace std;

class Engine
{
public:
	Engine():horsepower(), fuel{},type{} {}
	~Engine(){}

	void SetHorsepower(const int amount)
	{
		horsepower = amount;
	}
	void SetFuel(const char* fuel)
	{
		strcpy_s(this->fuel, sizeof(this->fuel), fuel);
	}
	void SetType(const char* type)
	{
		strcpy_s(this->type, sizeof(this->type), type);
	}

	void Print()
	{
		cout << "Engine: " << horsepower << "HP | Fuel: " << fuel << " | Type: " << type << endl;
	}
private:
	int horsepower;
	char fuel[256];
	char type[256];

};

class Car
{
public:
	Car(): brand{}, modelYear(), engine{}, length(){}
	~Car(){}

	void SetBrand(const char* brand)
	{
		strcpy_s(this->brand, sizeof(this->brand), brand);
	}
	void SetModelYear(const int modelYear)
	{
		this->modelYear = modelYear;
	}
	void AddEngine(const Engine* engine)
	{
		this->engine[length] = *engine;
		length++;
	}
	void Print()
	{
		cout << "Car: " << brand << "(" << modelYear << ")" << endl;
		for (int i = 0; i < length; ++i)
		{
			engine[i].Print();
		}
	}
private:
	char brand[256];
	int modelYear;
	Engine engine[100];
	int length;
};

int main()
{
	Engine engine;
	engine.SetHorsepower(450);
	engine.SetFuel("Gasoline");
	engine.SetType("V8");

	Car car;
	car.SetBrand("Ford Mustang");
	car.SetModelYear(2022);
	car.AddEngine(&engine);
	car.Print();
}
