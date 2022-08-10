//TMA1Question3
//Author Joshua Bard
//AU# 3453236

/*Program Purpose
Write a program that creates three vector<float> objects. 
Fill the first two objects with 25 floating-point numbers using a for loop as follows:

1.  fill the first vector object with the loop counter value;
2.  fill the second vector object with the loop counter value squared;
3.  finally, write a for loop that adds the corresponding elements in the first two vectors, 
	and puts the result in the corresponding element of the third vector.

compile: g++ -o TMA1Question3 TMA1Question3.cpp

Notes: In Mingw
*/

/*
It is all done in the main so no need for test cases
*/


//reference for vectors http://www.cplusplus.com/reference/vector/vector/

#include <iostream>
#include <vector>

using namespace std;

//We can do this all in the main
int main(){
	//create the 3 vector variables
	vector<float> vector1,vector2,vector3;

	//reference for push_back http://www.cplusplus.com/reference/vector/vector/push_back/
	//this is loop for part 1 that just takes 25 ints adds them to the vectors
	for(int i=0; i<25; i++){

		vector1.push_back(i);
		vector2.push_back(i*i);
	}
	//This for loop will at vector1 and vector2 at each instance then add the sum to vector3
	for(int i=0; i<vector1.size(); i++){

		float value = vector1.at(i)+ vector2.at(i);

		vector3.push_back(value);
	}
	//This is the loop that will be used as the output with formatting.
	for(int i=0; i<vector3.size(); i++){

		cout << "for " << i << "; " << vector1[i] << " + " << vector2[i] << " = " << vector3[i] << endl;
	}
	//gotta return 0 in the main :)
	return 0;
}