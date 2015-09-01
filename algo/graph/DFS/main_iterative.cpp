#include "Graph_Iterative.h"

int main()
{
   //undirected graph
   cout << "Undirected Graph: ";
   Graph g(4, false);

   g.addEdges(0, 1);
   g.addEdges(1, 2);
   g.addEdges(2, 3);
   g.addEdges(2, 1);
   g.addEdges(0, 3);

   g.DFS(2);
   cout << "corment DFS:";
   g.DFSCormen(2);

   cout << "Directed Graph: ";
   Graph g2(4, true);

   g2.addEdges(0, 1);
   g2.addEdges(1, 2);
   g2.addEdges(2, 3);
   g2.addEdges(2, 1);
   g2.addEdges(0, 3);

   g2.DFS(2);
   cout << "corment DFS:";
   g2.DFSCormen(2);

   return 0;
}
