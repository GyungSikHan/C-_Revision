#include<iostream>
using namespace std;

bool Solve(const char* str, const char* ret)
{
    if(strcmp(str, ret) == 0)
        return true;
    return false;
}

int main()
{
    char str[5][256]{};
    char ret[256]{};

    for (size_t i = 0; i < 5; i++)
        cin>>str[i];

    cin>>ret;

    bool bFlag{};
    for (size_t i = 0; i < 5; i++)
    {
        bFlag = Solve(str[i],ret);
        if(bFlag)
            break;
    }

    cout<<(bFlag ? "암호해제" : "암호틀림")<<endl;
    
}