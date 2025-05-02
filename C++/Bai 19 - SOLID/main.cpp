#include <iostream>
#include <string>
using namespace std;

// Chưa thông tin sản phẩm
class Product
{
    protected:
        int id;
        string name;
        double price;
   
    public:
        Product(int id, string name, double price)
            : id(id), name(name), price(price){}

        virtual void display() const
        {
            cout << "ID: " << id << " - Name: " << name << " - Price: " << price << endl;
        }
};

// Interface chung về giảm giá
class IDiscount
{
    public:
        virtual double applyDiscount(double price) = 0;
};

// Không có giảm giá
class NoDiscount : public IDiscount
{
    public:
        double applyDiscount(double price) override
        {
            return price;
        }
};  

// Giảm giá tết (10%)
class HolidayDiscount : public IDiscount
{
    public:
        double applyDiscount(double price) override
        {
            return price * 0.9;
        }
};

// Interface lưu trữ sản phẩm
class IProductStorage
{
    public:
        virtual void save(const Product *product) = 0;
};

// Lưu trữ vào RAM
class MemoryStorage : public IProductStorage
{
    private:
        Product *product1;
        Product *product2;

    public:
        MemoryStorage() : product1(nullptr), product2(nullptr){}

        void save(const Product *product) override
        {
            cout << "Lưu trữ thông tin vào RAM\n";

            if (!product1)
            {
                product1 = new Product(*product);
            }
            else if (!product2)
            {
                product2 = new Product(*product);
            }
        }

        ~MemoryStorage()
        {
            // Giải phóng bộ nhớ
            delete product1;
            delete product2;
        }
};

// Interface đọc thông tin sản phẩm sau khi lưu
class IProductReader
{
    public:
        virtual Product* getProduct1() = 0;
        virtual Product* getProduct2() = 0;
       
};

class ReadProduct : public IProductReader
{
    private:
        Product *product1;
        Product *product2;

    public:
        ReadProduct(Product* p1, Product* p2)
            : product1(p1), product2(p2) {}

        // hiển thị sản phẩm
        Product* getProduct1() override
        {
            return product1;
        }

        Product* getProduct2() override
        {
            return product2;
        }
};

// Sản phẩm vật lý
class PhysicalProduct : public Product
{
    public:
        PhysicalProduct(int id, string name, double price)
            : Product(id, name, price){}

        void display() const override
        {
            cout << "Physical!\n";
            Product::display();
        }
};

// Sản phẩm kỹ thuật số
class DigitalProduct : public Product
{
    public:
        DigitalProduct(int id, string name, double price)
            : Product(id, name, price){}

        void display() const override
        {
            cout << "Digital!\n";
            Product::display();
        }
};

// Interface chung cho việc vận chuyển sản phẩm
class IShippable
{
    public:    
        virtual void ship() = 0;
};

// Sản phẩm có thể vận chuyển
class ShippableProduct : public PhysicalProduct, public IShippable
{
    public:
        ShippableProduct(int id, string name, double price)
            : PhysicalProduct(id, name, price){}

        void ship() override
        {
            cout << "Shipping product: " << name << endl;
        }
};

int main()
{
    // Tạo sản phẩm
    Product *p1 = new PhysicalProduct(1, "Milk", 1.5);
    Product *p2 = new DigitalProduct(2, "E-Book", 4.5);

    // Lưu trữ sản phẩm
    IProductStorage *storage = new MemoryStorage();

    // thêm sản phẩm vào bộ nhớ
    storage->save(p1);
    storage->save(p2);

    // Đọc sản phẩm từ bộ nhớ
    ReadProduct *reader = new ReadProduct(p1, p2);

    // hiển thị sản phẩm
    cout << endl;
    cout << "Thông tin sản phẩm\n";
    reader->getProduct1()->display();
    reader->getProduct2()->display();

    // Áp dụng giảm giá
    cout << endl;
    IDiscount* discount = new HolidayDiscount();
    cout << "Giá sau khi giảm: $" << discount->applyDiscount(1.5) << endl;
    cout << "Giá sau khi giảm: $" << discount->applyDiscount(2) << endl;

    // Tạo sản phẩm có thể vận chuyển
    cout << endl;
    ShippableProduct* p3 = new ShippableProduct(3, "Break", 1000);
    p3->ship();

    // Giải phóng bộ nhớ để tránh rò rỉ
    delete p1,p2;
    delete storage;
    delete reader;
    delete discount;

    return 0;
}

