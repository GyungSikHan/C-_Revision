#include <iostream>

using namespace std;

class Student
{
public:
	Student():name(), score(), year(), className(){}
	Student(const char* name, const int score, const int year, const char* className)
		:score(score), year(year)
	{
		strcpy_s(this->name, sizeof(this->name), name);
		strcpy_s(this->className, sizeof(this->className), className);
	}
	~Student(){}

	const char* GetName() const { return name; }
	int GetScore() { return score; }
	int GetYear() { return year; }
	const char* GetClassName() const { return className; }
private:
	char name[256];
	int score;
	int year;
	char className[256];
};

class Teacher
{
public:
	Teacher():name{}, subject{}, years(), students{}, studentCount(){}
	Teacher(const char* name, const char* subject, const int years)
		:years(years),students{}, studentCount()
	{
		strcpy_s(this->name, sizeof(this->name), name);
		strcpy_s(this->subject, sizeof(this->subject), subject);
	}
	~Teacher(){}
	void AddStudnet(Student& student)
	{
		students[studentCount] = student;
		studentCount++;
	}
	void Print()
	{
		cout << "Teacher: " << name << " (" << subject << ", " << years << " years)" << endl;
		cout << "Students:" << endl;
		for (int i = 0; i < studentCount; ++i)
		{
			cout << "- " << students[i].GetName() << "(Grade " << students[i].GetYear() << ", Class " << students[i].GetClassName() << "): " << students[i].GetScore() << endl;
		}
	}
	
private:
	char name[256];
	char subject[256];
	int years;

	Student students[100];
	int studentCount;
};

int main()
{
	Student student1 = Student("Tom", 85, 2, "A");
	Student student2 = Student("Jane", 90, 2, "A");
	Student student3 = Student("Sam", 75, 2, "A");

	Teacher teacher = Teacher("Mr. Lee", "Math", 10);
	teacher.AddStudnet(student1);
	teacher.AddStudnet(student2);
	teacher.AddStudnet(student3);
	teacher.Print();
}