#include <iostream>

#include <cmath>

using namespace std;

class circle{
public:
    circle(double a){
        r=a;
    }
    void display(){
        cout<<"circle:a="<<r<<endl;
    }
    double GetPerimeter(){
        return 3.14*r*2.0;
    }
    double GetArea(){
        return 3.14*r*r;
    }
private:
    double r;
};

int main()

{

  double a;

  cin >> a;

  circle T(a);

  T.display();

  cout << "Perimeter:" << T.GetPerimeter() << endl;

  cout << "Area:" << T.GetArea() << endl;

  return 0;

}
