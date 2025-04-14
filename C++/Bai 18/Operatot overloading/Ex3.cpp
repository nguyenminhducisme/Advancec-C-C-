#include<iostream>
using namespace std;

// tham trị (pass by value) -> sao chép dữ liệu -> không ảnh hưởng biến gốc
// con trỏ -> thao tác trên địa chỉ gốc -> thay đôi biến gốc nhưng tốn bộ nhớ RAM
// tham chiếu (pass by reference) -> thao tác trên địa chỉ gốc ->  không làm tốn dữ liệu trên RAM

void swap(int &a, int &b)
{ 
    int tmp = a;
    a = b;
    b = tmp;
}

int main()
{
    int a = 10;
    int b = 20;

    /* Tham chiếu tới biến a */
    int &ref1 = a; // khai báo tên khác để quản lý địa chỉ của biến, không làm tốn dữ liệu trên RAM
    int &ref2 = b;
    cout << "Dia chi bien a: " << &a<< endl;
    cout << "Dia chi bien a: " << &ref1 << endl;

    swap(a, b);
    cout<< "a = " << a << endl << "b = " << b << endl;
    return 0;
}