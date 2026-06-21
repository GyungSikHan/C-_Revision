#include <iostream>
using namespace std;

struct NODE
{
	int age;
	NODE* next1;
	NODE* next2;
};

int main()
{
	NODE* head{};
	NODE simson{};
	NODE woman1{};
	NODE woman2{};
	NODE man1{};
	NODE man2{};
	NODE man3{};

	head = &simson;
	head->next1 = &woman1;
	head->next2 = &woman2;
	head->next1->next1 = &man1;
	head->next1->next2 = &man2;
	head->next2->next1 = &woman1;
	head->next2->next2 = &man3;

	head->age = 20;
	head->next1->age = 29;
	head->next1->next1->age = 25;
	head->next1->next2->age = 40;
	head->next2->age = 30;
	head->next2->next2->age = 38;

	cout << simson.age << endl;
	cout << woman1.age << endl;
	cout << woman2.age << endl;
	cout << man1.age << endl;
	cout << man2.age << endl;
	cout << man3.age << endl;
}
