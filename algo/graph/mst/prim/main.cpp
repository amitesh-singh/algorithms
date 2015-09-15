#include "graph.h"

#include <cstdio>

int TestCases;
int testCase;
int V, E;
int e1, e2;
int w;

int main()
{
   freopen("input.txt", "r", stdin);

   cin >> TestCases;
   for (testCase = 1; testCase <= TestCases; ++testCase)
     {
        cin >> V >> E;
        Graph g(V, false); //undirected graph.
        for (int i = 0; i < E; ++i)
          {
             cin >> e1 >> e2 >> w;
             g.addEdge(e1, e2, w);
          }

        cout << "************START****\n";
        g.prim();
        cout << "************END****\n";
     }
   return 0;
}
