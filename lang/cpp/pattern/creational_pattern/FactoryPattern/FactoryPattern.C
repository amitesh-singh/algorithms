#include<iostream>
#include<string>

using namespace std;

class Shape
{
    public:
    virtual ~Shape(){}
    virtual void draw() = 0;
    static Shape *Create(string type);
};

class Circle:public Shape
{
    public:
    void draw() 
    {
        cout << __PRETTY_FUNCTION__ << endl;
    }
};


Shape *Shape::Create(string type)
{
    if(type == "Circle")
        return new Circle();
}
int main()
{
    Shape *obj1 = Shape::Create("Circle");
    obj1->draw();
    delete obj1;


    return 0;
}
