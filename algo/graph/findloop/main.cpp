#include "graph.h"
#include <cstdio>

int test_case = 0;
int V, E;
int e1, e2;

int main()
{
   freopen("input.txt", "r", stdin);

   //read the test case
   cin >> test_case;
   for (int test = 1; test <= test_case; ++test)
     {
        // read the no. of vertices
        cin >> V >> E;
        Graph g(V, false);
        for (int i = 0; i < E; ++i)
          {
             //read edges.
             cin >> e1 >> e2;
             g.addEdges(e1, e2);
          }

        cout << "---------- START --------\n";
        g.findCycle();
        cout << "Back Edges: \n";
        g.findBackEdges();
        cout << "---------- END --------\n";

        //cout << "Loop: " << g.IsLoop() << endl;

     }

   return 0;
}
