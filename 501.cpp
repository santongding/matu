#include <iostream>

#include <cmath>

using namespace std;

class Point {

public:

  int x;

  int y;

  Point(int xx, int yy)

  {

    x = xx;

    y = yy;

  }

  void printPoint()

  {

    cout << "(" << x << "," << y << ")" << endl;

  }

};

class Line {

public:

  Point *p1, *p2;

  Line(int x1, int y1, int x2, int y2)

  {

    p1 = new Point(x1, y1);

    p2 = new Point(x2, y2);

  }

  Line(const Line &line)

  {
    p1=new Point(line.p1->x,line.p1->y);
    p2=new Point(line.p2->x,line.p2->y);
  }

  ~Line()

  {

    delete p1;

    delete p2;

  }

  void printLine()

  {

    p1->printPoint();

    p2->printPoint();

  }

};

int main()

{

int x1, y1, x2, y2;

cin >> x1 >> y1 >> x2 >> y2;

Line *l1 = new Line(x1, y1, x2, y2);

Line *l2 = new Line(*l1);

l2->printLine();

l1->p1->x++;

l2->printLine();

l1->p2->y--;

l2->printLine();

delete l1;

l2->printLine();

return 0;

}
