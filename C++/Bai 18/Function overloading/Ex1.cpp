#include <iostream>
using namespace std;

class TinhToan
{
    public:
void print(int a)
{
    cout << "a = " << a << endl;
}

void print(double a)
{
    cout << "a = " << a++ << endl;
}

void print(char a)
{
    cout << "a = " << a++ << endl; 
}

int sum(int a, int b)
{
    return a+b;
}

int sum(double a, double b)
{
    return a+b;
}
};

int main()
{
    TinhToan tt;
    tt.print(5.4);
    tt.print(5);
    

   
    return 0;
}