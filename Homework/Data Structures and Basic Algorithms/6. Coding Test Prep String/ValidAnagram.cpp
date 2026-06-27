#include<iostream>
#include <unordered_map>
using namespace std;

// void Check(string& str, int* arr)
void Check(string& str, unordered_map<char32_t, int>& m)
{
    // for (size_t i = 0; i < str.size(); i++)
    //     arr[str.at(i) - 'a']++;
    for(size_t i = 0; i < str.size(); i++)
    {
        if(m.empty())
            m.insert({str.at(i), 1});
        else
            m[str.at(i)]++;
    }

}

bool Solution(string& s, string& t)
{
    if(s.size() != t.size())
        return false;

    unordered_map<char32_t, int> m{};
    Check(s, m);

    for (size_t i = 0; i < t.size(); i++)
    {
        if(m[t.at(i)] == 0)
            return false;
        else
        {
            m[t.at(i)]--;
            if(m[t.at(i)] == 0)
                m.erase(t.at(i));
        }
    }
    
    // int arr[26]{};
    // int arr2[26]{};
    
    // Check(s, arr);
    // Check(t, arr2);

    // for (size_t i = 0; i < 26; i++)
    // {
    //     if(arr[i] != arr2[i])
    //         return false;
    // }
    return true;
}

int main()
{
    string s{}, t{};

    cin>>s>>t;
    cout<< (Solution(s,t) ? "true" : "false");

}