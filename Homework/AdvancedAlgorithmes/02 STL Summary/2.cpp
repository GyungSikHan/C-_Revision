#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n{};
vector<int> v;

void SelectSort()
{
	for (int i = 0; i < n-1; i++)
	{
		int idx = i;
		for (int j = i+1; j < n; j++)
		{
			if(v[idx] < v[j])
				idx = j;
		}ㅇ
		
		swap(v[idx],v[i]);
	}	
}

void InsertSort()
{
	for (int i = 1; i < n; i++)
	{
		int temp = v[i];
		int j = i-1;
		for(; j >= 0; j--)
		{
			if(temp > v[j])
			{
				v[j+1] = v[j];
			}
		}

		v[j+1] = temp;
	}
	
}

int main() 
{
	cin >> n;
	v.assign(n, 0);

	for (int i = 0; i < n; i++)
		cin >> v[i];

	// SelectSort();
	InsertSort();

	std::cout << "금" << v[0] << std::endl;
	std::cout << "은" << v[1] << std::endl;
	std::cout << "동" << v[2] << std::endl;
}