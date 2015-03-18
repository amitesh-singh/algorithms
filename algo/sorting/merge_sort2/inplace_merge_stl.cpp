// inplace_merge example
#include <iostream>
#include <algorithm>
#include <vector>
#include <iterator>
using namespace std;

int main () {
  int first[] = {5,10,15,20,25,11};
  int second[] = {50,40,30,20,10};
  vector<int> v(11);
  vector<int>::iterator it;

  sort (first,first+6);
  sort (second,second+5);

  copy (first,first+6,v.begin());
  copy (second,second+5,v.begin()+6);

  inplace_merge (v.begin(),v.begin()+5,v.end());
  copy(v.begin(),v.end(),ostream_iterator<int>(cout,"\n"));

  cout << "The resulting vector contains:";
  for (it=v.begin(); it!=v.end(); ++it)
    cout << " " << *it;

  cout << endl;
  
  return 0;
}
