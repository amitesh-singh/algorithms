#include <iostream>

template<size_t size>
struct mempool
{
   char mem[size];
   size_t index;
   mempool(): index(0) {}
   void print()
     {
        for (int i = 0; i < index; ++i)
          std::cout << std::hex << int(mem[i]) << " ";
        std::cout << std::endl;
     }
};
mempool<100> MEM;

void *operator new(size_t size, mempool<100> &m)
{

   void *ret = ::new (m.mem + m.index) char[size];
   m.index += size;
   return ret;
}

int main()
{
   int *p = new (MEM) int;
   *p = 2;

   char *p2 = new (MEM) char('A');
   *p2 = 'A';

   MEM.print();
   return 0;
}
