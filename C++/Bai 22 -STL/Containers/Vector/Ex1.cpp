#include<iostream>
#include<vector>

using namespace std;

int main()
{
    // vector<int> v = {1, 2, 3, 4, 5};
    vector<int> v(5);
    cout << "Amount of members: " << v.size() << endl;
    v.at(1) = 3;
    cout << "Value of member 1: " << v.at(1)<< endl;

    // Cách 1:
    for(int i= 00; i<v.size(); i++)
    {
        cout<< v.at(i) << " ";
    }
    cout << endl;

   
    v.pop_back();
    v.push_back(13);
    v.insert(v.begin()+2, 5);
    v.insert(v.end(), 43);

    for(const int& item : v)
    {
        cout << item<< " ";
    }
    cout << endl;
    // v.erase(v.begin()); // pop_front
    // v.erase(v.end() -1); // pop_back

    v.erase(v.begin(), v.begin() + 2); // xóa các phần tử trong khoảng này
    // v.resize(4);

    // Cách 2: range-based for loof (for cải tiến)
    for(const int& item : v)
    {
        cout << item<< " ";
    }
    cout << endl;

    // Cách 3:
    vector<int>::iterator it;

    for(it = v.begin(); it != v.end(); it++)
    {
        cout << *it << " ";
    }

   /*
    template <typename T>
    class vector
    {
       
    }
    */

    return 0;
}