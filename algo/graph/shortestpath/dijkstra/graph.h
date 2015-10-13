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

   int minDistance(int d[], bool tree[])
   {
     int minIndex, min = INFINITY;

     for (int v = 0; v < V; ++v)
     {
       if (tree[v] == false && min > d[v])
       {
         minIndex = v;
         min = d[v];
       }
     }

     return minIndex;
   }

// Naive approach with Array.
// O(V*V)
   void dijkstra(int s)
   {
     bool *tree = new bool[V];

     memset(tree, 0, sizeof(bool) * V);

     initializeSingleSource(s);

     for (int count = 1; count < V - 1; ++count)
     {
       int u = minDistance(d, tree);

       tree[u] = true;

       list<int>::iterator itr = adj[u].begin();

       for (; itr != adj[u].end(); ++itr)
       {
         RELAX(u, *itr);
       }

     } //for loop ends

     for (int v = 0; v < V; ++v)
     {
       cout << "d[" << v << "] = " << d[v] << endl;
     }
   }

   void addEdge(int e1, int e2, int w)
     {
        //Directed Graph
        adj[e1].push_back(e2);

        W[e1][e2] = w;

        if (!directed)
          {
             W[e2][e1] = w;
             adj[e2].push_back(e1);
          }
          
     }
};

#endif
