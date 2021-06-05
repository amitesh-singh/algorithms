#include <iostream>

template<typename T>
struct Node
{
   Node<T> *next {nullptr}, *prev{nullptr};
   T data;
   Node(const T &d): data(d) {}
};


template<typename T>
class List
{
   Node<T> *head {nullptr}, *tail {nullptr};

  public:
   List() {}
   void push_back(const T &d)
     {
        if (tail == nullptr && head == nullptr)
          {
             head = tail = new Node(d);
             return;
          }
        Node<T> *newNode = new Node(d);
        newNode->prev = tail;
        tail->next = newNode;
        tail = newNode;
     }

   void push_front(const T &d)
     {
        if (tail == nullptr && head == nullptr)
          {
             head = tail = new Node(d);
             return;
          }
        Node<T> *newNode = new Node(d);
        newNode->next = head;
        head->prev = newNode;
        head = newNode;
     }

   void print()
     {
        Node<T> *p = head;
        while (p)
          {
             std::cout << p->data << "->";
             p = p->next;
          }
        std::cout << std::endl;
     }

   void clear()
     {
        Node<T> *p = head;
        while (p)
          {
             Node<T> *tmp = p->next;
             delete p;
             p = tmp;
          }
     }

   void reverse()
     {
        if (head == nullptr || head->next == nullptr) return;
        Node<T> *next, *prev;
        Node<T> *p = head;
        while (p)
          {
             prev = p->prev;
             next = p->next;
             std::swap(p->next, p->prev);
             p = p->prev;
          }
        if (prev)
          {
             tail = head;
             head = prev->prev;
          }
     }
};



int main()
{
   List<int> list;
   list.push_back(10);
   list.push_back(11);
   list.push_back(12);
   list.push_front(0);

   list.print();
   list.reverse();
   list.print();
   list.push_front(-1);
   list.push_back(13);
   list.print();
   list.clear();

   return 0;
}
