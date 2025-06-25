#include <iostream>

using namespace std;

void func(int &x)
{
    cout << "lvalue reference\n";
}

void func(const int& x)
{
    cout << "lvalue reference to constant\n";
}

void func(int&& x)
{
    cout << "rvalue reference\n";
}

int main()
{
    int a = 3;
    const int b = 10;

    func(a);
    func(b);
    func(10);
    /**
     * gọi cả func(constt int&) và func(int&&) vì 10 là const
     * func(int&&) được ưu tiên hơn
     */
}