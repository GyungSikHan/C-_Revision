#include <iostream>
using namespace std;

int main()
{
	int map[4][4]
	{
		0,0,1,1,
		1,0,1,1,
		0,1,0,0,
		0,0,0,0
	};

	for (size_t i = 0; i < 4; i++)
		for (size_t j = 0; j < 4; j++)
			if(map[i][j] != 0)
				cout<<"y :" << i <<" x : "<< j<<" value: "<< map[i][j]  <<endl;	
}