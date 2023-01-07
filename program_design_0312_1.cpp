#include <iostream>
#include <string>
using namespace std;

int main()
{
    string str;
    while (cin >> str)
    {
        int arr[10];
        int j = 0;
        int check;
        for (int i = 0; i < 13; i++)
        {
            if (i == 1 || i == 5 || i == 11)
            {
                continue;
            }
            if (str[i] == 'X')
            {
                arr[j] = 10;
                j++;
            }
            else
            {
                arr[j] = str[i] - 48;
                j++;
            }
        }

        /*
        for (int i = 0; i<10; i++){
            cout << arr[i];
        }
        */
        check = (arr[0] * 1 + arr[1] * 2 + arr[2] * 3 + arr[3] * 4 + arr[4] * 5 + arr[5] * 6 + arr[6] * 7 + arr[7] * 8 + arr[8] * 9) % 11;
        if (arr[9] == check)
        {
            cout << "OK";
        }
        else
        {
            for (int i = 0; i < 12; i++)
            {
                cout << str[i];
            }
            if (check == 10)
            {
                cout << 'X';
            }
            else
            {
                cout << check;
            }
        }

        cout << endl;
    }
    return 0;
}