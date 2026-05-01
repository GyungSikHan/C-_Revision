# include<iostream>
using namespace std;

int main()
{
    char arr[6][3];
    char temp = 'A';
    for (int i = 2; i >= 0; i--)
    {
        for (int j = 5; j >= 0; j--)
        {
            arr[j][i] = temp++;
        }
    }
    
    int y{}, x{};
    cin>>y>>x;

    cout<<arr[y][x];
}