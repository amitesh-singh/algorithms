#include <iostream>
#include <list>
#include <stack>

using namespace std;

class Graph
{
   int _V;
   list<int> *adj;
 public:
    Graph(int V):_V(V), adj(new list<int>[_V])
      {
      }

    ~Graph()
      {
         delete [] adj;
      }

    void addEdge(int e1, int e2)
      {
         adj[e1].push_back(e2);
      }

    //Our topological sorting code.
    // First do DFS and after finish (or when the node is visited/turned black),
    // push the node into STACK
    enum Color {white, gray, black};

    void topologicalSortUtil(int source, Color color[], stack<int> &s)
      {
         //Discovered
         color[source] = gray;

         list<int>::iterator  itr = adj[source].begin();
         for (; itr != adj[source].end(); ++itr)
           {
              if (color[*itr] == white)
                {
                   color[*itr] = gray;
                   topologicalSortUtil(*itr, color, s);
                }
           }

         //Finished
         color[source] = black;
         s.push(source);
      }

    void topologicalSort()
      {
         Color *color = new Color[_V];
         stack<int> s;
         for (int i = 0; i < _V; ++i)
           {
              color[i] = white;
           }
         // or i could do memset() too.
         for (int i = 0; i < _V; ++i)
           {
              if (color[i] == white)
                topologicalSortUtil(i, color, s);
           }

         cout << "topological sort: " << endl;
         while (!s.empty())
           {
              cout << s.top() << " ";
              s.pop();
           }
         cout << endl;
         delete [] color;
      }

};

