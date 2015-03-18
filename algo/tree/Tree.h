#ifndef __TREE_H_
#define __TREE_H
//This is a design for a binary Tree with Edges
//remember acyclic graphs?
#include<iostream>
using namespace std;
#define F cout<< __PRETTY_FUNCTION__ << endl
namespace ami
{
    //FWD declaration
    template<class N,class E>
    struct Edge;
    

    template<class N,class E>
    struct Node
    {
        Edge<N,E> *left,*right;
        N data;
        void print()
        {
            cout << "Node:\n";
            cout << data << endl;
            cout << "Edges:\n";
            if(left!=0)
            cout << left->data << endl;
            if(right!=0)
            cout << right->data << endl;
            cout << "=============\n";
        }
        Node():left(0),right(0){}
        Node(const Node<N,E> &node):left(node.left),right(node.right),data(data){}
    };
    template<class N,class E>
    struct Edge 
    {
        Node<N,E> *link;
        E data;
        Edge():link(0){}
        
        Edge(const Edge<N,E> &edge):link(edge.link),data(edge.data){cout << data << endl;}
        Edge(Node<N,E> &node)
        {
            Node<N,E> *newNode = new Node<N,E>();
            newNode->data = node.data;
            link = newNode;
        }
    };

    template<class N,class E>
    class TreeE
    {
        void insertEdge(Node<N,E> *&r,Edge<N,E> *&newEdge)
        {
            F;
            if(r->left == 0 && r->data<newEdge->link->data)
            {
                r->left = newEdge;
                return;
            }
            else if(r->right == 0 && r->data >newEdge->link->data)
            {
                r->right = newEdge;
                return;
            }

            if(r->data<newEdge->link->data)
                insertEdge(r->left->link,newEdge);
            else if(r->data >newEdge->link->data)
                insertEdge(r->right->link,newEdge);
        }
        void print(Node<N,E> *r)
        {
            if(r == 0)
                return;
            if(r->left != 0)
             print(r->left->link);
             r->print();
             if(r->right!=0)
                 print(r->right->link);
        }
        public:
        Node<N,E> *root;
        TreeE():root(new Node<N,E>()){F;}
        void InsertEdge(Edge<N,E> &edge)
        {
            F;
            Edge<N,E> *newEdge = new Edge<N,E>(edge);
            insertEdge(root,newEdge);
        }
        void Print()
        {
            print(root);
        }

    };

    




}
#endif
