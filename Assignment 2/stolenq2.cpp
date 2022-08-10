//: TMA2Question2.cpp

/**
 * Title: TMA2Question2.cpp
 * Description:
 *      A program that dynamically creates pieces of storage of certain types, 
 *      print them out then delete them.
 * Date: July 13, 2019
 * Author: Tommy Wu
 */

/**
 * DOCUMENTATION
 * 
 * Program Purpose:
 *      1. Dynamically create memory for an int, a long, 100 chars and 100 
 *         floats.
 *      2. Print their addresses and their value.
 *      3. Delete them.
 * 
 * Compile: clang++ TMA2Question2.cpp -o TMA2Question2
 * Execution : ./TMA2Question2
 */

/**
 * No test available for a fully static program.
 * 
 * The program should print out the address and value of int and long.
 * The program will also print out all elements in char and float array, with 
 * their index, addresses and value.
 * 
 * Note that only 99 elements are printed out for char array, since the last 
 * char of a char array should always be '\0'.
 */

#include <iostream>

// for for loops and array init
const int MAGIC_NUMBER = 100;

using namespace std;

int main()
{
    // initialization

    // automatically 0
    int* integer = new int;  
    // automatically 0L
    long* long_integer = new long;  
    // automatically '\0' for everything inside
    char* char_array = new char[MAGIC_NUMBER](); 
    // automatically 0.0 for everything inside
    float* float_array = new float[MAGIC_NUMBER]();



    // assign

    // hard code for good
    const char temp[] = "abcdefghijklnmopqrtsuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklnmopqrtsuvwxyzABCDEFGHIJKLMNOPQRSTU";


    for (int i = 0; i < MAGIC_NUMBER; i++)
    {
        char_array[i] = temp[i];
    }
    
    for (int i = 101; i < 201; i++)
    {
        float_array[i - 101] = (float) i;
    }



    // print out 

    cout << "int @ " << &integer << " = " << *integer << endl;
    cout << "long @ " << &long_integer << " = " << *long_integer << endl;

    for (int i = 0; i < MAGIC_NUMBER; i++)
    {
        cout << i <<": float @ " << &float_array + sizeof(float) * i << " = " << 
        float_array[i] << endl;
    }

    for (int i = 0; i < MAGIC_NUMBER - 1; i++)  
    // the last char is '\0' and should not be printed out
    {
        cout << i <<": char @ " << &char_array + sizeof(float) * i << " = " << 
        char_array[i] << endl;
    }



    // delete these things from memory

    delete integer;
    delete long_integer;
    delete[] char_array;
    delete[] float_array;

    return 0;
} ///:~