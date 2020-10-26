#include<cmath>
#pragma once

class ShapeFactory
{
public:
	 ShapeFactory(){};
	 virtual ~ShapeFactory(){};

	 virtual float Circumstance(){return 0;};
	 ShapeFactory *Create(float a,float b,float c);
	 ShapeFactory *Create(float a,float b,float c,float d);
	 ShapeFactory *Create(float r);
};
#include "ShapeFactory.h"
class T:public ShapeFactory{
public:
    T(float A,float B,float C){
        a=A,b=B,c=C;
    }
    float Circumstance()override{
        return a+b+c;

    };
private:
    float a,b,c;
};
ShapeFactory *ShapeFactory::Create(float a,float b,float c){
    return new T(a,b,c);
}

class Rec:public ShapeFactory{
public:
    Rec(float A,float B,float C,float D){
        a=A,b=B,c=C,d=D;
    }
    float Circumstance()override{
        return a+b+c+d;

    };
private:
    float a,b,c,d;
};
ShapeFactory *ShapeFactory::Create(float a,float b,float c,float d){
    return new Rec(a,b,c,d);
}
class R:public ShapeFactory{
public:
    R(float R){
        r=R;
    }
    float Circumstance()override{
        return 3.14f*r*2.0f;

    };
private:
    float r;
};
ShapeFactory *ShapeFactory::Create(float r){
    return new R(r);
}
