#include <iostream>
#include "listClass.h"
#include "listCalss2.h"
#include "list.h"

int main()
{
	//ya::list<int> list;

	//list.push_back(1);
	//list.push_back(2);
	//list.push_back(3);

	//std::cout << list.size() << std::endl;

	//list.push_front(4);
	//list.push_front(5);
	//list.push_front(6);
	//std::cout << list.size() << std::endl;

	//for (ya::list<int>::iterator iter = list.begin(); iter != list.end(); ++iter)
	//{
	//	std::cout << *iter << std::endl;
	//}

	//list.pop_front();
	//list.pop_back();

	//std::cout << std::endl;

	//ya2::list<int> list2;

	//list2.push_back(1);
	//list2.push_back(2);
	//list2.push_back(3);

	//std::cout << list2.size() << std::endl;

	//list2.push_front(4);
	//list2.push_front(5);
	//list2.push_front(6);
	//std::cout << list2.size() << std::endl;

	//for (ya2::list<int>::iterator iter = list2.begin(); iter != list2.end(); ++iter)
	//{
	//	std::cout << *iter << std::endl;
	//}

	//list2.pop_front();
	//list2.pop_back();

	ya3::list<int> list;

	list.push_back(1);
	list.push_back(2);
	list.push_back(3);

	std::cout << list.size() << std::endl;

	list.push_front(4);
	list.push_front(5);
	list.push_front(6);
	std::cout << list.size() << std::endl;

	for (ya3::list<int>::iterator iter = list.begin(); iter != list.end(); ++iter)
	{
		std::cout << *iter << std::endl;
	}

	list.pop_front();
	list.pop_back();

	std::cout << list.empty() << std::endl;
	std::cout << list.front() << std::endl;
	std::cout << list.back() << std::endl;

	list.insert(list.begin() , 3);
	list.erase(list.begin() + 3);

	list.remove(1);
	std::cout << *(list.find(2)) << std::endl;

	for (ya3::list<int>::iterator iter = list.begin(); iter != list.end(); ++iter)
	{
		std::cout << *iter << std::endl;
	}
	list.clear();
	std::cout << list.size() << " " << list.empty() << std::endl;
}