#include <iostream>
using namespace std;

class Book
{
public:
	Book() :name{},author{},genre{}, pages() {}
	~Book(){}

	void SetBookInfo(const char* name, const char* author, const char* genre, const int pages)
	{
		strcpy_s(this->name, sizeof(this->name), name);
		strcpy_s(this->author, sizeof(this->author), author);
		strcpy_s(this->genre, sizeof(this->genre), genre);
		this->pages = pages;
	}
	const char* GetName() const
	{
		return name;
	}
	const char* GetAuthor() const
	{
		return author;
	}
	const char* GetGenre() const
	{
		return genre;
	}
	const int GetPages() const
	{
		return pages;
	}
private:
	char name[256];
	char author[256];
	char genre[256];
	int pages;
};

class Library
{
public:
	Library():books{}, bookCount(), libraryName{}, librarianName{} {}
	~Library(){}

	void AddBook(const Book* book)
	{
		books[bookCount] = *book;
		bookCount++;
	}
	void LibraryName(const char* libraryName)
	{
		strcpy_s(this->libraryName, sizeof(this->libraryName), libraryName);
	}
	void LibrarianName(const char* librarianName)
	{
		strcpy_s(this->librarianName, sizeof(this->librarianName), librarianName);
	}
	void LibraryInfo()
	{
		cout << "Library: " << libraryName << " | Mager: " << librarianName << endl;
		cout << "Books:" << endl;
		for (int i = 0; i < bookCount; ++i)
		{
			cout << "- \"" << books[i].GetName() << "\" by " << books[i].GetAuthor() << " (" << books[i].GetGenre() << ", " << books[i].GetPages() << "p)" << endl;
		}
 	}

private:
	Book books[100];
	int bookCount;
	char libraryName[256];
	char librarianName[256];
};

int main()
{
	Book book1;
	book1.SetBookInfo("1984", "Orwell", "Dystopia", 320);
	Book book2;
	book2.SetBookInfo("Dune", "Herbert", "Sci-Fi", 500);

	Library library;
	library.LibrarianName("Central Library");
	library.LibrarianName("Ms. Kim");
	library.AddBook(&book1);
	library.AddBook(&book2);
	library.LibraryInfo();
}