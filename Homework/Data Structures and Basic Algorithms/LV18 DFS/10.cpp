#include <iostream>
#include <vector>
using namespace std;

int arr[6]{};
int arr2[6]{};
vector<int> v;

int Add(int a, int b, int data)
{
    int temp = a + b + data;
    v.push_back(temp % 10);

    return temp / 10;
}

int main()
{
    for (size_t i = 0; i < 6; i++)
        cin >> arr[i];
    for (size_t i = 0; i < 6; i++)
        cin >> arr2[i];

    int temp{};
    for (int i = 5; i >= 0; i--)
    {
        temp = Add(arr[i], arr2[i], temp);
    }

    for (auto iter = v.rbegin(); iter != v.rend(); iter++)
        cout << (*iter) << " ";
}