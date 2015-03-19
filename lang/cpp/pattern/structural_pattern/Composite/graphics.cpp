// inspired by 'wiki' example
#include<iostream>
#include<vector>
using namespace std;

//Problem: Implement a graphic class which can be either Ellipse or Group of graphics.

//We can use Composite pattern 
/*
Ellipse => LEAF
Graphic =>Component
GraphicList=> Composite

*/

class Graphic
{
    public:
    virtual void print() = 0;
};

class GraphicGroup:public Graphic
{
    vector<Graphic *> g_;
    public:
    void add(Graphic *g){g_.push_back(g);}
    void print()
    {
        cout << "-----Composite----\n";
        for(int i=0;i<g_.size();++i)
        {
            g_[i]->print();
        }
        cout <<"------Composite Ends----\n";
    }
    ~GraphicGroup()
    {
        for(int i=0;i<0;++i)
        {
            delete g_[i];
        }
    }

};

class Ellipse:public Graphic
{
    public:
    void print()
    {
        cout << "Ellipse\n";
    }
};
int main()
{
    GraphicGroup gg[2];
    //gg[0] == combination of two ellipse
    gg[0].add(new Ellipse);
    gg[0].add(new Ellipse);

    //gg[1] ==> 1 ellipse
    gg[1].add(new Ellipse);
    for(int i =0;i<2;i++)
    {
        gg[i].print();
    }
    return 0;
}
