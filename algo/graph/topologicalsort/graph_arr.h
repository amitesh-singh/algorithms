//Implement graph without STL
#include <iostream>

using namespace std;

// This is our memory pool for allocating adj list.
int mem[100][100];

//its better to allocate it separately per stack obj?
//TODO:
int stackmem[100];
class stack
{
   int *mempool;
   int sp; //stack pointer position
 public:
   stack():mempool(stackmem), sp(-1)
   {
   }

   void push(int v)
     {
        if (sp == 99)
          {
             cerr << "Stack is full!!, can't push anything, mate!\n";
             return;
          }
        //cout << __func__ << " pushed: " << v << endl;
        mempool[++sp] = v;
     }

   void pop()
     {
        if (sp == -1)
          {
             cerr << "Stack is empty, mate!";
             return;
          }
        mempool[sp--] = -1;
     }

   int top()
     {
        if (sp == -1)
          {
             cerr << "Stack is empty, mate!";
             return -1;
          }
        return mempool[sp];
     }

   bool empty()
     {
        return sp == -1;
     }
};

class Graph
{
   int _V;
   int (*adj)[100];

   void _reset()
     {
        for(int i = 0; i < _V + 1; ++i)
          for(int j = 0; j < _V + 1; ++j)
            {
               adj[i][j] = -1;
            }
     }
 public:
   Graph(int V): _V(V)
   {
      adj = mem;
      _reset();
   }

   ~Graph()
     {
     }

   void addEdge(int e1, int e2)
     {
        // This is for DAG
        for (int i = 0; i < 100; ++i)
          {
             if (adj[e1][i] == -1)
               {
                  adj[e1][i] = e2;
                  break;
               }
          }
     }

   enum Color { white, gray, black };

   void printList()
     {
        for (int i = 0; i < _V; ++i)
          {
             cout << i + 1 << ": ";
             for (int j = 0; j < _V; ++j)
               {
                  cout << adj[i][j] << " ";
               }
             cout << endl;
          }
     }

   void topologicalSortUtil(int s, Color color[], stack &st)
     {
        color[s] = gray;

        int i = 0;
        for (; i < _V; ++i)
          {
             int current = adj[s][i];
             if (current == -1)
               break;
             if (color[current] == white)
               {
                  color[current] = gray;
                  topologicalSortUtil(current, color, st);
               }
          }

        color[s] = black;
        st.push(s);
     }

   void topologicalSort()
     {
        Color *color = new Color[_V];
        stack st;

        for (int i = 0; i < _V; ++i)
          {
             color[i] = white;
          }
        //printList();

        for (int i = 0; i < _V; ++i)
          {
             if (color[i] == white)
               topologicalSortUtil(i, color, st);
          }

        while (!st.empty())
          {
             cout << st.top() << " ";
             st.pop();
          }

        cout << endl;

        delete [] color;
     }
};
