 #include <iostream>
using namespace std;

template<typename T1, typename T2>
class Test
{
    private:
        int a;
    public:
        Test(int _a = 0) : a(_a){
            cout << "this is constructor\n";
        }
        void operator ()(){cout << "Test: \n";}
        void operator ()(T1 x){cout << "Test: x = " << x << endl;}
        void operator ()(T1 x, T2 y){cout << "Test: x = " << x << "Test y =" << y << endl;}
};

int main()
{
    

    // Cách 1: Cách gọi operator
    Test<int, double>()();  // gọi operator không có tham số
    Test<int, double>()(1); // gọi operator có 1 tham số

    // Cách 2
    Test<int, double> test;
    test();
    test(1);

    Test<int, int> test1(2); // Đây là constructor chứ không phải operator có 1 tham số
    

}