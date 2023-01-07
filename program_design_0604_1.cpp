#include <iostream>
#include <cmath>
using namespace std;
//設計樣板
/*write code here
    template <typename T> //可自由設計樣板sum, abs_sum,product, compute
    ...
    …*/

template <class T>
int sum(T foo[], T size)
{
    int answer = 0;
    for (int i = 0; i < size; i++)
    {
        answer += foo[i];
    }
    return answer;
}

template <class T>
int abs_sum(T foo[], T size)
{
    int answer = 0;
    for (int i = 0; i < size; i++)
    {
        answer += abs(foo[i]);
    }
    return answer;
}

template <class T>
int product(T foo[], T size)
{
    int answer = 1;
    for (int i = 0; i < size; i++)
    {
        answer *= foo[i];
    }
    return answer;
}

template <class F, class V>
V compute(F Fn, V foo[], V s, V v)
{
    v = Fn(foo, s);
    return v;
}

//
int main()
{ //請勿更動main()函式裡的程式碼
    int foo[10];
    int S;
    cin >> S;
    for (int i = 0; i < S; i++)
        cin >> foo[i];
    int v;
    v = 0;
    cout << compute(sum<int>, foo, S, v) << endl;
    v = 0;
    cout << compute(abs_sum<int>, foo, S, v) << endl;
    v = 1;
    cout << compute(product<int>, foo, S, v) << endl;
    return 0;
}
