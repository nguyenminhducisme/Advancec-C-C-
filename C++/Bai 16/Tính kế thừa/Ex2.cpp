#include<iostream>
#include<string>
using namespace std;

// class cha/ class gốc/ base class
class DoiTuong{
    // private:
    protected:
        string ten;
        int id;
        int age;

        bool checkname(string str)
        {
            for(int i = 0; i<str.length(); i++)
            {
                if(isdigit(str[i]) || !isalpha(str[i]))
                {
                    return false;
                }
            }
            return true;
        }
    public:
        DoiTuong()
        {
           DoiTuong dt1;
           dt1.ten = "Anh";
            
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

