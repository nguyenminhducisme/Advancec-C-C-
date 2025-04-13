#include "Ex1.hpp"




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
    sv1.display();

    HocSinh hs1;
    hs1.setName("Tuan");
    hs1.setAge(23);
    hs1.setLop("12A");
    hs1.display();

    GiaoVien gv1;
    gv1.setName("Hoang");
    gv1.setAge(32);
    gv1.setSubject("Toan");
    gv1.display();
    return 0;
}