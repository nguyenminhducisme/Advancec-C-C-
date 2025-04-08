#ifndef EX1_HPP
#define EX1_HPP

#include <iostream>
#include <string>
using namespace std;

class SinhVien
{
public:
    string name;     // thuộc tính (property)
    int age;

    void display();  // phương thức (method)

    // Constructor
    // SinhVien();    // hàm khởi tạo mặc định không có tham số
    // constructor có tham số
    // SinhVien(string newName, int newAge);
    /*
    - Trong constructor có tham số chia ra thành 2 loại nhỏ:
    + Có giá trị mặc định: SinhVien(string newName = " ", int newAge = 18)
    + Không có giá trị mặc định: SinhVien(string newName, int newAge);
    */
   // có giá trị mặc định
   SinhVien(string newName = " ", int newAge = 18);
   
   // Destructor
   ~SinhVien();
};

#endif // EX1_HPP
