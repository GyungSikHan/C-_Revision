#include<iostream>
using namespace std;

struct Point
{
    int y;
    int x;
};

int main()
{
    char arr[5][5]{};
    char c = 'A';
    Point M{};
    for (size_t i = 0; i < 25; i++)
    {
        if(c == 'M')
        {
            M.y = i/5;
            M.x = i%5;
        }
        arr[i/5][i%5] = c;
        c++;
    }

    char input{};
    cin>>input;
    Point inputData{};
    for (size_t i = 0; i < 25; i++)
    {
        if(arr[i/5][i%5] == input)
        {
            inputData.y = i/5;
            inputData.x = i%5;
            break;
        }
    }

    cout<< inputData.y - M.y <<","<<inputData.x - M.x;
    
    
}