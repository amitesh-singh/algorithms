#include <iostream>
#include <stack>
#include <string.h>
#include <vector>
#include <cstdlib> // abort()

using namespace std;

class Graph
{
   int V;
   int **mempool;
   int time;
   bool directed;
 public:
   Graph(int _V, bool _directed): V(_V), directed(_directed)
   {
      mempool = new int*[V];
      for(int i = 0; i < V; ++i)
        {
           mempool[i] = new int[V];
        }

      for (int i = 0; i < V; ++i)
        for (int j = 0; j < V; ++j)
          mempool[i][j] = -1;
   }
   ~Graph()
     {
        for (int i = 0; i < V; ++i)
          {
             delete [] mempool[i];
          }

        delete [] mempool;
     }

   void addEdges(int u, int v)
     {
        for (int i = 0; i < V; ++i)
          {
             if (mempool[u][i] == -1)
               {
                  mempool[u][i] = v;
                  break;
               }
          }
     }

   void print_mempool()
     {
        for (int i = 0; i < V; ++i)
          {
             cout << i << ": ";
             for (int j = 0; j < V; ++j)
               {
                  cout << mempool[i][j] << " ";
               }
             cout << "\n";
          }
     }

   enum Color {white, gray, black};

   void DFS_visit(int s, Color color[], int d[], int f[])
     {
        time++;
        d[s] = time;
        color[s] = gray;

        stack<int> st;
        st.push(s);

        while (!st.empty())
          {
             int u = st.top();
             st.pop();
             int **itr = mempool;
             for (int i = 0; i < V; ++i)
               {
                  if (itr[u][i] == -1) break;
                  if (color[itr[u][i]] == white)
                    {
                       color[itr[u][i]] = gray;
                       ++time;
                       d[itr[u][i]] = time;
                       st.push(itr[u][i]);
                    }
               }
             color[u] = black;
             ++time;
             f[u] = time;
             cout << u << ",";
          }
        cout << endl;
     }
   void DFS(int s)
     {
        Color *color = new Color[V];
        int *d = new int[V];
        int *f = new int[V];

        for (int i = 0; i < V; ++i)
          {
             color[i] = white;
             d[i] = f[i] = 0;
          }
        print_mempool();

        time = 0;
        DFS_visit(s, color, d, f);

        delete [] color;
        delete [] d;
        delete [] f;
     }

   //Question:
   // Find loop and print the loop.
   // If no loop  is found, print "no loop found"

   bool findCycleUtil(int s, bool visited[], bool restack[])
     {
        if (visited[s] == false)
          {
             visited[s] = true;
             restack[s] = true;

             int **itr = mempool;
             int u = 0;
             for (int i = 0; i < V; ++i)
               {
                  u = itr[s][i];
                  if (u != -1)
                    {
                       if (visited[u] == false)
                         {
                            if (findCycleUtil(u, visited, restack))
                              return true;
                         }
                       else if (restack[u])
                         return true;
                    }
               }
          }

        restack[s] = false;
        return false;
     }

   void findCycle()
     {
        bool *visited = new bool[V];
        bool *restack = new bool[V];

        memset(visited, 0, V * sizeof bool);
        memset(restack, 0, V * sizeof bool);

        bool found = false;
        for (int i = 0; i < V; ++i)
          {
             if ((found = findCycleUtil(i, visited, restack)))
               break;
          }
        if (found)
          {
             cout << "Loop found\n";
             cout << endl;
          }
        else
          cout << "No loop found\n";

        delete [] visited;
        delete [] restack;
     }

   // This finds the back edges in a direct graph
   // and print each cycle
   /*
      How can we detect back edges with DFS? For
      undirected graphs, easy: see if we’ve visited
      the vertex before, i.e. color ≠ WHITE.
      For directed graphs: Recall that we color a
      vertex GRAY while its adjacent vertices are
      being explored. If we re-visit the vertex while it
      is still GRAY, we have a back edge.
      */

   struct Edge
     {
        int e1, e2;
        Edge(int _e1, int _e2): e1(_e1), e2(_e2) {}
        void print()
          {
             cout << "(" << e1 << "," << e2 << ")";
          }
     };

   vector<Edge> edges;

   void findBackEdgesUtil(int s, Color color[], int parent[])
     {
        //cout << "********************* " << s << "****************\n";
        int u;
        if (color[s] == white)
          {
             //cout << s << " is grey now\n";
             color[s] = gray;
             for (int i = 0; i < V; ++i)
               {
                  u = mempool[s][i];
                  if (u != -1)
                    {
                       //cout << "color [" << u << "] = " << color[u] << endl;
                       if (color[u] == white)
                         {
                            parent[u] = s;
                            findBackEdgesUtil(u, color, parent);
                         }
                       else if (color[u] == gray)
                         {
                            cout << "Boom!, we have a back edge: (" << s << "," << u << ")";
                            cout << endl;
                            edges.push_back(Edge(s, u));
                         }
                    }
               }
          }
        //cout << s << " is black now\n";
        color[s] = black;
        //cout << "********************* FINISH  " << s << "****************\n";
     }

   void printPath(int v1, int v2, int parent[])
     {
        if (v1 == v2)
          {
             cout << v1 << " ";
          //abort();
          }
        else if (parent[v2] == -1)
          cout << "No path found\n";
        else
          {
             //cout << v1 << ", " << v2 << endl;
             printPath(v1, parent[v2], parent);
             cout << v2 << " ";
          }
     }

   void findBackEdges()
     {
        Color *color = new Color[V];
        int *parent = new int[V];

        memset(color, 0, sizeof(Color) * V);
        memset(parent, -1, V * sizeof(int));

        print_mempool();
        for (int i = 0; i < 1; ++i)
          findBackEdgesUtil(i, color, parent);

        cout << "no. of back edges: " << edges.size() << endl;
        for (int i = 0; i < edges.size(); ++i)
          {
             edges[i].print();
             cout << ";";
             cout << "Path: ";
             printPath(edges[i].e2, edges[i].e1, parent);
             cout << endl;
          }
        cout << endl;

        delete [] color;
        delete [] parent;
     }
};
