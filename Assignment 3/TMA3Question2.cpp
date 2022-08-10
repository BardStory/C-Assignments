//TMA3Question2
//Author Joshua Bard
//AU# 3453236
//June 25, 2020

/*Program Purpose:
Rewrite program #1 using an inline function to perform the calculation. 
In the test plan for this program (actual results section), 
compare the time required by this program to execute against the time required by the first 
(non-inline) program.

 Plan of Attack:
 use the last assignment but with inline function then compare
 	

compile: g++ TMA3Question2.cpp -o TMA3Question2 

Results: It seems to be a little faster using the inline function. This is very simmilar however.
There is no difference when there is loop in the inline function which I feel I should mention.

AVERAGE TIME IS 3.21s
HIGHSCORE IS 3.11s

Testfiles are not needed because it all takes place in main.

*/

#include <iostream>
#include <ctime>
#include <iomanip>

using namespace std;

//inline multiplication function.
inline multiplyfunction(double first, double second){
	double solution;
	solution = first * second;
	return solution;
}
//inlining this function has no perpose as it contains loops
//the compiler would just ignore the inline 
/*inline*/ void MultiplyNumbers(){
	int big_num = 10000;
	
	double count = 100.00;
	double sum = 0.0;

	double *array1 = new double[big_num];
	double *array2 = new double[big_num];

	//fills the first array
	for(int i=0; i<big_num;i++){
		array1[i] = count++;
	}
	
	count = big_num -1;
	
	//fills second array
	for(int i=0; i < big_num; i++){
		array2[i] = count--;
	}

	// multiplies and prints to the 10 digit using the setprecision method.
	for(int i=0; i < big_num;i++){
		sum = multiplyfunction(array1[i], array2[i]);


		//outputs the sum, Reference for setprecision below. just sets decimal value for floating point
		//http://www.cplusplus.com/reference/iomanip/setprecision/
		cout << array1[i] << "*" << array2[i] << "=" << setprecision(10) << sum << endl;
	}
}

int main(){
	//reference for clocks
	//https://www.tutorialspoint.com/c_standard_library/c_function_clock.htm
	clock_t start, end;
	double runtime = 0.0;
	double average_time = 0;

	//times being innacurate so we will loop it 20 times to get the most accurate average

	for(int i=0; i < 5; i++){
		start = clock();
		MultiplyNumbers();
		end = clock();
	
 		runtime = ((double)end - (double)start) / (double)CLOCKS_PER_SEC;
 		average_time += runtime ;
 	}
cout << "The runtime time to multiplicate of the last round was: " << setprecision(3) << runtime << "s" << endl;
cout << "The average runtime time was: " << setprecision(3) << average_time / 5.00  << "s" << endl;

return 0;
}
