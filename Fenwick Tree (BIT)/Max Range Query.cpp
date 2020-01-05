// Range Sum Query using Fenwick Tree / BIT

#include <iostream>
using namespace std;

int a[10000];
int BIT[10000] = {0};

void update(int i, int val, int N)
{
    while (i <= N)
    {
        BIT[i] = max(BIT[i], val);
        i += (i & (-i));
    }
}

int query(int i)
{
    int ans = 0;
    while (i > 0)
    {
        ans = max(BIT[i], ans);
        i -= (i & (-i));
    }

    return ans;
}

int main()
{

    int n;
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
        update(i, a[i], n);
    }

    int q;
    cin >> q;
    while (q--)
    {
        int idx;
        cin >> idx;
        cout << query(idx) << endl;
    }
}
