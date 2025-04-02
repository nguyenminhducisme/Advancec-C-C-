# Cấu trúc chương trình

                       REGISTER
                       Lần lượt call từ RAM vào
                       0101
                       0111

      ALU 

                                             RAM
                                          sao chép qua RAM (0101)
                                                           (0111)
                                                           (1001) <giả sử đây là phép cộng>

     FLASH
    0101010101 (binary code)



Giả sử
```c
#define sum(a,b) a+b

int main()
{
    sum(5, 6); // 5+6
}
```

```c
int sum(int a, int b)
{
    return a+b;
}
int main()
{
    sum(5, 6);
}
```

- Trên máy tính có 2 đối tượng này:
   - Programme counter
   - Main stack pointer


# Inline function
- Khi nào sử d
