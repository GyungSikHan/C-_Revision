#include <iostream>
using namespace std;

bool IsPattern(const char* str, const char* pattern, const int idx)
{
    for(int i = 0; i < 5; i++)
    {
        if(pattern[i] != str[idx+i])
            return false;
    }

    return true;
}

int main() 
{
    cout<<"start"<<endl;
    
    char str[256]{};
    std::cin>>str;

    char pattern[6]="GHOST";

    int idx{};
    bool bCheck{};
    while(str[idx] != '\0')
    {
        if(IsPattern(str, pattern, idx++))
        {
            bCheck=true;
            break;
        }
    }

    if(bCheck)
        cout<<"존재";
    else
        cout<<"존재하지 않음";

}
