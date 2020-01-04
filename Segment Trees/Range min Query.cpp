#include <iostream>
#include <climits>
using namespace std;

// Build the tree
void buildTree(int *a, int s, int e, int *tree, int index)
{
    if (s == e)
    {
        tree[index] = a[s];
        return;
    }
    //Recursive Case
    int mid = (s + e) / 2;
    buildTree(a, s, mid, tree, 2 * index);
    buildTree(a, mid + 1, e, tree, 2 * index + 1);

    tree[index] = min(tree[2 * index], tree[2 * index + 1]);
}

// Find the minimum element within a range l to r
int query(int *tree, int ss, int se, int qs, int qe, int index)
{
    //Complete Overlap
    if (ss >= qs && se <= qe)
        return tree[index];

    //No Overlap
    if (qe < ss || qs > se)
        return INT_MAX;

    //Partial Overlap
    int mid = (ss + se) / 2;
    int left = query(tree, ss, mid, qs, qe, 2 * index);
    int right = query(tree, mid + 1, se, qs, qe, 2 * index + 1);

    return min(left, right);
}

// Update the element at ith position
void update(int *tree, int ss, int se, int i, int inc, int index)
{

    if (i > se || i < ss || ss > se)
        return;

    if (ss == se)
    {
        tree[index] += inc;
        return;
    }
    int mid = (ss + se) / 2;
    update(tree, ss, mid, i, inc, 2 * index);
    update(tree, mid + 1, se, i, inc, 2 * index + 1);

    tree[index] = min(tree[2 * index], tree[2 * index + 1]);
    return;
}

//Update the elements within a range
void updateRange(int *tree, int ss, int se, int l, int r, int inc, int index)
{
    if (l > se || r < ss)
        return;
    if (ss == se)
    {
        tree[index] += inc;
        return;
    }

    int mid = (ss + se) / 2;
    updateRange(tree, ss, mid, l, r, inc, 2 * index);
    updateRange(tree, mid + 1, se, l, r, inc, 2 * index + 1);

    tree[index] = min(tree[2 * index], tree[2 * index + 1]);
    return;
}

int main()
{
    int a[] = {1, 3, 2, -5, 6, 4};
    int n = sizeof(a) / sizeof(int);

    int *tree = new int[4 * n + 1];
    buildTree(a, 0, n - 1, tree, 1);
    //Print the tree
    // for(int i=0; i<=13; i++)
    // cout<<tree[i]<<"  ";
    int l = 0, r = 2;
    cout << query(tree, 0, n - 1, l, r, 1) << endl;

    update(tree, 0, n - 1, 2, -20, 1);
    cout << query(tree, 0, n - 1, l, r, 1) << endl;

    l = 2, r = 4;
    updateRange(tree, 0, n - 1, l, r, 5, 1);
    cout << query(tree, 0, n - 1, 0, n - 1, 1);
}
