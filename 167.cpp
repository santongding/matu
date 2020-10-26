#include <iostream>
using namespace std;
class Shape{
public:
	Shape(){}
	~Shape(){}
	virtual double GetArea()=0;
	virtual double GetPerimeter()=0;
	static Shape* createRectangle(double length,double width);
	static Shape* createCircle(double radius);
};
class Rectangle:public Shape{
public:
    Rectangle(double ll,double ww){
        l=ll,w=ww;
    }
    double GetArea(){
        return l*w;
    }
    double GetPerimeter(){
        return (l+w)*2.0;
    }
private:
    double l,w;
};
class Circle:public Shape{
public:
    Circle(double ll){
        r=ll;
    }
    double GetArea(){
        return 3.14*r*r;
    }
    double GetPerimeter(){
        return 6.28*r;
    }
private:
    double r;
};
Shape * Shape::createRectangle(double l,double w){return new Rectangle(l,w);}
Shape * Shape::createCircle(double r){return new Circle(r);}
