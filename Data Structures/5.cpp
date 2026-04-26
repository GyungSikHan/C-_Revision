#include <iostream>
using namespace std;

int main()
{
	int arr[5]{ 1,5,1,5,3 };
	int input[3]{ 1,2,3};

	for (size_t i = 0; i < 3; ++i)
	{
		int count{};
		for (size_t j = 0; j < 5; ++j)
		{
			if (arr[j] == input[i])
			{
				count++;
			}
		}

		cout << input[i] << ": " << count << "개" << endl;
	}
}