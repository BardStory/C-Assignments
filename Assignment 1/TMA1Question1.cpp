//TMA1Question1
//Author Joshua Bard
//AU# 3453236

/*
Program Purpose
Write a program that opens a file and counts the whitespace-separated words in that file.

compile: g++ -o TMA1Question1 TMA1Question1.cpp

Notes: In Mingw

No classes
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

Disscussion it does not count numbers only strings
*/

//C++ reference for the class fstream
//http://www.cplusplus.com/reference/fstream/fstream/
#include <iostream>
#include <fstream>
//important for understanding basics of c++
//reference https://medium.com/breaktheloop/why-using-namespace-std-is-used-after-including-iostream-dc5ae45db652#:~:text=First%20of%20all%2C%20you%20need,etc%20with%20the%20same%20name.&text=%E2%80%9Cusing%20namespace%20std%E2%80%9D%20means%20we,things%20with%20in%20std%20namespace.
using namespace std;

//This function will be how we counter the number of words in the file

int word_count(char filename[]){
	//ifstream is how we access the file
	ifstream fin(filename);
	//string word represents each indivudual word
	string word;
	int counter = 0;

	//this will loop until there are no words in the file and everytime it sees a word adds to the counter
	while (!fin.eof()){
		fin >> word;
		counter++;
	}
	//closes the file and returns the total counter of words.
	fin.close();
	//counter has a word to many so we can just substract once the loop is finished.
	counter = counter-1;
	return counter;

}

//this is where we will enter the filename. Because it is a name we will make it a char array.
//We then use Cout to print to the terminal to enter the file
//more info on how << and >> work at https://www.javatpoint.com/cpp-basic-input-output#:~:text=Standard%20end%20line%20(endl),standard%20end%20line%20(endl)%3A

int main()
{
	char filename[1000];
	cout << "Please enter the filename: ";
	cin >> filename;
	//endl is just like \n so that the next output is on a new line
	cout << "In the file there are " << word_count(filename) << " words." << endl;
	//the main must return someting
	return 0;
}