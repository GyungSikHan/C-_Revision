#include <iostream>

using namespace std;

int One()
{
	int data[10]{};

	return sizeof(data);
}

int Two()
{
	double data[3]{};
	char vect[10]{};
	int dt[10]{};

	return sizeof(data) + sizeof(vect) + sizeof(dt);
}

int Three()
{
	struct Node
	{
		int x;
		char t;
	};

	Node vect[100]{};

	return sizeof(vect);
}

int Four()
{
	struct Node
	{
		int x;
		char* next;
	};
	Node vect{};

	return sizeof(vect);
}
int main()
{
	int n{};
	cin >> n;
	int ret{};
	switch (n)
	{
	case 1:
		ret = One();
		break;
	case 2:
		ret = Two();
		break;
	case 3:
		ret = Three();
		break;
	case 4:
		ret = Four();
		break;
	default:
		break;
	}

	cout << ret << endl;
}