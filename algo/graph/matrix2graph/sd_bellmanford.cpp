#include <iostream>
#include <cstdio>
#include <cstring>

/*
   This code shows how to convert a given matrix to a graph.
   This is useful for path finding.

   e.g.
   4
   SRC 1 1 4
   1   1 1 1
   3   3 2 1
   0   1 1 DEST

   find the minimum distance from SRC to DEST
 */
using namespace std;

int T;
int N;

int input[100][100];

// Note: Each node can have at max 4 edges.
// we can present that matrix into a graph
// we will have N *N vertices and each cell actually presents the node of graph
// and value of the node is the weight of the edge.

int mem[10000][4];
int weight[10000][10000];

bool isSafe(int i, int j)
{
   if (i >= 0 && i < N &&
       j >= 0 && j < N)
     return true;

   return false;
}

class Graph
{
   int V;
   int *d;
   int *p;
 public:
   ~Graph()
     {
        delete [] d;
        delete [] p;
     }
    Graph(int _V): V(_V)
   {
      for (int i = 0; i < V; ++i)
        {
           for (int j = 0; j < 4; ++j)
             {
                mem[i][j] = -1;
             }
        }
   }

    void addEdge(int v1, int v2, int w)
      {
         for (int i = 0; i < 4; ++i)
           {
              if (mem[v1][i] == -1)
                {
                   mem[v1][i] = v2;
                   break;
                }
           }
         weight[v1][v2] = w;
      }

    void print()
      {
         for (int i = 0; i < V; ++i)
           {
              for (int j = 0; j < 4; ++j)
                {
                   cout << mem[i][j] << " ";
                }
              cout << "\n";
           }
         cout << "\n";
      }

#define INF 9999
    void initializeSource(int s)
      {
         d = new int[V];
         p = new int[V];

         memset(d, INF, sizeof(int) * V);
         memset(p, -1, sizeof(int) * V);

         d[s] = 0;
      }

    void relax(int u, int v)
      {
         if (d[u] != INF && d[v] > d[u] + weight[u][v])
           {
              d[v] = d[u] + weight[u][v];
              p[v] = u;
           }
      }

    int bellmanFord(int s)
      {
         initializeSource(s);
         // Relax each edge with V - 1
         for (int count = 1; count <= V - 1; ++count)
           {
              for (int i = 0; i < V; ++i)
                {
                   for (int j = 0; j < 4; ++j)
                     {
                        if (mem[i][j] == -1)
                          break;
                        relax(i, mem[i][j]);
                     }
                }
           }

         // return DEST position distance
         return d[V - 1];
      }
};

int main()
{
   char c;
   freopen("input.txt", "r", stdin);

   cin >> T;

   for (int testCase = 1; testCase <= T; ++testCase)
     {
        cin >> N;
        for (int i = 0; i < N; ++i)
          {
             for (int j = 0; j < N; ++j)
               {
                  cin >> c;
                  // This is how you convert a char to integer
                  input[i][j] = c - '0';
               }
          }

        Graph g(N * N);

        for (int i = 0; i < N; ++i)
          {
             for (int j = 0; j < N; ++j)
               {
                  if (isSafe(i, j + 1))
                    {
                       g.addEdge(i * N + j, i * N + j + 1,
                                 input[i][j + 1]);
                    }
                  if (isSafe(i, j - 1))
                    {
                       g.addEdge(i * N + j, i * N + j - 1,
                                 input[i][j - 1]);
                    }
                  if (isSafe(i + 1, j))
                    {
                       g.addEdge(i * N + j, (i + 1) * N + j,
                                 input[i + 1][j]);
                    }
                  if (isSafe(i - 1, j))
                    {
                       g.addEdge(i * N + j, (i - 1) * N + j,
                                 input[i - 1][j]);
                    }
               }
          }

        //g.print();
        cout << "#" << testCase << " " << g.bellmanFord(0) << endl;

     }

   return 0;
}
