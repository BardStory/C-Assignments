#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;

class Point
{
   private:
double x,y;
public :
Point()
{
x=0;
y=0;
}
Point(double px,double py)
{
x=px;
y=py;
}
friend ostream& operator<<(ostream& os, Point &p)
{
os<<"("<<p.x<<","<<p.y<<")";
return os;
}
Point &operator+(const Point& rhs)
{
Point *po=new Point();
po->setPoint(x+rhs.get_x(),y+rhs.get_y());
return *po;
}
Point &operator-(const Point& rhs)
{
Point *po=new Point();
po->setPoint(x-rhs.get_x(),y-rhs.get_y());
return *po;
}
  
void setPoint(double px,double py)
{
x=px;
y=py;
}
double get_x()const
{
return x;
}
double get_y()const
{
return y;
}
  
};
class Shape
{
protected:
double width,height;
Point center;
public :
Shape()
{
width=0;
height=0;
}
Shape(double w,double h)
{
width=w;
height=h;
}
virtual double area()=0;
virtual double circumference()=0;
virtual void display()=0;

};
class Circle : public Shape
{
Point center;
double radius;
  
public :
Circle(Point p,double r)
{
center=p;
radius=r;
}
void setRadius(double r)
{
radius=r;
}
double getRadius()
{
return radius;
}
double circumference()
{
return 2*3.14159*radius;
}
double area()
{
return radius*radius*3.14159;
}
  
void display()
{
   cout<<"Circle :"<<endl;
   cout<<"Center :"<<center<<endl;
   cout<<"Radius :"<<radius<<endl;
   cout<<"Area :"<<area()<<endl;
   cout<<"Perimeter :"<<circumference()<<endl;
   }
};
class Triangle : public Shape
{
Point p1;
Point p2;
Point p3;
int side1;
int side2;
int side3;
public :
Triangle()
{

}
Triangle(Point p1,Point p2,Point p3,int side1,int side2,int side3)
{
this->p1=p1;
this->p2=p2;
this->p3=p3;
this->side1=side1;
this->side2=side2;
this->side3=side3;
}
  
double area()
{
    double p = circumference() / 2;

double area = sqrt(p * (p - side1) * (p - side2) * (p - side3));
  
return area;
}
double circumference()
{
return side1+side2+side3;
}

void display()
{
   cout<<"Triangle :"<<endl;
   cout<<"3 Points :"<<p1<<", "<<p2<<", "<<p3<<endl;
   cout<<"Side1 :"<<side1<<endl;
   cout<<"Side2 :"<<side2<<endl;
   cout<<"Side3 :"<<side3<<endl;
   cout<<"Area :"<<area()<<endl;
   cout<<"Perimeter :"<<circumference()<<endl;
   }
};
class Square: public Shape
{
Point p1;
Point p2;
Point p3;
Point p4;
  
double side;
public :
Square(Point p1,Point p2,Point p3,Point p4,double s)
{
   this->p1=p1;
this->p2=p2;
this->p3=p3;
this->p4=p4;
side=s;
}
double getSide()
{
return side;
}
void setSide(double s)
{
side=s;
}
double area()
{
return side*side;
}
double circumference()
{
return 4*side;
}
void display()
{
   cout<<"Square :"<<endl;
   cout<<"4 Points :"<<p1<<", "<<p2<<", "<<p3<<", "<<p4<<endl;
   cout<<"Side :"<<side<<endl;
   cout<<"Area :"<<area()<<endl;
   cout<<"Perimeter :"<<circumference()<<endl;
   }
};
int main()
{
   Point p1;
  
Circle c(p1,23);

Point p2(3,4);
Point p3(-4,6);
Point p4(5,4);
Square s(p1,p2,p3,p4,25);

Triangle t(p1,p2,p3,10,20,30);

c.display();
cout<<endl;

s.display();
cout<<endl;

t.display();

return 0;
}