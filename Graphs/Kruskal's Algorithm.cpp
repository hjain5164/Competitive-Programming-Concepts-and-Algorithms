#include <iostream>
#include <algorithm>
using namespace std;

class Edge
{
public:
    int src;
    int dest;
    int weight;
};

class Set
{
public:
    int rank;
    int parent;
};

int find(Set *set, int i)
{
    if (set[i].parent != i)
    {
        set[i].parent = find(set, set[i].parent);
    }
    return set[i].parent;
}

void Union(Set *set, int v1, int v2)
{
    int v1_root = find(set, v1);
    int v2_root = find(set, v2);
    if (set[v1_root].rank < set[v2_root].rank)
    {
        set[v1_root].parent = v2_root;
    }
    else if (set[v1_root].rank > set[v2_root].rank)
    {
        set[v2_root].parent = v1_root;
    }
    else
    {
        set[v2_root].parent = v1_root;
        set[v1_root].rank++;
    }
}

bool cmp(Edge e1, Edge e2)
{
    return e1.weight < e2.weight;
}
void Kruskals(Edge *input, int n, int e)
{
    sort(input, input + e, cmp); //sort input array on the basis of weights.
    Edge *output = new Edge[n - 1];
    Set *set = new Set[n];
    for (int i = 0; i < n; i++)
    {
        set[i].rank = 0;
        set[i].parent = i;
    }
    int counter = 0, i = 0;
    while (counter < n - 1)
    {
        Edge currentEdge = input[i];
        int sourceParent = find(set, currentEdge.src);
        int destParent = find(set, currentEdge.dest);
        if (sourceParent != destParent)
        {
            output[counter] = currentEdge;
            Union(set, sourceParent, destParent);
            counter++;
        }
        i++;
    }
    for (int m = 0; m < n - 1; m++)
    {
        cout << output[m].src << "--" << output[m].dest << " with weight = " << output[m].weight << endl;
    }
    int total_weight = 0;
    for (int m = 0; m < n - 1; m++)
        total_weight += output[m].weight;
    cout << "Total weight is " << total_weight << endl;
}
int main()
{
    int n, e; //no of vertices and edges
    cin >> n >> e;
    Edge *input = new Edge[e];
    for (int i = 0; i < e; i++)
    {
        int s, d, w;
        cin >> s >> d >> w;
        input[i].src = s;
        input[i].dest = d;
        input[i].weight = w;
    }
    Kruskals(input, n, e);
}
