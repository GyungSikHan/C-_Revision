#include<iostream>
#include<string>

using namespace std;

string str;
int cnt;
char ret[3]{};

void dfs(int level, int idx)
{
    if(level == 3)
    {
        cnt++;
        cout<<ret<<endl;
        return;
    }


    for (size_t i = idx; i < str.size(); i++)
    {
        ret[level] = str[i];
        dfs(level+1, i);
    }
    
}

int main()
{
    cin>>str;
    dfs(0, 0);
}