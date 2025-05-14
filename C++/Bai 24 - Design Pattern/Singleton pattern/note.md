# DESIGN PATTERN

- Là các giải pháp tổng quát cho các __vấn đề phổ biến__ trong phát triển phần mềm.
- Một số vấn đề thường gặp:
  - Khó kiếm soát việc tạo đối tượng
  - Khó mở rộng hoặc thay đổi hành vi
  - Giao tiếp giữa các modules phức tạp
  - Lặp code hoặc logic tương tự nhau
  - Logic xử lý và giao diện người dùng (UI) bị trộn lẫn

- Design Patterns thường được chia thành các loại sau:
  - _Creation patterns_ (mẫu khởi tạo): quản lý việc khởi tạo đối tượng (VD: __Singleton, Factory__)
  - _Structural Patterns_ (Mẫu cấu trúc): Tổ chức cấu trúc của các lớp và đối tượng (VD: __Decorator__, __Adapter__, __Composite__)
  - _Behavioral Patterns_ (Mẫu hành vi): Xác định cách các đối tượng tương tác với nhau (VD: __Observer, MPC__, __Strategy__)

## SINGLETON PATTERN

- Đặt vấn đề:
  - Khi lập trình với GPIO (ODR), Timer,... nó sẽ có địa chỉ cố định. Khi khởi tạo nhiều object thì object sẽ vào những địa chỉ trên để ghi giá trị. Khi khởi tạo nhiều object thì tốn nhiều tài nguyên trên RAM. Vậy có cách nào chỉ khởi tạo một lần duy nhất, không cần tốn bộ nhớ cấp phát khi sử dụng lại hay không?

- Singleton là một mẫu thiết kế thuộc nhóm Creational (mẫu khởi tạo), nó đảm bảo rằng một class chỉ có một đối tượng duy nhất được tạo ra, và cung cấp một phương thức để truy cập đến đối tượng đó từ bất kỳ đâu trong chương trình.

- Singleton thường sử dụng cho những hệ thống chỉ cần một phiên bản duy nhất như: kết nối cơ sở dữ liệu, bộ nhớ đệm (cache), logger để ghi log, hoặc cấu hình hệ thống.

### Ví dụ triển khai

```cpp
#include <iostream>
using namespace std;

/*
* private constrcutor: Để đảm bảo không thể khởi tạo từ bên ngoài class
* con trỏ static: trỏ tới đối tượng duy nhất này
* hàm static: tạo đối tượng
*/

void gpio_inti()
{
    cout << "GPIO Init params\n";
}

class GPIO
{
    private:
        GPIO()
        {
            cout << "This is contructor" << endl;
        }

      static  GPIO *gpio;

    public:
        static GPIO* createObject() // Để khởi tạo trực tiếp từ class
        {
            // gpio = new GPIO();
            // cout << &gpio << endl;

            if(gpio == nullptr)
            {
                gpio = new GPIO();
                gpio_inti();
            }
            return gpio;
        }
};

GPIO *GPIO::gpio = nullptr;

int main()
{
    // GPIO gp1, gp2, gp3;
    GPIO::createObject(); 
    GPIO::createObject(); 
    GPIO::createObject(); 
    // Chỉ trả 1 lần vì constructor chỉ chạy khi có đối tượng mới được tạo ra
   return 0;
}
```

### Các thành phần chính của Singleton

- Private constructor:
  - Đảm bảo rằng không ai có thể khởi tạo đối tượng từ bên ngoài class
- Static Instance:
  - Đối tượng tĩnh duy nhất của class
  - Không thể tạo ra nhiều hơn một đối tượng của class Singleton
- Static method
  - Phương thức để truy cập đến đối tượng duy nhất từ mọi nơi trong chương trình

### Ưu điểm

- 

### Nhược điểm

- Khó mở rộng và không linh hoạt
