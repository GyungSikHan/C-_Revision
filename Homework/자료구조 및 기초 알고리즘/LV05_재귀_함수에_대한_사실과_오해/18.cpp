#include<iostream>
using namespace std;

class Tower
{
    public:
    Tower()
    :height()
    {}
    Tower(int height)
    : height(height)
    {}
    ~Tower(){}

    int GetHeight()const
    {
        return height;
    }
private:
    int height;
};


int main()
{
    Tower myTower;
    Tower seoulTower(100);

    cout<<"높이는 "<<myTower.GetHeight()<<"m"<<endl;
    cout<<"높이는 "<<seoulTower.GetHeight()<<"m"<<endl;
}