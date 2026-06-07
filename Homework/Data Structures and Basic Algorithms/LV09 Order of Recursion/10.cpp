#include<iostream>
using namespace std;

bool Solve(const char (*str)[3], const char* c)
{
    for (size_t i = 0; i < 2; i++)
    {
        for (size_t j = 0; j < 3; j++)
        {
            if(str[i][j] == *c)
            {
                return true;
            }
        }
        
    }
    return false;
}

int main()
{
    char str[2][2][3]
    {
        {
            'A','T','B',
            'C','C','B'
        },
        {
            'A','A','A',
            'B','B','C'
        }
    };
    char c{};
    cin>>c;

    bool bFlag{};
    for (size_t i = 0; i < 2; i++)
    {
        bFlag = Solve(str[i], &c);

        if(bFlag)
            break;
    }

    if(bFlag)
        cout<<"Find"<<endl;
    else
        cout<<"Not find"<<endl;
    
}