#include "graph.h"

int main()
{
   Graph g(4, true);

   g.addEdges(0, 1);
   g.addEdges(0, 2);
   g.addEdges(2, 0);
   g.addEdges(2, 1);
   g.addEdges(0, 3);
   g.addEdges(2, 3);
   g.addEdges(3, 3);

   //start the DFS from '2'
   g.DFS(2);
   cout << endl;

   //start the DFS from '0'
   g.DFS(0);
   cout << endl;
   cout << "Is graph cyclic? " << g.isCyclic() << endl;
   cout << "Is graph cyclic ~~ iterative? " << g.isCyclicIterative() << endl;

   Graph g2(3, true);

   g2.addEdges(0, 1);
   g2.addEdges(1, 2);
   //g2.addEdges(0, 2);
   //this does not work!!
   //Remember DFS does not work for directed graph
   cout << "Is graph cyclic? " << g2.isCyclic() << endl;
   cout << "Is graph cyclic ~~ iterative? " << g2.isCyclicIterative() << endl;

   return 0;
}
