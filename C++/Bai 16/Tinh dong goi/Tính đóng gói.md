# Tính đóng gói - Encapsulation
- Như ở class, ta thấy các thông tin khởi tạo không được kiểm chứng, name = "anh123" hay age = -5 có thể âm. Nhưng khi chạy chương trình không báo lỗi do không được kiểm chứng
```cpp

int main(){
    SinhVien sv1("Anh 123", -5);
    sv1.setName()
   
    // sv1.age = 23; 
    // sv1.name = "Anh12";
    sv1.display();

    sv1.x = 103;
    cout << sv1.x << endl;

    SinhVien::show();
}
```
1. Để khắc phục, ta để nó trong private để __tránh việc truy cập từ bên ngoài, ta có thể truy cập từ bên trong class qua các hàm__

### Định nghĩa:

1. Tính đóng gói (Encapsulation) là ẩn đi các property “mật” khỏi người dùng. Và để làm được điều này, ta sẽ khai báo các property ở quyền truy cập private/protected (tức là không thể truy cập trực tiếp tới các property này thông qua object bên ngoài). 

2. Trong trường hợp ta muốn đọc hoặc ghi các property này, thì ta sẽ truy cập gián tiếp thông qua các method ở quyền truy cập public.
