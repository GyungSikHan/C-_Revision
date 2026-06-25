#include<iostream>
using namespace std;

enum Name
{
    Amy,
    Bob,
    Chole,
    Diane,
    Edger
};

int main()
{
    int arr[5][5]
    {
        0,0,0,0,1,
        1,0,0,0,0,
        0,1,0,0,0,
        0,1,0,0,0,
        0,0,0,0,0,
    };

    int ret[5]{};

    for (size_t i = 0; i < 5; i++)
        for (size_t j = 0; j < 5; j++)
            if(arr[i][j] == 1)
                ret[j] ++;
    
    int Max=-1;
    int idx{};
    for (size_t i = 0; i < 5; i++)
    {
        if(Max < ret[i])
        {
            Max = ret[i];
            idx = i;
        }
    }

    switch (idx)
    {
    case 0:
        cout<<"Amy";
        break;
    case 1:
        cout<<"Bob";
        break;
    case 2:
        cout<<"Chole";
        break;
    case 3:
        cout<<"Diane";
        break;
    case 4:
        cout<<"Diane";
        break;
    case 5:
        cout<<"Edger";
        break;
    }
    
}