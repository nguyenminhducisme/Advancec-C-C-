#include <iostream>
using namespace std;


// void print()
// {
//     cout << "I am empty function and "
//             "I am called at last.\n";
// }

template <typename T1, typename... Types>
void print(T1 var1, Types... var2)
{
    cout << var1 << endl;
    (cout << ... << var2) << endl;
    // fold expression
    print(1, 2, 3, "Hi\n");
}

int main()
{
    print(1, "Hello world\n", "Hello world\n", "Pass me any params\n");
    return 0;
}