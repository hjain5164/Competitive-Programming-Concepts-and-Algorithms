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
    void printList()
    {
        for (auto i : adjList)
        {
            cout << i.first << "->  ";
            for (auto entry : i.second)
            {
                cout << entry << " , ";
            }
            cout << endl;
        }
    }
};
int main()
{
    // Graph of string is made
    //Similaryly graph of int or any other type can be made
    Graph<string> g;
    g.addEdge("Putin", "Trump", false);
    g.addEdge("Putin", "Modi", false);
    g.addEdge("Putin", "Pope", false);
    g.addEdge("Modi", "Trump");
    g.addEdge("Modi", "Yogi");
    g.addEdge("Yogi", "Prabhu", false);
    g.addEdge("Prabhu", "Modi", false);
    //Map stores entries in sorted order

    g.printList();
}
