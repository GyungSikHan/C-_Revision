#include<iostream>

using namespace std;

int nextPermutation(int* data, int n)
{
    int i = n-1;
    while (i > 0 && data[i-1] >= data[i])
    {
        i-=1;
    }

    if(i <= 0)
        return 0;

    int j = n-1;
    while (data[j] <= data[i-1])
    {
        j-=1;
    }
    
    int temp = data[i-1];
    data[i-1] = data[j];
    data[j] = temp;

    j = n-1;
    while (i < j)
    {
        temp = data[i];
        data[i] = data[j];
        data[j] = temp;
        i+=1;
        j -=1;
    }

    return 1;
}

int main()
{
    int data[4] {1,2,3,4};
    int x{};
    int n = 4;
    int result{};

    while (true)
    {
        for (x = 0; x < 4; x++)
        {
            cout<<data[x];
        }
        cout<<endl;
        
        result = nextPermutation(data, n);
        if(result == 0)
            break;
    }
    
}