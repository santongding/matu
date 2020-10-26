#include <iostream>
using namespace std;
class Clock{
public:
	Clock(int h,int m,int s){
	 hour =(h>23? 0:h);
	 minute = (m>59?0:m);
	 second = (s>59?0:m);
	}
	virtual void run(){
		second = second+1;
		if (second>59)
		{
			second =0;
			minute+=1;
		}
		if (minute>59)
		{
			minute =0;
			hour+=1;
		}
		if (hour>23)
		{
			hour =0;
		}
	}
	virtual void showTime(){
		cout<<"Now:"<<hour<<":"<<minute<<":"<<second<<endl;
	}
	int getHour(){return hour;}
	int getMinute(){return minute;}
	int getSecond(){return second;}

Clock * createClockWithDate(int h,int m,int s,int year,int month,int day);
protected:
	int hour;
	int minute;
	int second;
};

class Date{
public:
	Date(int y=1996,int m=1,int d=1){
		day =d;
		year =y;
		month =m;
		if (m>12||m<1)
		{
			m=1;
		}
		if(d>days(y,m)){
			day = 1;
		}
	};
	int days(int year,int month);
	void NewDay();
	void display(){
		cout<<year<<"-"<<month<<"-"<<day<<endl;
	}
protected:
	int year;
	int month;
	int day;
};
#include "ClockAndDate.h"
void Date::NewDay(){
    day++;
    if(day>days(year,month)){
        month++;
        day=1;
        if(month>12){
            month=1;
            year++;
        }
    }
}
int Date::days(int year,int month){
    int d[]={31,28,31,30,31,30,31,31,30,31,30,31};
    if(year%100){
        if(!year%4)d[1]++;
    }else{
        if(year%400==0)d[1]++;
    }
    return d[month-1];
}
class ClockWithDate:public Clock,public Date{
public:
    ClockWithDate(int h,int m,int s,int year,int month,int day):Clock(h,m,s),Date(year,month,day){};
    void run()override{
        Clock::run();
        if(hour+minute+second==0){
            Date::NewDay();
        }
    }
    void showTime()override{
        Clock::showTime();
        Date::display();
    }
};
Clock* Clock::createClockWithDate(int h,int m,int s,int year,int month,int day){
	return new ClockWithDate(h,m,s,year,month,day);
}
