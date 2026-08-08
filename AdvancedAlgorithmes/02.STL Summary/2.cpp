#include <iostream>
#include <string>
#include <unordered_map>

int main()
{
	std::unordered_map<std::string, int> score;
	score["alice"] = 10;
	score["bob"] = 20;

	auto it = score.find("bob");
	if (it != score.end())
		std::cout << "bob score=" << it->second << std::endl;

	if (score.count("charlie") == 0)
		std::cout << "no charlie\n";

}