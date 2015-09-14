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
        if (d[v] > d[u] + W[u][v])
          {
             d[v] = d[u] + W[u][v];
             p[v] = u;
          }
     }

 public:

   stack<int> topsortVertices;

   void DFS_visit(int s, bool visited[])
     {
        visited[s] = true;

        list<int>::iterator itr = adj[s].begin();

        for (; itr != adj[s].end(); ++itr)
          {
             if (!visited[*itr])
               DFS_visit(*itr, visited);
          }
        // done with s, finish
        topsortVertices.push(s);
     }

   void DFS()
     {
        bool *visited = new bool[V];

        memset(visited, 0, V);

        for (int i = 0; i < V; ++i)
          {
             if (!visited[i])
               DFS_visit(i, visited);
          }

        delete [] visited;
     }

   void dagSingleSourceShortestPath(int s)
     {
        DFS(); //topo sort is done
        initializeSingleSource(s);

        int u;

        while (!topsortVertices.empty())
          {
             u = topsortVertices.top();

             topsortVertices.pop();

             list<int>::iterator itr = adj[u].begin();
             for (; itr != adj[u].end(); ++itr)
               {
                  RELAX(u, *itr);
               }
          }
        //lets print out d[]
        for (int i = 0; i < V; ++i)
          {
             cout << "[" << i << "] = " << d[i] << endl;
          }
     }

   Graph(int _V): V(_V), adj(new list<int>[V])
   {
      d = new int[V];
      p = new int[V];
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
     }

};

#endif
