//TMA3Question3
//Author Joshua Bard
//AU# 3453236
//June 25, 2020

/*Program Purpose:
Create a simple class (DoStuff) containing an int, and overload the operator+ as a member function. 
Also, provide a print() member function that takes an ostream& as an argument and prints to that 
ostream&. Add a binary operator- and operator+ to the class as member functions. 
You should be able to use the objects in complex expressions such as a + b – c. 
Now add the operator++ and operator--, both prefix and postfix versions. 
Overload the << operator to provide the same functionality as the print() member function. 
Test the class to show that all requirements work correctly.

Note uses MingGW

compile: g++ TMA3Question3.cpp -o TMA3Question3
Execution: ./TMA3Question3

Testfiles are not needed because it all takes place in main.

The first run with only prefix when x =1 should be

PREFIX OPERATIONS
x starts as: 1
increment: 2
value of x is: 2
decrement: 1
x value is: 1

POSTFIX OPERATIONS
x starts as: 1
increment: 1
value of x is: 2
decrement: 2
x value is: 1

<< OPERATION
Should print x as 1 aka the solution
*/

#include <iostream>

using namespace std;

class DoStuff{
	//declares the variable interger
private:
	int integer;

public:
	DoStuff() : integer(0){
	};

	DoStuff(int filler_variable) : integer(filler_variable){
	}
	//this should overload the = operator
	DoStuff operator+(){
		return *this;
	}
	//binary addition
	//reference for reference variables same one used in TMA2
	//https://www.tutorialspoint.com/cplusplus/cpp_references.htm
	DoStuff operator+(DoStuff& binaryNumber){
		return DoStuff(this -> integer + binaryNumber.integer);
	}
	//binary substraction
	DoStuff operator-(DoStuff& binaryNumber){
		return DoStuff(this -> integer - binaryNumber.integer);
	}
	//prints outputs
	//reference for std::to_string() below
    //https://en.cppreference.com/w/cpp/string/basic_string/to_string
	void print(std::ostream& output){
        output << std::to_string(this -> integer);
    }

	//prefix incrementation
    DoStuff& operator++ (){
        ++this ->integer;
        return *this;
    }

     //Postfix decrementation
    DoStuff operator++ (int){
        DoStuff object(*this);
        this -> integer++;
        return object;
    }

    //prefix decrementation
    DoStuff& operator-- (){
        --this -> integer;
        return *this;
    }

    //postfix decrementation
    DoStuff operator-- (int){
        DoStuff object(*this);
        this ->integer--;
        return object;
    }

    //using the ostream was complicated. I used a microsoft reference to understand the layoud
    //https://docs.microsoft.com/en-us/cpp/standard-library/overloading-the-output-operator-for-your-own-classes?view=vs-2019
    friend std::ostream& operator <<(std::ostream& output, const DoStuff& final_value){
    	// returns the output with a string version of the integer.
        return output << std::to_string(final_value.integer);
    }
};


int main()
{
	
	/*
	TESTCASES
	DoStuff a(1), b(3), c(2);
	DoStuff x(a+b-c);

	DoStuff a(1), b(3), c(2);
	DoStuff x(a-b-c);
	*/
	//initialse doStuff with numbers
	DoStuff a(7), b(-2), c(4);
	DoStuff x(a+b-c);

	//performs the first test
	cout << "Using DoStuff: " << endl;
	cout << "7 + (-2) - 4 = ";
	x.print(cout); 
	cout << endl;

	//Below is the test for every operation

	cout << endl << "Testing DoStuff operations: " << endl << endl;

	cout << "The value of x: "; 
	x.print(cout);
	cout << endl;

	cout << "x with prefix incremetation (++x) = ";
	(++x).print(cout); 
	cout << endl;

	cout << "The value of x: "; 
	(x).print(cout); 
	cout << endl;

	cout << "x with prefix decrementation (--x) = ";
	(--x).print(cout); 
	cout << endl;
	
	cout << "The value of x: "; 
	(x).print(cout); 
	cout << endl;

	cout << "x with postfix incremetation (x++) = ";
	(x++).print(cout); 
	cout << endl;
	
	cout << "The value of x: "; 
	(x).print(cout); 
	cout << endl;
	
	cout << "x with postfix decrementation (--x) = ";
	(x--).print(cout); 
	cout << endl;

	cout << "The value of x: "; 
	(x).print(cout); 
	cout << endl;

	cout << endl << "Testing DoStuff operation <<: "<< endl;
	cout << x << endl;



    return 0;
} 