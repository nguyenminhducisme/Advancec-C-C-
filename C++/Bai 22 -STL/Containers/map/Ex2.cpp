#include <iostream>
#include <map>
#include <string>
using namespace std;

typedef struct
{
    string name;
    int age;
    string lop;
} SinhVien;

int main(int argc, char const *argv[])
{
    map<string, SinhVien> Database =
    {
        {
            "SV101", {
                "Tuan",
                21,
                "CDT"
            }
        },
        {
            "SV100", {
                "Hoang",
                20,
                "DDT"
            }
        },
        
        {
            "SV102", {
                "Anh",
                22,
                "KTMT"
            }
        }
    };

    for (auto item : Database)
    {
        cout << "ID: " << item.first << " - Ten: " << item.second.name << " - Tuoi: " << item.second.age << " - Lop: " << item.second.lop << endl;
    }
    return 0;
}

