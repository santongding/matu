#include<iostream>
using namespace std;
class Date{
 public:
       Date(int y =1996,int m=1,int d=1);
       int days(int year,int month);
       void NewDay();
 void display()
 {
    cout<<year<<"-"<<month<<"-"<<day<<endl;
 }
 private:
      int year; //Äê
      int month; //ÔÂ
      int day;  // ÈÕ
};
#include "CDate.h"
int dd[]={0,31,28,31,30,31,30,31,31,30,31,30,31};
Date::Date(int y,int m,int d){
    if(m>12){
        printf("Invalid month!\n");
        m=1;
    }
    if(d>days(y,m)){
        printf("Invalid day!\n");
        d=1;
    }
    year=y,month=m,day=d;
}
int  Date::days(int year,int month){
    if(month!=2){
        return dd[month];
    }else{
        if(year%100)return dd[month]+((year%4)?0:1);
        else return dd[month]+((year%400)?0:1);
    }
}
void Date::NewDay(){
    if(day==days(year,month)){
        day=1,month++;
        if(month==13)year++,month=1;
    }else{
        day++;
    }
}
int main(){
Date d(1993,13,32);
d.display();
}
