// A C++ program to check if four given points form a square or not. 
#include <iostream> 
using namespace std; 
  
// Structure of a point in 2D space 
struct checkPoints { 
    int x, y; 
}; 
  
// A utility function to find square of distance 
// from point 'p' to point 'q' 
int distSq(checkPoints p, checkPoints q) 
{ 
    return (p.x - q.x) * (p.x - q.x) + (p.y - q.y) * (p.y - q.y); 
} 
  
// This function returns true if (point1, point2, point3, point4) form a 
// square, otherwise false 
bool isSquare(checkPoints point1, checkPoints point2, checkPoints point3, checkPoints point4) 
{ 
    int d2 = distSq(point1, point2); // from point1 to point2 
    int d3 = distSq(point1, point3); // from point1 to point3 
    int d4 = distSq(point1, point4); // from point1 to point4 
  
    if (d2 == 0 || d3 == 0 || d4 == 0)     
        return false; 
  
    // If lengths if (point1, point2) and (point1, point3) are same, then 
    // following conditions must met to form a square. 
    // 1) Square of length of (point1, point4) is same as twice 
    // the square of (point1, point2) 
    // 2) Square of length of (point2, point3) is same 
    // as twice the square of (point2, point4) 
  
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
  
