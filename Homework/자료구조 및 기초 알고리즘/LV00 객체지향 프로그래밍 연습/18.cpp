#include <iostream>
using namespace std;

class Movie
{
public:
	Movie(): movieName{}, runningTime(), genre{}, grade{}{}
	~Movie(){}

	void SetMoveName(const char* name)
	{
		strcpy_s(movieName, sizeof(movieName), name);
	}
	const char* GetMoveName()const { return movieName; }
	void SetRunningTime(const int time)
	{
		runningTime = time;
	}
	const int GetRunningTime() const { return runningTime; }
	void SetGenre(const char* genre)
	{
		strcpy_s(this->genre, sizeof(this->genre), genre);
	}
	const char* GetGenre()const { return genre; }

	void SetGrade(const char* grade)
	{
		strcpy_s(this->grade, sizeof(this->grade), grade);
	}
	const char* GetGrade() const { return grade; }
private:
	char movieName[256];
	int runningTime;
	char genre[256];
	char grade[256];
};

class Theater
{
public:
	Theater(): name{},location{}, movie{}, length(){}
	~Theater(){}

	void SetName(const char* name)
	{
		strcpy_s(this->name, sizeof(this->name), name);
	}
	void SetLocation(const char* location)
	{
		strcpy_s(this->location, sizeof(this->location), location);
	}
	void AddMovie(Movie* movie)
	{
		this->movie[length] = *movie;
		length++;
	}

	void Print()
	{
		cout << "Theater: " << name << " | Location: " << location << endl;
		cout << "Now Showing: " << endl;
		
		int total{};
		for (int i = 0; i < length; ++i)
		{
			cout << "- \"" << movie[i].GetMoveName() << "\" (" << movie[i].GetRunningTime() << " min, " << movie[i].GetGenre() << ", " << movie[i].GetGrade() << endl;
			total += movie[i].GetRunningTime();
		}

		cout << "Total: " << total << " minutes" << endl;
	}
	
private:
	char name[256];
	char location[256];
	Movie movie[100];
	int length;
};

int main()
{
	Movie movie;
	movie.SetMoveName("Avatar");
	movie.SetRunningTime(162);
	movie.SetGenre("FPS");
	movie.SetGrade("12+");
	Movie movie2;
	movie2.SetMoveName("Titanic");
	movie2.SetRunningTime(195);
	movie2.SetGenre("Romance");
	movie2.SetGrade("All");

	Theater theater;
	theater.SetName("CGV Gangnam");
	theater.SetLocation("Seoul");
	theater.AddMovie(&movie);
	theater.AddMovie(&movie2);
	theater.Print();
}