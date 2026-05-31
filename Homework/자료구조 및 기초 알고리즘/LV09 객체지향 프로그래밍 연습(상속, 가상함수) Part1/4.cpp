#include <iostream>

using namespace std;

class Instrument
{
public:
	virtual void Play(){}
};

class Piano : public Instrument
{
public:
	void Play() override
	{
		cout << "ding ding" << endl;
	}
};

class Guitar : public Instrument
{
	void Play() override
	{
		cout << "strum strum" << endl;
	}
};

int main()
{
	Piano p; Guitar g;
	Instrument* instruments[] = { &p, &g };
	for (int i = 0; i < 2; ++i)
		instruments[i]->Play();
}