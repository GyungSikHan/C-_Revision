#include<iostream>
using namespace std;


int main()
{
    int vect[7]{3,5,4,2,6,6,5};
    int bit[7];

    for (size_t i = 0; i < 7; i++)
    {
        cin>>bit[i];
    }

    for (size_t i = 0; i < 7; i++)
    {
        if(bit[i] == 0)
            vect[i] = 0;
        else
            vect[i] = 7;
    }
    
    for (size_t i = 0; i < 7; i++)
    {
        cout<<vect[i]<<" ";
    }
}