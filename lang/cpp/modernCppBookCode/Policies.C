#include<iostream>
using namespace std;

template<class T>
class OpNewCreator
{
	public:
	static T *Create()
	{
		return new T;
	}
	protected:
	//restricted outsiders to apply delete
	~OpNewCreator()
	{
	}
};

class Widget
{
};
template<template <class> class CreationPolicy>
class WidgetManager:public CreationPolicy<Widget>
{
};
int main()
{

	WidgetManager<OpNewCreator> widgetmanager_;
	Widget *widget1 = widgetmanager_.Create();

	return 0;
}
