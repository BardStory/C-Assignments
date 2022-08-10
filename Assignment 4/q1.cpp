#include <iostream>
using namespace std;


class Point
{

public:
   int x, y;
   Point()
   {
       x = 0;
       y = 0;
   }

   Point(int a, int b)
   {
       x = a;
       y = b;
   }

   Point operator+(Point& obj)
   {
       Point t;

       t.x = x + obj.x;
       t.y = y + obj.y;
       return t;

   }

   Point operator-(Point& obj)
   {
       Point t;

       t.x = x - obj.x;
       t.y = y - obj.y;
       return t;

   }

   friend ostream& operator<<(ostream& o, Point& p)
   {
       o << "X coordinate :" << p.x << endl;
       o << "Y coordinate :" << p.y << endl;
       return o;
   }
};

class Shape
{
public:
   void area();
   void circumference();
   void display();


};

class Circle :public Shape
{
   Point p;
   int radius;
public:
   Circle(Point& p1, int r)
   {
       p = p1;
       radius = r;
   }

   void area()
   {
       cout << "Area of circle is " << 3.14*radius*radius << endl;
   }

   void circumference()
   {
       cout << "circumference of circle is " << 3.14 * 2 * radius << endl;
   }


   void display()
   {
       cout << "Area of circle is " << 3.14*radius*radius << endl;
       cout << "circumference of circle is " << 3.14 * 2 * radius << endl;
   }


};


class Square :public Shape
{
   Point p1, p2, p3, p4;

public:
   Square(Point& p1, Point& p2, Point& p3, Point& p4)
   {
       this->p1 = p1;
       this->p2 = p2;
       this->p3 = p3;
       this->p4 = p4;
   }

   void area()
   {
       int side = sqrt((p1.x - p2.x)*(p1.x - p2.x) + (p1.y - p2.y)*(p1.y - p2.y));
       cout << "Area of Square is " << side*side << endl;
   }

   void circumference()
   {
       int side = sqrt((p1.x - p2.x)*(p1.x - p2.x) + (p1.y - p2.y)*(p1.y - p2.y));

       cout << "circumference of Square is " << 4 * side << endl;
   }

   void display()
   {
       int side = sqrt((p1.x - p2.x)*(p1.x - p2.x) + (p1.y - p2.y)*(p1.y - p2.y));
       cout << "Area of Square is " << side*side << endl;

       cout << "circumference of Square is " << 4 * side << endl;
   }

};

class Triangle :public Shape
{

   Point p1, p2, p3;
public:


   Triangle(Point& a, Point& b, Point& c)
   {
       p1 = a;
       p2 = b;
       p3 = c;
   }


   void circumference()
   {
       int s1 = sqrt((p1.x - p2.x)*(p1.x - p2.x) + (p1.y - p2.y)*(p1.y - p2.y));
       int s2 = sqrt((p1.x - p3.x)*(p1.x - p3.x) + (p1.y - p3.y)*(p1.y - p3.y));
       int s3 = sqrt((p3.x - p2.x)*(p3.x - p2.x) + (p3.y - p2.y)*(p3.y - p2.y));
       cout << "circumference of Triangle is " << s1 + s2 + s3 << endl;


   }

   void area()
   {
       int area = abs(p1.x*(p2.y - p3.y) + p2.x*(p3.y - p1.y) + p3.x*(p1.y - p2.y)) / 2;
       cout << "Area of Triangle is " << area << endl;
   }

   void display()
   {
       int s1 = sqrt((p1.x - p2.x)*(p1.x - p2.x) + (p1.y - p2.y)*(p1.y - p2.y));
       int s2 = sqrt((p1.x - p3.x)*(p1.x - p3.x) + (p1.y - p3.y)*(p1.y - p3.y));
       int s3 = sqrt((p3.x - p2.x)*(p3.x - p2.x) + (p3.y - p2.y)*(p3.y - p2.y));
       cout << "circumference of Triangle is " << s1 + s2 + s3 << endl;
       int area = abs(p1.x*(p2.y - p3.y) + p2.x*(p3.y - p1.y) + p3.x*(p1.y - p2.y)) / 2;
       cout << "Area of Triangle is " << area << endl;

   }


};

class Rectangle :public Shape
{

   Point p1, p2;
public:


   Rectangle(Point& a, Point& b, Point& c)
   {
       p1 = a;
       p2 = b;
       p3 = c;
   }
   void area()
   {
       int height = sqrt((p1.x - p2.x)*(p1.x - p2.x) + (p1.y - p2.y)*(p1.y - p2.y));
       int width = sqrt((p1.x - p3.x)*(p1.x - p3.x) + (p1.y - p3.y)*(p1.y - p3.y));
       int area=height*width;

       cout<<"Area of Rectangle ="<<area<<endl;
   }

   void perimeter()
   {
       int height = sqrt((p1.x - p2.x)*(p1.x - p2.x) + (p1.y - p2.y)*(p1.y - p2.y));
        int width = sqrt((p1.x - p3.x)*(p1.x - p3.x) + (p1.y - p3.y)*(p1.y - p3.y));
        int perimeter=2*(height+width);

        cout<<" Perimeter of rectangle are = "<<perimeter<<endl;
   }

   void display()
   {
        int height = sqrt((p1.x - p2.x)*(p1.x - p2.x) + (p1.y - p2.y)*(p1.y - p2.y));
        int width = sqrt((p1.x - p3.x)*(p1.x - p3.x) + (p1.y - p3.y)*(p1.y - p3.y));
        int perimeter=2*(height+width);
        int area=height*width;

        cout<<"Area of Rectangle ="<<area<<endl;
        cout<<" Perimeter of rectangle are = "<<perimeter<<endl;

   }

};
int main(int argc, char const *argv[])
{

   Point p1(10, -5);
   Circle c(p1, 23);
   c.area();
   c.circumference();

   cout << "=========================================\n";
   Point p2(5, -5);
   Point p3(-10, 7);
   Point p4(4, 23);
   Point p5(-6, 12);
   Square s(p2, p3, p4, p5);
   s.area();
   s.circumference();


   cout << "=========================================\n";

   Point p6(0, 0);
   Point p7(10, 10);
   Point p8(-15, 15);
   Triangle t(p6, p7, p8);
   t.area();
   t.circumference();
   cout << "=========================================\n";

   Point p9(0, 0);
   Point p10(10, 10);
   Point p11(10, 10);

   Rectangle r(p9, p10, p11);
   r.area();
   r.perimeter();
   return 0;
}