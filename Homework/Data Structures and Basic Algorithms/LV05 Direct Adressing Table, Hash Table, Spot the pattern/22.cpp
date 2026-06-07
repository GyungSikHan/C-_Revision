#include <ctime>

#include "22Time.h"
using namespace std;

int main()
{
	Time time1(4, 50, 40);
	Time time2(3, 40, 30);

	Time time3 = time1 + time2;

	time1.Print();
	time2.Print();
	time3.Print();
}