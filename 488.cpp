#include <iostream>

using namespace std;

class Clock

{

  public:

  Clock(int h, int m, int s);

  void ShowTime()

{

    cout << "Now:" << hour << ":" << minute << ":" << second << endl;

  }

  private:

  int hour;

  int minute;

  int second;

};

void ck(int &x,const int mx){
        if(x>=mx)x=0;
        if(x<=0)x=0;
};
Clock::Clock(int h,int m, int s)
{
    ck(h,24),ck(m,60),ck(s,60);
    hour=h;
    minute=m;
    second=s;
}

int main()

{

  Clock *c1, *c2;

  int type;

  cin>>type;

  switch(type)

{

    case 1:

      c1 = new Clock(24,24,-1);

      c1->ShowTime();

      break;

    case 2:

      c2 = new Clock(5,20,30);

      c2->ShowTime();

      break;

}

  return 0;

}
