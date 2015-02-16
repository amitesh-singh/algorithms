#include <iostream>
#include <cstdio>

using namespace std;

static void
print_matrix(int *m, int rows, int cols)
{
   int i = 0;
   for (; i < rows * cols; ++i)
     {
        cout << m[i] << ",";
     }

   cout << endl;
}

static void
_print_2d_matrix(int **m, int rows, int cols)
{
   for (int i = 0; i < rows; ++i)
     {
        for (int j = 0; j < cols; ++j)
          {
//             cout << m[i][j] << ",";
             printf("%5d ,", m[i][j]);
          }
        cout << endl;
     }
}

int main()
{
   const int rows = 4, col = 4;

   //1st way.
   int *matrix = new int[rows * col];

   for(int i = 0; i < rows * col; ++i)
     {
        matrix[i] = i;
     }

   print_matrix(matrix, rows, col);

   delete []matrix;

   //2nd way
   int **m =new int*[rows];

   for (int i = 0; i < rows; ++i)
     {
        m[i] = new int[col];
     }

   int x = 0;
   for (int i = 0; i < rows; ++i)
     {
        for (int j = 0; j < col; ++j)
          {
             m[i][j] = x++;
          }
     }

   cout << "2d matrix: \n";
   _print_2d_matrix(m, rows, col);

   //clean up
   for(int i = 0; i < rows; ++i)
     {
        delete []m[i];
     }

   delete []m;

   //3rd way

   return 0;
}
