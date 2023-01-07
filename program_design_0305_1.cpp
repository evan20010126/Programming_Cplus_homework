#include <iostream>
#include <iomanip>
using namespace std;

int main()
{
    int number;
    cin >> number;
    int input;
    for (int i = 0; i < number; i++)
    {
        cin >> input;
        cout << fixed << setprecision(2) << input * 3.306 << " " << input * 3.95 << endl;
    }
    return 0;
}