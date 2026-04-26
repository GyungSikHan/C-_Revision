#include <iostream>
using namespace std;

class Player
{
public:
	Player()
	{
		strcpy_s(mName, "Unkown");
		mHeight = 0;
	}

	Player(const char* name, int height)
	{
		int len = strlen(name);
		for (int i = 0; i < len; ++i)
		{
			mName[i] = name[i];
		}

		mName[len] = '\0';
		mHeight = height;
	}
	~Player()
	{
		
	}

	void Display()
	{
		cout << "이름: " << mName << ", 키: " << mHeight << "cm" << endl;
	}
private:
	char mName[256];
	int mHeight;
};

int main()
{
	Player nadal("나달", 183);
	nadal.Display();

	Player federer = Player("페더러", 184);
	federer.Display();
}