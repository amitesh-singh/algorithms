#include <iostream>
#include <stack>
#include <string.h>

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
             cout << "i: " << i << endl;
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
             cout << __func__ << endl;

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


};
