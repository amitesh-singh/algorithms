//
// this example shows the matrix bfs traversal level. We have a matrix named bfs_matrix[][] which shows the
// level of traversal from a point - very good conceptual
// this is helful in case of you need to know who gonna win a race if two objects are present
// in matrix and everybody is running.

#include <iostream>
#include <cstdio>
#include <cstdlib>

using namespace std;

template<class T>
class Queue
{
  T mem[101];
  int f, r;
public:
  Queue(): f(-1), r (-1) {}

  bool empty()
  {
    return (f == -1 && r == -1);
  }

  T front()
  {
    if (empty())
    {
      cerr << "queue is empty!" << endl;
      abort();
    }
    return mem[f];
  }

  void push(T s)
  {
    if (empty())
    {
      f = r = 0;
    }
    else
    r = (r + 1) % 101;
    mem[r] = s;
  }

  void pop()
  {
    if (empty())
    {
      cerr << "underflow";
      abort();
    }
    else if (f == r) // note this ***
    {
      f = r = -1;
    }
    else
    f = (f + 1) % 101;

  }

};

struct Pos
{
  int r, c;
  int d;
  Pos(): r(0), c(0), d(0){}
  Pos(int _r, int _c, int _d): r(_r), c(_c), d(_d) {}
};


int T;
int R, C; //row and columns

int m[10][10]; // matrix
int bfs_matrix[10][10]; // this shows the traversal of object from a position in matrix to its peers
int sol[10][10];
            //  Up Down Left Right
const int dr[] = {-1, 1, 0, 0};
const int dc[]   = {0, 0, -1, 1};

bool isSafe(int r, int c, int mat[][10])
{
  if (r >= 0 && r < R && c >= 0 && c < C)
    return true;

  return false;
}

void bfsUtil(int r, int c, int mat[][10])
{
  int level = 1;
  Queue<Pos> q;

  q.push(Pos(r, c, 0));
  sol[r][c] = 1;
  bfs_matrix[r][c] = 0;
  while (!q.empty())
  {
    Pos curr = q.front();
    q.pop();
    sol[curr.r][curr.c] = 1;

    //Left, right, top and bottom
    for (int i = 0; i < 4; ++i)
    {
      int ddr = curr.r + dr[i];
      int ddc = curr.c + dc[i];
      if (isSafe(ddr, ddc, mat) && !sol[ddr][ddc])
      {
        bfs_matrix[ddr][ddc] = curr.d + 1;
        q.push(Pos(ddr, ddc, curr.d + 1));
      }
    }
  }
}

void bfs(int r, int c, int mat[][10])
{
  bfsUtil(r, c, mat);
}

void printMatrix(int mat[][10])
{
  for (int i = 0; i < R; ++i)
  {
    for (int j = 0; j < C; ++j)
    {
      cout << mat[i][j] << " ";
    }
    cout << "\n";
  }
}

int main()
{
  freopen("./bfs_matrix.txt", "r", stdin);

  int r, c;
  cin >> T;
  for (int t = 1; t <= T; ++t)
  {
    //int r, c; //start Positions
    cin >> R >> C;
    cin >> r >> c;

    for(int i = 0; i < R; ++i)
    {
      for (int j = 0; j < C; ++j)
      {
        cin >>  m[i][j];
        sol[i][j] = 0;
      }
    }
    //Write your algo here.
    bfs(r, c, m);
    printMatrix(bfs_matrix);

  }

  return 0;
}

//sol[i][j] = 0;
