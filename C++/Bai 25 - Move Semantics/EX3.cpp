#include <iostream>
using namespace std;


class User
{
    private:
        int *id;	// raw pointer


    public:
        // constructor
        User(int i){ id = new int(i); }


        // Copy constructor
        User(const User& other)
        {
            this->id = other.id;
            display();
        }

        // Move constructor
        User(User &&other)
        {
            this->id = other.id;
            other.id = nullptr;
            cout << "This is move constructor\n";
        }

        // Move assignment operator
        User operator = (User &&other)
        {
            if(this != &other)
            {
                this->id = other.id;
                other.id = nullptr;
                cout << "this is move assignment operator\n";
            }
            return *this;
        }

        // Copy assignment operator
        User operator = (const User& other)
        {
            if(this != &other)
            {
                this->id = other.id;
                cout << "this is assignment\n";
            }
            return *this;
        }

        void display() const
        {
            cout << "id = " << id << endl;
        }
};
   
int main()
{
    User a(2);
    // User b = a;  // Copy constructor được gọi (vừa khởi tạo vừa sao chép thì cái này được gọi)
    User b(3);
    b = a; // còn khởi tạo xong mới gán thì copy assignment operator

    User c = move(a); // move constructor được gọi
    User d(5);
    d = move(c);
    /**
     * hàm move có 1 chức năng duy nhất:
     * Chuyển đổi 1 lvalue thành 1 rvalue (nhưng chỉ tạm thời)
     */

    a.display();
    b.display();
    c.display();
    d.display();


    return 0;
}
