# Tính kế thừa

```cpp

class DoiTuong{
    private:
        string ten;
        int id;
};

class SinhVien: public DoiTuong // Ta muốn kế thừa class DoiTuong
{
    public:
        string ten;
        int id;
        string chuyenNganh;
};

class HocSinh: public DoiTuong // Ta muốn kế thừa class DoiTuong
{
    public:
        string ten;
        int id;
        string lop;
};

class GiaoVien: public DoiTuong // Ta muốn kế thừa class DoiTuong
{
    public:
        string ten;
        int id;
        string chuyenMon;
};

- Liệu có thể gộp những property giống nhau ở 3 class để rút gọn code hay không? ==> Hoàn toàn có thể
```

## Protected:
1. Không cho phép các đối tượng bên ngoài truy cập tới, nhưng lại có thể truy cập từ bên trong (Giống private).
2. Sao chép tất cả những hàm và biến trong cha vào hàm con, trừ những biến và hàm trong private

```markdown

- Các member public của class cha vẫn sẽ là public trong class con.
- Các member protected của class cha vẫn sẽ là protected trong class con.
- Các member private của class cha không thể truy cập trực tiếp từ class con nhưng có thể được truy cập gián tiếp qua các phương thức public hoặc protected của class cha.


```

# Kế thừa protected
- Chuyển tất cả phạm vi thành protected, public cũng thành protected, trừ private.
# Kế thừa private
- Chuyển tất cả phạm vi thành private

```cpp
- Ta có 1 hàm display() ở trong class SinhVien như sau
void SinhVien::display()
{
    cout << "Ten: " << name << endl;
    cout << "Tuoi: "<< age << endl;
    cout << "ID: "  << id << endl;
    cout << "Chuyen nganh: " <<chuyenNganh << endl << endl;
}

- Thì nó sẽ ưu tiên hàm có sẵn trong class, nếu không thấy nó mới tìm đến hàm display() có trong class cha
```