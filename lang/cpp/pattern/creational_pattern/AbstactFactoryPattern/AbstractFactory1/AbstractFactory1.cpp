#include<iostream>

using namespace std;
#define __func__ __FUNCTION__
class Shape
{
public:
	Shape()
	{
		puts(__func__);
	}
	virtual void Draw() = 0;
	virtual ~Shape()
	{
	}
};
class Circle:public Shape
{
public:
	Circle()
	{
		puts(__func__);
	}
	void Draw()
	{
		puts(__func__);
	}
};
class Triangle:public Shape
{
public:
	Triangle()
	{
		puts(__func__);
	}
	void Draw()
	{
		puts(__func__);
	}
};
class Polygon:public Shape
{
public:
	Polygon()
	{
		puts(__func__);
	}
	void Draw()
	{
		puts(__func__);
	}
};

class Ellipse:public Shape
{
public:
	Ellipse()
	{
		puts(__func__);
	}
	void Draw()
	{
		puts(__func__);
	}
};
class Factory
{
public:
	virtual Shape *createStraightShapes() = 0;
	virtual Shape *createCurveShapes() = 0;
	virtual ~Factory()
	{
	}
};

class SimpleFacory:public Factory
{
public:
	Shape* createStraightShapes()
	{
		return new Triangle();
	}
	Shape* createCurveShapes()
	{
		return new Circle();
	}
};
class ComplexFactory:public Factory
{
public:
	Shape* createStraightShapes()
	{
		return new Polygon();
	}
	Shape *createCurveShapes()
	{
		return new Ellipse();
	}
};

Factory *getFactory()
{
	int i;
	cout << "enter simple (0) or complex (1) structure:\n";
	cin >> i;
	switch(i)
	{
	case 0:
		return new SimpleFacory();
	case 1:
		return new ComplexFactory();
	default:
		//basically, do nothing.
		return 0;
	}
}
class App
{
public:
	App(Factory *factory)
	{
		Shape* shape1 = factory->createStraightShapes();
		Shape* shape2 = factory->createCurveShapes();
		shape1->Draw();
		shape2->Draw();
		delete shape1;
		delete shape2;
		delete factory;
	}
	~App()
	{
	}
};
int main()
{
	App app(getFactory());
	
	char ch;
	cin >> ch;
	return 0;
}