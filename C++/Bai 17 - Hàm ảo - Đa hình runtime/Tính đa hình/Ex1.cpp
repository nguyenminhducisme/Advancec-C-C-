#include "Ex1.hpp"




void DoiTuong::display() const
{
    cout << "Ten: " << name << endl;
    cout << "Tuoi: "<< age << endl;
    cout << "ID: "  << id << endl;
}

void SinhVien::setMajor(string newMajor)
{
    chuyenNganh = newMajor;
}

void SinhVien::display() const
{
    DoiTuong::display();
    cout << "Chuyen nganh: " <<chuyenNganh << endl << endl;
   
}
void HocSinh::setLop(string newLop)
{
    lop = newLop;
}

void HocSinh::display() const
{
    DoiTuong::display();
    cout<< "Lop: "  << lop <<endl <<endl; 
}

void GiaoVien::setSubject(string newSubject)
{
    chuyenMon = newSubject;
}

void GiaoVien::display() const
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
    //sv1.display();

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

    // dt = &sv1;
    // dt->display();
    /* Chỉ in cho mình 3 thông tin
Ten: Anh
Tuoi: 23
ID: 1
    */
 

 

    return 0;
}