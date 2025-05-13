#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
    // vector<int> vec = {3, 1, 5, 9, 8};

    // sort(vec.begin(), vec.end(), [](int i, int j){return i<j;});

    // for(const auto& item : vec)
    // {
    //     cout << item << endl;
    // }
    // cout << endl;

    vector<int> vec = {1,3 ,4, 6, 7, 10};

    int count_odds = 0;
    int count_even = 0;

    vector<int> odds, evens;

    count_if(vec.begin(), vec.end(), [&](int x)
{
    if(x%2 == 0)
    {
        count_even ++;
        evens.push_back(x);
    }
    else{
        count_odds ++;
        odds.push_back(x);
    }

    return false;
});


    cout << "So luong so le la: " << count_odds << endl;
    for(const auto& item: odds)
    {
        cout << item<< " ";
    }
    cout << endl;




    return 0;
}