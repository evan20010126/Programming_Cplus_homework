/* PRESET CODE BEGIN - NEVER TOUCH CODE BELOW */

#include <iostream>
#include <iomanip>
using namespace std;
const int MAX_MINUTE = 10;
class Timer
{
private:
    int min, sec;

public:
    Timer() : min(0), sec(0) {}

    Timer(int s) : min(s / 60), sec(s % 60)
    {
        while (min >= MAX_MINUTE)
            min -= MAX_MINUTE;
    }

    Timer(int m, int s) : min(m), sec(s)
    {
        while (min >= MAX_MINUTE)
            min -= MAX_MINUTE;
    }

    Timer operator++();
    Timer operator--(int);
    friend Timer operator+(const Timer &a, const Timer &b);
    friend ostream &operator<<(ostream &out, const Timer &foo);
};

int main()
{

    int input_1, input_2;
    Timer foo;
    while (cin >> input_1 >> input_2)
    {
        foo = foo + input_1;
        cout << foo << endl;
        foo = input_2 + foo;
        cout << foo << endl;
        cout << ++foo << endl;
        foo = input_2;
        for (int i = input_2; i >= 0; --i)
            cout << foo-- << endl;
    }

    return 0;
}

/*ostream& operator<< (ostream& out, const Timer& foo) {
  
}
Timer  operator+ (const Timer& a, const Timer& b) {
   
}
Timer  Timer::operator++ () {
   
}
Timer  Timer::operator-- (int) {
    
}*/

/* PRESET CODE END - NEVER TOUCH CODE ABOVE*/

ostream &operator<<(ostream &out, const Timer &foo)
{
    out << setw(2) << setfill('0') << foo.min << " : " << setw(2) << setfill('0') << foo.sec;
    return out;
}
Timer operator+(const Timer &a, const Timer &b)
{
    //plus sec

    Timer temp;
    temp.min = a.min + b.min;
    int temp_sec = a.sec + b.sec;
    if (temp_sec >= 60)
    {
        temp_sec -= 60;
        (temp.min)++;
        temp.sec = temp_sec;
    }
    else
    {
        temp.sec = temp_sec;
    }

    return temp;
}
Timer Timer::operator++()
{
    (this->sec)++;
    if (this->sec == 60)
    {
        this->min++;
        this->sec -= 60;
    }
    return *this;
}
Timer Timer::operator--(int)
{
    Timer R = (*this);
    (this->sec)--;
    if (this->sec < 0)
    {
        this->sec = 59;
        this->min--;
    }
    return R;
}