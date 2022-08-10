//TMA3Question1
//Author Joshua Bard
//AU# 3453236
//June 25, 2020

/*Program Purpose:
Write a program in which you create a const whose value is determined at runtime by reading the time 
when the program starts (Hint: use the <ctime> standard header). 
In a separate function, have the program create two arrays of 10 000 doubles. 
Initialize the first array with sequential integral values starting with 100, 
and initialize the second array with the same numbers, but in reverse order 
(i.e., the first array would contain 100, 101, 102… while the second array contains 10099, 10098, 10097…). 
Loop through both arrays using a single loop, multiply the corresponding array elements from each 
array together, and display the result. Read the time when the program completes the multiplication,
then compute and display the runtime time. Do not use inline functions in this program.

compile: g++ TMA3Question1.cpp -o TMA3Question1 
EXECUTION ./TMA3Question1 


 Plan of Attack:
 	Create two arrays both of size 10000
 	Multiply them one by one
 	Find the time taken using ctime

Testfiles are not needed because it all takes place in main.

Gonna run it in a repeat of 5 times to get the average time as it does seem to very.


AVERAGE TIME IS 3.41s
HIGHSCORE IS 3.30





*/

#include <iostream>
#include <ctime>
#include <iomanip>

using namespace std;

void MultiplyNumbers(){
	int big_num = 10000;
	
	double count = 100.00;
	double sum = 0.0;

	double *array1 = new double[big_num];
	double *array2 = new double[big_num];

	//fills the first array
	for(int i=0; i<big_num;i++){
		array1[i] = count++;
	}
	//substract 1 to count to start at 10999
	count = big_num -1;
	//fills second array
	for(int i=0; i < big_num; i++){
		array2[i] = count--;
	}

	// multiplies and prints to the 10 digit using the setprecision method.
	for(int i=0; i < big_num;i++){
		sum = array1[i]*array2[i];
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
 	//prints and changes the precision to 3 to allow for readability
	cout << "The runtime time to multiplicate of the last round was: " << setprecision(3) << runtime << "s" << endl;
	cout << "The average runtime time was: " << setprecision(3) << average_time / 5.00  << "s" << endl;

	return 0;
}