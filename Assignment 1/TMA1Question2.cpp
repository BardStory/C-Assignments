//TMA1Question2
//Author Joshua Bard
//AU# 3453236

/*Program Purpose
Write a program that opens a (text) file, 
and displays the contents of that file one line at a time. 
After a line has been displayed, 
the program should wait for the user to press the <enter> key before displaying 
the next line in the file.

compile: g++ -o TMA1Question2 TMA1Question2.cpp

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

Disscussion it does not count numbers only strings
*/
#include <iostream>
#include <fstream>

using namespace std;

//This is how we will traverse the file by each line
void printline(char filename[]) {
  //inserts the first line into the file
  ifstream fin(filename);
   
  string nextline;
  string currentline;
  //http://www.cplusplus.com/reference/string/string/getline/
  /*The loop will go through every line of the text file
  inside the loop it will replace the current line with the next line
  and it will print the current line
  */
  while(getline(fin,currentline) ){
    getline(cin, nextline);
    cout << currentline;
    }

    fin.close();
}

//we can essentually just use the same main as Question1 as we are input is from filename
//and we call the function printline 
int main(){
  char filename[1000];
  cout << "Please enter the filename: ";
  cin >> filename;
  
  printline(filename);
    
  return 0;
}