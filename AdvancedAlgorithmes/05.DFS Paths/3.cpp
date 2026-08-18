#include<iostream>

char history[10]{};
char ox[2]{'O','X'};
char data[10] = "ABCD";

void dfs(int level)
{
    int cnt = 0;
    if(level == 4)
    {
        for (size_t i = 0; i < 4; i++)
        {
            if(history[i] == 'O')
                cnt++;
        }
        
        if(cnt == 3)
        {
            for (size_t i = 0; i < 4; i++)
            {
                if(history[i] == 'O')
                    std::cout<<data[i];
            }
            std::cout<<std::endl;
        }

        return;
    }

    for (size_t i = 0; i < 2; i++)
    {
        history[level] = ox[i];
        dfs(level+1);
        history[level] = 0;
    }
}

int main()
{
    dfs(0);
}