#include <iostream>
using namespace std;

class Logger
{
public:
	Logger(){}
	virtual ~Logger(){}
	virtual void Log(const char* message) = 0;
};

class ConsoleLogger : public Logger
{
public:
	ConsoleLogger() {}
	~ConsoleLogger() override{}
	void Log(const char* message) override
	{
		cout << "ConsoleLogger: "<<message << endl;
	}
};

class FileLogger : public Logger
{
public:
	FileLogger() {}
	~FileLogger() override {}
	void Log(const char* message) override
	{
		cout << "FileLogger: " << message << endl;
	}
};

class NetworkLogger : public Logger
{
public:
	NetworkLogger() {}
	~NetworkLogger() override {}
	void Log(const char* message) override
	{
		cout << "NetworkLogger: " << message << endl;
	}
};

int main()
{
	ConsoleLogger console; FileLogger file; NetworkLogger network;
	Logger* loggers[] = { &console, &file, &network };
	for (int i = 0; i < 3; ++i)
		loggers[i]->Log("System started");
}