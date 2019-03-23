// Problem:
// Given a 1 to N Snakes and Ladders board, starting and the ending points of all
// Snakes and Ladders. You have to find out the Minimum number of dice throws to win
// the game. Each dice throw can have any number from 1 to 6.

//Code:

#include <iostream>
#include <map>
#include <queue>
#include <list>
using namespace std;

template <typename T>
class Graph
{
    map<T, list<T>> adjList;

  public:
    Graph()
    {
    }
    void addEdge(T u, T v, bool bidir = true)
    {
        adjList[u].push_back(v);
        if (bidir)
            adjList[v].push_back(u);
    }
    int bfs(T source_node, T destination_node)
    {
        queue<T> q;
        map<T, int> dist;
        map<T, T> parent;
        for (auto i : adjList)
        {
            dist[i.first] = INT8_MAX;
        }
        q.push(source_node);
        dist[source_node] = 0;
        parent[source_node] = source_node;
        while (!q.empty())
        {
            T node = q.front();
            q.pop();
            for (int neighbor : adjList[node])
            {
                if (dist[neighbor] == INT8_MAX)
                {
                    q.push(neighbor);
                    parent[neighbor] = node;
                    dist[neighbor] = dist[node] + 1;
                }
            }
        }
        //Move Backward and reach the source
        cout << "One possible shortest path is :\t";
        T temp = destination_node;
        while (temp != source_node)
        {
            cout << temp << "<--";
            temp = parent[temp];
        }
        cout << source_node << endl;
        return dist[destination_node];
    }
};
int main()
{
    Graph<int> g;
    int board[50] = {0};
    board[2] = 13;
    board[5] = 2;
    board[9] = 18;
    board[18] = 11;
    board[17] = -13;
    board[20] = -14;
    board[24] = -8;
    board[25] = -10;
    board[32] = -2;
    board[34] = -22;
    //Construct the graph
    for (int u = 0; u <= 36; u++)
    {
        // At every node we can throw the dice
        for (int dice = 1; dice <= 6; dice++)
        {
            int v = u + dice + board[u + dice];
            g.addEdge(u, v, false);
        }
    }
    int ans = g.bfs(0, 36);
    cout << endl
         << "Minimum number of dice throws is :\t" << ans << endl;
    ;
}
