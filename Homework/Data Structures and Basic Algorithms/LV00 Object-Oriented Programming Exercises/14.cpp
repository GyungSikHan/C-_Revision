#include <iostream>
using namespace std;

class Author
{
public:
	Author(): name{}, email{}, major{}{}
	~Author(){}

	void SetName(const char* name)
	{
		strcpy_s(this->name, sizeof(this->name), name);
	}
	const char* GetName()const
	{
		return name;
	}
	void SetEmail(const char* email)
	{
		strcpy_s(this->email, sizeof(this->email), email);
	}
	const char* GetEmail()const
	{
		return email;
	}
	void SetMajor(const char* major)
	{
		strcpy_s(this->major, sizeof(this->major), major);
	}
	const char* GetMajor()const
	{
		return major;
	}

private:
	char name[256];
	char email[256];
	char major[256];
};

class Article
{
public:
	Article(): title{}, day{},chars(), authors{}, authorCount() {}
	~Article(){}

	void SetTitle(const char* title)
	{
		strcpy_s(this->title, sizeof(this->title), title);
	}
	void SetDay(const char* day)
	{
		strcpy_s(this->day, sizeof(this->day), day);
	}
	void SetChars(int chars)
	{
		this->chars = chars;
	}
	void AddAuthor(Author* author)
	{
		authors[authorCount] = *author;
		authorCount++;
	}

	void PrintInfo()
	{
		cout << "Article: \"" << title << "\" (Write Day: " << day << ", " << chars << " chars)" << endl;
		for (int i = 0; i < authorCount; ++i)
		{
			cout << "Author: " << authors[i].GetName() << " | Email: " <<
				authors[i].GetEmail() << " | Field: " << authors[i].GetMajor() << endl;
		}
	}

private:
	char title[256];
	char day[256];
	int chars;
	Author authors[100];
	int authorCount;
};

int main()
{
	Author author;
	author.SetName("Alice Kim");
	author.SetEmail("alice@domin.com");
	author.SetMajor("Computer Science");

	Article article;
	article.SetTitle("Rise of AI");
	article.SetDay("26-04-28");
	article.SetChars(1240);
	article.AddAuthor(&author);

	article.PrintInfo();
}