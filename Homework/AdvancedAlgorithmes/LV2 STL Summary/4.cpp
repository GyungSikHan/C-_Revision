#include<iostream>
#include<vector>
using namespace std;

const int Line = 5;

string arr[Line]{};
int first{}, second{};

string Sort(const string str)
{
    vector<int> temp;
    
    for (int i = 0; i < str.size(); i++)
        temp.push_back(str.at(i) - '0');
    

    sort(temp.begin(), temp.end());
    
    string ret{};
    for (int i = 0; i < temp.size(); i++)
        ret+=to_string(temp.at(i));
    
    return ret;
}

int main()
{
    for (int i = 0; i < Line; i++)
        cin>>arr[i];

    cin>>first>>second;
    arr[first] = Sort(arr[first]);
    arr[second] = Sort(arr[second]);
    
    for (int i = 0; i < Line; i++)
        cout<<arr[i][0]<<" ";
}