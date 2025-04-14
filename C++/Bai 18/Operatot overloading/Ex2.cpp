#include<iostream>
using namespace std;

class PhanSo
{
    private:
        int tuso;
        int mauso;
    public:
        PhanSo(int num = 0, int den = 1): tuso(num), mauso(den){}

        PhanSo operator + (const PhanSo &other) const
        {
            // PhanSo::tuso = 10;
             PhanSo ketqua;

            ketqua.tuso = PhanSo::tuso * other.mauso + PhanSo::mauso * other.tuso;
            ketqua.mauso = PhanSo::mauso *other.mauso;

            // p1 + ----> Phanso::tuso = 1, PhanSo::mauso = 2;

            return ketqua;
        }

        bool operator == (const PhanSo other) const
        {
            return PhanSo::tuso == other.tuso;
        }

        void display() const
        {
            
            cout << tuso << "/" << mauso << endl;
        }
};

int main()
{
    PhanSo p1(1, 2); // 1/2
    PhanSo p2(3, 4); // 3/4
    PhanSo p3 = p1 + p2; // tu so: 1*4 + 2*3 = p1.tuso * p2.mauso  + p1.mauso * p2.tuso
    PhanSo p4 = p1 + p1 + p1;
    p3.display();
    p1.display();
    p2.display();
    p4.display();
    return 0;
}