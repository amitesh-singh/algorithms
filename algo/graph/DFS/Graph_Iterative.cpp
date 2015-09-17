#include <iostream>
#include <list>
#include <stack>
#include <cstdio>

using namespace std;

class Graph
{
   bool directed;
   int V;
   list<int> *adj; //Adjacency list

   void DFSUtil(int v, bool visited[])
   {
      stack<int> s;

      s.push(v);
      visited[v] = true;

      while (!s.empty())
      {
         int visited_node = s.top();
         s.pop();
         cout << visited_node << " ";

         list<int>::iterator itr = adj[visited_node].begin();
         for (; itr != adj[visited_node].end(); ++itr)
         {
            //push all the children into stack
            if (!visited[*itr])
              {
                 s.push(*itr);
                 visited[*itr] = true;
              }
         }
      }
      cout << endl;
   }

public:
   // n -> no .of vetices
   // dir -> directed or undirected.
   Graph(int n, bool dir): directed(dir), V(n), adj(new list<int>[V])
   {
   }

   void addEdges(int v, int w)
   {
      adj[v].push_back(w);
      if (!directed)
         adj[w].push_back(v);
   }

   void DFS(int v)
   {
      bool *visited = new bool[V];
      for (int i = 0; i < V; ++i)
      {
         visited[i] = false;
      }

      DFSUtil(v, visited);
   }

   enum Color {white, grey, black};

   void DFSCormen(int v)
     {
        int time = 0;
        Color *color = new Color[V];
        int *d = new int[V];
        int *f = new int[V];

        for (int i = 0; i < V; ++i)
          {
             color[i] = white;
             d[i] = f[i] = 0;
          }

        stack<int> s;

        s.push(v);
        int current;
        bool reprocess = false;
        time = time + 1;
        d[v] = time;
        color[v] = grey;
        cout << endl;
        cout << v << " is discovered now\n";

        bool isAllChildrenFinished = true;

        while (!s.empty())
          {
             reprocess = false;
             isAllChildrenFinished = true;
             current = s.top();
             list<int>::iterator itr = adj[current].begin();
             list<int>::iterator itr2= adj[current].begin();

             for (; itr != adj[current].end(); ++itr)
               {
                  if (color[*itr] == white)
                    {
                       color[*itr] = grey;
                       s.push(*itr);
                       isAllChildrenFinished = false;
                       reprocess = true;
                       cout << (int)(*itr) << " is discovered now\n";
                       break;
                    }
                  else if (color[*itr] == grey)
                    {
                       isAllChildrenFinished = false;
                    }
               }

             if (reprocess)
               continue;

             if (isAllChildrenFinished)
               {
                  f[current] = ++time;
                  s.pop();
                  color[current] = black;
                  cout << current << "is black now\n";
               }
          };
        cout << endl;

        delete [] color;
        delete [] f;
        delete [] d;
     }

}; //class ends


int main()
{
   //undirected graph

   cout << "Directed Graph: ";
   Graph g2(3, true);

   g2.addEdges(0, 1);
   g2.addEdges(1, 2);

   cout << "corment DFS:";
   g2.DFSCormen(0);

   return 0;
}
