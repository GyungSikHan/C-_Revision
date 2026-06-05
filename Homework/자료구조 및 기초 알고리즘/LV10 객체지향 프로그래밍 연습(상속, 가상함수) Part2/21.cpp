#include <iostream>
using namespace std;

class Subject
{
public:
	Subject(){}
	virtual ~Subject(){}
	virtual void Request() = 0;
};

class RealSubject: public Subject
{
public:
	RealSubject(){}
	void Request() override
	{
		cout << "Real Subject " << endl;
	}
	~RealSubject() override
	{
		
	}
};

class Proxy : public Subject
{
public:
	Proxy():realSubject() {}
	Proxy(RealSubject* ptr):realSubject(ptr){}
	void Request() override
	{
		cout << "Proxy Request, ";
		if (!realSubject)
		{
			cout << "real subject is null" << enl;
			return;
		}
		realSubject->Request();
	}
	~Proxy() override{}
private:
	RealSubject* realSubject;
};

int main()
{
	RealSubject real;
	Proxy proxy(&real);
	Subject* subjects[] = { &real, &proxy };
	for (int i = 0; i < 2; ++i)
		subjects[i]->Request();
}