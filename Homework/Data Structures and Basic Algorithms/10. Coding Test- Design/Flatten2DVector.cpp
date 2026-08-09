#include <iostream>
#include <vector>

using namespace std;

class Vector2D
{
public:
	Vector2D(vector<vector<int>>arr)
	{
		for (int i = 0; i < arr.size(); ++i)
		{
			for (int j = 0; j < arr[i].size(); ++j)
			{
				data.push_back(arr[i][j]);
			}
		}
	}
	int next()
	{
		int temp = data[nextIndex];
		nextIndex++;

		return temp;
	}
	bool hasNext()
	{
		return (nextIndex < data.size());
	}

private:
	vector<int> data;
	int size;
	int nextIndex;
};

int main()
{
	vector<vector<int>>arr{ {1,2},{3},{4} };
	Vector2D vector2D(arr);
	cout<<vector2D.next()<<endl;
	cout<<vector2D.next()<<endl;
	cout<<vector2D.next()<<endl;
	cout<<(vector2D.hasNext()?"True":"False")<<endl;
	cout<<(vector2D.hasNext()?"True":"False")<<endl;
	cout << vector2D.next() << endl;
	cout<<(vector2D.hasNext() ? "True" : "False") << endl;
}