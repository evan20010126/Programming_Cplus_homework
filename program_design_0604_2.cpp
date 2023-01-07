#include <iostream>
#include <iomanip>
#include <string>
#include <sstream>
#include <algorithm>
#include <vector>
using namespace std;

struct Time
{
    int hr, min;
    Time(int h, int m) : hr(h), min(m) {}
    Time(const string &time)
    {
        char ch;
        istringstream foo(time); //使用sstream 建立一個流foo
        foo >> hr >> ch >> min;
    }
};

template <class T>
struct compare
{
    bool operator()(const T &a, const T &b) const
    {
        if (static_cast<Time>(a).hr != static_cast<Time>(b).hr)
        {
            return static_cast<Time>(a).hr < static_cast<Time>(b).hr;
        }
        else
        {
            return static_cast<Time>(a).min < static_cast<Time>(b).min;
        }
    }
};

int main()
{
    //Time tt[10]();
    vector<Time> time_vec;

    vector<int> hr_vec;
    vector<int> min_vec;
    string input;
    while (cin >> input)
    {
        Time temp(input);
        time_vec.push_back(temp);
        //hr_vec.push_back(temp.hr);
        //min_vec.push_back(temp.min);
    }
    sort(time_vec.begin(), time_vec.end(), compare<Time>());
    // int hr_arr[hr_vec.size()];
    // int min_arr[min_vec.size()];
    // for (int i = 0; i < hr_vec.size(); i++)
    // {
    //     hr_arr[i] = hr_vec[i];
    //     min_arr[i] = min_arr[i];
    // }
    // if (time_vec[0].hr < 10)
    //     cout << "0";
    // cout << time_vec[0].hr << ":";
    // if (time_vec[0].min < 10)
    //     cout << "0";
    // cout << time_vec[0].min;
    for (int i = 0; i < time_vec.size(); i++)
    {
        if (time_vec[i].hr < 10)
            cout << "0";
        cout << time_vec[i].hr << ":";
        if (time_vec[i].min < 10)
            cout << "0";
        cout << time_vec[i].min << " ";
    }
    cout << endl;
    return 0;
}