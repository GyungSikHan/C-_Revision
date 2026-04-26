#include <iostream>
using namespace std;

struct Student
{
public:
	char name[20];
	int id;
	int math;
	int english;
	int science;
	float Average;

public:
	void AverageScore()
	{
		Average = (math + english + science) / 3.0f;
	}
	void PrintInfo()
	{
		cout << "Name: " << name << " (ID: " << id << ")" << endl;
		cout << "Math: " << math << ", English: " << english << ", Science: " << science << endl;
		cout << "Average Score: " << Average << endl;
	}
};

int main()
{
	Student John;
	cin >> John.name >> John.id >> John.math >> John.english >> John.science;
	John.AverageScore();
	John.PrintInfo();

	Student Minho;
	cin >> Minho.name >> Minho.id >> Minho.math >> Minho.english >> Minho.science;
	Minho.AverageScore();
	Minho.PrintInfo();

	Student Gahong;
	cin >> Gahong.name >> Gahong.id >> Gahong.math >> Gahong.english >> Gahong.science;
	Gahong.AverageScore();
	Gahong.PrintInfo();
}