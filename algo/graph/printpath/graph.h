#include <iostream>
#include <queue>
#include <list>
#include <cstring>

using namespace std;

class Graph
{
   int V;
   bool directed;
   list<int> *adj;
 public:
   Graph(int n, bool dir): V(n), directed(dir),
                           adj(new list<int>[V])
   {
   }

   ~Graph()
     {
        delete [] adj;
     }

   void addEdges(int e1, int e2)
     {
        adj[e1].push_back(e2);
        if (!directed)
          adj[e2].push_back(e1);
     }

   enum Color {white, grey, black};

   void printPathUtil(int v1, int v2, int parent[])
     {
        if (v1 == v2)
          cout << v1 << ",";
        else if (parent[v2] == -1)
          cout << "no path\n";
        else
          {
             printPathUtil(v1, parent[v2], parent);
             cout << v2 << ",";
          }
     }

   void printPath(int v1, int v2)
     {
        Color *color = new Color[V];
        int *parent = new int[V];

        for (int i = 0; i < V; ++i)
          {
             color[i] = white;
             parent[i] = -1;
          }

        //prepare our parent relationship
        queue<int> q;

        q.push(v1);
        color[v1] = grey;

        while (!q.empty())
          {
             int current = q.front();
             q.pop();
             list<int>::iterator itr = adj[current].begin();
             for (; itr != adj[current].end(); ++itr)
               {
                  if (color[*itr] == white)
                    {
                       color[*itr] = grey;
                       parent[*itr] = current;
                       q.push(*itr);
                    }
               }

             color[current] = black;
          }

        printPathUtil(v1, v2, parent);

        delete [] color;
        delete [] parent;
     }
};
