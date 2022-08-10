//TMA4Question1
//Author Joshua Bard
//AU# 3453236
//June 25, 2020

/*Program Purpose:
Write a program that creates a class hierarchy for simple geometry.

1. Start with a Point class to hold x and y values of a point. 

2. Overload the << operator to print point values, and the + and – operators to add and subtract point coordinates 
(Hint: keep x and y separate in the calculation).

3. Create a pure abstract base class Shape, which will form the basis of your shapes. 
The Shape class will contain abstract functions to calculate area and circumference of the shape, 
plus provide the coordinates (Points) of a rectangle that encloses the shape (a bounding box). 
These will be overloaded by the derived classes. 
Create a display() function that will display the name of the class, 
and all stored information about the class (including area, circumference, and bounding box).

4.Build the hierarchy by creating the Shape classes Circle, Square, and Triangle. 
For these derived classes, create default constructors, and constructors whose arguments can initialize the shapes appropriately using the correct number of Point objects 
(i.e., Circle requires a Point center and a radius, Square requires four Point vertices, while Triangle requires three Point vertices).

5.In main(), create one instance each of the following: 
   Circle(10, -5) with a radius of 23;
   Square (5, -5)(-10,7)(4,23)(-6,12); 
   and Triangle(0,0)(10,10)(-15,15). 
   Display the information from each object.

compile: g++ TMA4Question1.cpp -o TMA4Question1 
EXECUTION ./TMA4Question1 

No testfiles needed as it is all done in the main
*/

#include <iostream>
#include <cmath>
using namespace std;

   //Struct below is used with some methods further on to check if 4 points are a square.
   //The reference to where I got this methods and struct is located below and in method area.
   //https://www.geeksforgeeks.org/check-given-four-points-form-square/#:~:text=The%20idea%20is%20to%20pick,to%20%E2%88%9A2%20times%20d.
struct checkPoints { 
    int x, y; 
}; 
//Creates the class point
class Point{
public:
   int x,y;
   Point(){
      x,y=0;
   }

   Point(int x1, int y1){
      x = x1;
      y = y1;
   }

   //methods to retrieve X and Y values easily
   int getX()const
   {
      return x;
   }
      int getY()const
   {
      return y;
   }

   //overides the + operation
   Point operator+(Point& holder){
      Point temp;

      temp.y = y + holder.y;
      temp.x = x + holder.x;
      
      return temp;
   }
   //overides the - operation
   Point operator-(Point& holder){
      Point temp;

      temp.y = y - holder.y;
      temp.x = x - holder.x;

      return temp;
   }

   friend ostream& operator<<(ostream& output, Point& temp_point){
      output  << "(" << temp_point.x << "," << temp_point.y << ")";
      
      /*output << endl << "x=" << temp_point.x << endl;
      output << "y=" << temp_point.y << endl << "------------------";*/
      return output;

   }
};

//Creates the abstract data class for Shape with the 4 methods
class Shape{
public: 
   void area();
   void circumference();
   void display();
   void boundingbox();
};
//------------------------------------------------------------------------
//derived class from shape for the circle
class Circle : public Shape{
   Point middle;
   int radius;
   double pi = 3.1415926535897932384626433832795028841971693993751058209749445923078164062862089986280348253421170679;
public:
  //constructor
   Circle(Point& temp_point, int rad){
      radius=rad;
      middle = temp_point;
   }
   //finds the area of the circle
   void area(){
      double solution_area = pi * radius *radius;
      cout << "Area: " << solution_area << endl;
   }
   //finds the circumference of the circle
   void circumference(){
      double solution_circ = 2 * pi * radius;
      cout << "Circumference: " << solution_circ << endl;
   }

   //Takes the mid point and substracts or adds the radius to find values for the box
   // Because we only use a single point it does not require as much work
   //we substract and add 1 so that the rectangle does not have the same points
   void boundingbox(){
    int tempX = middle.getX();
    int tempY = middle.getY();
    
    int point1ValueX = radius + tempX + 1;
    int point2ValueX = tempX - radius - 1;

    int point3ValueY =  radius + tempY + 1;
    int point4ValueY = tempY - radius - 1;

    Point Boxp1(point1ValueX,middle.getY());
    Point Boxp2(point2ValueX,middle.getY());
    Point Boxp3(middle.getX(), point3ValueY);
    Point Boxp4(middle.getX(), point4ValueY);

    cout << "Bounding Box Points: " << Boxp1 << Boxp2 << Boxp3 << Boxp4 << endl;
   }

   //Method to display Circle
   void display(){
      cout << "----------------------------------------------------------" << endl;
      cout << "Circle: " <<endl;
      cout << "Center: " << middle << endl;
      cout << "Radius:" << radius << endl;
      area();
      circumference();
      boundingbox();
   }
};

//---------------------------------------------------------------------------------------
//class derived from shape for Square
class Square: public Shape{
   Point point1;
   Point point2;
   Point point3;
   Point point4;
   int side;

public:
  //constructor
   Square(Point& point1, Point& point2, Point& point3, Point& point4)
   {
       this->point1 = point1;
       this->point2 = point2;
       this->point3 = point3;
       this->point4 = point4;
   }
   //finds the area
   void area(){
      int sideX = (point1.x - point2.x);
      int sideY = (point1.y - point3.y);
      int side = sideX * sideY;
      cout << "Area: " << side << endl;
   }
   //finds teh circumference
   void circumference(){
      int side2 = (point1.x - point2.x);
      int circ = 4 * side2;
      cout << "Circumference: " << circ << endl;
      }

      //This checks each point for the smallest, largest X and Y values
      //it then puts those values and substracts 1 for the smallest
      //and adds 1 for the largest.
      //It then uses those numbers to set the box points.
      void boundingbox(){
        int smallestX = point1.getX();
        int smallestY = point1.getY();
        int largestX = point1.getX();
        int largestY = point1.getY();
        
        if(smallestX > point2.getX()){
          smallestX = point2.getX();
        }

        if(smallestX > point3.getX()){
          smallestX = point3.getX();
        }
        if(smallestX > point4.getX()){
          smallestX = point3.getX();
        }

        smallestX = smallestX -1;

        if(smallestY > point2.getY()){
          smallestY = point2.getY();
        }
        if(smallestY > point3.getY()){
          smallestY = point3.getY();
        }
        if(smallestY > point4.getY()){
          smallestY = point4.getY();
        }
        smallestY = smallestY -1;

        if (largestX < point2.getX()){
          largestX = point2.getX();
        }
        if (largestX < point3.getX()){
          largestX = point3.getX();
        }
        if (largestX < point4.getX()){
          largestX = point4.getX();
        }
        largestX = largestX +1;

        if (largestY < point2.getY()){
          largestY = point2.getY();
        }
        if (largestY < point3.getY()){
          largestY = point3.getY();
        }
        if (largestY < point4.getY()){
          largestY = point4.getY();
        }
        largestY = largestY +1;


        Point Boxp1(smallestX,smallestY);
        Point Boxp2(smallestX,largestY);
        Point Boxp3(largestX, smallestY);
        Point Boxp4(largestX, largestY);

       cout << "Bounding Box Points: " << Boxp1 << Boxp2 << Boxp3 << Boxp4 << endl;
      }

  //Creates the output
  void display(){ 
  cout << "Square: " <<endl;
  cout << "4 points: " << point1 <<", " << point2 <<", " << point3 <<", " <<point4 << endl;
  cout << "Side length:" << side << endl;
  area();
  circumference();
  boundingbox();
 } 
};
//creates the class for triangle
class Triangle : public Shape{
Point point1;
Point point2;
Point point3;  
int pX1, pY1,pX2,pY2,pX3,pY3 = 0;

//constructor
public:
 Triangle(Point& a, Point& b, Point& c){
    point1 = a;
    point2 = b;
    point3 = c;
 }
 //Finds the area of the triangle
 void area(){
  pX1 = point1.getX();
  pX2 = point2.getX();
  pX3 = point3.getX();
  pY1 = point1.getY();
  pY2 = point3.getY();
  pY2 = point3.getY();

  int areasol = ((pX2 - pX1) * (pY3 - pY1) - (pX3 - pX1) * (pY2 - pY1))/2;
  cout << "Area: " << areasol << endl;    
 }
//finds the circumference of the triangle
void circumference()
{
  int s1 = sqrt((point1.getX() - point2.getX())*(point1.getX() - point2.getX()) + (point1.getY() - point2.getY())*(point1.getY() - point2.getY()));
  int s2 = sqrt((point1.getX() - point3.getX())*(point1.getX() - point3.getX()) + (point1.getY() - point3.getY())*(point1.getY() - point3.getY()));
  int s3 = sqrt((point3.getX() - point2.getX())*(point3.getX() - point2.getX()) + (point3.getY() - point2.getY())*(point3.getY() - point2.getY()));
  int circ = s1 + s2 +s3;
  cout << "Circumference: " << circ << endl;
}
//Same idea as square. Takes the lowest and highest of each point X and Y values.
//And uses them to display a rectangle that could fit the shape.
void boundingbox(){
    int smallestX = point1.getX();
    int smallestY = point1.getY();
    int largestX = point1.getX();
    int largestY = point1.getY();
    
    if(smallestX > point2.getX()){
      smallestX = point2.getX();
    }

    if(smallestX > point3.getX()){
      smallestX = point3.getX();
    }

    smallestX = smallestX -1;

    if(smallestY > point2.getY()){
      smallestY = point2.getY();
    }
    if(smallestY > point3.getY()){
      smallestY = point3.getY();
    }
    smallestY = smallestY -1;

    if (largestX < point2.getX()){
      largestX = point2.getX();
    }
    if (largestX < point3.getX()){
      largestX = point3.getX();
    }
    
    largestX = largestX +1;

    if (largestY < point2.getY()){
      largestY = point2.getY();
    }
    if (largestY < point3.getY()){
      largestY = point3.getY();
    }
    largestY = largestY + 1;


    Point Boxp1(smallestX,smallestY);
    Point Boxp2(smallestX,largestY);
    Point Boxp3(largestX, smallestY);
    Point Boxp4(largestX, largestY);

   cout << "Bounding Box Points: " << Boxp1 << Boxp2 << Boxp3 << Boxp4 << endl;
  }
  //displays the triangle
  void display(){
  cout << "----------------------------------------------------------" << endl;
  cout << "Triangle: " <<endl;
  cout << "3 points: " << point1 <<", " << point2 <<", " << point3 << endl;
  area();
  circumference();
  boundingbox();
}
};


   //Method below is a way to check if 4 points form a square
   //The reference to where I got this method is below
   //https://www.geeksforgeeks.org/check-given-four-points-form-square/#:~:text=The%20idea%20is%20to%20pick,to%20%E2%88%9A2%20times%20d.
   int distSq(checkPoints p, checkPoints q) 
   { 
    return (p.x - q.x) * (p.x - q.x) + (p.y - q.y) * (p.y - q.y); 
   } 

   bool isSquare(checkPoints point1, checkPoints point2, checkPoints point3, checkPoints point4) 
{ 
    int d2 = distSq(point1, point2); 
    int d3 = distSq(point1, point3); 
    int d4 = distSq(point1, point4); 
  
    if (d2 == 0 || d3 == 0 || d4 == 0)     
        return false; 

    if (d2 == d3 && 2 * d2 == d4 
        && 2 * distSq(point2, point4) == distSq(point2, point3)) { 
        return true; 
    } 
  
    // The below two cases are similar to above case 
    if (d3 == d4 && 2 * d3 == d2 
        && 2 * distSq(point3, point2) == distSq(point3, point4)) { 
        return true; 
    } 
    if (d2 == d4 && 2 * d2 == d3 
        && 2 * distSq(point2, point3) == distSq(point2, point4)) { 
        return true; 
    } 
  
    return false; 
} 

//Main method for testing the points
//Uses same points as instructions except for Square
int main(){
   Point p1(10, -5);
   Circle c(p1,23);
   c.display();

   //--------------------------------------------------------------------------------
   Point p2(5,-5);
   Point p3(-10,7);
   Point p4(4,23);
   Point p5(-6,12);
   
   Square s(p2,p3,p4,p5);

   checkPoints checkp2 = {5, -5},checkp3 = {-10, 7},checkp4 = {4, 23}, checkp5 = {-6, 12};

   bool squarecheck1 = isSquare(checkp2,checkp3,checkp4,checkp5);

   //Test if the points can be a square or not. If not it shows the error msg
   if(squarecheck1 == true){
      s.display();
   }
   else{
      cout << "-----------ERROR--------------";
      cout << endl << "These points cannot form a square" << endl;
      cout << "Points at: " << p2 << "," << p3 << "," << p4 << "," <<p5 << endl;
   }
   //------------------------------------------------------------------------------------------
   //Below is an example of a square with points that do make a square
   Point p21(20,10);
   Point p31(10,20);
   Point p41(20,20);
   Point p51(10,10);
   Square sq(p21,p31,p41,p51);

   checkPoints checkp21 = {20, 10},checkp31 = {10, 20},checkp41 = {20, 20}, checkp51 = {10, 10};

   bool squarecheck = isSquare(checkp21,checkp31,checkp41,checkp51);
   
   if(squarecheck == true){
      cout << "----------------------------------------------------------";
      cout << endl << "These points are a square" << endl;
      sq.display();
   }
   else{
      cout  << endl << "--------------------ERROR---------------------------------";
      cout << endl << "These points cannot form a square" << endl;
      cout << "Points at: " << p21 << "," << p31 << "," << p41 << "," <<p51 << endl;
   }

//---------------------------------------------------------------------
   //Creates a triangle and displays

   Point p6(0,0);
   Point p7(10,10);
   Point p8(-15,15);
   Triangle t(p6,p7,p8);
   t.display();


  return 0;
}