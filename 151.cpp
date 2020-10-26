#include <iostream>
#include "Building.h"
#include<bits/stdc++.h>
using namespace std;
/*class Building{
public:
	Building(char *name,int floor,int room,int area){
		strcpy(this->name,name);
		this->floor = floor;
		this->room = room;
		this->area = area;
	}
	virtual void display(){
		cout<<"Name:"<<name<<endl;
		cout<<"Floor:"<<floor<<endl;
		cout<<"Room:"<<room<<endl;
		cout<<"Area:"<<area<<endl;
	}
	Building * createTeachBuilding(char *name,int floor,int room,int area,char *function);
	Building * creatDormBuilding(char *name,int floor,int room,int area,int peoples);
protected:
	char name[20];
	int floor;
	int room;
	float area;

};*/
class TeachBuilding:public Building{
public:
    TeachBuilding(char *name,int floor,int room,int area,char *function):Building(name,floor,room,area){
        strcpy(this->function,function);
    }
    void display()override{
        Building::display();
        cout<<"Function:"<<function<<endl;
    }
private:
    char function[20];
};
Building* Building::createTeachBuilding(char *name,int floor,int room,int area,char *function){
	return  new TeachBuilding(name,floor,room,area,function);
}
class DormBuilding:public Building{
public:
    DormBuilding(char *name,int floor,int room,int area,int peoples):Building(name,floor,room,area){
        this->peoples=peoples;
    }
    void display()override{
        Building::display();
        cout<<"Peoples:"<<peoples<<endl;
    }
private:
    int peoples;
};
Building * Building::creatDormBuilding(char *name,int floor,int room,int area,int peoples){
	return new DormBuilding(name,floor,room,area,peoples);
}
