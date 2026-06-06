#include <iostream>
using namespace std;

class Book
{
public:
	Book():title{} , author{}{}
	virtual void Display()
	{
		cout << "제목: " <<title << ", 작가: " << author;
	}

protected:
	char title[256];
	char author[256];
};

class EBook : public Book
{
public:
	EBook(const char* title, const char* author, double fileSize)
		:fileSize(fileSize)
	{
		strcpy_s(this->title, sizeof(this->title), title);
		strcpy_s(this->author, sizeof(this->author), author);
	}
	void Display() override
	{
		Book::Display();
		cout << ", File Size: " << fileSize << endl;
	}
private:
	double fileSize;
};

class PaperBook : public Book
{
public:
	PaperBook(const char* title, const char* author, int page)
		:page(page)
	{
		strcpy_s(this->title, sizeof(this->title), title);
		strcpy_s(this->author, sizeof(this->author), author);
	}
	void Display() override
	{
		Book::Display();
		cout << ", Page: " << page << endl;
	}
private:
	int page;
};
int main()
{
	EBook eb("Clean Code", "Robert Martin", 5.2);
	PaperBook pb("Refactoring", "Martin Fowler", 450);
	Book* books[] = { &eb, &pb };
	for (int i = 0; i < 2; ++i)
		books[i]->Display();

}