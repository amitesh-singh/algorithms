#include <iostream>
#include <cstdio>
#include <cstring>
//MAX radius = 100
using namespace std;

struct Rect
{
   int x, y;
};


static char mem[2 * 100 * 100 * sizeof(Rect)];

static void
_print_matrix(Rect *rect, int r, int c)
{
   for(int i = 0; i < r; ++i)
     {
        for(int j = 0; j < c; ++j)
          {
             cout << "(" << rect[i * c + j].x
               << "," << rect[i * c + j].y  << ")" << "   ";
          }
        cout << "\n";
     }
}

static bool
_is_rect_inside(int i, int j, int r1, int r2)
{
   int c1 = (j - r2) * (j - r2) + (i - r2) *(i - r2) - r2 * r2;
   int c2 = (j - r1) * (j - r1) + (i - r1) * (i - r1) - r1 * r1;

  // cout << "(" << j << "," << i << ":";
  // cout << "c1: " << c1 << " c2: " << c2 << endl;

   int d1 = (j + 1 - r2) * (j + 1 - r2) + (i - r2) *(i - r2) - r2 * r2;
   int d2 = (j + 1 - r1) * (j + 1 - r1) + (i - r1) * (i - r1) - r1 * r1;

   int e1 = (j - r2) * (j - r2) + (i - 1 - r2) *(i - 1 - r2) - r2 * r2;
   int e2 = (j - r1) * (j - r1) + (i - 1 - r1) * (i - 1 - r1) - r1 * r1;

   int f1 = (j + 1 - r2) * (j + 1 - r2) + (i - 1 - r2) * (i - 1- r2) - r2 * r2;
   int f2 = (j + 1 - r1) * (j + 1 - r1) + (i - 1 - r1) * (i - 1 - r1) - r1 * r1;

   if (c1 <= 0 &&  c2 >= 0 && d1 <= 0 && d2 >= 0
       && e1 <= 0 && e2 >= 0 && f1 <=0 && f2 >= 0)
     return true;

   return false;
}

static int
_find_rects_in_circles(int r1, int r2)
{
   if (r1 >= r2)
     return 0;
   int n = 2 * r2;
   Rect *matrix = new(mem) Rect[n * n];

   memset(matrix, 0, n * n);

   //initialize matrix
   // only do calculation for quarter part
   int ret = 0;
   for(int i = 0; i < r2; ++i)
     {
        for (int j = 0; j < r2; ++j)
          {
             //ignore i = 0, j = 0
             if (i == 0 && j == 0) continue;
             //index_row * column + index_column
             matrix[i * r2 + j].x = j;
             //matrix[i * r2 + j].x -= r2;
             matrix[i * r2 + j].y = i;
             //matrix[i * r2 + j].y -= r2;
             //apply first check

             if (_is_rect_inside(i, j, r1, r2))
               ret++;
          }
     }
   //_print_matrix(matrix, r2, r2);

   //lets apply our logic

   return ret;
}

int test_case = 0;
int main()
{
   freopen("input.txt", "r", stdin);

   cin >> test_case;
   int r1, r2;

   for (int test = 1; test <= test_case; ++test)
     {
        //Note: r1 < r2
        cin >> r1;
        cin >> r2;
        cout << r1 << "," << r2 << endl;
        cout << "inside: " << 4 * _find_rects_in_circles(r1, r2) << endl;
     }

   return 0;
}
