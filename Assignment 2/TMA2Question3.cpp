//TMA2Question3.cpp
//Author Joshua Bard
//AU# 3453236
//Date June 24, 2020

/*Program Purpose:
Write a program in which you create a Hen class. Inside this class, nest a Nest class. 
Inside Nest, place an Egg class. Each class should have a display() member function. 
For each class, create a constructor and a destructor that prints an appropriate message when 
it is called. In main(), create an instance of each class using new, 
and call the display() function for each one. After calling display(), 
free the storage using delete.

Plan of Attack:
create a class Hen with a constructor, deconstructor, display
Create a class in the class with constructor, deconstructor, display
create a class in the previously class with a constructor, deconstructor, display

Honestly easiest way to do this is create the hen class then copy paste with new names

compile: g++ TMA2Question3.cpp -o TMA2Question3.exe
Execution: ./TMA2Question3
*/

/*
	No test files needed as it is all done in main

	Should display if done properly 

	Constructed Hen
	Constructed Nest
	Constructed Egg
	Display Hen
	Display Nest
	Display Egg
	Deconstructed Hen
	Deconstructed Nest
	Deconstructed Egg
*/

#include <iostream>

using namespace std;

//creates the class Hen with a constructor,deconstructor and display method
class Hen{
public: 
	Hen(){
		cout << "Constructed Hen" << endl;
	}
	//reference for a destructor below
	//https://www.geeksforgeeks.org/destructors-c/
	~Hen(){
		cout << "Deconstructed Hen" << endl;
	}

	void display(){
		cout << "Display Hen" << endl;
	}
	//creates the class Nest with a constructor,deconstructor and display method
	class Nest{
	public:
		Nest(){
			cout << "Constructed Nest" << endl;
		}
		~Nest(){
			cout << "Deconstructed Nest" << endl;
		}
	
		void display(){
			cout << "Display Nest" << endl;
		}
		//creates the class Egg with a constructor,deconstructor and display method
		class Egg{
		public:
			Egg(){
				cout << "Constructed Egg" << endl;
			}
			~Egg(){
			cout << "Deconstructed Egg" << endl;
			}
		
			void display(){
			cout << "Display Egg" << endl;
			}

		};
	};
};
int main(){
	//creating an object of each class and subclass
	Hen* object1 = new Hen();
    Hen::Nest* object2 = new Hen::Nest();
    Hen::Nest::Egg* object3 = new Hen::Nest::Egg();

    //Reference on how to use methods in classes
    //https://www.tutorialspoint.com/cplusplus/cpp_member_operators.htm
    object1 -> display();
    object2 -> display();
    object3 -> display();
    //deletes objects to free storage
    delete object1;
    delete object2;
    delete object3;

    return 0;
}