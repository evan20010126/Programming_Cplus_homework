/* PRESET CODE BEGIN - NEVER TOUCH CODE BELOW */

#include <iostream>
#include <iomanip>
#include <cmath>
#include <string>
using namespace std;
const double TOL = 1e-10;
class ERR
{
public:
    string msg()
    {
        return "retry";
    }
};
class Point
{
private:
    double x, y;

public:
    Point(double a = 0., double b = 0.) : x(a), y(b) {}
    double getx() { return x; }
    double gety() { return y; }
    friend istream &operator>>(istream &in, Point &pt);
};

istream &operator>>(istream &in, Point &pt)
{
    return in >> pt.x >> pt.y;
}

class Triangle
{
private:
    Point pt1, pt2, pt3;

public:
    Triangle(Point &p, Point &q, Point &r) throw(ERR)
        : pt1(p), pt2(q), pt3(r)
    {
        if (area() < TOL)
            throw ERR();
    }
    double area();
    double perimeter();
    friend ostream &operator<<(ostream &out, Triangle &foo);
};

int main()
{
    Point a, b, c;
    while (1)
    {
        try
        {
            cin >> a >> b >> c;
            Triangle foo(a, b, c);
            cout << foo << endl;
            break;
        }
        catch (ERR &err)
        {
            cout << err.msg() << endl;
        }
    }
    return 0;
}

/* PRESET CODE END - NEVER TOUCH CODE ABOVE*/

double Triangle::area()
{
    double AB_vector_a;
    AB_vector_a = pt2.getx() - pt1.getx();
    double AB_vector_b;
    AB_vector_b = pt2.gety() - pt1.gety();
    double AC_vector_c;
    AC_vector_c = pt3.getx() - pt1.getx();
    double AC_vector_d;
    AC_vector_d = pt3.gety() - pt1.gety();
    // cout << "Hello" << (1 / 2) * abs(AB_vector_a * AC_vector_d - AB_vector_b * AC_vector_c) << "HI" << endl;
    double answer;
    answer = abs(AB_vector_a * AC_vector_d - AB_vector_b * AC_vector_c) / 2;
    return answer;
}

double Triangle::perimeter()
{
    double AB_vector_a = pt2.getx() - pt1.getx();
    double AB_vector_b = pt2.gety() - pt1.gety();
    double AC_vector_c = pt3.getx() - pt1.getx();
    double AC_vector_d = pt3.gety() - pt1.gety();
    double BC_vector_e = pt3.getx() - pt2.getx();
    double BC_vector_f = pt3.gety() - pt2.gety();
    double AB_length = sqrt(AB_vector_a * AB_vector_a + AB_vector_b * AB_vector_b);
    double AC_length = sqrt(AC_vector_c * AC_vector_c + AC_vector_d * AC_vector_d);
    double BC_length = sqrt(BC_vector_e * BC_vector_e + BC_vector_f * BC_vector_f);
    return AB_length + AC_length + BC_length;
}

ostream &operator<<(ostream &out, Triangle &foo)
{
    out << fixed << setprecision(2) << "area = " << foo.area() << endl
        << "perimeter = " << foo.perimeter();
    return out;
}