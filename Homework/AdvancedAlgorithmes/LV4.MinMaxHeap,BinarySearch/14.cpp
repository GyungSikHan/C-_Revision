#include <iostream>
#include <algorithm>
using namespace std;

const string eraseStr[5]
{
	"chicken",
	"pizza",
	"jockbal",
	"bread",
	"samhap"
};

string str{};

int main()
{
	cin >> str;

	string temp = str;
	std::transform(temp.begin(), temp.end(), temp.begin(), ::tolower);
	
	for (int i = 0; i < 5; ++i)
	{

		while (true)
		{
			size_t idx = temp.find(eraseStr[i]);
			if (idx == string::npos)
				break;
			//원하는 범위의 글자를 원하는 글자로 변경하는 함수 string::replace
			temp.replace(idx, eraseStr[i].size(), "###");
			str.replace(idx, eraseStr[i].size(), "###");

			//temp.erase(idx, eraseStr[i].size());
			//temp.insert(idx, "###");

			//str.erase(idx, eraseStr[i].size());
			//str.insert(idx, "###");
		}
	}

	cout << str;
}