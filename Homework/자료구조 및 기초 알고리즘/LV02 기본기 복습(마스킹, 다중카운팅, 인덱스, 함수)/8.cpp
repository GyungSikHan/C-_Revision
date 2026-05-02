#include<iostream>
using namespace std;

int main()
{
    int vect[3][3]{3,7,4,2,2,4,2,2,5};
    int target[3]{};
    int ret[3]{};

    for (size_t i = 0; i < 3; i++)
    {
        cin>>target[i];
    }

    int counting{};

    for (size_t i = 0; i < 3; i++)
    {
        for (size_t j = 0; j < 9; j++)
        {
            if(target[i] == vect[j/3][j%3])
            {
                ret[i]++;
            }
        }
    }
    
    int max = -1;
    int maxRet = -1;
    for (size_t i = 0; i < 3; i++)
    {
        if(max < ret[i])
        {
            max = ret[i];
            maxRet = target[i];
        }
    }
    cout<<maxRet;
}