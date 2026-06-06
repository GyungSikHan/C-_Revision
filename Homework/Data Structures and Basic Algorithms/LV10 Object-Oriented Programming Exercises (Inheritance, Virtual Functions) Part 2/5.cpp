#include <iostream>
#include <algorithm>
using namespace std;

class Filter
{
public:
	Filter():buffer{}{}
	virtual char* Apply(const char* str) = 0;

protected:
	char buffer[256];
};

class UpperCaseFilter : public Filter
{
public:
	char* Apply(const char* str) override
	{
		for (int i = 0; i < strlen(str); ++i)
		{
			buffer[i] = std::toupper(str[i]);
		}

		return buffer;
	}
};

class LowerCaseFilter : public Filter
{
public:
	char* Apply(const char* str) override
	{
		for (int i = 0; i < strlen(str); ++i)
		{
			buffer[i] = std::tolower(str[i]);
		}

		return buffer;
	}
};

class ReverseFilter : public Filter
{
public:
	char* Apply(const char* str) override
	{
		int idx{};
		for (int i = strlen(str) - 1; i >= 0; --i)
		{
			buffer[idx++] = str[i];
		}

		return buffer;
	}
};


int main()
{
	UpperCaseFilter upper; LowerCaseFilter lower; ReverseFilter reverse;
	Filter* filters[] = { &upper, &lower ,&reverse};
	for (int i = 0; i < 3; ++i)
		std::cout << filters[i]->Apply("Hello") << std::endl;
}