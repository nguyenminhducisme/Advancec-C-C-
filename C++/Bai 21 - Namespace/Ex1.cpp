#include <iostream>
using namespace std;


namespace std
{
    int x = 10;
    int a = 4;
}

namespace A{
    char *name = (char*)"Anh 20";

    void display(){
        cout << "Name: " << name << endl;
    }

    namespace C{
        void display()
        {
            cout << "Hello world 1\n";
        }
    }
}
namespace B{
    char *name = (char*)"Anh 21";

    void display(int a, double b){
        cout << "Name: " << name << endl;
    }
}

namespace A{
    int x;
    int y;
}

using namespace A;
// using namespace B; 
/*
=====> "name is ambigous"
*/

int main(){
    cout << "Name: " << name << endl;
    cout << "Name: " << B::name << endl;
    A::display();
    B::display(3, 5);
    A::C::display();
    A::x = 5;
    cout << A::x << endl;
    cout << std::x << endl;
    return 0;
}


