#include <iostream>
#include <iomanip>
#include <stdlib.h>
using namespace std;

// 使用全域變數
//queen : 皇后位置
class Queens
{
private:
    int counter;      //計算符合擺法的總數
    bool queen[8][8]; //儲存皇后位置，若該座標為皇后設為ture
    // 檢查新的皇后若擺放在 (r,c) 位置是否適當
    bool valid_position(int r, int c)
    {
        // 檢查是否與已有的皇后在同一行, 同一列或在對角線上
        //若有在同一行、同一列或對角線的話回傳false，反之回傳true
        /*---------------------------------*/
        for (int i = 0; i < 8; i++)
        {
            if (queen[r][i] == true || queen[i][c] == true)
            {
                return false;
            }
        }

        int k = 1;
        while (r - k >= 0 && c + k <= 7)
        {
            if (queen[r - k][c + k] == true)
            {
                return false;
            }
            k++;
        }

        k = 1;
        while (r - k >= 0 && c - k >= 0)
        {
            if (queen[r - k][c - k] == true)
            {
                return false;
            }
            k++;
        }

        k = 1;
        while (r + k <= 7 && c - k >= 0)
        {
            if (queen[r + k][c - k] == true)
            {
                return false;
            }
            k++;
        }

        k = 1;
        while (r + k <= 7 && c + k <= 7)
        {
            if (queen[r + k][c + k] == true)
            {
                return false;
            }
            k++;
        }
        return true;
        /*---------------------------------*/
    }

public:
    //建立建構函式，將counter初值設為0,queen陣列所有元素設為false
    /*---------------------------------*/
    Queens();

    /*---------------------------------*/

    // int amount = 1;
    // 遞迴找尋皇后位置

    // int stack[8];

    // int stack_ptr = -1;
    void
    locate_queen(int col)
    {
        //每一行每一列都要有一個皇后，可從第一行第一列開始找起(queen[0][0])
        //可利用前面valid_position判斷是否符合
        //找到一種解的話將counter + 1並找下一組
        /*---------------------------------*/
        for (int i = 0; i < 8; i++)
        {
            if (valid_position(i, col))
            {
                if (col == 7)
                {
                    counter++;
                }
                else
                {
                    queen[i][col] = true;
                    locate_queen(col + 1);
                    queen[i][col] = false;
                }
            }
        }
        /*---------------------------------*/
    }
    //輸出符合的總數
    void print()
    {
        cout << counter << endl;
    }
};
int main()
{
    Queens game;
    game.locate_queen(0);
    game.print();
}

Queens::Queens()
{
    counter = 0;
    for (int i = 0; i < 8; i++)
    {
        for (int j = 0; j < 8; j++)
        {
            queen[i][j] = false;
        }
    }
    // for (int i = 0; i < 8; i++)
    // {
    //     stack[i] = 0;
    // }
}