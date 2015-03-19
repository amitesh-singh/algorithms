#ifndef _BTREE_H_
#define _BTREE_H_
#include<iostream>
#include<vector>


template<class T>
class Element
{
    public:
    T data_;
};

//
//
//
template<template<class> class T,template<class,class> class Container>
class BTreeNode
{
    public:
    BTreeNode *parent;
    Container<BTreeNode *,std::allocator<BTreeNode *> > children_;
    Container<T,std::allocator<T> >  keys_;
    bool leaf;
};

template<class T,template<class,class> class Container>
class BTree
{
    typedef void (*v_fun)(Element<T> &);
    public:

    int order_;
    BTreeNode<T,Container> *root_;
};

#endif
