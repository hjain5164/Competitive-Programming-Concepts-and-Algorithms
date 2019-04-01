#include <iostream>
#include <map>
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

    void dfsHelper(T node, map<T, bool> &visited, list<T> &ordering)
    {
        visited[node] = true;
        //Call DFS on unvisited neighbors of current node.
        for (T neighbor : adjList[node])
        {
            if (!visited[neighbor])
            {
                dfsHelper(neighbor, visited, ordering);
            }
        }
        //All the children of current node have been visited
        //We can add current node to the list
        ordering.push_front(node);
    }

    void dfsTopologicalSort()
    {
        map<T, bool> visited;
        list<T> ordering;
        for (auto i : adjList)
        {
            //i is a pair (node,list of nodes)
            T node = i.first;
            if (!visited[node])
            {
                dfsHelper(node, visited, ordering);
            }
        }
        for (T ele : ordering)
        {
            cout << ele << "-->";
        }
    }
};
int main()
{
    Graph<string> g;
    g.addEdge("English", "Programming Logic", false);
    g.addEdge("Maths", "Programming Logic", false);
    g.addEdge("Programming Logic", "HTML", false);
    g.addEdge("Programming Logic", "Python", false);
    g.addEdge("Programming Logic", "Java", false);
    g.addEdge("Programming Logic", "JS", false);
    g.addEdge("Python", "Web Dev", false);
    g.addEdge("HTML", "CSS", false);
    g.addEdge("CSS", "JS", false);
    g.addEdge("JS", "Web Dev", false);
    g.addEdge("Java", "Web Dev", false);
    g.addEdge("Python", "Web Dev", false);

    g.dfsTopologicalSort();
}
