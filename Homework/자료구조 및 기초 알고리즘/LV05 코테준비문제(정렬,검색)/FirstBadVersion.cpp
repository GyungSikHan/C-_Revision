#include <iostream>
using namespace std;

int bad;
bool isBadVersion(int version)
{
	return bad <= version;
}

int FirstBadVersion(int n)
{

	for (size_t i = 1; i <= n; i++)
	{
		if(isBadVersion(i))
			return i;
	}

	return -1;
}

int main()
{
	cout<<boolalpha;
	int n{};
	cin>>n >> bad;	
	cout<<"First bad version : " <<  FirstBadVersion(n);
}