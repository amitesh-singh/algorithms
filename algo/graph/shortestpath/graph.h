#include <iostream>
#include <list>
#include <queue>

using namespace std;

//In this example, we are going to calculate the 
// 
class Graph
{
   int V;
   list<int> *adj;
 public:
   Graph(int n): V(n)
   {
      adj = new list<int>[V];
   }

   void addEdges(int e1, int e2)
     {
        adj[e1].push_back(e2);
        adj[e2].push_back(e1);
     }

   //we gonna do BFS
   void shortestDUtil(int v, bool visited[], int d[])
     {
        queue<int> q;

        q.push(v);
        visited[v] = true;
        d[v] = 0;

        while (!q.empty())
          {
             int current = q.front();
             q.pop();
             cout << current << ",";

             list<int>::iterator itr = adj[current].begin();
             for (; itr != adj[current].end(); ++itr)
               {
                  if (!visited[*itr])
                    {
                       visited[*itr] = true;
                       q.push(*itr);
                       d[*itr] = d[current] + 1;
                    }
               }
          }
     }

   void shortestD(int v)
     {
        bool *visited = new bool[V];
        int *d = new int[V];

        for (int i = 0; i < V; ++i)
          {
             visited[i] = false;
             d[i] = 0;
          }

        cout << "***********START**************\n";
        shortestDUtil(v, visited, d);
        cout << endl;

        for (int i = 0; i < V; ++i)
          {
             cout << "d[" << i << "]: " << d[i] << endl;
          }
        cout << "***********END**************\n";

        delete [] visited;
        delete [] d;
     }
};
