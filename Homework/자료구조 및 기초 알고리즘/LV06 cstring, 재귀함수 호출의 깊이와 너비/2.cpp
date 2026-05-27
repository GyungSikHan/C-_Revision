#include<iostream>
using namespace std;

void InputLogInfo(char* id, char* password)
{
    cin>>id>>password;
}

bool CheckLogin(char* ID, char* PASSWORD, char* id, char* password)
{
    if(strcmp(ID,id) != 0)
        return false;
    if(strcmp(PASSWORD,password)!= 0)
        return false;
    return true;
}

int main()
{
    char ID[256] = "qlqlaqkq";
    char PASSWORD[256] = "tkaruqtkf";

    char id[256]{};
    char password[256]{};

    InputLogInfo(id,password);
    if(CheckLogin(ID,PASSWORD,id,password))
        cout<<"LOGIN";
    else
        cout<<"INVALID";
}