#include<iostream>
using namespace std;

int GetSum(int* arr, int idx)
{
    int length = (idx+5 <= 11 ? idx+5 : 11);
    int sum{};
    for (size_t i = idx; i < length ; i++)
    {
        sum+= arr[i];
    }
    return sum;
}

int main()
{
    int arr[11]{3,4,1,1,2,6,8,7,8,9,10};
    int startIdx{};
    cin>>startIdx;

    cout<< GetSum(arr, startIdx);
}