#include <iostream>
using namespace std;

int main()
{
    // int 타입 동적 할당
    int* ptr_int = new int;
    *ptr_int = 100;

    // double 타입 동적 할당
    double* ptr_double = new double;
    *ptr_double = 100.123;

    // 값 출력
    cout << "int형 숫자의 값은 " << *ptr_int << "입니다." << endl;
    cout << "int형 숫자의 메모리 주소는 " << ptr_int << "입니다." << endl;

    cout << "double형 숫자의 값은 " << *ptr_double << "입니다." << endl;
    cout << "double형 숫자의 메모리 주소는 " << ptr_double << "입니다." << endl;

    // 메모리 해제 (중요!)
    delete ptr_int;
    delete ptr_double;

    return 0;
}
