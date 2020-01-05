// Range Sum Query using Fenwick Tree / BIT

#include <iostream>
using namespace std;

int a[10000];
int BIT[10000] = {0};

void update(int i, int inc, int N)
{
    while (i <= N)
    {
        BIT[i] += inc;
        i += (i & (-i));
    }
}

int query(int i)
{
    int sum = 0;
    while (i > 0)
    {
        sum += BIT[i];
        i -= (i & (-i));
    }

    return sum;
}

int main()
{

    int n;
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
        // Build the tree
        update(i, a[i], n);
    }

    int q;
    cin >> q;
    while (q--)
    {
        int l, r;
        cin >> l >> r;
        cout << query(r) - query(l - 1) << endl;
    }
}
