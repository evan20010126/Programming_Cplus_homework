/* PRESET CODE BEGIN - NEVER TOUCH CODE BELOW */

#include <iostream>
#include <iomanip>
using namespace std;
class matrix
{
private:
    double a11, a12, a21, a22;

public:
    void inverse();
    friend istream &operator>>(istream &, matrix &);
    friend ostream &operator<<(ostream &, matrix &);
};

int main()
{
    matrix matrix_A;
    cin >> matrix_A;
    matrix_A.inverse();
    cout << matrix_A;
}

/* PRESET CODE END - NEVER TOUCH CODE ABOVE*/

void matrix::inverse()
{
    double delta = a11 * a22 - a12 * a21;
    if (delta == 0)
    {
        a11 = -99999;
        a12 = -99999;
        a21 = -99999;
        a22 = -99999;
    }
    else
    {
        int temp_A_element;
        temp_A_element = a11;
        a11 = a22 / delta;
        a22 = temp_A_element / delta;
        a21 = -a21 / delta;
        a12 = -a12 / delta;
    }
}

istream &operator>>(istream &in, matrix &A)
{
    in >> A.a11 >> A.a12 >> A.a21 >> A.a22;
    return in;
}

ostream &operator<<(ostream &out, matrix &A)
{
    if (A.a11 == -99999)
    {
        out << "singular matrix" << endl;
    }
    else
    {
        out << fixed << setprecision(1) << A.a11 << " " << A.a12 << "\n"
            << A.a21 << " " << A.a22 << "\n";
    }
    return out;
}