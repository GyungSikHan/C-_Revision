#include<iostream>
using namespace std;

int main()
{
    int a{},b{};
    char c{};
    cin>>a>>b>>c;

    for (size_t i = 0; i < 2; i++)
    {
        for (size_t j = 0; j < a; j++)
        {
            for (size_t k = 0; k < b; k++)
            {
                cout<<c;
            }
            cout<<endl;
        }
    }
    
}