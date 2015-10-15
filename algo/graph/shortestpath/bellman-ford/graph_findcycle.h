#ifndef _GRAPH_H__
#define _GRAPH_H__

#include <iostream>
#include <list>
#include <stack>
#include <cstring> // for mmeset()

using namespace std;

#define INFINITY 99999

int W[100][100];

class Graph
{
   int V;
   list<int> *adj;
   int *d;
   int *p;
   bool directed;

   void initializeSingleSource(int s)
     {
        for (int i = 0; i < V; ++i)
          {
             d[i] = INFINITY;
             p[i] = 0;
          }
        //set source distance to 0
        d[s] = 0;
     }

   void RELAX(int u, int v)
     {
        if (d[u] != INFINITY && d[v] > d[u] + W[u][v])
          {
             d[v] = d[u] + W[u][v];
             p[v] = u;
          }
     }

 public:

   bool bellmanFord(int s)
     {
        initializeSingleSource(s);

        // Relax each edge V - 1 times
        for (int count = 1; count <= V - 1; ++count)
          {
             int row = 0;
             for (; row < V; ++row)
               {
                  list<int>::iterator itr = adj[row].begin();
                  for (; itr != adj[row].end(); ++itr)
                    {
                       RELAX(row, *itr);
                    }
               }
          }

        bool *unrelaxedEdges = new bool[V];
        memset(unrelaxedEdges, 0, sizeof(bool) * V);

        int row = 0;
        for (; row < V; ++row)
          {
             list<int>::iterator itr = adj[row].begin();
             for (; itr != adj[row].end(); ++itr)
               {
                  if (d[row] != INFINITY && d[*itr] > d[row] + W[row][*itr])
                    {
                       cout << row << "---" << *itr << " Negative Weight Cycle found\n";
                       unrelaxedEdges[*itr] = true;
                       //return false;
                    }
               }
          }

        for (int i = 0; i < V; ++i)
          {
             cout << "d[" << i << "] = " << d[i];
             if (unrelaxedEdges[i])
               cout << "----> unrelaxed edge\n";
             else
               cout << "\n";
          }

        return true;
     }

   Graph(int _V, bool _directed): V(_V), adj(new list<int>[V])
   {
      d = new int[V];
      p = new int[V];
      directed = _directed;
   }

   ~Graph()
     {
        delete [] d;
        delete [] p;
        delete [] adj;
     }

   void addEdge(int e1, int e2, int w)
     {
        //Directed Graph
        adj[e1].push_back(e2);

        W[e1][e2] = w;
        //Note: We are only processing a edge for one time.. so
        // we don't need double entry event in case of undirected GRAPH
        /*
        if (!directed)
          {
             W[e2][e1] = w;
             adj[e2].push_back(e1);
          }
          */
     }
};

#endif
