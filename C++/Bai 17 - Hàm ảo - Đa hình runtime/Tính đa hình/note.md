# Tính đa hình - Polymorphism
- có nghĩa là nhiều dạng và xảy ra khi chúng ta có nhiều class liên quan với nhau thông qua tính kế thừa

```cpp
void DoiTuong::display() 
{
    cout << "Ten: " << name << endl;
    cout << "Tuoi: "<< age << endl;
    cout << "ID: "  << id << endl;
}

void SinhVien::setMajor(string newMajor)
{
    chuyenNganh = newMajor;
}

void SinhVien::display()
{
    DoiTuong::display();
    cout << "Chuyen nganh: " <<chuyenNganh << endl << endl;
}
void HocSinh::setLop(string newLop)
{
    lop = newLop;
}

void HocSinh::display()
{
    DoiTuong::display();
    cout<< "Lop: "  << lop <<endl <<endl; 
}

void GiaoVien::setSubject(string newSubject)
{
    chuyenMon = newSubject;
}

void GiaoVien::display()
{
    DoiTuong::display();
    cout<< "Chuyen mon: "  << chuyenMon <<endl <<endl; 
}


int main()
{
  
    SinhVien sv1 ; // đối tượng (object) - là những biến được gọi từ class
   
    sv1.setName("Anh");
    sv1.setAge(23);
    sv1.setMajor("DTVT");
   // sv1.display();

    HocSinh hs1;
    hs1.setName("Tuan");
    hs1.setAge(23);
    hs1.setLop("12A");
   // hs1.display();

    GiaoVien gv1;
    gv1.setName("Hoang");
    gv1.setAge(32);
    gv1.setSubject("Toan");
   // gv1.display();

    DoiTuong *dt; 

    dt = &sv1;
    dt->display();
    /* Chỉ in cho mình 3 thông tin
Ten: Anh
Tuoi: 23
ID: 1
    */
    dt = &hs1;
    dt->display();
}
```
* Lý do tại sao mà chỉ in ra 3 thông tin chứ không in ra thông tin setup riêng (chuyên môn, lớp...):
    - Vì ta khai báo __DoiTuong *dt1__ là con trỏ kiểu đối tượng, nên nó gọi hàm display từ clas DoiTuong

1. Ép kiểu từ class cha -> class con: down-casting
```cpp
((SinhVien *)dt)->display(); // down-casting
```

```cpp
   DoiTuong dt1;
   dt = &dt1;

   ((SinhVien*)dt)->display();     
    /* Nếu trong class con có thêm thông tin so với class cha thì sẽ không đủ thông tin để in ra, như ở trường hợp này thì thiếu mất thông tin chuyên ngành */

   ==> Output:
Ten:
Tuoi: 688904752
ID: 4
Chuyen nganh:
```
2. Ép kiểu từ class con -> class cha: up-casting

```cpp
/*< Up-casting */
SinhVien *sv = &sv1;
((DoiTuong*)sv)->display();
```


# Hàm ảo - Virtual function
- Là 1 hàm thành viên được khai báo trong __class cha__.
- Khi 1 hàm là __virtual__, nó có thể ghi đè (__override__) trong class con để cung cấp cách triển khai riêng
- Khi gọi 1 hàm ảo thông quan 1 con trỏ hoặc tham chiếu đến lớn con, hàm sẽ được quyết định dựa trên đối tượng thực tế mà con trỏ đang trỏ tới chứ không phụ thuộc vào con trỏ

```cpp
// Không cần ép kiểu con trỏ nữa vì nó dựa trên thành phần nó đang quản lí

DoiTuong *dt; 

    dt = &sv1;
    dt->display();


==> Output:
    Ten: Anh
    Tuoi: 23
    ID: 1
    Chuyen nganh: DTVT
``` 

### Overload:
- Kế thừa -> mở rộng -> overload: Có thể mở rông thêm cả tham số và cả thông tin bên trong.
- Virtual -> mở rộng -> override -> cung cấp từ khóa 'override'
- Override: giúp người đọc nhận biết hàm này được dùng lại từ Class khác và phải giống __hoàn toàn__ về đặc điểm với hàm cha.

```cpp
class DoiTuong
{
    virtual void display() ;
};
class SinhVien : public DoiTuong
{
   private:
         string chuyenNganh;
   public:
         void setMajor(string newMajor);

         void display() override;
};
```
### Giúp cho trình biên dịch hiểu mình đang định nghĩa lại 1 hàm ảo từ class cha. Hơn nữa, còn giúp ích trong việc đọc code dễ hiểu hơn.

# Hàm thuần ảo - Pure virtual function
- Là 1 __hàm ảo__ không có phần định nghĩa trong class cha, được khai báo với cú pháp = 0 và khiến class cha trở thành __class trừu tượng ( Abstract class)__, nghĩa là không thể tạo đối tượng từ class này.

1. Biến 1 class thành class trìu tượng
2. Bắt buộc những class con phải định nghĩa lại hàm thuần ảo này