#include<iostream>

using namespace std;

int groupCount = 4;
int parent[11]{0,0,1,1,0,2,2,0,3,0,4};

int n{};
char c1{}, c2{};

int getParet(char c, int idx)
{
    if(parent[c-'A'] == 0)
        return idx;
        
}

int main()
{
    cin>>n;
    for (size_t i = 0; i < n; i++)
    {
        cin>>c1>>c2;


    }
    
}