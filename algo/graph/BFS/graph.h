#include <iostream>
#include <queue>
#include <list>
#include <cstring>

using namespace std;

class Graph
{
   int V;
   bool directed;
   list<int> *adj;
 public:
   Graph(int n, bool dir): V(n), directed(dir),
                           adj(new list<int>[V])
   {
   }
   ~Graph()
     {
        delete [] adj;
     }

   void addEdges(int e1, int e2)
     {
        adj[e1].push_back(e2);
        if (!directed)
          adj[e2].push_back(e1);
     }

   void shortestSDUtil(int v, bool visited[])
     {
        queue<int> q;
        int *d = new int[V];
        memset(d, 0, V);

        q.push(v);
        d[v] = 0;
        //we already visited v
        visited[v] = true;

        while (!q.empty())
          {
             int current = q.front();
             q.pop();
             //visit the neighbours
             list<int>::iterator itr = adj[current].begin();
             for (; itr != adj[current].end(); ++itr)
               {
                  if (!visited[*itr])
                    {
                       visited[*itr] = true;
                       q.push(*itr);
                       d[*itr] = d[current] + 1; //weight
                       //we are assuming that our weight is 1 
                    }
               }
          }
        cout << endl;
        for (int i = 0; i < V; ++i)
          {
             cout << i << ":" << d[i] << endl;
          }

        delete [] d;
     }

   //find the distance of other vertex 
   // from v
   void shortestSD(int v)
     {
        bool *visited = new bool[V];

        for (int i = 0; i < V; ++i)
          visited[i] = false;

        shortestSDUtil(v, visited);

        delete [] visited;
     }

   void BFS(int v)
     {
        bool *visited = new bool[V];

        for (int i = 0; i < V; ++i)
          visited[i] = false;

        queue<int> q;
        q.push(v);
        visited[v] = true;

        cout << "BFS Search: ";

        while (!q.empty())
          {
             v = q.front();
             q.pop();
             cout << v << ",";

             list<int>::iterator itr = adj[v].begin();
             for (; itr != adj[v].end(); ++itr)
               {
                  if (!visited[*itr])
                    {
                       visited[*itr] = true;
                       q.push(*itr);
                    }
               }
          }
        cout << endl;
        delete [] visited;
     }

   //This is the BFS based on cormen book theory
   //in this case, the vertex have different colors.
   //Three STAGES of color, one is white, grey and black
   //vertex colors
   enum Color {white, grey, black};

   const char *printColor(Color color)
     {
        switch(color)
          {
           case white:
              return "white";
           case grey:
              return "grey";
           case black:
              return "black";
           default:
              return "unknow color";
          }
     }

   void BFSCormen(int s)
     {
        Color *color = new Color[V];
        //parent node
        int *parent = new int[V];

        for (int i = 0; i < V; ++i)
          {
             color[i] = white;
             parent[i] = -1; //No parent (root will have no parent)
          }

        queue<int> q;
        q.push(s);
        color[s] = grey; // we already processed s
        parent[s] = -1; // It does not have parent since we are starting from s.

        while (!q.empty())
          {
             int current = q.front();
             q.pop();
             list<int>::iterator itr = adj[current].begin();
             for (; itr != adj[current].end(); ++itr)
               {
                  if (color[*itr] == white)
                    {
                       color[*itr] = grey;
                       parent[*itr] = current;
                       q.push(*itr);
                    }
               }
             color[current] = black; // make the color of visited parent - black.
             cout << "A node is visited........\n";
             cout << current << endl;
             for (int i = 0; i < V; ++i)
               {
                  cout << i << ": " << printColor(color[i]) << endl;
               }
             cout << "*****end****\n";
          }
        cout << endl;

        delete [] parent;
        delete [] color;
     }
};
