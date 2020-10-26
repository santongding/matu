#include <iostream>
#include<cstring>
using namespace std;
class Person{
public:
	Person(char *name,char sex,char *ID,char *birthday){
		strcpy(this->name,name);
		this->sex =sex;
		strcpy(this->ID,ID);
		strcpy(this->birthday,birthday);
	}
	virtual void display(){
		cout<<"Name:"<<name<<endl;
		cout<<"Sex:"<<sex<<endl;
		cout<<"ID:"<<ID<<endl;
		cout<<"Birthday:"<<birthday<<endl;
	}
	Person* createStu_Techer(char *name,char sex,char *ID, char *birthday,char *position,char *major);
	Person* createStudent(char *name,char sex,char *ID,char *birthday,char *major);
	Person* createTeacher(char *name,char sex, char *ID,char *birthday,char *position);
private:
	char name[20];
	char sex;
	char ID[20];
	char birthday[12];
};
#include <iostream>
#include<cstring>
//#include "Person.h"
using namespace std;
class Student:virtual public Person{
public:
    Student(char *name,char sex,char *ID,char *birthday,char *major):Person(name,sex,ID,birthday){
        strcpy(this->major,major);
    }
    void display()override{
		cout<<"Major:"<<major<<endl;
	}

private:
    char major[100];
};

class Teacher:virtual public Person{
public:
    Teacher(char *name,char sex,char *ID,char *birthday,char *position):Person(name,sex,ID,birthday){
        strcpy(this->position,position);
    }
    void display()override{
		cout<<"Position:"<<position<<endl;
	}

private:
    char position[100];
};
class Stu_Teacher:public Student,public Teacher{
public:

    Stu_Teacher(char *name,char sex,char *ID,char *birthday,char * position,char *major):Person(name,sex,ID,birthday),Student(name,sex,ID,birthday,major),Teacher(name,sex,ID,birthday,position){

    }


    void display()override{
        Person::display();
		Student::display();
		Teacher::display();
	}
};
Person* Person::createStudent(char *name,char sex,char *ID,char *birthday,char *major){
	return new Student(name,sex,ID,birthday,major);
}
Person* Person::createTeacher(char *name,char sex, char *ID,char *birthday,char *position){
	return new Teacher(name,sex,ID,birthday,position);
}
Person* Person::createStu_Techer(char *name,char sex,char *ID, char *birthday,char *position,char *major){
	return new Stu_Teacher(name,sex,ID, birthday,position,major);
}
int main(){
    string s[10];
    for(int i=0;i<6;i++)cin>>s[i];
    Person p(&s[0][0],s[1][0],&s[2][0],&s[3][0]);
    p.display();
    Person *tp=p.createTeacher(&s[0][0],s[1][0],&s[2][0],&s[3][0],&s[4][0]);
    tp->display();
}
