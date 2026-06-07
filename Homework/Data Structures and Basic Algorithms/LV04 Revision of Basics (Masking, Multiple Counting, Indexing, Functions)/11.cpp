#include<iostream>
using namespace std;

int IsSame(char* name1, char* name2)
{
    return strcmp(name1, name2);
}

int main()
{
    char name1[256]{};
    char name2[256]{};
    
    cin>>name1;
    cin>>name2;

    if(IsSame(name1,name2) == 0)
        cout<<"동명";
    else
        cout<<"남남";
}