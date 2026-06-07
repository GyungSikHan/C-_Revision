#include <iostream>
using namespace std;

class Student
{
public:
	Student():name{},score(){}
	Student(const char* name, const int score)
		:score(score)
	{
		strcpy_s(this->name, sizeof(this->name), name);
	}
	virtual ~Student(){}
	virtual char GetGrade() const = 0;

protected:
	char name[256];
	int score;
};

class UndergraduateStudent : public Student
{
public:
	UndergraduateStudent(){}
	UndergraduateStudent(const char* name, const int score)
		:Student(name, score)
	{}
	char GetGrade() const override
	{
		if (score < 90)
			return 'B';
		return 'A';
	}
};

class GraduateStudent : public Student
{
public:
	GraduateStudent() {}
	GraduateStudent(const char* name, const int score)
		:Student(name, score)
	{}
	char GetGrade() const override
	{
		if (score < 95)
			return 'B';
		return 'A';
	}
};

int main()
{
	UndergraduateStudent us("Kim", 92);
	GraduateStudent gs("Lee", 92);
	Student* students[] = { &us, &gs };
	for (int i = 0; i < 2; ++i)
		std::cout << students[i]->GetGrade() << std::endl;

}