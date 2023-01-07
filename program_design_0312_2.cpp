#include <iostream>
#include <math.h>
#include <cmath>
#include <iomanip>
using namespace std;

int main()
{
    int number;
    int n;
    double p;
    int i;
    cin >> number;
    for (int k = 0; k < number; k++)
    {
        cin >> n >> p >> i;
        double q = (1 - p);
        double answer = pow(q, (i - 1)) * p / (1 - pow(q, n));
        cout << fixed << setprecision(4) << answer << endl;
    }

    return 0;
}