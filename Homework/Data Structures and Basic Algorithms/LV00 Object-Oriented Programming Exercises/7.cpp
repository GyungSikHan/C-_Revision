#include <iostream>
#include <thread>
#include <chrono>
using namespace std;

class Timer
{
public:
	Timer()
		:timerName{}, bTimerStart(false), startTime(), endTime(), elapsed(), totalTime()
	{}
	Timer(char* timerName)
		: bTimerStart(false), startTime(), endTime(), elapsed(), totalTime()
	{
		strcpy_s(this->timerName, sizeof(timerName),timerName);
	}
	~Timer() {}

	void StartTimer(bool bStart)
	{
		if (!bStart)
			return;
		bTimerStart = bStart;
		auto start = chrono::high_resolution_clock::now();

		for (int i = 0; i < 5; ++i)
		{
			std::this_thread::sleep_for(chrono::milliseconds(100));
			ElapsedTime();
		}
	}

	void ElapsedTime()
	{
		if (!bTimerStart)
			return;

		endTime = chrono::high_resolution_clock::now();
		elapsed = endTime - startTime;
		startTime = endTime;
		totalTime += elapsed;
	}

	void Print()
	{
		cout << "Timer \"" << timerName << "\" " << (bTimerStart == true ? "started." : "not start") << endl;
		cout << "Elapsed: " << elapsed << " / Total: " << totalTime << endl;
	}


private:
	char timerName[256];
	bool bTimerStart;
	chrono::time_point<chrono::steady_clock> startTime;
	chrono::time_point<chrono::steady_clock> endTime;
	chrono::duration<double, std::milli> elapsed;
	chrono::duration<double, std::milli> totalTime;
};

int main()
{
	char name[] = "Cooking";
	Timer timers = Timer(name);

	timers.StartTimer(true);
	timers.Print();
}