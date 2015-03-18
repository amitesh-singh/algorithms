#include <iostream>
#include "graph.h"

int main(int argc, char **argv)
{
   Graph g;

   g.AddEdges("Kanpur", "Varanasi", 400);
   g.AddEdges("Kanpur", "New Delhi", 500);
   g.AddEdges("Noida", "New Delhi", 40);
   g.AddEdges("GZB", "New Delhi", 60);

   g.print();

   return 0;
}
