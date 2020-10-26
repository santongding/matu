#include<iostream>
#include<cstring>
using namespace std;
class Table{
public:
    Table(float H){
        high=H;
    }
    float GetHigh(){
        return high;
    }
private:
    float high;
};
class Circle{
public:
    Circle(float R){
        radius=R;
    }
    float GetArea(){
        return 3.14f*radius*radius;
    }
private:
    float radius;
};
class RoundTable:public Table,public Circle{
public:
    RoundTable(float R,float H,char *C):Circle(R),Table(H){
        strcpy(color,C);
    }
    char *GetColor(){
        return color;
    }
private:
    char color[20];
};
int main(){
    float radius,high;
	char color[20];
	cin>>radius>>high>>color;

	RoundTable RT(radius,high,color);
	cout<<"Area:"<<RT.GetArea()<<endl;
	cout<<"High:"<<RT.GetHigh()<<endl;
	cout<<"Color:"<<RT.GetColor()<<endl;
	return 0;
}
