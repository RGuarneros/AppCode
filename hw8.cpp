// Richard Guarneros rg47499

#include <iostream>
using std::cin;
using std::cout;

#include <cmath>
using std::sqrt;

#include <fmt/format.h>
using fmt::format,fmt::print;

#include <memory>
using std::make_shared,std::shared_ptr;

class Point {
protected:
  float x,y;
public:
  Point(float ux,float uy) { x = ux; y = uy; };
  // Point class methods
  float dx( Point other ) {
    return other.x-x; };
  float dy( Point other ) {
    return other.y-y; };
  float distance(Point other) {
    float wd = dx(other), ht = dy(other);
    return sqrt( wd*wd + ht*ht );
  };
  // added scale method to move point around
  void scale(float scaleby){
    x*=scaleby;y*=scaleby;
  }
};

class Rectangle {
private:
  Point bottom_left,top_right;
public:
  Rectangle( Point bl,Point tr )
    : bottom_left(bl),top_right(tr) {};
  float area() {
    float
      xsize = bottom_left.dx(top_right),
      ysize = bottom_left.dy(top_right);
    return xsize*ysize;
  };
};

class DynRectangle {
private:
    shared_ptr<Point> bottom_left=nullptr,
      top_right = nullptr;
public:
  // constructor:
  DynRectangle(shared_ptr<Point> botcorner,shared_ptr<Point> topcorner):
    bottom_left(botcorner), top_right(topcorner){};

  // area function:
  float area() {
    float
      xsize = bottom_left->dx(*top_right),
      ysize = bottom_left->dy(*top_right);
    return xsize*ysize;
  };
};

int main() {

  //Smart Pointers: Exercise 4 
  {
    auto 
      origin = make_shared<Point>(0,0),
      fivethree = make_shared<Point>(5,3),
      sevenfive = make_shared<Point>(7,5);
    DynRectangle baserectangle(origin,fivethree),
        toprectangle(fivethree,sevenfive);
    cout << "Base rectangle area: " << baserectangle.area() << '\n';   
    cout << "Top rectangle area: " << toprectangle.area() << '\n';
    fivethree->scale(0.5);
    cout << "Base rectangle area: " << baserectangle.area() << '\n';   
    cout << "Top rectangle area: " << toprectangle.area() << '\n';
  }
  //Used scale function to move the shared point
  return 0;
}