#include<iostream>

using namespace std;

int arr[100]{};
int n{};

void insert(const int data, int idx)
{
    if(arr[idx] == 0)
    {
        arr[idx] = data;
        return;
    }

    if(arr[idx] > data)
        insert(data, idx*2);
    else if(arr[idx] < data)
        insert(data, idx*2+1);
}

bool find(const int data, int level)
{
    if (arr[level] == 0)
        return false;
    if (arr[level] == data)
        return true;

    if (arr[level] < data)
        return find(data, level * 2 + 1);
    else
        return find(data, level * 2);
}

int main()
{
    cin>>n;

    for (size_t i = 0; i < n; i++)
    {
        int data{};
        cin>>data;

        insert(data, 1);
    }

    for (int i = 1; i <= 6; ++i)
    {
        cout << i <<":" << (find(i, 1) == false ? 'X' : 'O') << endl;
    }
    
}