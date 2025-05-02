# Namespace 

- Tình huống thường xảy ra trong lập trình C/C++. Ví dụ: Code bạn đang viết có hàm tên là test() và có thư viện khác có sẵn mà cũng có hàm test(). Bây giờ, trình biên dịch không biết phiên bản nào của hàm mà bạn muốn sử dụng trong code của mình.
- Làm sao để giải quyết vấn đề trên?

## 1. khái niệm

- Namespace là cách nhóm các đối tượng như biến, hàm, class, struct... vào một không gian tách biệt

## 2. Đặc điểm

- C++ cho phép tạo các namespace **lồng nhau**, nghĩa là **một namespace có thể chứa một namespace khác bên trong nó**.
- Namespace có thể được **mở rộng bằng cách khai báo nhiều lần cùng một tên namespace trong các phần khác nhau của chương trình**. Các khai báo này sẽ được trình biên dịch ghép lại thành một namespace duy nhất.

## 3. Namespace mở rộng

## 4. Name Mangling

- Biến đổi tên (Name Mangling) là một cơ chế của trình biên dịch g++ nhằm mã hóa tên hàm, biến, class, namespace,... thành tên duy nhất, để tránh xung đột trong quá trình biên dịch (giai đoạn compiler).
- Trong C++, ta có thể dùng:
    - Class chứa hàm thành viên
    - Nạp chồng hàm (hàm trùng tên, khác tham số)
    - Template
    - Namespace
```
void display1(int a);	-> 1234abc
void display1(double a); -> 1347fhd
```

```cpp
namespace A {
    void foo() {
        cout << "A::foo()" << endl;
    }
}
===>
    A::foo() → _ZN1A3fooEv
    B::foo() → _ZN1B3fooEv
------------------------------
namespace B {
    void foo() {
        cout << "B::foo()" << endl;
    }
}
```

## 5. Keyword using
