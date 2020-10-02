// Problem - Write a recursive code to check whether an array is sorted or not
#include <iostream>
using namespace std;

bool isSorted(int *a, int n)
{
    if (n == 1)
    {
        return true;
    }
    if (a[0] < a[1] && isSorted(a + 1, n - 1))
    {
        return true;
    }
    return false;
}
int main()
{
    int a[] = {1, 2, 3, 4, 51, 6, 7};
    int n = 7;
    if (isSorted(a, n))
        cout << "Sorted";
    else
        cout << "Not Sorted";
}
