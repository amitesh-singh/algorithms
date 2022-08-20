#include <iostream>
#include <vector>
#include <cstring>

using namespace std;

/*
   This syntax works for C-style arrays and anything that supports an iterator via begin() and end() functions.
   This includes all standard template library container classes (including std::string) and initialization_list
   (which we’ll cover in the next lesson). You can also make it work for your custom classes by defining iterator-style
   begin() and end() member functions. If you’re using an older class that doesn’t support begin() and end() member functions,
   you can write free standing begin(x) and end(x) functions and this syntax will still work.
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

   int a[] = {10, 11, 12, 2, 45, 23};

   cout << "C array: " << endl;
   for (auto i: a)
     {
        cout << i << " ";
     }
   cout << endl;

   //custom class example

   struct str {
        str(const char *s) {
             if (!s) {
                  throw std::runtime_error("unable to create string with null");
             }
             len_ = strlen(s) + 1;
             data_ = new char[len_];
             strncpy(data_, s, len_);
             data_[len_] = 0;
        }

        char& operator[](int index) const {
             if (index > len_) {
                  throw std::runtime_error("out of index");
             }
             return data_[index];
        }
        const char &get(int index) {
             return data_[index];
        }

        const char *begin() const {
             if (!data_) {
                  throw std::runtime_error("str is not initialized");
             }
             return &data_[0];
        }
        const char *end() const {
             if (!data_) {
                  throw std::runtime_error("str is not initialized");
             }
             return &data_[len_ -1];
        }
        char *begin() {
             if (!data_) {
                  throw std::runtime_error("str is not initialized");
             }
             return &data_[0];
        }

        char *end() {
             if (!data_) {
                  throw std::runtime_error("str is not initialixed");
             }

             return &data_[len_ - 1];
        }

       private:
        char *data_ = nullptr;
        size_t len_ = 0;
   };

   try {
        str s("hey");
        std::cout << s[0] << '\n';
        s[0] = 'g';
        for (const auto &c: s) {
             std::cout << c << " ";
        }
        for (auto &c: s) {
             std::cout << c << " ";
        }
        for (const auto &c: std::string("hey"))
          std::cout << c << " ";

   } catch (const exception &e) {
        std::cout << e.what() << '\n';
   }

   return 0;
}
