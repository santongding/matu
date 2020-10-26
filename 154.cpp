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

Clock * createNewClock(int h,int m,int s);
private:
	int hour;
	int minute;
	int second;
};
#include "Clock.h"
class NewClock:public Clock{
public:
    NewClock(int h,int m,int s):Clock(h,m,s){};

    void showTime()override{
        cout<<"Now:"<<(getHour()%12)<<":"<<getMinute()<<":"<<getSecond()<<(getHour()/12?"PM":"AM")<<endl;
    }
};
Clock* Clock::createNewClock(int h,int m,int s){
	return new NewClock(h,m,s);
}
