#include <cmath>
#include <iostream>
using namespace std;

//2。数组对称
bool isDuiCheng(int *a, int left, int right)
{
    if (left >= right)
        return true;
    return a[left] == a[right] && isDuiCheng(a, left + 1, right - 1);
}

int main(int argc, char const *argv[])
{
    int arr[] = {1, -1, -1, 1};

    int n = sizeof(arr) / sizeof(int) - 1;
    cout << isDuiCheng(arr, 0, n) << endl;
    return 0;
}
