#ifndef _ADJACENCY_H_
#define _ADJACENY_H_

#include <iostream>


class Graph
{
   bool **_matrix;
   int _vertices;

public:
   Graph(int v): _vertices(v)
   {
      _matrix = new bool*[_vertices];

      for (int i = 0; i < _vertices; ++i)
        {
           _matrix[i] = new bool[_vertices];
        }

      //initialize it to false or 0
      for (int r = 0; r < _vertices; ++r)
        for (int c = 0; c < _vertices; ++c)
          _matrix[r][c] = false;
   }

   void addEdge(int i, int j)
     {
        if (i >= 0 && i < _vertices
            && j >= 0 && j < _vertices)
          {
             //undirected graph
             _matrix[i][j] = true;
             _matrix[j][i] = true;
          }
     }

   bool isEdge(int i, int j)
     {
        if (i >= 0 && i < _vertices
            && j >= 0 && j < _vertices)
          {
             return _matrix[i][j];
          }

        return false;
     }

   //based on https://class.coursera.org/algo-004/lecture/55
   void genericGraphSearch(int node)
     {
        bool *visited = new bool[_vertices];
        memset(visited, 0, _vertices);

        visited[node] = true;
        for (int col = 0; col < _vertices; ++col)
          {
             if (_matrix[node][col] == 1)
               {
                  //mark it visited
                  visited[col] = true;
               }
          }

     }

   void print()
     {
        //print the matrix.
        cout << "   ";
        for (int c = 0; c < _vertices; ++c)
          cout << c << " ";
        cout << endl;
        for (int r = 0; r < _vertices; ++r)
          {
             cout << r << ": ";
             for(int c = 0; c < _vertices; ++c)
               {
                  cout << _matrix[r][c] << " ";
               }
             cout << "\n";
          }
     }

   ~Graph()
     {
        for (int i = 0; i < _vertices; ++i)
          {
             delete []_matrix[i];
          }

        delete []_matrix;
     }
};

#endif
