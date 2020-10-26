#include <iostream>
using namespace std;
class Vehicle{
public:
	Vehicle(){
		cout<<"Vehicle constructor..."<<endl;
	}
	~Vehicle(){
		cout<<"Vehicle destructor..."<<endl;
	}
	virtual void display()const =0;
	static Vehicle * createCar();
	static Vehicle * createTruck();
	static Vehicle * createBoat();
};
class Car:public Vehicle{
public:
    Car(){
        cout<<"Car constructor..."<<endl;
    }
    ~Car(){
		cout<<"Car destructor..."<<endl;
	}
    void display() const{
        cout<<"This is a car!"<<endl;
    //    puts("This is a car!");
	}
};
class Truck:public Vehicle{
public:
    Truck(){
        cout<<"Truck constructor..."<<endl;
    }
    ~Truck(){
		cout<<"Truck destructor..."<<endl;
	}
    void display() const{
        cout<<"This is a Truck!"<<endl;
    //    puts("This is a !");
	}
};
class Boat:public Vehicle{
public:
    Boat(){
        cout<<"Boat constructor..."<<endl;
    }
    ~Boat(){
		cout<<"Boat destructor..."<<endl;
	}
    void display() const{
        cout<<"This is a Boat!"<<endl;
    //    puts("This is a!");
	}
};
Vehicle * Vehicle::createCar(){return new Car();}
Vehicle * Vehicle::createTruck(){return new Truck();}
Vehicle * Vehicle::createBoat(){return new Boat();}
int main(){
    for(int i=0;i<1;i++)
        Vehicle::createTruck()->display();
 //   delete Vehicle::createBoat();
}
