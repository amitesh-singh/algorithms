#include <iostream>
#include <cstdio>
#include <cstring>
#include <list>

using namespace std;


/*

   input is no. of nodes
output:
   connect all given nodes

   e.g. 4
   0--------1
   | \    / |
   |__\__/__|
   2--------3


 */



class Graph
{
   int n;
   list<int> *adj;
 public:
   Graph(int _n): n(_n)
   {
      adj = new list<int>[n];
   }

   void addEdge(int u, int v)
     {
        adj[u].push_back(v);
        //adj[u].push_back(v);
     }
   //printing in adj list manner.
   void print()
     {
        for (int i = 0; i < n; ++i)
          {
            cout << i << ":";
            list<int>::iterator itr = adj[i].begin();
            for (; itr != adj[i].end(); ++itr)
              {
                 cout << *itr << ", ";
              }
            cout << endl;
          }
     }

   void build()
     {
        // build graph, connect all components to each other
        // without any self-loop
        bool *visited = new bool[n];

        memset(visited, false, sizeof(bool) * n);

        for (int i = 0; i < n ; ++i)
          {
             for (int j = 1; j < n; ++j)
               {
                  if (visited[j] || visited[i] ||
                      i == j) continue;

                  addEdge(i, j);
                  addEdge(j, i);
               }
             visited[i] = true;
          }

          delete [] visited;
     }
};

int T, N;
int main()
{
   freopen("input.txt", "r", stdin);

   cin >> T;
   for (int testCase = 1; testCase <= T; ++testCase)
     {
        cin >> N;

        Graph g(N);
        g.build();
        g.print();
     }

   return 0;
}
