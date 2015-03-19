#include<iostream>
#include<vector>


//B-Tree - RAM based
template<class T>
class Element
{
    public:
    T data_;
};

template<class E,template<class,class> class Container>
class BTreeNode
{
    public:
    BTreeNode *parent_;
    Container<E,std::allocator<E> > keys_;
    Container<BTreeNode *,std::allocator<BTreeNode *> > children_;
};

int main()
{
    BTreeNode<Element<int>,std::vector> bt;
    bt.parent_ = 0;
    return 0;
}
