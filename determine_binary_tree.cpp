#define CAPCITY 1000
#include <cmath>
#include <iostream>
#include <queue>
#include <vector>
using namespace std;

int input_size;

int find_idx(int arr[], int target) {
    for (int i = 0; i < input_size; ++i) {
        if (arr[i] == target)
            return i;
    }
    return -1;
}

void ans_func(int ans[], int arr1[], int arr0[], int l_idx, int r_idx, int place_idx, int &count) {
    if (count >= input_size)
        return;

    ans[place_idx] = arr0[count];
    if (l_idx >= r_idx)
        return;

    int target_idx = find_idx(arr1, arr0[count]);
    int right_start_idx;

    for (int i = l_idx + 1; i <= r_idx; ++i) {
        if (target_idx < find_idx(arr1, arr0[i])) {
            right_start_idx = i;
            break;
        }
    }

    ans_func(ans, arr1, arr0, l_idx + 1, right_start_idx - 1, place_idx * 2, ++count); // left
    ans_func(ans, arr1, arr0, right_start_idx, r_idx, place_idx * 2 + 1, ++count);     // right
}

int main() {

    /* process input data */
    vector<int> all_input;
    int tmp;
    while (cin >> tmp)
        all_input.push_back(tmp);
    input_size = all_input.size() / 2;
    int arr0[input_size];
    int arr1[input_size];
    for (int i = 0; i < all_input.size(); ++i) {
        if (i < input_size) {
            arr0[i] = all_input[i];
        } else {
            arr1[i - input_size] = all_input[i];
        }
    }
    /* end */

    int ans[CAPCITY] = {0};
    int count = 0;
    ans_func(ans, arr1, arr0, 0, input_size - 1, 1, count);

    int ele_counter = 0;
    for (int i = 1; i <= 20; ++i) {
        bool flag = false;
        for (int j = (int)pow(2, i - 1); j <= (int)pow(2, i) - 1; ++j) {
            if (ans[j] != 0) {
                flag = true;
            }
        }
        if (flag == false)
            break;

        cout << i << ":";
        bool is_First = true;
        for (int j = 0; j < (int)pow(2, i - 1); ++j) {
            if (is_First) {
                ele_counter++;
                if (ans[ele_counter] != 0) {
                    cout << ans[ele_counter];
                    is_First = false;
                }
            } else {
                ele_counter++;
                if (ans[ele_counter] != 0) {
                    cout << "," << ans[ele_counter];
                }
            }
        }
        cout << endl;
    }

    return 0;
}