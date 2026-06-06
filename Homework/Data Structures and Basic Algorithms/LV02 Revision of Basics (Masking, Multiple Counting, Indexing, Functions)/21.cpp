#include<iostream>
using namespace std;

class Calculator
{
public:
    Calculator(){}
    ~Calculator(){}

    void InputData()
    {
        cin>>data1>>data2;
    }

    int Add()
    {
        return data1+data2;
    }
    int Subtraction()
    {
        return data1 - data2;
    }
    int Multiplication()
    {
        return data1*data2;
    }
    int Division()
    {
        return data1 / data2;
    }
    int Modulo()
    {
        return data1%data2;
    }


private:
    int data1;
    int data2;
};

int main()
{
    Calculator calculator;

    calculator.InputData();
    cout<<"덧셈:"<<calculator.Add()<<endl;
    cout<<"뺄셈:"<<calculator.Subtraction()<<endl;
    cout<<"곱셈:"<<calculator.Multiplication()<<endl;
    cout<<"나눗셈:"<<calculator.Division()<<endl;
    cout<<"나머지:"<<calculator.Modulo()<<endl;
}