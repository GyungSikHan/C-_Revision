#include <iostream>
using namespace std;

class Book
{
public:
	Book() {}
	~Book() {}

	size_t StringSize(const char* str)
	{
		size_t len = strlen(str);
		return len;
	}

	void StringCopy(char* str, const char* str2)
	{
		size_t len = StringSize(str2);

		for (int i = 0; i < len; ++i)
		{
			str[i] = str2[i];
		}
		str[len] = '\0';
	}
	void SetTitle(const char* title)
	{
		StringCopy(this->title, title);
	}
	
	void SetAuthor(const char* author)
	{
		StringCopy(this->author, author);
	}

	void SetPublisher(const char* publisher)
	{
		StringCopy(this->publisher, publisher);
	}

	void SetPrice(float price)
	{
		this->price = price;
	}

	void Print()
	{
		cout << "[Book]" << endl;
		cout << "Title: \"" << title << "\"" << endl;
		cout << "Author: \"" << author << "\"" << endl;
		cout << "Publisher: \"" << publisher << "\"" << endl;
		cout << "Price: $" << price<<endl;
	}
	
private:
	char title[256];
	char author[256];
	char publisher[256];
	float price;
};
int main()
{
	Book book{};
	book.SetTitle("1984");
	book.SetAuthor("George Orwell");
	book.SetPublisher("Penguin");
	book.SetPrice(15.99f);
	book.Print();
}