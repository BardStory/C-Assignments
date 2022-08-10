#include <iostream>
using namespace std;

class Rodent { //abstract base class
protected:
int hands, legs; //properties
public:
void set_values (int a, int b) //setter method for properties
{ hands=a; legs=b; }
virtual int getLegCount (void) =0; //common method
};

class Mouse: public Rodent { //child class
public:
int getLegCount (void) //implenting common method
{ return (hands + legs); }
};

class Gerbil: public Rodent { //child class
public:
int getLegCount (void) //implenting common method
{ return (legs); }
};

int main () {
  
Mouse mouse1,mouse2,mouse3,mouse4,mouse5; //declaring child classes
Gerbil gerbil1,gerbil2,gerbil3,gerbil4,gerbil5;
  
Rodent * rodents[] = {&mouse1,&mouse2,&mouse3,&mouse4,&mouse5,&gerbil1,&gerbil2,&gerbil3,&gerbil4,&gerbil5}; //array of pointer of 10 rodents
  
cout << "Leg counts : " << endl; //print the result of common method
for (int i = 0; i < 10; i++) {
rodents[i]->set_values(2*(i+1),2*(i+1));
cout << rodents[i]->getLegCount() << '\n';
}
  
return 0;
}