//TMA1Question4
//Author Joshua Bard
//AU# 3453236

/*Program Purpose
Write a program that uses two nested for loops and the modulus operator (%) to detect and print 
the prime numbers from 1 to 10,000. Prime numbers are integral numbers that are 
not evenly divisible by any other numbers except for themselves and one. 
Display all the primes found.


compile: g++ -o TMA1Question4 TMA1Question4.cpp

Notes: In Mingw
*/

/*
It is all done in the main so no need for test cases
*/


#include <iostream>
#include <cmath>

using namespace std;

int main(){
//Created a boole to keep track if we are on a prime number or not
   bool primenumber = true;
   //For loop that goes from 1-10 000
   for(int i = 1; i<=10000; i++){
   	//We assume that all numbers will be prime
    primenumber = true;
    //test if it is a prime number
    for(int j = 2;j<=sqrt(i);j++){
        //not prime is found
        if(i % j == 0){
        	//we set prime number to false and break the loop to prevent it from being printed
            primenumber = false;
            break;
        }
    }
    //only prints when the prime number is currently true
    if(primenumber == true){
         cout << i << " ";
    }
   }
   return 0;
}