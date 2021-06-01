#include <iostream>
#include <unordered_set>

//delete dups from a sorted linked list
// 1->1->2->2 
// 1, 2
// 1->2->6->6->4
// 1->2->6->4

template<typename T>
struct listnode
{
   listnode<T> *next = nullptr;
   T val;
   listnode(const T &d): val(d)
   {
      next = nullptr;
   }
};

using node = listnode<int>;

void prepareList(node *&head, int k)
{
   if (head == nullptr)
     {
        head = new node(k);
        return;
     }
   node *p = head;
   while (p->next)
     {
        p = p->next;
     }

   p->next = new node(k);
}

void deleteList(node *&head)
{
   node *p = head;

   while (p)
     {
        node *next = p->next;
        delete p;
        p = next;
     }
}

//we need a dummy head here
node *deleteDups(node *&head)
{
   if (head == nullptr)
     return head;

   node *curr = head;
   node *prev {nullptr};
   std::unordered_set<int> s;

   while (curr)
     {
        if (s.find(curr->val) != s.end())
          {
             node *next = curr->next;
             prev->next = next;
             delete curr;
             curr = next;
             continue;
          }
        else
          {
             s.insert(curr->val);
          }
        prev = curr;
        curr = curr->next;
     }

   return head;
}

void print(node *head)
{
   if (head == nullptr)
     {std::cout << "[]\n"; return;}

   node *p = head;
   while (p)
     {
        std::cout << p->val << "->";
        p = p->next;
     }
   std::cout << std::endl;
}

int main(int argc, char **argv)
{
   if (argc != 2)
     {
        std::cerr << argv[0] << " <inputfile>\n";
        return 1;
     }
   freopen(argv[1], "r", stdin);
   int T;
   std::cin >> T;
   for (int i = 1; i <= T; ++i)
     {
        int n;
        std::cin >> n;
        node *head = nullptr;
        for (int j = 0; j < n; ++j)
          {
             int val;
             std::cin >> val;
             prepareList(head, val);
          }
        std::cout << "input: ";
        print(head);
        node *newhead = deleteDups(head);
        std::cout << "output: ";
        print(newhead);

        deleteList(newhead);
        std::cout << std::endl;
     }
   return 0;
}
