#ifndef _GRAPH_H
#define _GRAPH_H

#include <iostream>
#include <list>
#include <queue>

using namespace std;

#define F cout << __func__ << endl

class Graph
{
   int V;
   list<int> *adj;
   int time;
 public:

   void clear()
     {
        for (int i = 0; i < V; ++i)
          {
             adj[i].clear();
          }
        V = -1;
        time = 0;
        delete [] adj;
        adj = 0;
     }

   ~Graph()
     {
        if (adj)
          delete [] adj;
     }

   void setV(int n)
     {
        V = n;
        adj = new list<int>[V];
     }

   Graph(int n):V(n), adj(new list<int>[V])
   {
      F;
   }

   void addEdges(int v1, int v2)
     {
        adj[v1].push_back(v2);
        adj[v2].push_back(v1);
     }

   enum Color { white, gray, black };
   void DFSCormen()
     {
        Color *color = new Color[V];
        int *parent = new int[V];
        int *d = new int[V]; //discovery time
        int *f = new int[V]; //finishing time.

        for (int i = 0; i < V; ++i)
          {
             color[i] = white;
             parent[i] = -1;
             d[i] = f[i] = 0;
          }

        time = 0; //initialize our timer
        for (int i = 0; i < V; ++i)
          {
             if (color[i] == white)
               {
                  DFSCormen_Visit(i, color, parent, d, f);
                  cout << endl;
               }
          }

        delete [] color; delete [] parent; delete [] d; delete [] f;
     }

   void DFSCormen_Visit(int v, Color color[],
                        int parent[], int d[],
                        int f[])
     {
        cout << v << " is gray now" << endl;
        color[v] = gray; // v is discovered hence set the color to gray
        ++time;
        d[v] = time; // v is discovered.

        list<int>::iterator itr = adj[v].begin();
        for (; itr != adj[v].end(); ++itr)
          {
             if (color[*itr] == white)
               {
                  parent[*itr] = v;
                  DFSCormen_Visit(*itr, color, parent, d, f);
               }
          }
        color[v] = black;
        ++time;
        f[v] = time;
        cout << v << " is black now\n";
        cout << v << "(" << d[v] << "/" << f[v] << ")" << ", ";
     }

   void BFSCormen_Util(int v, Color color[])
     {
        queue<int> q;

        q.push(v);
        color[v] = gray; // v is visited or discovered.
        while (!q.empty())
          {
             int current = q.front();
             cout << current << " is gray now\n";
             q.pop();

             list<int>::iterator itr = adj[current].begin();
             for (; itr != adj[current].end(); ++itr)
               {
                  if (color[*itr] == white)
                    {
                       color[*itr] = gray;
                       q.push(*itr);
                    }
               }
             color[current] = black;
             cout << current << "===>>";
             cout << current << " is black now\n";
          }
     }

   void BFSCormen(int v)
     {
        cout << "**********BFS***********\n";
        Color *color = new Color[V];

        for (int i = 0; i < V; ++i)
          {
             color[i] = white;
          }
        //what we do in BFS?
        BFSCormen_Util(v, color);

        delete [] color;
     }
};

#endif
