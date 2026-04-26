#include <iostream>
using namespace std;

class Student
{
public:
	char name[20];
	int id;
	int year;
	char department[20];
	
public:
	void StudentInfo()
	{
		cout << "\t- " << name << " (" << department << ", " << year << "nd year)" << endl;
	}
};

class Course
{
public:
	char courseName[127];
	char professorName[127];
	int capacity = 0;
	int size = 0;
	Student students[50];

public:
	void AddStudents(Student student)
	{
		if (capacity <= size)
		{
			cout << "정원 초과" << endl;
			return;
		}

		students[size] = student;
		size++;
	}
	void CourseInfo()
	{
		cout << "Course: " << courseName << " | Instructor: " << professorName << " | Capacity: " << capacity << endl;
		cout << "Students: " << endl;
		for (int i = 0; i < size; ++i)
		{
			students[i].StudentInfo();
		}
	}
};

int main()
{
	Course course;
	cin >> course.courseName;// = "Programming 101";
	cin >> course.professorName;// = "Dr. Kim";
	cin >> course.capacity;// = 30;

	Student alice;
	cin>>alice.name;// = "Alice";
	cin>>alice.year;// = 2;
	cin >> alice.department;// = "CS";

	Student Bob;
	cin>>Bob.name; //= "Bob";
	cin >> Bob.year; //= 2;
	cin >> Bob.department;// = "CS";

	Student Charlie;
	cin >> Charlie.name;// = "Charlie";
	cin>>Charlie.year;// = 2;
	cin >> Charlie.department;// = "CS";

	course.AddStudents(alice);
	course.AddStudents(Bob);
	course.AddStudents(Charlie);

	course.CourseInfo();
}