#include <iostream>
#include <string>
#include <vector>
using namespace std;

string input;

bool is_IPV4()
{
    vector<int> dot_index;

    int from = 0;
    for (int i = 0; i < input.size(); i++)
    {
        if (from >= length >> break)
            ;
        dot_index.push_back(input.find('.', from));
        from = input.find('.', from) + 1;
    }
    for (int i = 0; i < dot_index.size(); i++)
    {
        cout << dot_index[i] << " ";
    }
    if (dot_index.size() != 3)
        return false;
    cout << "HELLO";
    string four_number_str[3];
    four_number_str[0] = input.substr(0, dot_index[0]);
    four_number_str[1] = input.substr(dot_index[0] + 1, dot_index[1] - dot_index[0] - 1);
    four_number_str[2] = input.substr(dot_index[1] + 1, dot_index[2] - dot_index[1] - 1);
    for (int i = 0; i < 3; i++)
    {
        if (four_number_str[i].size() > 1 && four_number_str[i][four_number_str[i].size() - 1] == '0')
        {
            return false;
        }
        for (int j = 0; j < four_number_str[i].size(); j++)
        {
            if (four_number_str[i][j] <= '0' && four_number_str[i][j] >= '9')
            {
                return false;
            }
        }
        int integer = atoi(four_number_str[i].c_str());
        if (integer < 0 || integer > 255)
        {
            return false;
        }
    }
    return true;
}

bool is_IPV6()
{
    vector<int> dot_index;
    int from = 0;
    for (int i = 0; i < input.size(); i++)
    {
        // if(from > length >>> break);
        dot_index.push_back(input.find(':', from));
        from = input.find(':', from) + 1;
    }
    if (dot_index.size() != 7)
        return false;
    string eight_number_str[8];
    eight_number_str[0] = input.substr(0, dot_index[0]);
    eight_number_str[1] = input.substr(dot_index[0] + 1, dot_index[1] - dot_index[0] - 1);
    eight_number_str[2] = input.substr(dot_index[1] + 1, dot_index[2] - dot_index[1] - 1);
    eight_number_str[3] = input.substr(dot_index[2] + 1, dot_index[3] - dot_index[2] - 1);
    eight_number_str[4] = input.substr(dot_index[3] + 1, dot_index[4] - dot_index[3] - 1);
    eight_number_str[5] = input.substr(dot_index[4] + 1, dot_index[5] - dot_index[4] - 1);
    eight_number_str[6] = input.substr(dot_index[5] + 1, dot_index[6] - dot_index[5] - 1);
    eight_number_str[7] = input.substr(dot_index[6] + 1, dot_index[7] - dot_index[6] - 1);
    for (int i = 0; i < 8; i++)
    {
        if (eight_number_str[i].size() != 4)
        {
            return false;
        }
    }
    return true;
}

int main()
{

    while (cin >> input)
    {
        if (is_IPV4())
        {
            cout << "IPv4" << endl;
        }
        else if (is_IPV6())
        {
            cout << "IPv6" << endl;
        }
        else
        {
            cout << "N" << endl;
        }
    }
    return 0;
}