#include <iostream>
#include <cstdlib>

//independent queue code.
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
  Pos(): r(0), c(0){}
  Pos(int _r, int _c): r(_r), c(_c) {}
};

int main()
{
  Queue<int> q;
  q.push(10);

  q.push(11);
  q.push(100);

  while(!q.empty())
  {
    int u = q.front();
    q.pop();
    cout << u << ",";
  }
  cout << endl;

  Queue<Pos> pos;

  pos.push(Pos(10, 11));
  pos.push(Pos(11, 12));

  while (!pos.empty())
  {
    Pos p = pos.front();
    pos.pop();
    cout << "(" << p.r << "," << p.c << ")" << endl;
  }

  return 0;
}
