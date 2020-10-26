#include<iostream>

#include<cmath>

using namespace std;

class Point{
public:
    double a,b;
    Point(double,double);
    double Distance(const Point &p){
        return sqrt(pow((a-p.a),2)+pow(b-p.b,2));
    }
};

int main(){

double a,b,c,d;

cin>>a>>b>>c>>d;

Point A(a,b),B(c,d);

cout<<A.Distance(B)<<endl;

return 0;

}

Point::Point(double a,double b){

this->a=a;

this->b=b;

}
