#include <iostream>
#include <map>
using namespace std;

// template <typename T1, typename T2>
// class pair
// {
//     T1 a;
//     T2 b;         bản chất của pair
// };

int main()
{
    pair<int, int> p = {1, 2};
    cout << p.first << endl << p.second << endl;

    pair<pair<int, int>, string> p1 = {{1, 2}, "abc"};

    cout << p1.first.first << " "<< p1.first.second << " " << p1.second << endl;

    // cách khai báo thứ nhất
    map<string, string>arr =
    {
        {"one", "Tuan"},
        {"two", "Minh"}
    };
/**
 * key duy nhất, nếu key giống nhau, thì lấy cặp key-value sau cùng
 * key khi truy xuất thì sẽ sắp xếp từ nhỏ đến lớn, chứ không theo thứ tự khai báo
 * Example
key: one - value: Anh
key: three - value: Hoang
key: two - value: Trung

 */
    // cách khai báo thứ hai
    arr["one"] = "Anh" ;// Cặp key-value 1
    arr["two"] = "Trung" ;// cặp key-value 2
    arr["three"]= "Hoang";

    for(const auto& item : arr)
    {
        cout << "key: " << item.first << " - value: " << item.second << endl; // first là key, second là value
    }
    cout << endl;

    // Cách in thứ 2:
    for(const auto& [k, v] : arr)
    {
        cout << "Key: " << k << "- value: " << v << endl;
    }

    cout << endl;
    // cách 3: dùng iterator
    map <string, string> :: iterator it;

    for(it = arr.begin(); it != arr.end(); it++)
    {
        cout << "key" << (*it).first << " - value: " << (*it).second << endl;
    }

    cout << endl;

    arr.erase("one");

    for(it = arr.begin(); it != arr.end(); it++)
    {
        cout << "key: " << (*it).first << " - value: " << (*it).second << endl;
    }
    return 0;
}