#include<iostream>
using namespace std;

int main()
{
    char arr[11]{};
    cin>>arr;

    int idx{}, idx2{};

    char min = 'Z', max = 'A';
    int i{};
    while (arr[i] != '\0')
    {
        if((int)arr[i] < (int)min)
        {
            min = arr[i];
            idx2 = i;
        }
        if((int) arr[i] > (int)max)
        {
            max = arr[i];
            idx = i;
        }
        i++;
    }
    
    cout<<idx<<"\n"<<idx2<<endl;
    
}