#include "graph.h"
#include <cstdio>

int test_case = 0;
int main()
{
   freopen("input.txt", "r", stdin);

   //read the test case
   cin >> test_case;
   int V;
   for (int test = 1; test <= test_case; ++test)
     {
        // read the no. of vertices
        cin >> V;
        printf("V: %d\n", V);
        Graph g(V, false);
        for (int i = 0; i < V; ++i)
          {
             int e1, e2;
             //read edges.
             cin >> e1 >> e2;
             g.addEdges(e1, e2);
          }

        g.DFS(1);

        //cout << "Loop: " << g.IsLoop() << endl;

     }

   return 0;
}
