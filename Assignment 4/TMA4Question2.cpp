//TMA4Question2
//Author Joshua Bard
//AU# 3453236
//June 25, 2020

/* Program Purpose
Create an inheritance hierarchy of Rodent: Mouse, Gerbil, Hamster, etc. 
In the base class, provide methods that are common to all Rodents, 
and refine these in the derived classes to perform different behaviours 
depending on the specific type of Rodent. Rodent must be created as a pure abstract base class. 
Create an array of pointers (10) to Rodent, and fill it with different specific types of Rodents. 
Call your base class methods, and display the results.

compile: g++ TMA4Question2.cpp -o TMA4Question2 
EXECUTION ./TMA4Question2 

Creates the class rodent and 5 subspecies of rodents.
The only thing that I found was arm/legs and they all have tails....
*/

#include <iostream>
#include <string>

using namespace std;

class Rodent{
protected:
	int arms;
	int legs;
	int tails;
public:
	void set_values(int a, int b, int c){

		arms = a;
		legs = b;
		tails = c;
	}

	virtual int GetArmsAndLegs(void) =0;

	virtual int Tails(void) =0;
};

class Hamster : public Rodent{
public:

	int GetArmsAndLegs(void){
		return legs;
	}

	int Tails(void){
		return tails;
	}
};

class Mouse : public Rodent{
public:
	int GetArmsAndLegs(void){
		return legs;
	}
	int Tails(void){
		return tails;
	}
};

class Gerbil : public Rodent{
public:

	int GetArmsAndLegs(void){
		return legs;
	}
	int Tails(void){
		return tails;
	}
};

class Chinchilla : public Rodent{
public:

	int GetArmsAndLegs(void){
		return legs;
	}
	int Tails(void){
		return tails;
	}
};

class Beaver : public Rodent{
public:
	int GetArmsAndLegs(void){
		return legs;
	}
	int Tails(void){
		return tails;
	}
};

int main(){
	Hamster Hami, Hamich;
	Mouse Moose, Minx, Merium;
	Gerbil Gabe, Gabriel;
	Chinchilla Chuck, Charles;
	Beaver Dave;


	Rodent * pets[] = {&Hami,&Hamich,&Moose,&Minx,&Merium,&Gabe,&Gabriel,&Chuck,&Chuck,&Charles,&Dave};

	cout << " The total number of tails: " << endl;

	for(int i=0; i<10; i++){
		pets[i] -> set_values((i+1),(i+1),(i+1));
		cout << pets[i] -> Tails() << "," << endl;
	}
	
	cout << "Number of total legs and arms on rodents: " << endl;
	
	for(int i=0; i<10; i++){
		pets[i] -> set_values(2*(i+1),2*(i+1),2*(i+1));
		cout << pets[i]-> GetArmsAndLegs() << "," << endl;
	}

return 0;
}