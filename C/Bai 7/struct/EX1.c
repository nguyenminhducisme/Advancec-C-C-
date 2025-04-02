#include<stdio.h>
#include<stdint.h>
// struct SinhVien
// {
//     char *name;
//     int    age;
//     double gpa;
// };

// struct  SinhVien sv1, sv2, sv3;
typedef struct 
{
    double x;
    short y;
    short z;
    short a;
}SinhVien;

// SinhVien sv1, *sv2, sv3;

int main()
{
    // sv1.name = "anh";
    // sv1.age  = 23;
    // sv1.gpa  = 8.0;
    // printf("Ten sinh vien 1: %s\n", sv1.name);
    
    // sv2->name = "Trung";
    // sv2->age  = 30;
    // sv2->gpa  = 7.8;
    // printf("Ten sinh vien 2: %s\n", sv2->name);
    printf("%d", sizeof(SinhVien));

    return 0;
}