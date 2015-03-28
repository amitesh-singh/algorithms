#ifndef _MY_GRAPH_H
#define _MY_GRAPH_H

#include <iostream>
#include <map>
#include <list>
#include <queue>

using namespace std;

enum Color { WHITE, GREY, BLACK};

struct Vertex
{
    int _n;
    Color _color;

    Vertex(int n):_n(n), _color(WHITE) {}

    void print()
    {
        cout << _n << " visited\n";
    }

    Vertex(Vertex &c):_n(c._n), _color(c._color)
    {
    }
};

class Graph
{
    struct Compare
    {
    };
    map<Vertex *, list<Vertex *> *, Compare> _adj;

public:
    Graph()
    {
    }

    ~Graph()
    {

    }

    Vertex *getVertex(int n)
    {
        map<Vertex *, list<Vertex *> *>::iterator itr = _adj.begin();

        for (; itr != _adj.end(); ++itr)
        {
            if (itr->first->_n == n)
                return itr->first;
        }

        return nullptr;
    }

    void addEdges(Vertex *v1, Vertex *v2)
    {
        //This is undirected graph.
        //find v1
        map<Vertex *, list<Vertex *> *>::iterator itrV1 = _adj.find(v1);
        map<Vertex *, list<Vertex *> *>::iterator itrV2 = _adj.find(v2);

        if (itrV1 != _adj.end())
        {
            cout << "v1..\n";
            _adj[v1]->push_back(v2);
        }
        else
        {
            cout << "empty v1..\n";
            list<Vertex *> *l = new list<Vertex *>();
            l->push_back(v2);
            _adj[v1] = l;

        }

        if (itrV2 != _adj.end())
        {
            cout << "v2..\n";
            _adj[v2]->push_back(v1);
        }
        else
        {
            cout << "empty v2..\n";
            list<Vertex *> *l = new list<Vertex *>();;
            l->push_back(v1);
            _adj[v2] = l;
        }        
    }

    void BFS(Vertex *v)
    {
        queue<Vertex *> q;

        v->_color = GREY;
        q.push(v);

        while(!q.empty())
        {
            Vertex *current = q.front();
            q.pop();

            list<Vertex *>::iterator itr = _adj[current]->begin();
            for (; itr != _adj[current]->end(); ++itr)
            {
                if ((*itr)->_color == WHITE)
                {
                    (*itr)->_color = GREY;
                    q.push(*itr);
                    cout << "pushing ..";
                    (*itr)->print();
                }
            }

            current->_color = BLACK;
            current->print();            
        }

    }
};

#endif