#include <iostream>
#include <string>
#include <vector>
//serial data for a linked list with random pointers
//1->2,2->4,3->1

struct node
{
   std::string d1, d2;
   node(std::string d1, std::string d2): d1(d1), d2(d2) {}
   void print()
     {
        std::cout << d1 << "->" <<  d2 << ",";
     }
};
void tokenize(const std::string &str, std::string delim1, std::string delim2, std::vector<node> &ans)
{
    if (str == "") return;

    int start = 0;
    int end = str.find(delim1);
    while (end != std::string::npos)
      {
         std::string tmp(str.substr(start, end - start));
         int pos = tmp.find(delim2, 0);
         std::string d1 = tmp.substr(0, pos);
         std::string d2 = tmp.substr(pos + delim2.size());
         ans.push_back(node(d1, d2));

         start = end + delim1.size();
         end = str.find(delim1, start);
      }
    std::string tmp(str.substr(start));
    int pos = tmp.find(delim2, 0);
    std::string d1 = tmp.substr(0, pos);
    std::string d2 = tmp.substr(pos + delim2.size());
    ans.push_back(node(d1, d2));
}

int main()
{
    std::vector<node> ans;
    tokenize("1->2,3->4,5->6", ",", "->", ans);
    for (auto &x: ans)
      {
         x.print();
      }
    std::cout << std::endl;

    return 0;
}
