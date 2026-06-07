#include<iostream>
using namespace std;

void InputData(int* data)
{
    for (size_t i = 0; i < 5; i++)
    {
        cin>>data[i];
    }
}

int Pain(const int* data1, const int* data2)
{
    int count{};
    for (size_t i = 0; i < 5; i++)
    {
        if(data1[i] == 1 && data2[i] == 1)
            count++;
    }

    return count;
}

int main()
{
    int up[5]{};
    int down[5]{};

    InputData(up);
    InputData(down);
    cout<<Pain(up,down)<<"개";

}