#include <iostream>
#include <string>
using namespace std;

int main()
{
	string str;
	getline(cin, str);
	cout << str<<endl;

	char str2[256]{};
	cin.getline(str2, 256);
	cout << str2 << endl;


	string str3{}, str4{};
	cin >> str3;
	cout << str3 << endl;
	getline(cin, str4);
	cout <<str4 <<endl;
	
	cin >> str3;
	cout << str3 << endl;
	cin.ignore();
	getline(cin, str4);
	cout << str4 << endl;
}