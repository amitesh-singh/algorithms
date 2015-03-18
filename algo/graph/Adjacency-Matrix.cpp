#include <iostream>
using namespace std;
#include "Adjacency-Matrix.h"


int main()
{
   Graph g(4);
   g.addEdge(0, 1);
   g.addEdge(2, 3);
   g.addEdge(0, 3);
   g.addEdge(1, 3);

   g.print();

   return 0;

}
