#include <iostream>
#include <vector>
#include <string>

using namespace std;

/*
   This syntax works for C-style arrays and anything that supports an iterator via begin() and end() functions. This includes all standard template library container classes (including std::string) and initialization_list (which we’ll cover in the next lesson). You can also make it work for your custom classes by defining iterator-style begin() and end() member functions. If you’re using an older class that doesn’t support begin() and end() member functions, you can write free standing begin(x) and end(x) functions and this syntax will still work.

 */
int main()
{
   vector<int> myvector;

   myvector.push_back(10);
   myvector.push_back(20);
   myvector.push_back(12);
   myvector.push_back(16);
   myvector.push_back(17);

   // x is readonly
   for (auto x: myvector)
     cout << x << " ";
   cout << endl;

   // x can be modified
   for (auto& x: myvector)
    ++x;
   cout << "After increment: " << endl;
   for (auto x: myvector)
     cout << x << " ";
   cout << endl;

   // C array example
   int a[] = {10, 11, 12, 2, 45, 23};

   cout << "C array: " << endl;
   for (auto i: a)
     {
        cout << i << " ";
     }
   cout << endl;

   // C++ string example
   cout << "C++ string: ";
   string s = "Gulabo";

   for (auto c: s)
     {
        cout << c;
     }
   cout << "\n";

   // TODO: add custom class example.

   return 0;
}
