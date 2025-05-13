#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

/**
[capture](parameter_list) -> return_type
{
    // code
}

[capture](parameter_list)
{
    //code ==> kiểu trả về sẽ tự động suy diễn từ đoạn code này
}
 */

/**
 * CAPTURE
 * truyền giá trị -> đọc
 * truyền tham chiếu -> ghi
 * = --> truyền giá trị các biến xung quanh, nhưng cũng chỉ đọc
 * & --> truyền tham chiếu tất cả các biến xung quanh, có quyền ghi và đọc
 * và cách phối hợp giữa các cách trên
 */


int main()
{
    int a = 10;
    int x = 1, y = 2, z = 3;

    [x, y, z]()
    {
       // x = 10; ==  error: assignment of read-only variable 'x'
       // tức chỉ được đọc không được ghi
        cout << x << endl;
        cout << y << endl;
        cout << z << endl;
       
    }();
    [=]()
    {
       // x = 10; ==  error: assignment of read-only variable 'x'
       // tức chỉ được đọc không được ghi
        cout << x << endl;
        cout << y << endl;
        cout << z << endl;
        cout << a << endl;
    }();

    cout <<endl;
    [&x, y, z]()
    {
       x = 10; // được thay đổi (ghi) do ta truyền tham chiếu
        cout << x << endl;
        cout << y << endl;
        cout << z << endl;
    }();

    cout <<endl;
    [&]()
    {
       x = 10;
       y = 20;
       z = 30;
        cout << x << endl;
        cout << y << endl;
        cout << z << endl;
    }();

    return 0;
}