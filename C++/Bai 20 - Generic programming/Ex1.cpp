#include<iostream>
using namespace std;

template <typename T1, typename T2>
auto sum(T1 a, T2 b)
{
    return a+b;
}

template <typename T>
T sum(T a, T b)
{
    return a+b;
}

// tham số mặc định
template <typename T = int>
T square(T x)
{
    return x * x;
}


int main()
{
    cout << "Sum: " << sum(1,2)<< endl; // T: int
    cout << "Sum: " << sum(1.4, 2.7) << endl; // T: double
    cout << "Sum: " << sum(1, 2.7) << endl; // Tham số T1: int quyết định kiểu trả về của hàm

    // auto b; Như thế này là lỗi vì phải có một giá trị để auto xác định kiểu
    auto x = 2;
    auto y = 3.5;
    auto z = 'a';
    auto t = "hello";

    cout << square(4.5) << endl;
    cout << square<double>(4.5) << endl; // ép kiểu int -> double
    

    return 0;
}