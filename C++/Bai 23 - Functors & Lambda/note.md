# Functors & Lambda
----------------------------------

# 1. Lambda Expression
- Là 1 hàm ẩn danh (Tức là 1 hàm không cần tên và có thể khai báo ngại tại nơi cần dùng) __anonymous function__
- Cú pháp:
```cpp
[capture](parameter_list) -> return_type
{
    // code
}

[capture](parameter_list)
{
    //code ==> kiểu trả về sẽ tự động suy diễn từ đoạn code này
}
```

- Có 2 cách để sử dụng Lambda
    - Gán hàm này cho 1 biến ==> Cách này có thể tái sử dụng được nhiều lần, do nội dung đã được lưu trữ lại trong biến func
```cpp
    int main()
{
    auto func = []() 
    {
    cout <<"Hello world\n";
    };
    func();
    return 0;
}
```

    - sử dụng trực tiếp ==> Cách này chỉ sử đụng được 1 lần

```cpp
[]() 
    {
    cout <<"Hello world\n";
    }();
```

```cpp
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

```

## capture
- Cho biết cách sử dụng các biến xung quanh lambda
    - [<name_variable>]: truyền giá trị của biến cụ thể sẽ sử dụng ==> chỉ dùng để đọc
    - [&<name_variable>]: truyền tham chiếu của biến cụ thể sẽ sử dụng ==> có thể đọc và ghi
    - [=]: truyền giá trị tất cả các biến xung quanh

# 2. Functor

- Trong C+, Functor (Đối tượng hàm - functor object) là 1 object có thể hoạt động như một hàm. Nói cách khác, functor là một đối tượng của class(struct) có định nghĩa toán tử __operator()__ để có thể gọi ra như một hàm thông thường.

```cpp
template<typename T1, typename T2>
class Test
{
    public:
        void operator ()(){}
        void operator ()(T1 x){}
        void operator ()(T1 x. T2 y){}
};
```

- Đặc điểm của Functor:
 - Là hàm thành viên có quyền truy cập là public.
 - Không phải là static method.
 - Có khai báo operator ().
