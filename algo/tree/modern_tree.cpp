#include <iostream>
#include <optional>
#include <vector>
#include <memory>

template<typename T>
struct Tree
{
   struct Node
     {
        T value_ = T{};
        Node *left = nullptr;
        Node *right = nullptr;
     };

   Node *add(auto&&... args)
     {
        storage_.push_back(std::make_unique<Node>(std::forward<decltype(args)>(args)...));
        return storage_.back().get();
     }
   Node *root;
   void print()
     {
        for (auto &v: storage_) {
             std::cout << "val: " << v->value_ << std::endl;
        }
     }
  private:
   std::vector<std::unique_ptr<Node>> storage_;

};

int main()
{
   Tree<std::string> tree;

   tree.root = tree.add("root node");
   tree.root->left = tree.add("left node");
   tree.root->right = tree.add("right node");

   tree.print();

   return 0;
}
