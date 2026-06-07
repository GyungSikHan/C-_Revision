#include<iostream>
using namespace std;

int arr[5]{3,5,1,9,7};

void Move(const char* c)
{
    if(*c == 'R')
    {
        int temp = arr[4];
        for (int i = 3; i >= 0; i--)
        {
            arr[i+1] = arr[i];
        }
        arr[0] = temp;
    }
    else
    {
        int temp = arr[0];
        for (int i = 1; i < 5; i++)
        {
            arr[i-1] = arr[i];
        }
        arr[4] = temp;
    }

}

int main()
{
    for (size_t i = 0; i < 4; i++)
    {
        char c{};
        cin>>c;

        Move(&c);
    }

    for (size_t i = 0; i < 5; i++)
    {
        cout<<arr[i]<<" ";
    }
    
    
}