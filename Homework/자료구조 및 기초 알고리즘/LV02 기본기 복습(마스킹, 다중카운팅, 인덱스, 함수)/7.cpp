#include<iostream>
using namespace std;

int main()
{
    char vect[6]{'B','T','K','I','G','Z'};
    char target[4]{};

    for (size_t i = 0; i < 4; i++)
    {
        cin>>target[i];
    }

    int count{};
    for (size_t i = 0; i < 4; i++)
    {
        for (size_t j = 0; j < 6; j++)
        {
            if(vect[j] == target[i])
                count++;
        }
    }
    
    cout<<count;
}