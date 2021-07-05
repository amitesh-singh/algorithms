//range min query
// find min value in an array for a range i, j
// 10, 12, 33, -1, 0, 1
//check notes for more details
//

#include <iostream>
#include <vector>
#include <initializer_list>
class segment_tree
{
   using vi = std::vector<int>;
   int n;
   vi st, &A;

   int left(int idx)
     {
        return (idx << 1) + 1;
     }

   int right (int idx)
     {
        return (idx << 1) + 2;
     }

   int parent(int idx)
     {
        return (idx - 1)/2;
     }

   //Top to bottom approach
   void build(int idx, int L, int R)
     {
        if (L == R)
          {
             st[idx] = L;
             return;
          }

        build(left(idx), L, (L + R)/2);
        build(right(idx), (L + R)/2 + 1, R);

        int p1 = st[left(idx)], p2 = st[right(idx)];
        st[idx] = A[p1] <= A[p2] ? p1 : p2;
     }

   // returns the index of min value in the given range
    int rmq(int idx, int L, int R, int i, int j)
      {
         if (i > R or j < L) return -1;
         if (i <= L and j >= R) return st[idx];

         int p1 = rmq(left(idx), L, (L + R)/2, i, j);
         int p2 = rmq(right(idx), (L + R)/2 + 1, R, i, j);

         if (p1 == -1) return p2;
         if (p2 == -1) return p1;
         return A[p1] <= A[p2] ? p1 : p2;
      }


  public:
    segment_tree(vi &input): n(input.size()), A(input)
   {
      st.reserve(4 *n);
      st.assign(4 * n, 0);

      build(0, 0, n - 1);
   }

   void rebuild(vi &input)
     {
        n = input.size();
        A = input;

        build(0, 0, n - 1);
     }

   int rmq(int i, int j)
     {
        return rmq(0, 0, n - 1, i, j);
     }

   //bottom to top
   void update(int array_index)
     {
        if (array_index >= n) return;
        //position of array element in segment tree would be +n of index
        int pos = array_index + n;
        
        while (pos != 0)
          {
             pos = parent(pos);
             st[pos] = A[st[left(pos)]] <= A[st[right(pos)]] ? st[left(pos)]: st[right(pos)];
          }
       // st[pos] = A[st[left(pos)]] <= A[st[right(pos)]] ? st[left(pos)]: st[right(pos)];
     }

   void print()
     {
        std::cout << "size: " << n << std::endl;
        for (auto &x: st)
          {
             std::cout << x << ",";
          }
        std::cout << "\n";
     }
};


int main()
{
   std::vector<int> v{18, 17, 12, 19, 15, 11, -2};
   for (auto &x: v)
     std::cout << x << "->";
   std::cout << std::endl;
   segment_tree stree(v);

   std::cout << "index: rmq(0, 6): " << stree.rmq(0, 6) << std::endl;

   std::cout << "updating an element:\n";
   v[0] = 1;
   stree.update(0);
   for (auto &x: v)
     std::cout << x << "->";
   std::cout << std::endl;

   std::cout << "index: rmq(0, 6): " << stree.rmq(0, 6) << std::endl;
   //we need to rebuild the segment tree if an element is deleted or added
   std::cout << "deleting an element\n";
   v.pop_back();

   stree.rebuild(v);

   std::cout << "index: rmq(0, 5): " << stree.rmq(0, 5) << std::endl;
   for (auto &x: v)
     std::cout << x << "->";
   std::cout << std::endl;
   return 0;
}
