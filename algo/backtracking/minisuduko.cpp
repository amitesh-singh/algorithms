//Use this file as template, just copy and paste
#include<iostream>
#include<cstdlib>
#include<cstdio>

using namespace std;

int T; //test cases
int N; // matrix size
int mat[10][10]; // matrix

bool is_distinct(int m[][10], int x, bool isRow)
{
  int *l = new int[N];

  if (isRow)
  {
    for(int i = 0; i < N; ++i)
    {
      l[i] = m[x][i];
    }
  }
  else
  {
    for(int i = 0; i < N; ++i)
    {
      l[i] = m[i][x];
    }
  }

  for(int i = 0; i < N; ++i)
  {
	if (l[i] == 0) continue;

    for (int j = 0; j < N && i != j; ++j)
    {
      if (l[i] == l[j])
      {
        delete [] l;
        return false;
      }
    }
  }

  delete [] l;
  return true;
}

bool is_valid(int m[][10])
{
  //check for rows
  for (int r = 0; r < N; ++r)
  {
    if (!is_distinct(m, r, true))
      return false;
  }
  //check for cols
  for(int c = 0; c < N; ++c)
  {
    if (!is_distinct(m, c, false))
      return false;
  }

  return true;
}

bool isSafe(int m[][10], int r, int c)
{
    if (r >= 0 && r < N && c >= 0 && c < N)
      return true;
    return false;
}

bool solve(int m[][10], int empties)
{
  if (empties == 0)
    return is_valid(m);

  //check for each cell
  for (int r = 0; r < N; ++r)
  {
    for (int c = 0; c < N; ++c)
    {
      if (m[r][c] != 0) continue;
      // for {1.. N}
      for (int n = 1; n <= N; ++n)
      {
        m[r][c] = n;
        if (is_valid(m) && solve(m, empties - 1))
          return true;
        m[r][c] = 0;
      }
    }
  }

  return false;
}

void printMatrix(int m[][10])
{
  for (int r = 0; r < N; ++r)
  {
    for (int c = 0; c < N; ++c)
    {
      cout << m[r][c] << " ";
    }
    cout << "\n";
  }
}
int main()
{
  //write your test cases in sample.txt
  freopen("./minisuduko.txt", "r", stdin);

  cin >> T;
  for (int t = 1; t <= T; ++t)
  {
    int filledCells = 0;
    cin >> N;
    for (int r = 0; r < N; ++r)
    {
      for (int c = 0; c < N; ++c)
      {
        cin >> mat[r][c];
        if (mat[r][c] != 0)
          filledCells++;
      }
    }

    cout << "Case #" << t << endl;
    if(solve(mat, N * N - filledCells))
    {
      //print mat
      printMatrix(mat);
    }
    else
    cout << "-1" << endl;
  }

  return 0;
}
