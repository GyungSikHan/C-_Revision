#include<iostream>
#include<string>
using namespace std;

void Lower(string& s)
{
    for (size_t i = 0; i < s.size(); i++)
    {
        char c = s.at(i);
        if(c >= 'A' && c<= 'Z')
            s[i] = std::tolower(c);
    }
}

string MakeStr()
{
    string s{};
    getline(cin, s);
    Lower(s);

    string temp{};

    for (size_t i = 0; i < s.size(); i++)
        if(s.at(i) >= 'a' && s.at(i) <= 'z')
            temp += s.at(i);
    return temp;
}

bool Palindrome(const string& s)
{
    int size = s.size() / 2;
    int back = s.size()-1;
    
    for (size_t i = 0; i < size; i++)
        if(s.at(i) != s.at(back--))
            return false;
    
    return true;
}

int main()
{
    string ret{};
    ret = MakeStr();
    cout<<ret<<endl;
    cout<< (Palindrome(ret) ? "true" : "false");
}