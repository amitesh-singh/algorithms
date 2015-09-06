#include <iostream>
#include <cstdio>
#include "graph.h"

using namespace std;

int test_cases;
int vertices;
int edges;
int main()
{
   freopen("input.txt", "r", stdin);

   //First read no. of test cases
   cin >> test_cases;

   for (int test = 1; test <= test_cases; ++test)
     {
        int e1, e2;
        //Read no. of vertices
        cin >> vertices;
        cin >> edges;

        //Its directed acyclic graph, DAG
        Graph g(vertices);

        //read edges
        for (int e = 0; e < edges; ++e)
          {
             cin >> e1 >> e2;
             cout << e1 << " " << e2 << " ";
             g.addEdge(e1, e2);
          }
        cout << endl;

        //g.topologicalSort();
        //cout << "paths from 0 to 3: " << g.findPaths(0, 3);

        g.findPathsAfterTS(0, 3);
        cout << endl;
     }

   return 0;
}
