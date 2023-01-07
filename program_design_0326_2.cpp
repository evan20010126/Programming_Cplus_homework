#include <iostream>
#include <limits.h>
#include <cmath>

using namespace std;

int dp_function(int i, int j, int dp[][30], int nums[]);

int main()
{
    while (true)
    {
        int arr_len;
        cin >> arr_len;
        if (arr_len == 0)
            break;
        int nums[arr_len];
        for (int i = 0; i < arr_len; i++)
            cin >> nums[i];
        int dp[30][30] = {};
        for (int i = 0; i < 30; i++)
        {
            for (int j = 0; j < 30; j++)
            {
                dp[i][j] = INT_MIN;
            }
        }
        if (dp_function(0, arr_len - 1, dp, nums) >= 0)
        {
            cout << "WIN" << endl;
        }
        else
        {
            cout << "LOSE" << endl;
        }
    }
    return 0;
}

int dp_function(int i, int j, int dp[][30], int nums[])
{
    if (i == j)
        return nums[i];
    if (dp[i][j] != INT_MIN)
    {
        return dp[i][j];
    }
    else
    {
        int case1 = nums[i] - dp_function(i + 1, j, dp, nums);
        int case2 = nums[j] - dp_function(i, j - 1, dp, nums);
        dp[i][j] = max(case1, case2);
        return dp[i][j];
    }
}