#include <iostream>
using namespace std;

class Student
{
public:
	Student():name{},major{}, id(), years(){}
	~Student(){}

	void SetName(const char* name)
	{
		strcpy_s(this->name, sizeof(this->name), name);
	}
	const char* GetName()const { return name; }
	void SetID(const int id)
	{
		this->id = id;
	}
	const int GetID()const { return id; }
	void SetYears(const int years)
	{
		this->years = years;
	}
	const int GetYears() { return years; }
	void SetMajor(const char* major)
	{
		strcpy_s(this->major, sizeof(this->major), major);
	}
	const char* GetMajor()const { return major; }

private:
	char name[256];
	char major[256];
	int id;
	int years;
};

class Course
{
public:
	Course(): CourseName{},limiteCapacity(), ProfessorName{}, students{}, size(){}
	~Course(){}

	void SetCourseName(const char* name)
	{
		strcpy_s(CourseName, sizeof(CourseName), name);
	}
	void LimiteCapacity(const int capacity)
	{
		limiteCapacity = capacity;
	}
	void SetProfessorName(const char* name)
	{
		strcpy_s(ProfessorName, sizeof(ProfessorName), name);
	}
	void AddStudent(Student* student)
	{
		if (size == limiteCapacity)
			return;

		students[size] = *student;
		size++;
	}

	void Print()
	{
		cout << "Course: " << CourseName << " | Instructor: " << ProfessorName << " | Capacity: " << limiteCapacity << endl;
		cout << "Students: " << endl;

		for (int i = 0; i < size; ++i)
		{
			cout << "- " << students[i].GetName() << " (" << students[i].GetMajor() << ", " << students[i].GetID() << ", " << students[i].GetYears() << "nd year)" << endl;
		}
	}
private:
	char CourseName[256];
	char ProfessorName[256];
	int limiteCapacity;
	Student students[100];
	int size;

};
int main()
{
	Student student;
	student.SetName("Alice");
	student.SetID(20251111);
	student.SetMajor("CS");
	student.SetYears(2);

	Student student2;
	student2.SetName("Bob");
	student2.SetID(20262222);
	student2.SetMajor("EE");
	student2.SetYears(1);

	Student student3;
	student3.SetName("Charlie");
	student3.SetID(20233333);
	student3.SetMajor("CS");
	student3.SetYears(3);

	Course course;
	course.SetCourseName("Programming 101");
	course.SetProfessorName("Dr. Kim");
	course.LimiteCapacity(30);
	course.AddStudent(&student);
	course.AddStudent(&student2);
	course.AddStudent(&student3);

	course.Print();
}