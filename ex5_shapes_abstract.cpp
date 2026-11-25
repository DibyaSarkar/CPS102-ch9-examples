// Example 5: Pure virtual functions, abstract classes, is-a vs. has-a
// Follows zyBooks Figure 9.6.1: Shape, Circle, Rectangle, Point
//
//   Shape  has-a  Point        (composition: a data member)
//   Circle    is-a Shape       (inheritance)
//   Rectangle is-a Shape       (inheritance)

#define _USE_MATH_DEFINES       // needed for M_PI on some Windows compilers
#include <iostream>
#include <cmath>
#include <vector>
using namespace std;

class Point {
public:
   Point() { x = 0.0; y = 0.0; }
   Point(double xVal, double yVal) { x = xVal; y = yVal; }
   double GetX() const { return x; }
   double GetY() const { return y; }
   void SetX(double xVal) { x = xVal; }
   void SetY(double yVal) { y = yVal; }
private:
   double x;
   double y;
};

// Abstract class: it has at least one pure virtual function (= 0)
class Shape {
public:
   virtual ~Shape() {}

   // Pure virtual: no body here. Every concrete shape MUST provide one.
   virtual double ComputeArea() const = 0;

   Point GetPosition() const { return position; }
   void SetPosition(Point newPos) { position = newPos; }
   void MovePositionRelative(double dx, double dy) {
      position.SetX(position.GetX() + dx);
      position.SetY(position.GetY() + dy);
   }

protected:
   Point position;          // HAS-A: every Shape has a Point
};

class Circle : public Shape {   // IS-A: a Circle is a Shape
public:
   Circle(double r) { radius = r; }

   // "override" asks the compiler to check this really matches the base version
   double ComputeArea() const override {
      return M_PI * pow(radius, 2);
   }
private:
   double radius;
};

class Rectangle : public Shape {  // IS-A: a Rectangle is a Shape
public:
   Rectangle(double l, double h) { length = l; height = h; }
   double ComputeArea() const override {
      return length * height;
   }
private:
   double length;
   double height;
};

int main() {
   // Shape s;                        // ERROR: cannot create an abstract object
   // Shape* p = new Shape();         // ERROR: not on the heap either
   Shape* shapePtr = nullptr;         // OK: pointers to an abstract class are fine

   Circle    myCircle(2.0);
   Rectangle myRect(3.0, 4.0);

   shapePtr = &myCircle;
   cout << "Circle area:    " << shapePtr->ComputeArea() << endl;
   shapePtr = &myRect;
   cout << "Rectangle area: " << shapePtr->ComputeArea() << endl;

   // has-a in action: move the circle using the inherited Point
   myCircle.SetPosition(Point(1.0, 1.0));
   myCircle.MovePositionRelative(2.5, -1.0);
   cout << "Circle now at (" << myCircle.GetPosition().GetX() << ", "
        << myCircle.GetPosition().GetY() << ")" << endl;

   // Polymorphism: total area of mixed shapes in one loop
   vector<Shape*> shapes = { &myCircle, &myRect };
   double total = 0.0;
   for (Shape* s : shapes) {
      total += s->ComputeArea();
   }
   cout << "Total area:     " << total << endl;

   return 0;
}
