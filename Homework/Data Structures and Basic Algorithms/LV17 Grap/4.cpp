#include<iostream>
using namespace std;

int main()
{
    string str{};
    cin>>str;

    int arr[26]{};
    for(int i = 0; i < str.size(); i++)
        arr[str.at(i) - 'A']++;
    int count{};

    for(int i = 0; i < 26; i++)
        if(arr[i] != 0)
            count++;

    cout<<count<<"종류"<<endl;
}