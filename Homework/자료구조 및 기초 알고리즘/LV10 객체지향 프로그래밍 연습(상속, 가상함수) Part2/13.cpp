#include <iostream>
using namespace std;

class Command
{
public:
	Command(const char* command)
	{
		strcpy_s(this->command, sizeof(this->command), command);
	}
	~Command(){}
	virtual void Execute() = 0;
	virtual void Undo() = 0;
protected:
	char command[256];
};

class MoveCommand : public Command
{
public:
	MoveCommand(const char* command):Command(command){}
	~MoveCommand(){}
	void Execute() override
	{
		cout << command << " 이동 실행" << endl;
	}
	void Undo() override
	{
		cout << command << " 이동 취소" << endl;
	}
};

class AttackCommand : public Command
{
public:
	AttackCommand(const char* command) :Command(command) {}
	~AttackCommand() {}
	void Execute() override
	{
		cout << command << " 공격" << endl;
	}
	void Undo() override
	{
		cout << command << " 공격 취소" << endl;
	}
};

int main()
{
	MoveCommand move("North"); AttackCommand attack("Enemy");
	Command* commands[] = { &move, &attack };
	for (int i = 0; i < 2; ++i) {
		commands[i]->Execute();
		commands[i]->Undo();
	}
}