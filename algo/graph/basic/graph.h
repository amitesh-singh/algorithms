#ifndef GRAPH_H
#define GRAPH_H

#include <iostream>
#include <string>
#include <vector>
#include <map>

#define F std::cout << __func__ << std::endl

class Graph
{
   class Vertex;
   //DO not expose edge public
   class Edge
     {
      public:
         Edge(Vertex *src, Vertex *dest, int w)
            :_src(src), _dest(dest), _weight(w)
           {
              F;
           }
         //making it public for easy access inside the graph class.
         int _weight;
         Vertex *_src, *_dest;
     };
   //do not expose vertex
   class Vertex
     {
      public:
         //making it public for easy access inside the graph class.
         std::vector<Edge *> _edges;
         std::string _id; //name ?
         Vertex(std::string id):_id(id)
           {
           }
         void addEdge(Edge *e)
           {
              if (e)
                _edges.push_back(e);
           }
         void print()
           {
              std::cout << ":" << _id << "->";
              std::cout << "edge count: " << _edges.size();
             for (int j = 0; j < _edges.size(); ++j)
               {
                  std::cout << _edges[j]->_weight << ",";
               }
             std::cout << std::endl;
           }
     };

   void addVertex(Vertex *v)
     {
        //if not found
        if (vertices.find(v->_id) == vertices.end())
          {
             vertices[v->_id] = v;
          }
        else
          {
             std::cout << "We already have " << v->_id << std::endl;
          }
     }
   bool find(std::string id)
     {
        return (vertices.find(id) != vertices.end());
     }
 public:
   void AddEdges(std::string src, std::string dest, int w)
     {
        Vertex *vSrc = 0, *vDest = 0;
        bool is_src = false;
        bool is_dest = false;
        if (!find(src))
          vSrc = new Vertex(src);
        else
          is_src = true;
        if (!find(dest))
          vDest = new Vertex(dest);
        else
          is_dest = true;

        Edge *edge = new Edge(vSrc, vDest, w);

        if (!is_src)
          vSrc->addEdge(edge);
        else
          vertices[src]->addEdge(edge);

        if (!is_dest)
          vDest->addEdge(edge);
        else
          vertices[dest]->addEdge(edge);

        addVertex(vSrc);
        addVertex(vDest);
     }

   void print()
     {
        std::map<std::string, Vertex *>::iterator itr = vertices.begin();

        for (;itr != vertices.end(); ++itr)
          {
             itr->second->print();
          }
     }

 private:
   //In this case, vertices needs to be unique? is n't it?
   //std::vector<Vertex *> vertices;
   //now lets make it better 
   std::map <std::string, Vertex *> vertices;
};

#endif
