#include<iostream>
using namespace std;
class Date{
public:
	Date(int y=1996,int m=1,int d=1){
		day = d;
		month = m;
		year = y;
		if (m>12 || m<1)
		{
			month=1;
		}
		if (d>days(y,m))
		{
			cout<<"Invalid day!"<<endl;
			day=1;
		}
	};
    int days(int year,int month){
    int d[]={31,28,31,30,31,30,31,31,30,31,30,31};
    if(year%100){
        if(!year%4)d[1]++;
    }else{
        if(year%400==0)d[1]++;
    }
    return d[month-1];
}
	void display(){
		cout<<year<<"-"<<month<<"-"<<day<<endl;
	}
	friend void operator<<(ostream & out, Date &p){
        p.display();
	}
private:
	int year;
	int month;
	int day;
};


int main(){
     int y,m,d;
	 cin>>y>>m>>d;
	 Date dt(y,m,d);
	 cout<<dt;
	 return 0;
}
