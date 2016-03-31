#include <iostream>

using namespace std;

static void
printRange(int n1, int n2)
{
  //base case
  if (n1 == n2)
  {
    cout << n1 << ",";
  }
  else
  {
    //recursive case
    cout << n1 << ",";
    printRange(n1 + 1, n2);
  }
}

int main()
{
  printRange(10, 21);
  cout << endl;

  printRange(100, 200);
  cout << endl;

  return 0;
}
