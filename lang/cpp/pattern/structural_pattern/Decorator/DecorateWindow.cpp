#include<iostream>
using namespace std;
#define F cout << __PRETTY_FUNCTION__ << endl

//interface 
//low level denom
class Window
{
    public:
    virtual void draw() = 0;
    virtual ~Window()
    {
        F;
    }
};

class SimpleWindow:public Window
{
    public:
    void draw()
    {
        F;
    }
    ~SimpleWindow()
    {
        F;
    }

};


class Decorator:public Window
{
    protected:
        Window *window_;
    public:
    Decorator(Window *w):window_(w)
    {
        F;
    }
    virtual void draw()
    {
        window_->draw();
    }
    virtual ~Decorator()
    {
        F;
        delete window_;
    }
};

class BorderDecorator:public Decorator
{
    public:
    BorderDecorator(Window *w):Decorator(w)
    {
        F;
    }
    void draw()
    {
        Decorator::draw();
        F;
    }
    virtual ~BorderDecorator()
    {
        F;
 //       delete window_;
    }
};

class ScrollDecorator:public Decorator
{
    public:
    ScrollDecorator(Window *w):Decorator(w)
    {
        F;
    }
    void draw()
    {
        Decorator::draw();
        F;
    }
    virtual ~ScrollDecorator()
    {
        F;
   //     delete window_;
    }
};


int main()
{
    Window *w = new BorderDecorator(new ScrollDecorator(new SimpleWindow));
    w->draw();
    delete w;
    return 0;
}
