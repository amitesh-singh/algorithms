#include <cassert>
#include <iterator>
#include <functional> // greater<>
#include <iostream>

#define SIZE(a) (sizeof(a) / sizeof(*a))

//code for finding kth largest element in union of two arrays
template<class RandomAccessIterator, class Compare>
typename std::iterator_traits<RandomAccessIterator>::value_type
nsmallest_iter(RandomAccessIterator firsta, RandomAccessIterator lasta,
               RandomAccessIterator firstb, RandomAccessIterator lastb,
               size_t n,
               Compare less) {
  //assert(issorted(firsta, lasta, less) && issorted(firstb, lastb, less));
  for ( ; ; ) {
    assert(n < static_cast<size_t>((lasta - firsta) + (lastb - firstb)));
    if (firsta == lasta) return *(firstb + n);
    if (firstb == lastb) return *(firsta + n);

    size_t mida = (lasta - firsta) / 2;
    size_t midb = (lastb - firstb) / 2;
    if ((mida + midb) < n) {
      if (less(*(firstb + midb), *(firsta + mida))) {
        firstb += (midb + 1);
        n -= (midb + 1);
      }
      else {
        firsta += (mida + 1);
        n -= (mida + 1);
      }
    }
    else {
      if (less(*(firstb + midb), *(firsta + mida)))
        lasta = (firsta + mida);
      else
        lastb = (firstb + midb);
    }
  }
}


int main() {
  int a[] = {5,4,3};
  int b[] = {2,1,0};
  int k = 3; // find minimum value, the 1st smallest value in a,b

  int i = k - 1; // convert to zero-based indexing
  int v = nsmallest_iter(a, a + SIZE(a), b, b + SIZE(b),
                         SIZE(a)+SIZE(b)-1-i, std::greater<int>());
  std::cout << v << std::endl; // -> 0
  return v;
}

