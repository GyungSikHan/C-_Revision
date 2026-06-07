#include<iostream>
using namespace std;

void CheckMap(const int (*map)[3], const int (*pix)[2], char (*ret)[2])
{
    for (size_t i = 0; i < 4; i++)
    {
        for (size_t j = 0; j < 6; j++)
        {
            if(pix[i/2][i%2] == map[j/3][j%3])
            {
                ret[i/2][i%2] = true;
                break;
            }
        }
    }
    
}

int main()
{
    int map[2][3]
    {
        3, 55, 42,
        -5, -9, -10
    };
    int pix[2][2];

    for (size_t i = 0; i < 4; i++)
    {
        cin>>pix[i/2][i%2];
    }

    char ret[2][2]{};
    CheckMap(map, pix, ret);

    for (size_t i = 0; i < 2; i++)
    {
        for (size_t j = 0; j < 2; j++)
        {
            if(ret[i][j])
                cout<<"Y ";
            else    
                cout<<"N ";
        }
        cout<<endl;
    }
    
}