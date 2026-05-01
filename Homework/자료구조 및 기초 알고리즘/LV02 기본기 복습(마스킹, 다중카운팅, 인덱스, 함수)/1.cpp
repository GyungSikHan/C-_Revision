#include<iostream>
using namespace std;

struct Point 
{
    int y;
    int x;
};

Point Serch(const char (*arr)[4], const char& c )
{
    Point temp{-1,-1};

    for (size_t i = 0; i < 3; i++)
    {
        for (size_t j = 0; j < 4; j++)
        {
            if(arr[i][j] == c)
            {
                temp.y = i;
                temp.x = j;
                return temp;
            }
        }
        
    }
    return temp;
}

int main()
{
    char arr[3][4]
    {
        'A','T','K','B',
        'C','Z','F',' d',
        'H','G','E','I'
    };
    char a{};
    int y{},x{};
    cin>>a>>y>>x;

    Point point = Serch(arr, a);    

    if(point.y < 0 || point.y >= 3 || point.x < 0 || point.x >= 4)
    {
        cout<<"실패"<<endl;
        return 0;
    }

    cout<<arr[point.y+y][point.x+x];
}