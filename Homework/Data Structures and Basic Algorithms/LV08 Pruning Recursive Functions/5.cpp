#include<iostream>
using namespace std;

char name[5] {'E','W','A','B','C'};
char path[5];
int visited[26];

void Solve(const char* c, int level)
{
    if(level == 4)
    {
        cout<<path<<endl;
        return;
    }

    for (size_t i = 0; i < 5; i++)
    {
        if(name[i] == *c || visited[name[i] - 'A'] != 0)
            continue;
        visited[name[i] - 'A'] = 1;
        path[level] = name[i];
        Solve(c,level+1);
        path[level] = '\0';
        visited[name[i] - 'A'] = 0;
    }
    

}

int main()
{
    char c{};
    cin>>c;
    visited[c-'A'] = 1;
    Solve(&c,0);
}