# Function Overloading ( Nạp chồng hàm )
- Là việc định nghĩa nhiều hàm __cùng tên, cùng chức năng__ nhưng __khác tham số__ trong cùng một phạm vi
- Trình biên dịch sẽ chọn hàm phù hợp dựa trên kiểu và số lượng đối số khi gọi hàm.
``` cpp
void print(int a)
{
    cout << "a = " << a << endl;
}

void print(double a)
{
    cout << "a = " << a++ << endl;
}

int main()
{
    print(5.4); ==> Output: 5.4
    print(5);   ==> Output: 5
    return 0;
}
```

## Vì sao lại xảy ra ở compile time?
- Vì mỗi hàm có 1 "mã" khác nhau, khi ta gọi overloaded function thì compiler sẽ tìm mã của hàm đó rồi mới chạy.