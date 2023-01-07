#include <iostream>
#include <string>
#include <vector>
using namespace std;

vector<string> vec1;

int find_in_vec(string element)
{
    for (int i = 0; i < vec1.size(); i++)
    {
        if (vec1[i] == element)
            return i;
    }
    return -1;
}

int main()
{
    string input;
    int num;
    cin >> input;
    cin >> num;

    vector<int> vec2;
    for (int i = 0; i < input.size() - num + 1; i++)
    {
        string input_sub = input.substr(i, num);
        int index = find_in_vec(input_sub);
        if (index < 0)
        {
            vec1.push_back(input_sub);
            vec2.push_back(1);
        }
        else
        {
            vec2[index]++;
        }
    }
    for (int i = 0; i < vec1.size(); i++)
    {
        cout << "> " << vec1[i] << " : " << vec2[i] << endl;
    }

    return 0;
}
