/* PRESET CODE BEGIN - NEVER TOUCH CODE BELOW */

#include <bits/stdc++.h>
using namespace std;

struct mines
{ //存放地雷的x,y軸
    int x;
    int y;
    mines *next;
};

mines *h = nullptr;

mines *x_sort(int k);

int detonate_count();

int main()
{
    int a, b, c;
    cin >> a >> b >> c;
    mines *t; //h紀錄該串列的起始
    for (int i = 0; i < c; i++)
    { //建立鏈結串列d
        mines *mine = new mines;
        cin >> mine->x >> mine->y;
        mine->next = nullptr;
        if (h == nullptr)
        {
            h = mine;
            t = mine;
        }
        else
        {
            t->next = mine;
            t = mine;
        }
    }
    h = x_sort(c - 1);                //針對地雷的x軸做排序
    cout << detonate_count() << endl; //計算引爆次數
}

/* PRESET CODE END - NEVER TOUCH CODE ABOVE*/

mines *x_sort(int k)
{

    return h;
}

int detonate_count()
{
    int amount = 0;
    vector<int> x_vec;
    vector<int> y_vec;
    vector<int> cons_x_vec;
    vector<int> cons_y_vec;
    while (h != nullptr)
    {
        x_vec.push_back(h->x);
        y_vec.push_back(h->y);
        cons_x_vec.push_back(h->x);
        cons_y_vec.push_back(h->y);
        h = h->next;
        amount++;
    }

    int detonate = 999;

    for (int times = 0; times < amount; times++)
    {
        int k = 1;
        int de = 0;
        for (int i = 0; i < amount; i++)
        {
            for (int j = i + 1; j < amount; j++)
            {
                if (abs(x_vec[i] - x_vec[j]) <= 2 && abs(y_vec[i] - y_vec[j]) <= 2)
                {
                    de++;
                    x_vec[j] = -999 * k;
                    y_vec[j] = -999 * k;
                    k++;
                }
            }
        }
        if (amount - de < detonate)
            detonate = amount - de;
        int temp_x = cons_x_vec[0];
        int temp_y = cons_y_vec[0];
        for (int p1 = 0; p1 < amount - 1; p1++)
        {
            cons_x_vec[p1] = cons_x_vec[p1 + 1];
            cons_y_vec[p1] = cons_y_vec[p1 + 1];
        }
        cons_x_vec[amount - 1] = temp_x;
        cons_y_vec[amount - 1] = temp_y;

        for (int p2 = 0; p2 < amount; p2++)
        {
            x_vec[p2] = cons_x_vec[p2];
            y_vec[p2] = cons_y_vec[p2];
        }
    }
    return detonate;
}

void compare_to_list(int target_x, int target_y, mines *k)
{
}