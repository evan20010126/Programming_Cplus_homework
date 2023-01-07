#include <iostream>
using namespace std;
int main()
{
    string input_str;
    int case_num = 1;
    bool is_first = true;
    while (cin >> input_str)
    {
        if (is_first)
        {
            is_first = false;
        }
        else
            cout << endl;
        cout << "AB Circle #" << case_num << ":" << endl;
        case_num++;
        //compute total
        int total_a = 0;
        int total_b = 0;
        for (int i = 0; i < input_str.length(); i++)
        {
            if (input_str[i] == 'a')
                total_a++;
            if (input_str[i] == 'b')
                total_b++;
        }

        for (int i = 0; i < input_str.length(); i++)
        {

            int sub_a = 0, sub_b = 0; //計算到的ij中ab
            int Sub_a, Sub_b;         //剩餘的ab
            for (int j = i + 1; j < input_str.length(); j++)
            {
                if (input_str[j - 1] == 'a')
                    sub_a++;
                if (input_str[j - 1] == 'b')
                    sub_b++;
                Sub_a = total_a - sub_a;
                Sub_b = total_b - sub_b;
                if (sub_a == Sub_b || sub_b == Sub_a)
                {
                    cout << i << "," << j << endl;
                }
            }
        }
    }
    return 0;
}