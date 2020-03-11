#include <iostream>
#include <list>
#include <algorithm>

//control the order in which draw() function of the list<Shape *> is called.

class Shape
{
    int drawingOrder;
    public:
    Shape(int order): drawingOrder(order) {}
    int getOrder() const { return drawingOrder; }
    virtual void draw() = 0;
};

class Circle: public Shape
{
    public:
    Circle(int drawingOrder = 1): Shape(drawingOrder) {};
    void draw()
    {
        std::cout << "order: " << getOrder() << std::endl;
    }
};

class Rectangle : public Shape
{
    public:
    Rectangle(int drawingOrder = 2): Shape(drawingOrder) {}

    void draw()
    {
        std::cout << "order: " << getOrder() << std::endl;
    }
};


int main()
{
    std::list<Shape *> l {
        new Rectangle(), new Circle(), new Rectangle(), new Circle()
    };

    l.sort([]( const Shape *lhs, const Shape *rhs)->bool
    {
        return lhs->getOrder() - rhs->getOrder();
    });

    for (auto i: l) 
        i->draw();
    for (auto i: l)
        delete i;

    return 0;
}