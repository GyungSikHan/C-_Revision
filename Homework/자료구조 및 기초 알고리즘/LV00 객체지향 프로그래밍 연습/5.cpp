#include <iostream>
#include <string>
using namespace std;

class Student
{
public:
    Student(){}
    ~Student(){}

    void SetName(const char* name)
    {
        strcpy(this->name, name);
    }
    void SetID(int id)
    {
        this->id = id;
    }
    void SetMathScore(const int score)
    {
        mathScore = score;
    }
    void SetEnglishScore(const int score)
    {
        englishScore = score;
    }
    void SetScienceScore(const int score)
    {
        scienceScore = score;
    }

    void CirculAver()
    {
        averageScore = (float)(mathScore+englishScore+scienceScore) / 3.0f;
    }

    void Print()
    {
        cout<<"Name: "<<name<<" (ID: "<<id<<")"<<endl;
        cout<<"Math: "<<mathScore<<", English: "<<englishScore<<", Science: "<<scienceScore<<endl;
        cout<<"AverageScore: "<<averageScore<<endl;
    }

private:
    char name[256];
    int id;
    int mathScore;
    int englishScore;
    int scienceScore;
    float averageScore;

};

int main() 
{
    Student john{};
    john.SetName("John");
    john.SetID(20231234);
    john.SetMathScore(85);
    john.SetEnglishScore(78);
    john.SetScienceScore(92);
    john.CirculAver();
    john.Print();
}