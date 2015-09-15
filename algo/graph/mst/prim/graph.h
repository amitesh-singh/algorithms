#ifndef _GRAPH_H
#define _GRAPH_H

#include <iostream>
#include <list>

using namespace std;

#define INF 99999

//int W[100][100];
int adjm[100][100];

class Graph
{
   int V;
   bool directed;
   void reset()
     {
        for (int i = 0; i < V + 1; ++i)
          {
             for (int j = 0; j < V; ++j)
               {
                  adjm[i][j] = 0;
 //                 W[i][j] = 0;
               }
          }
     }
 public:
   Graph(int _V, bool dir):V(_V)
   {
      directed = dir;
   }

   ~Graph()
     {
     }

   void addEdge(int e1, int e2, int w)
     {
        adjm[e1][e2] = w;

        if (!directed)
          {
             adjm[e2][e1] = w;
          }
     }

   int minKey(int key[], bool mst[])
     {
        int min = INF, minIndex;

        for (int v = 0; v < V; ++v)
          {
             if (mst[v] == false && min > key[v])
               {
                  min = key[v];
                  minIndex = v;
               }
          }

        return minIndex;
     }

   void prim()
     {
        //choose the first
        int *key;
        bool *mst;

        key = new int[V];
        mst = new bool[V];
        int *parent = new int[V];

        for (int i = 0; i < V; ++i)
          {
             key[i] = INF;
             mst[i] = false;
          }

        //start from 0
        key[0] = 0;

        for (int count = 0; count < V - 1; ++count)
          {
             int u = minKey(key, mst);

             mst[u] = true;

             for (int v = 0; v < V; ++v)
               {
                  if (adjm[u][v] && mst[v] == false
                      && adjm[u][v] < key[v])
                    {
                       parent[v] = u;
                       key[v] = adjm[u][v];
                    }
               }
          }

        for (int i = 1; i < V; ++i)
          {
             cout << parent[i] << "--" << i << ":" << adjm[i][parent[i]] << endl;
          }

        delete [] key;
        delete [] mst;
        delete [] parent;

     }
};

#endif
