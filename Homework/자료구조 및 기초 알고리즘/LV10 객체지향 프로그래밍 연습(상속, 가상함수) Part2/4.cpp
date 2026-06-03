#include <iostream>
using namespace std;

class Authenticator
{
public:
	virtual void Authenticate(const char* userName, const char* password) = 0;
};

class PasswordAuth : public Authenticator
{
public:
	PasswordAuth():user{"user123"}, password{"pass456"}{}
	void Authenticate(const char* userName, const char* password) override
	{
		cout << "Password Auth" << endl;
		if (strcmp(this->user, userName) != 0 || strcmp(this->password, password))
		{
			cout << "로그인 실패, ID/PASSWORD 확인 필요" << endl;
			return;
		}

		cout << "로그인 성공" << endl;
	}

private:
	char user[256];
	char password[256];
};

class BiometricAuth : public Authenticator
{
public:
	BiometricAuth() :user{ "user123" }, password{ "pass456" } {}
	void Authenticate(const char* userName, const char* password) override
	{
		cout << "Biometric Auth" << endl;
		if (strcmp(this->user, userName) != 0 || strcmp(this->password, password))
		{
			cout << "로그인 실패, 등록된 생체정보 아님" << endl;
			return;
		}

		cout << "로그인 성공" << endl;
	}

private:
	char user[256];
	char password[256];
};


int main()
{
	PasswordAuth passAuth; BiometricAuth bioAuth;
	Authenticator* auths[] = { &passAuth, &bioAuth };
	for (int i = 0; i < 2; ++i)
		auths[i]->Authenticate("user123", "pass456");
}