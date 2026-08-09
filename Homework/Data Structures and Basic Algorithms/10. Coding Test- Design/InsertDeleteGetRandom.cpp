#include <iostream>
#include <vector>

using namespace std;

class RandomizedSet
{
public:
	RandomizedSet()
		:data(), Size() 
	{}
	bool insert(int val)
	{
		if (Size != 0 && find(data.begin(), data.end(), val) != data.end())
			return false;
		
		data.push_back(val);
		Size++;
		return true;
	}
	bool remove(int val)
	{
		if (Size == 0)
			return false;
		auto iter = find(data.begin(), data.end(), val);
		if (iter == data.end())
			return false;
		Size--;
		data.erase(iter, iter + 1);
		return true;
	}
	int getRandom()
	{
		srand(time(NULL));

		int ran = (int)(rand() % Size);

		return data[ran];
	}
	
private:
	vector<int> data;
	int Size;
};

int main()
{
	RandomizedSet rand{};

	cout<<(rand.insert(1)?"true":"false")<<endl;
	cout<<(rand.remove(2)?"true":"false")<<endl;
	cout<<(rand.insert(2) ? "true" : "false" )<<endl;
	cout<<rand.getRandom() << endl;
	cout<<(rand.remove(1)?"true":"false") << endl;
	cout<<(rand.insert(2)?"true":"false") << endl;
	cout<<rand.getRandom() << endl;

}