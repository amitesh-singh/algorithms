#include <iostream>
#include <cstdio>

using namespace std;

const int rows = 3;
const int cols = 3;

int test_cases = 1;;

static int
_get_max_sum(int **m, int r, int c)
{
   int sum_h = 0, sum_h_max = 0;
   //sum of horizontal
   for (int i = 0; i < rows; ++i)
   {
      for (int j = 0; j < cols; ++j)
        {
           sum_h += m[i][j];
        }
      sum_h_max = max(sum_h_max, sum_h);
      sum_h = 0;
   }

   //Vertical
   int sum_v = 0, sum_v_max(0);

   for (int i = 0; i < cols; ++i)
     {
        for (int j = 0; j < rows; ++j)
          sum_v += m[j][i];

        sum_v_max = max(sum_v_max, sum_v);
        sum_v = 0;
     }

   int sum_d1(0), sum_d_max(0);
   //Diagonal. Left to right
   for (int i = 0, j = 0; i < rows && j < cols; ++i, ++j)
     {
        sum_d1 += m[i][j];
     }
   int sum_d2(0);
   //Diagonal. Right to Left
   for (int i = 0, j = cols - 1; i < rows && j >= 0; ++i, --j)
     {
        sum_d2 += m[i][j];
     }
   sum_d_max = max(sum_d1, sum_d2);

   return max(sum_d_max, max(sum_h_max, sum_v_max));
}

static void
print_matrix(int **m, int r, int c)
{
   for (int i = 0; i < r; ++i)
     {
        for (int j = 0; j < c; ++j)
          {
             printf("%5d", m[i][j]);
          }
        cout << endl;
     }
}

int main()
{
   freopen("sum_input.txt", "r", stdin);

   int **m = new int*[rows];
   for (int i = 1; i <= rows; ++i)
     {
        m[i - 1] = new int[cols];
     }

   for (int test = 1; test <= test_cases; ++test)
     {
        int t = 0;
        cin >> t;
        for (int i = 0; i < rows; ++i)
          for (int j = 0; j < cols; ++j)
            cin >> m[i][j];

        print_matrix(m, rows, cols);
        cout << "#" << t << " " << _get_max_sum(m, rows, cols) << endl;
     }

   //Clean up the matrix
   for (int i = 1; i <=rows; ++i)
     {
        delete [] m[i -1];
     }
   delete [] m;

   return 0;
}
