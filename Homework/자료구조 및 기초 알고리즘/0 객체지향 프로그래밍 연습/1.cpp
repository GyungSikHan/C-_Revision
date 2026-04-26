#include <iostream>
using namespace std;

class Person
{
public:
	Person() {}
	~Person() {}

	void SetName(const char* name)
	{
		size_t len = strlen(name);
		for (size_t i = 0; i < len; ++i)
		{
			this->name[i] = name[i];
		}
		this->name[len] = '\0';
	}

	void SetAge(const int age)
	{
		this->age = age;
	}

	void SetGender(const char* gender)
	{
		int len = strlen(gender);
		for (int i = 0; i < len; ++i)
		{
			this->gender[i] = gender[i];
		}
		this->gender[len] = '\0';
	}

	void SetFrom(const char* from)
	{
		int len = strlen(from);
		for (int i = 0; i < len; ++i)
		{
			this->from[i] = from[i];
		}
		this->from[len] = '\0';
	}

	void Introduce() const
	{
		cout << "My name is " << name << ", " << age << "years old, " << gender << ", from " << from << endl;
	}
private:
	char name[256];
	int age;
	char gender[256];
	char from[256];
};


int main()
{
	Person person{};
	person.SetName("Alice");
	person.SetAge(25);
	person.SetGender("Female");
	person.SetFrom("Canade");

	person.Introduce();
}