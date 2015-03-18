#include "graph_weight.h"
#include <cstdio>

int test_case;
int main()
{
   int V = 0;
   int e1, e2, w;

   freopen("input.txt", "r", stdin);

   cin >> test_case;
   cout << "test case: " << test_case << endl;
   for (int test = 1; test <= test_case; ++test)
     {
        cin >> V;
        cout << "edge: " << V << endl;
        Graph g(V);
        int x;
        cin >> x;

        for (int i = 0; i < x; ++i)
          {
             cin >> e1 >> e2 >> w;
             cout << e1 << "," << e2 << "," << w << endl;
             g.addEdges(e1, e2, w);
          }
        //run our shortest distance algorithms for 0 vertex
        g.shortestD(0);
        g.shortestD(1);
        g.shortestD(2);
     }

   return 0;
}
