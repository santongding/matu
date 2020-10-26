#include <iostream>

#include <cmath>

using namespace std;

class Ctriangle{
public:
    Ctriangle(double aa,double bb,double cc){
        a=aa,b=bb,c=cc;
    }
    void display(){
        cout<<"Ctriangle:a="<<a<<",b="<<b<<",c="<<c<<endl;
    }
    double GetPerimeter(){
        return a+b+c;
    }
    double GetArea(){
        double p=(a+b+c)/2.0;

        return sqrt(p*(p-a)*(p-b)*(p-c));
    }
private:
    double a,b,c;
};

int main(){
	double a,b,c;
	cin>>a>>b>>c;
	Ctriangle T(a,b,c);
	T.display();
	cout<<"Perimeter:"<<T.GetPerimeter()<<endl;
	cout<<"Area:"<<T.GetArea()<<endl;
	return 0;
}
