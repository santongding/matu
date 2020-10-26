#include <iostream>
using namespace std;
class Location{
public:
	Location(int xx,int yy){
		x =xx;
		y =yy;
	}
Location &operator +(Location &offset);
Location &operator -(Location &offset);

int getX(){return x;}
int getY(){return y;}
private:
	int x;
	int y;
};
Location &Location::operator+(Location &offset){
    x+=offset.getX();
    y+=offset.getY();
    return *this;
}
Location &Location::operator-(Location &offset){
    x-=offset.getX();
    y-=offset.getY();
    return *this;
}
