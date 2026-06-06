#include <iostream>
using namespace std;

class Movie
{
public:
	Movie()
		:name{}, duration(),genre{},ageRating(),director{}
	{
		
	}
	Movie(const char* name, int duration, const char* genre, int ageRating, const char* director)
		:duration(duration), ageRating(ageRating)
	{
		strcpy_s(this->name, sizeof(this->name), name);
		strcpy_s(this->genre, sizeof(this->genre), genre);
		strcpy_s(this->director, sizeof(this->director), director);
	}
	~Movie()
	{
		
	}

	void Print()
	{
		cout << "[Movie]\n";
		cout << "Title: " << name << endl;
		cout << "Duration: " << duration << "min\n";
		cout << "Genre: " << genre << endl;
		cout << "Ratged: " << ageRating <<"+" << endl;
		cout << "Directed by: " << director << endl;
	}

private:
	char name[256];
	int duration;
	char genre[256];
	int ageRating;
	char director[256];
};

int main()
{
	Movie movie = Movie("Interstellar", 169, "Sci-Fi", 12, "Nolan");
	movie.Print();
}