#include <iostream>

#include <cmath>

using namespace std;

class Crectangle{
public:
    Crectangle(double a,double b){
        w=a;
        h=b;
    }
    void display(){
        cout<<"Crectangle:a="<<w<<",b="<<h<<endl;
    }
    double GetPerimeter(){
        return (w+h)*2.0;
    }
    double GetArea(){
        return w*h;
    }
private:
    double w,h;
};

int main()

{

  double a, b;

  cin >> a >> b;

  Crectangle T(a,b);

  T.display();

  cout << "Perimeter:" << T.GetPerimeter() << endl;

  cout << "Area:" << T.GetArea() << endl;

  return 0;

}
