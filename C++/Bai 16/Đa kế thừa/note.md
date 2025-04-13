- Kế thừa nhiều class khác nhau
```cpp
#include<iostream>
#include<string>
using namespace std;

// class cha/ class gốc/ base class
class DoiTuong{
    // private:
    protected:
        string ten;
        int id;
    public:
        DoiTuong()
        {
            DoiTuong dt1;
            
        }
};

// class con / class dẫn xuất
class SinhVien : protected DoiTuong // Ta muốn kế thừa class DoiTuong
{
    private:
        string chuyenNganh;
    public:
        SinhVien()
        {
            SinhVien sv1;
            sv1.ten = "Anh";
        }
};

class HocSinh: protected  DoiTuong // Ta muốn kế thừa class DoiTuong
{
    public:
        
        string lop;
};

class GiaoVien: protected  DoiTuong // Ta muốn kế thừa class DoiTuong
{
    public:
        
        string chuyenMon;
};

int main()
{
    DoiTuong dt;


    SinhVien sv1;
    HocSinh hs1;
   // hs1.ten = "Anh"; Không thể sử dụng được vì biến đó nằm trong private

    return 0;
}

```