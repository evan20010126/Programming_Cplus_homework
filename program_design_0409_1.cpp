#include <iostream>

using namespace std;

struct Parking_Fee
{
    int parking_fee(int hr1, int min1, int hr2, int min2)
    {
        int hour = hr2 - hr1;
        int min = min2 - min1;
        if (min < 0)
        {
            hour -= 1;
            min += 60;
        }
        if (min > 0)
            hour++;
        int SUM = 0;

        if (hour <= 2)
        {
            SUM += hour * 50;
        }
        else if (hour <= 10)
        {
            SUM += 2 * 50;
            SUM += (hour - 2) * 40;
        }
        else
        {
            SUM += 2 * 50;
            SUM += 8 * 40;
            SUM += (hour - 10) * 30;
        }
        return SUM;
    }
};

int main()
{
    Parking_Fee car;
    int hr1, min1, hr2, min2;
    while (cin >> hr1 >> min1 >> hr2 >> min2)
    {
        cout << car.parking_fee(hr1, min1, hr2, min2) << endl;
    }

    return 0;
}