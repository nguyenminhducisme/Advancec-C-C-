#include<iostream>
#include<list>

using namespace std;

int main()
{
    list<int> lst = {1, 2, 3, 4, 5};

    lst.push_back(10);
    lst.push_back(15);
    lst.push_back(20);
    lst.push_front(25);

    // for(int i = 0; i < list.size(); i++)
    // {
    //     cout << list;
    // }

    // range-based for loop
    for (const auto& item: lst)
    {
        cout << item << " ";
    }
    cout << endl;

   

    // iterator
    list<int>::iterator it;

    for(it = lst.begin(); it != lst.end(); it ++)
    {
        cout << *it << " ";
    }
    cout << endl;

    for(it = lst.end(); it != lst.begin(); it --)
    {
        cout << *it << " ";
    }
    cout << endl;
    // ==> Output: 6 10 5 4 3 2 Tại sao lại có giá trị 6 ?

    lst.insert(lst.begin(), 12); // push front
    lst.insert(lst.end(), 13); // push back

    // lst.insert(lst.begin() + 1, 150); WRONG

    it = lst.begin();
    int index = -1;
    for(it = lst.begin(); it != lst.end(); it ++)
    {
        ++index;
        if(index == 4)
        {
            lst.insert(it, 150);
        }
    }

    lst.remove(3);

    // Cách 1: Sử dụng auto
    for(auto it1 = lst.rbegin(); it1 != lst.rend(); it1 ++)
    {
        cout << *it1 << " ";
    }
    cout << endl;
    
    /*
    r trong rend hay rbegin là reverse
    */
    // Cách 2: Sử dụng reverse iterator
    list<int> ::reverse_iterator rit;
    for (rit = lst.rbegin(); rit != lst.rend(); rit ++)
    {
        cout << *rit << " ";
    }
    cout << endl;

    it = lst.end();
    while(it != lst.begin())
    {
        cout << *(--it) << " ";
    }

    

    return 0;
}