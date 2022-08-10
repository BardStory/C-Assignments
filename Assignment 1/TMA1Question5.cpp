//TMA1Question5
//Author Joshua Bard
//AU# 3453236

/*Program Purpose
Write a program that creates an array of 100 string objects. 
Fill the array by having your program open a (text) file, 
and read one line of the file into each string until you have filled the array. 
Display the array using the format “line #: <string>”, where # is the actual line number 
(you can use the array counter for this value), and <string> is the stored string.

compile: g++ -o TMA1Question5 TMA1Question5.cpp

Notes: In Mingw
*/

/*
TEST PLAN

Test 0: 
(blank document)


Test 1: 
Contains words


Test 2: 
This has words
on different lines


Test 3: 
This has

more words

seperated by multiple lines 


Test 4:
(document goes over 100 lines)

Disscussion It will not work for a file with over 100 lines
*/



#include <iostream>
#include <fstream>
//reference for cstdlib http://www.cplusplus.com/reference/cstdlib/
#include <cstdlib>

using namespace std;

int main(){
	//variable initialising
	string filename;
	string storedlines[100];
	string currentLine;
	int i=0;
	//sets up the filename to be entered
	cout << "Please enter the filename: ";
	cin >> filename;


	ifstream input(filename.c_str());
	
	//goes and store each line into the storage array
	while (getline(input, currentLine)){
		storedlines[i]=currentLine;
		i++;
	}

//loop for the output to print the proper format
//Assuming we are allowed to print the empty lines
for(int i=0; i<100;i++){
	cout << "line " << i+1 << ": " << storedlines[i] << endl;
}

input.close();
return 0;
}