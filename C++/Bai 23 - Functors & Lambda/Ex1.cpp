#include <iostream>
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




int main()
{
    // auto func = []() 
    // {
    // cout <<"Hello world\n";
    // };
    // func();

    []() 
    {
    cout <<"Hello world\n";
    }();
   

    cout << [](int a, int b, int c)
    {
        return a+b+c;
    }(1, 2, 3) << endl;

    cout << [](auto... args)
    {
        double sum = 0;
        double arr[] = {args...};
        for(int i = 0; i<(sizeof(arr)/sizeof(arr[0])); i++)
        {
            sum = sum+ arr[i];
        }
        return sum;
    }(1, 2, 3, 3.5) << endl;

    return 0;
}