#include <iostream>
#include <iomanip>
using namespace std;

int main()
{
    int D;
    while (cin >> D)
    {
        int amount = 70;
        if (D <= 1500)
        {
            cout << amount << endl;
        }
        else
        {
            while (D > 1500)
            {
                D -= 500;
                amount += 5;
            }
            cout << amount << endl;
        }
    }
    return 0;
}