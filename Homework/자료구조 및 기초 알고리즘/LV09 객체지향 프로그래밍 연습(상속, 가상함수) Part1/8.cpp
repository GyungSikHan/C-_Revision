#include <iostream>
using namespace std;

class Notification
{
public:
	Notification():info{}{}
	virtual void Send() { cout << info << endl; }

protected:
	char info[256];
};

class EmailNotification : public Notification
{
public:
	EmailNotification(const char* info)
	{
		strcpy_s(this->info, sizeof(this->info), info);
	}
	void Send() override
	{
		cout << info << " Send" << endl;
	}
};

class SMSNotification : public Notification
{
public:
	SMSNotification(const char* info)
	{
		strcpy_s(this->info, sizeof(this->info), info);
	}
	void Send() override
	{
		cout << info << " Send" << endl;
	}
};

int main()
{
	EmailNotification e("kim@example.com");
	SMSNotification s("010-1234-5678");
	Notification* notices[] = { &e, &s };
	for (int i = 0; i < 2; ++i)
		notices[i]->Send();

}