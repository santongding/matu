#include<iostream>
using namespace std;

class Student{
public:
    static double sum[3];
    Student(char *name,char *num,int gd1,int gd2,int gd3){
        Name=name,Num=num,v1=gd1,v2=gd2,v3=gd3;
        sum[0]+=v1,sum[1]+=v2,sum[2]+=v3;
    }
    char * Name,*Num;
    int v1,v2,v3;
    void display(){
        cout<<Name<<" "<<Num<<" "<<v1<<" "<<v2<<" "<<v3<<endl;//%s %s %d %d %d\n",Name,Num,*v1,*v2,*v3);
    }
    static double average1(){
        return sum[0]/3.0;
    }
        static double average2(){
        return sum[1]/3.0;
    }
        static double average3(){
        return sum[2]/3.0;
    }

};
double Student::sum[3]={0};
int main(){
	Student *stu1,*stu2,*stu3;
	char name1[10],name2[10],name3[10];
	char num1[12],num2[12],num3[12];
	int grade1[3],grade2[3],grade3[3];
	cin>>name1>>num1>>grade1[0]>>grade1[1]>>grade1[2];
	cin>>name2>>num2>>grade2[0]>>grade2[1]>>grade2[2];
	cin>>name3>>num3>>grade3[0]>>grade3[1]>>grade3[2];
	stu1 = new Student(name1,num1,grade1[0],grade1[1],grade1[2]);
	stu2 = new Student(name2,num2,grade2[0],grade2[1],grade2[2]);
	stu3 = new Student(name3,num3,grade3[0],grade3[1],grade3[2]);

	stu1->display();
	stu2->display();
	stu3->display();

    cout<<"The average grade of course1:"<<stu2->average1()<<endl;
	 cout<<"The average grade of course2:"<<stu2->average2()<<endl;
	  cout<<"The average grade of course3:"<<stu2->average3()<<endl;
	  return 0;
}
