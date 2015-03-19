//Abstract Factory method implementation.
//wrote on 06/02/2012

#include<iostream>
using namespace std;


class Button
{
public:
	virtual void paint() =0;
	virtual ~Button()
	{
	}
};

class WinButton:public Button
{
public:
	void paint()
	{
		cout << "win button\n";
	}

};

class MacButton:public Button
{
public:
	void paint()
	{
		cout << "mac button\n";
	}
};

class GUIFactory
{
public:
	virtual Button *createButton() = 0;
	virtual ~GUIFactory()
	{
	}
};

class WinFactory:public GUIFactory
{
public:
	Button *createButton()
	{
		return new WinButton();
	}
	~WinFactory()
	{
	}
};
class MacFactory:public GUIFactory
{
public:
	Button *createButton()
	{
		return new MacButton();
	}
	~MacFactory()
	{
	}
};

class Application
{
public:
	//TODO null check?
	Application(GUIFactory *factory)
	{
		Button *button = factory->createButton();
		button->paint();
		delete button;
		delete factory;
	}
};

GUIFactory *getFactory()
{
	int input;
	cout << "Enter OS: 1 - Window, 2 - MAC OSx\n";
	cin >> input;
	if(input == 1)
		return new WinFactory();
	else if(input == 2)
		return new MacFactory();
	else
		return 0;
}

#define DEBUG
#ifdef DEBUG
int main(int argc,char **argv)
{

	Application app(getFactory());
	int i;
	cin >> i;
	return 0;
}
#endif