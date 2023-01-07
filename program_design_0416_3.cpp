#include <iostream>
using namespace std;

void N(int arr[], int P)
{
    cout << arr[0] << endl;
    int temp = arr[0];
    for (int i = 0; i < P - 1; i++)
    {
        arr[i] = arr[i + 1];
    }
    arr[P - 1] = temp;
}

int find(int arr[], int P, int target)
{
    int index = 0;
    while (arr[index] != target)
    {
        index++;
    }
    return index;
}

void E(int arr[], int P, int target)
{
    int index = find(arr, P, target);
    int temp = arr[index];
    for (int i = index; i > 0; i--)
    {
        arr[i] = arr[i - 1];
    }   
    arr[0] = temp;
}
int main()
{
    int case_num = 1;
    while (true)
    {
        int P, C; //P表總人口 C表行為指令

        cin >> P >> C;
        if (P == 0 && C == 0)
            break;
        cout << "Case " << case_num << ":" << endl;
        int arr[P];
        for (int i = 0; i < P; i++)
        {
            arr[i] = i + 1;
        }

        for (int i = 0; i < C; i++)
        {
            char CH;
            cin >> CH;
            if (CH == 'N')
            {
                N(arr, P);
            }
            else if (CH == 'E')
            {
                int number;
                cin >> number;
                E(arr, P, number);
            }
        }
        case_num++;
    }

    return 0;
}