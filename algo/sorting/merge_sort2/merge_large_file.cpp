#include <fstream>
#include <iterator>
#include <algorithm>

int main()
{
   std::ifstream in1("in1.txt");
   std::ifstream in2("in2.txt");
   std::ofstream ut("ut.txt");
   std::istream_iterator<int> in1_it(in1);
   std::istream_iterator<int> in2_it(in2);
   std::istream_iterator<int> in_end;
   std::ostream_iterator<int> ut_it(ut, "\n");

   std::merge(in1_it, in_end, in2_it, in_end, ut_it);
}

