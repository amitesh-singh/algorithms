#include "graph.h"
#include <cstdio>
//read input from file input.txt

int V, E;
int E1[100], E2[100];
int main()
{
   //now cin will take input from input.txt
   freopen("input.txt", "r", stdin);
   // cout will write everything to output.txt
   //freopen("output.txt", "w+", stdout);

   int test_case;
   for (test_case = 1; test_case <= 1; ++test_case)
     {
        cin >>  V >> E;
        Graph g(V);
        //cout << "V: " << V << " E: " << E << endl;
        for (int i = 0; i < E; i++)
          {
             cin >> E1[i] >> E2[i];
             //cout << E1[i] << " " << E2[i] << " ";
             g.addEdges(E1[i], E2[i]);
          }
        g.DFS(0);
     }

   return 0;
}
