#include<iostream>
using namespace std;

void Table(const int (*win)[3], int* data)
{
    for(int i = 0; i < 6; i++)
    {
        data[win[i/3][i%3]]++;
    }
}

int main()
{
    int win[2][3]
    {
        3,5,1,
        4,2,6
    };

    int people[4]{};
    int table[10]{};

    for (size_t i = 0; i < 4; i++)
    {
        cin>>people[i];
    }

    Table(win, table);
    
    for (size_t i = 0; i < 4; i++)
    {
        cout<<people[i];
        if(table[people[i]])
            cout<<"번 합격"<<endl;
        else
            cout<<"번 불합격"<<endl;
    }
    
}