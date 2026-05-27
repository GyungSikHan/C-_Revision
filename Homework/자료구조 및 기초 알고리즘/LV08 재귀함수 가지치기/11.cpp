#include <iostream>
using namespace std;

int main()
{
    int arr[8]{};
    for (size_t i = 0; i < 8; i++)
        cin >> arr[i];

    int pivot = 0;

    int l = 1;
    int r = 7;
    while (l < r)
    {
        if (arr[l] < arr[pivot])
            l++;
        else if (arr[r] > arr[pivot])
            r--;
        else
            swap(arr[l], arr[r]);
    }
    swap(arr[pivot], arr[r-1]);

    for (size_t i = 0; i < 8; i++)
        cout << arr[i] << " ";
}