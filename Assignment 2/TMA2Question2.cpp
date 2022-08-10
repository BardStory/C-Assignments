//TMA2Question2.cpp
//Author Joshua Bard
//AU# 3453236
//Date June 24, 2020

/*Program Purpose:
Write a program that dynamically creates pieces of storage of the following types using new: 
int, long, an array of 100 chars, and an array of 100 floats. 
Print the addresses and values of these using the format: “type @ <address>= <value>”. 
After you have printed all the addresses and values, free the storage using delete. 
Fill the char array using copies of the lowercase and uppercase alphabet (a-z, A-Z), 
and fill the float array using sequential numbers starting with 101.

Plan of attack:
Essentially we create a int,long and two arrays for char and float
We want ot print their address aswell as their values
We then want to delete them to free storage

compile: g++ TMA2Question2.cpp -o TMA2Question2.exe
Execution: ./TMA2Question2
*/


/*
This program should not require test as it is done in the main. No need for test files.

Idealy will print a single int and single long number

It should print 100 of each array except for the char array because of the null pointer
*/

#include <iostream>

using namespace std;

int main(){
	//initialise pointers and variables.
	int *integer = new int;
	long *long_int = new long;
	char *charArray = new char[100];
	float *floatArray = new float[100];
	//Make an alphabet array larger then 100 characters for the char array
	char alphabet[] = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ" ;
	int j = 0;

//we only made a pointer to a single int and long so I assume this is acceptable
cout << "int @" << &integer << "= " << *integer << endl;
cout << "long @" << &long_int << "= " << *long_int << endl;

//after we output the information we can delete to free storage
delete integer;
delete long_int;


for(int i = 101; i < 201; i++){
	floatArray[j] = (float) i;
	j++;
}
//http://tutors.ics.uci.edu/index.php/tutor-resources/81-cpp-resources/122-cpp-ref-pointer-operators
//^ reference to how to reference in c++ using &
for(int i=0; i < 100; i++){
	cout << i <<": float @ " << &floatArray + sizeof(float) * i << "= " << floatArray[i] << endl;
}
//free the storage
delete[] floatArray;

for(int i=0; i < 100; i++){
	charArray[i] = alphabet[i];
}

// we can only do 99 elements in this char array because of the '\0' at the end.
//The easiest work around would be to make the charArray size 101 instead of 100 to output
//one hundred solutions but in this case should be fine
for(int i = 0; i < 99; i++){
	cout << i << ": char @ " << &charArray + sizeof(float) * i << "= " << charArray[i] << endl;
}
//free the storage
delete[] charArray;
return 0;

}